#include <filesystem>
#include <fstream>
#include <iostream>

#include "Semantic/semantic.h"
#include "Utils/dot.h"
#include "Utils/utils.h"
#include "parser.tab.h"

extern FILE *yyin;
extern int yyparse();
extern int yylex();

TSScriptNode *root = new TSScriptNode();

void MakeTreeImage(std::string dotExecPath, std::string filename)
{
    std::cout << "Generating dot file for " << filename << std::endl;
    using namespace std::filesystem;
    const auto dotFile = current_path() / "Output" / filename;
    create_directory(current_path() / "Output");

    std::fstream treeOut;
    treeOut.open(dotFile, std::ios_base::out);
    ToDot(root, treeOut);

    std::cout << "Generating picture" << std::endl;
    RunDot(dotExecPath, dotFile.string());
}

int main(const int argc, char **argv)
{
    std::string dotExecPath =
        (std::filesystem::current_path() / "dot\\dot.exe").string();

    std::string filePath;
    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "--dot") == 0 && i + 1 < argc)
        {
            dotExecPath = argv[i + 1];
            ++i;
        }
        else
        {
            std::cout << "Opening file " << argv[i] << std::endl;
            const auto err = fopen_s(&yyin, argv[i], "r");

            if (err != NULL)
            {
                std::cerr << "Failed to open file: " << argv[i] << std::endl;
                return 1;
            }
            filePath = argv[i];
        }
    }

    if (!yyin)
    {
        yyin = stdin;
    }

    std::cout << "Building syntax tree" << std::endl;
    yyparse();

    if (!std::filesystem::exists(dotExecPath))
    {
        std::cerr << "Error: dot executable not found at " << dotExecPath
                  << std::endl;
        return 1;
    }
    MakeTreeImage(dotExecPath, "TreeBeforeSemantic.dot");

    std::string fileName = GetFilename(filePath);

    Semantic semantic(root);
    semantic.analyze(fileName);

    if (!semantic.errors.empty())
    {
        std::cout << std::endl << ">>> Semantic errors:" << std::endl;
        for (auto const &error : semantic.errors)
        {
            std::cout << error << std::endl;
        }
        std::cout << "<<<" << std::endl;
    }

    MakeTreeImage(dotExecPath, "TreeAfterSemantic.dot");
}
