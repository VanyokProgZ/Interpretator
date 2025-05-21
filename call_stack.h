#pragma once
#include "Lexem.h";
#include <stack>

class MemoryBlock {
public:
	bool new_var;
	size_t sz;
	Lexem title;
	std::vector<Lexem> data;
	Lexem end;
	MemoryBlock() :title("",unknown_name,unknown_name,0,"",""), data(), end("", unknown_name, unknown_name, 0, "",""), sz(0), new_var(0) {};
	MemoryBlock(const Lexem& t, const Lexem& d, const Lexem& e, size_t s_) : title(t), data({ d }), end(e),sz(s_),new_var(0) {};
	MemoryBlock& operator=(const MemoryBlock& right) {
		title = right.title;
		data = right.data;
		end = right.end;
		new_var = right.new_var;
		return *this;
	}
	size_t size() {
		return sz;
	}
	
};

class CallStack {
public:
	std::vector<MemoryBlock> stack;
	void push(const MemoryBlock& l) { stack.push_back(l); }
	MemoryBlock top() { return stack.back(); }
	void pop() { stack.pop_back(); }
	size_t size()const { return stack.size(); }
};
