#include "code_segment.h"

CodeSegment::CodeSegment(const std::vector<std::string>& v) {
	code_rows = v;
	i = 0;
}
std::string CodeSegment::get_next_row() {
	return code_rows[i++];
}
std::pair<std::string, size_t> CodeSegment::get_next_row(size_t ind) {
	i = ind;
	i++;
	return { code_rows[i-1],i-1};
}
void CodeSegment::print_all() {
	for (const auto& el : code_rows) {
		std::cout << el << '\n';
	}
}
size_t CodeSegment::get_index() { 
	if (!i) { throw j_error("try to get index from emty code segment"); }
	return i-1; 
}
void CodeSegment::insert_input_point() {
	code_rows.push_back(true_main);
}
bool CodeSegment::isEmpty() { return i >= code_rows.size(); }

void from_file_to_code_segment(const std::string& file_name, CodeSegment& segment) {
	auto v = grab_file(file_name);
	for (auto& el : v) {
		cut_white_begin(el); past_spaces(el);
	}
	segment = CodeSegment(v);
}

void CodeSegment::set_index(size_t ind) {
	i = ind;
}
