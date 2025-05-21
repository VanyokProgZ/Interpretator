#pragma once
#include <vector>
#include "Lexem.h"
#include "stack"
#include <map>

//enum OPERATION_PRIORITY {
//
//	round_bracket_open_priority = 0,
//	operator_plus_priority = 1,
//	operator_minus_priority = 1,
//	operator_multiply_priority = 2,
//	operator_division_priority = 2,
//	operator_ostatok_priority = 2,
//
//};

std::vector<Lexem> translate_to_rpn(const std::vector<Lexem>& infix);
