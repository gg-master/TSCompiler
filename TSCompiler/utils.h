#pragma once

#include <string>

void Print(const std::string& message, const int line = -1);
char* Dublicate(const char* source);
void PrintError(const std::string& errorMessage, const int line = -1);
void PrintIntegerLiteral(const std::string& type, const int integer);
void PrintFloatingPointLiteral(const double floatingPoint);
void PrintStringLiteral(const std::string& literal);
void RemoveCharacterFromString(std::string& str, char ch);
void RemoveUnderline(std::string& str);
void LastTokenMatched(const int token);