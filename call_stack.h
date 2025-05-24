#pragma once
#include "Lexem.h";
#include <stack>

class MemoryBlock {
public:
	bool new_var;
	size_t sz;
	Lexem title;
	size_t array_pointer;
	std::vector<Lexem> data;
	Lexem end;
	MemoryBlock() :title("", unknown_name, unknown_name, 0, "", ""), data(), end("", unknown_name, unknown_name, 0, "", ""), sz(0), new_var(0), array_pointer(0) {};
	MemoryBlock(const Lexem& t, const Lexem& d, const Lexem& e, size_t s_) : title(t), data({ d }), end(e),sz(s_),new_var(0),array_pointer(0) {};
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
	void print_all() {
		std::cout << "\033[31mCALL STACK TOP\033[0m\n";
		for (long long i = stack.size() - 1; i >-1; i--) {
			std::cout << i<<"]  " << stack[i].title.text << "  ------  " << stack[i].data[0] << "    params: (int8: " << static_cast<int>(stack[i].data[0].cs_int8) << ", int32: " << stack[i].data[0].cs_int32 << ", int64: " << stack[i].data[0].cs_int64 << ", float32: " << stack[i].data[0].cs_float32 << ", float64: " << stack[i].data[0].cs_float64 << ", link: " << stack[i].title.link << ") " << std::endl;
		}
		std::cout << "\033[31mCALL STACK BOTTOM\033[0m\n";
	}
};
