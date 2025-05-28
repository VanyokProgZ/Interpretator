#pragma once
#include <vector>
#include "Lexem.h"
#include "stack"
#include <map>

std::vector<Lexem> translate_to_rpn( std::vector<Lexem>& infix);
