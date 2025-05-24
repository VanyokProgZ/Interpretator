#pragma once
#include "processor.h"

class Ariphmetic_module;

class Lexem_Queue_Assembler {
	Processor* processor;
	long long arg_brackets_is_working;
	size_t cnt_brackets_eq;
	int state = 0;
	std::vector<std::string> args;
	std::vector<std::string >class_name_space = {};
	std::string signature;
	std::vector<long long> states;
	std::vector<long long> brackets;
	std::vector<size_t> while_addr;
	std::vector<std::vector<Lexem>> expressions;
public:
	size_t instruction_definer();

public:
	std::vector<Lexem> lexem_queue;

	Lexem_Queue_Assembler(Processor* p);

	void push_back(const Lexem& lexem);

};
