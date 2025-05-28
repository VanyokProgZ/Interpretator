#pragma once
#include <string>
#include <vector>
#include "string_process.h"
#include "preprocess.h"

class CodeSegment {
	size_t i;
	std::vector<std::string> code_rows;
public:
	std::string true_main = "<int>main();";
	CodeSegment() = default;
	CodeSegment(const std::vector<std::string>&);
	std::string get_next_row();
	std::pair<std::string,size_t> get_next_row(size_t ind);
	void print_all();
	bool isEmpty();
	size_t get_index();
	void insert_input_point();
	void set_index(size_t ind);
	size_t size();
};

void from_file_to_code_segment(const std::string& file_name, CodeSegment& segment);