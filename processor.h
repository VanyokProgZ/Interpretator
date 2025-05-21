#pragma once
#include "code_segment.h"
#include "string_process.h"
#include "handlers.h"
#include <queue>
#include "rpn.h"
#include "call_stack.h"

class Lexem_Queue_Assembler;

class Processor {
	
public:
	std::vector<std::vector<Lexem>> Prev_Expr;

	bool GLOBAL_SCAN;
	std::vector<bool> if_signals;

	CodeSegment code_segment;
	CallStack call_stack;

	handleClassNames Class_names_list;
	handleFuncNames Function_names_list;

	Processor(const std::string& input_file);
	void run();

};


