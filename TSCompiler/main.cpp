#include <iostream>
#include <fstream>
#include <filesystem>

#include "parser.tab.h"
#include "dot.h"

extern FILE* yyin;
extern int yyparse();
extern int yylex();

struct TSScriptNode* root;


void MakeTreeImage(std::string_view filename)
{
    {
        std::cout << "Generating dot file for " << filename << std::endl;
        using namespace std::filesystem;
        const auto dotFile = current_path() / "Output" / filename;
        create_directory(current_path() / "Output");
        {
            std::fstream treeOut;
            treeOut.open(dotFile, std::ios_base::out);
            ToDot(root, treeOut);
        }
        std::cout << "Generating picture" << std::endl;
        RunDot("../ThirdParty/dot/dot.exe", dotFile.string());
    }
}

int main(const int argc, char** argv)
{
    if (argc > 1)
    {
        std::cout << "Opening file " << argv[1] << std::endl;
        const auto err = fopen_s(&yyin, argv[1], "r");

        if (err != NULL) {
            std::cout << "Failed to open file: " << argv[1] << std::endl;
        }
    }
    else { yyin = stdin; }

    std::cout << "Building syntax tree" << std::endl;
    yyparse();

    MakeTreeImage("TreeBeforeSemantic.dot");
}
