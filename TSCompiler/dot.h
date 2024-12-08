#pragma once
#include <ostream>
#include "nodes.h"

void ToDot(TSScriptNode* node, std::ostream& out);

void RunDot(std::string_view dotPath, std::string_view dotFilePath);
