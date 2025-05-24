#pragma once
#include <vector>
#include "Lexem.h"
#include <stack>
#include "processor.h"
#include "Lexem_Queue_asm.h"

class Ariphmetic_module {
	std::vector<std::string >class_name_space = { };
	std::vector<Lexem> rpn_form;
	Processor* processor;

public:
	Ariphmetic_module(const std::vector<Lexem>& rpn, Processor* p);

	void Calculate(std::vector<Lexem>& lexem_queue, Lexem_Queue_Assembler& lexem_queue_asm);

	size_t int_calc(Lexem& rpn_);
	size_t bool_calc(Lexem& rpn_);
	size_t char_calc(Lexem& rpn_);
	size_t float_calc(Lexem& rpn_);
	size_t double_calc(Lexem& rpn_);
};