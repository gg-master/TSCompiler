#include <iostream>
#include <string>
#include <algorithm>

char* Dublicate(const char* source)
{
    const auto length = std::strlen(source) + 1;
    char* destination = new char[length];
    std::fill(destination, destination + length, 0);
    std::copy(source, source + length, destination);
    return destination;
}

void Print(const std::string& message, const int line = -1) {
    if (line >= 0) {
        std::cout << "Line:" << line << ". ";
    }
    std::cout << message << std::endl;
}

void PrintError(const std::string& errorMessage, const int line = -1) {
    if (line >= 0) {
        std::cerr << "ErrLine:" << line << ". ";
    }
    std::cerr << "error: " << errorMessage << std::endl;
}

void PrintWarn(const std::string& message, const int line = -1) {
    if (line >= 0) {
        std::cout << "WarnLine:" << line << ". ";
    }
    std::cout << "warn: " << message << std::endl;
}

void PrintIntegerLiteral(const std::string& type, const int integer) {
    Print("Found " + type + " integer literal: " + std::to_string(integer));
}

void PrintFloatingPointLiteral(const double floatingPoint) {
    Print("Found floating point literal: " + std::to_string(floatingPoint));
}

void PrintStringLiteral(const std::string& literal) {
    Print("Found string literal: \"" + literal + "\"");
}

void RemoveCharacterFromString(std::string& str, char ch) {
    const auto newLast = std::remove(str.begin(), str.end(), ch);
    str.erase(newLast, str.end());
}

void RemoveUnderline(std::string& str) {
    RemoveCharacterFromString(str, '_');
}

void LastTokenMatched(const int token) {
    
}