#pragma once
#include "Lexem.h"
#include <stack>

class MemoryBlock {
public:
	bool new_var;
	size_t sz;
	Lexem title;
	size_t array_pointer;
	std::vector<Lexem> data;
	Lexem end;
	MemoryBlock();
	MemoryBlock(const Lexem& t, const Lexem& d, const Lexem& e, size_t s_);
	MemoryBlock& operator=(const MemoryBlock& right);
	size_t size();
};

class CallStack {
public:
	std::vector<MemoryBlock> stack;
	void push(const MemoryBlock& l);
	MemoryBlock top();
	void pop();
	size_t size() const;
	void print_all();
};
