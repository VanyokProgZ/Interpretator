#include "ALU.h"

Ariphmetic_module::Ariphmetic_module(const std::vector<Lexem>& rpn, Processor* p) :rpn_form(rpn), processor(p){};

void Ariphmetic_module::Calculate(std::vector<Lexem>& lexem_queue, Lexem_Queue_Assembler& lexem_queue_asm) {

	Lexem end_of_block("", unknown_name, unknown_name, 0, "","");
	Lexem main_data("", unknown_name, unknown_name, 0, "","");
	Lexem begin_of_block("", unknown_name, unknown_name, 0, "","");
	MemoryBlock mem;
	std::vector<Lexem> data;
	std::stack<Lexem> obj;
	for (size_t i = 0; i < rpn_form.size(); i++) {

		if (rpn_form[i].type == _data_type_) continue;

		if (in(rpn_form[i].type, { double_literal,int_literal, var_name,new_var,char_symbol })) {

			switch (rpn_form[i].type)
			{
			case int_literal:
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem(rpn_form[i].text, int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem(rpn_form[i].text, _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = std::stoi(rpn_form[i].text);
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.push(mem);
				break;
			case double_literal:
				end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block","double");
				main_data = Lexem(rpn_form[i].text, double_literal, _double_, 0, "double","double");
				begin_of_block = Lexem(rpn_form[i].text, _timed_memory_block_begin, _double_, 1, "double","double");
				main_data.cs_float64 = std::stod(rpn_form[i].text);
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.push(mem);
				break;
			case char_symbol:
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
				main_data = Lexem(rpn_form[i].text, char_symbol, _char_, 0, "double", "char");
				begin_of_block = Lexem(rpn_form[i].text, _timed_memory_block_begin, _double_, 1, "char", "char");
				main_data.cs_int8 = rpn_form[i].text[0];
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.push(mem);
				break;
			case new_var:

				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", rpn_form[i].returned_type);
				data = std::vector<Lexem>(processor->Class_names_list.get_class_size(rpn_form[i].type_signature));
				begin_of_block = Lexem(rpn_form[i].text, _timed_memory_block_begin, rpn_form[i].data_type, processor->Class_names_list.get_class_size(rpn_form[i].type_signature), rpn_form[i].type_signature,rpn_form[i].returned_type);
				mem.title = begin_of_block;
				mem.data = data;
				mem.end = end_of_block;
				mem.sz = begin_of_block.arg_c;
				mem.new_var = true;
				processor->call_stack.push(mem);
				break;
			case var_name:

				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block",rpn_form[i].returned_type);

				bool found = 0;
				for (long long u = processor->call_stack.size() - 1; u > -1; u--) {
					if (processor->call_stack.stack[u].title.text == rpn_form[i].text) {
						mem = processor->call_stack.stack[u];
						found = 1;
						break;
					}
				}

				if (!found)
					throw j_error("Cant find variable " + rpn_form[i].text);
				mem.new_var = false;
				processor->call_stack.push(mem);
				break;
			}
		}
		else {

			size_t argc = rpn_form[i].arg_c;
			/*if (rpn_form[i].type == operator_copy) {
				rpn_form[i].type_signature = processor->call_stack.stack[processor->call_stack.size() - 2].title.type_signature + "&::" + rpn_form[i].type_signature;
			}*/

			/*if (rpn_form[i].type == operator_copy) {
				rpn_form[i].type_signature = processor->call_stack.stack[processor->call_stack.size() - 2].title.type_signature + "&::" + rpn_form[i].type_signature + "::(::" + processor->call_stack.top().title.type_signature + "::)";
			}*/

			//----------------------------------------------------
			//					 |_ _| \ | |_   _|
			//					  | ||  \| | | |  
			//					  | || |\  | | |  
			//					 |___|_| \_| |_|  
			//----------------------------------------------------
							//int +
			if (rpn_form[i].type_signature == "int::int::operator+::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 + processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator+::(::char::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 + processor->call_stack.stack.back().data[0].cs_int8;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator+::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 + processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator+::(::double::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 + processor->call_stack.stack.back().data[0].cs_float64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator+::(::float::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 + processor->call_stack.stack.back().data[0].cs_float32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			//int *
			else if (rpn_form[i].type_signature == "int::int::operator*::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 * processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator*::(::char::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 * processor->call_stack.stack.back().data[0].cs_int8;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator*::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 * processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator*::(::double::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 * processor->call_stack.stack.back().data[0].cs_float64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator*::(::float::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 * processor->call_stack.stack.back().data[0].cs_float32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			//int -
			else if (rpn_form[i].type_signature == "int::int::operator-::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 - processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator-::(::char::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 - processor->call_stack.stack.back().data[0].cs_int8;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator-::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 - processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator-::(::double::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 - processor->call_stack.stack.back().data[0].cs_float64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator-::(::float::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 - processor->call_stack.stack.back().data[0].cs_float32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			//int /
			else if (rpn_form[i].type_signature == "int::int::operator/::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 / processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator/::(::char::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 / processor->call_stack.stack.back().data[0].cs_int8;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator/::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 / processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator/::(::double::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 / processor->call_stack.stack.back().data[0].cs_float64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator/::(::float::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 / processor->call_stack.stack.back().data[0].cs_float32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			//int &
			else if (rpn_form[i].type_signature == "int::int::operator&::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 & processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator&::(::char::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 & processor->call_stack.stack.back().data[0].cs_int8;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator&::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 & processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator&::(::double::)") {
				throw  j_error("Nelzya & between int and double");
			}
			else if (rpn_form[i].type_signature == "int::int::operator&::(::float::)") {
				throw  j_error("Nelzya & between int and float");
			}
			//int |
			else if (rpn_form[i].type_signature == "int::int::operator|::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 | processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator|::(::char::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 | processor->call_stack.stack.back().data[0].cs_int8;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator|::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 | processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator|::(::double::)") {
				throw  j_error("Nelzya | between int and double");
			}
			else if (rpn_form[i].type_signature == "int::int::operator|::(::float::)") {
				throw  j_error("Nelzya | between int and float");
			}
			//int ^
			else if (rpn_form[i].type_signature == "int::int::operator^::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 ^ processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator^::(::char::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 ^ processor->call_stack.stack.back().data[0].cs_int8;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator^::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int32 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 ^ processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator^::(::double::)") {
				throw  j_error("Nelzya ^ between int and double");
			}
			else if (rpn_form[i].type_signature == "int::int::operator^::(::float::)") {
				throw  j_error("Nelzya ^ between int and float");
			}
			//int <
			else if (rpn_form[i].type_signature == "bool::int::operator<::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 < processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator<::(::char::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 < processor->call_stack.stack.back().data[0].cs_int8;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator<::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 < processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator<::(::double::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 < processor->call_stack.stack.back().data[0].cs_float64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator<::(::float::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 < processor->call_stack.stack.back().data[0].cs_float32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			//int <=
			else if (rpn_form[i].type_signature == "bool::int::operator<=::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 <= processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator<=::(::char::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 <= processor->call_stack.stack.back().data[0].cs_int8;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator<=::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 <= processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator<=::(::double::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 <= processor->call_stack.stack.back().data[0].cs_float64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator<=::(::float::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 <= processor->call_stack.stack.back().data[0].cs_float32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			//int >
			else if (rpn_form[i].type_signature == "bool::int::operator>::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 > processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator>::(::char::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 > processor->call_stack.stack.back().data[0].cs_int8;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator>::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 > processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator>::(::double::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 > processor->call_stack.stack.back().data[0].cs_float64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator>::(::float::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 > processor->call_stack.stack.back().data[0].cs_float32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			//int >=
			else if (rpn_form[i].type_signature == "bool::int::operator>=::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 >= processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator>=::(::char::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 >= processor->call_stack.stack.back().data[0].cs_int8;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator>=::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 >= processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator>=::(::double::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 >= processor->call_stack.stack.back().data[0].cs_float64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator>=::(::float::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 >= processor->call_stack.stack.back().data[0].cs_float32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			//int ==
			else if (rpn_form[i].type_signature == "bool::int::operator==::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 == processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator==::(::char::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 == processor->call_stack.stack.back().data[0].cs_int8;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator==::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 == processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator==::(::double::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 == processor->call_stack.stack.back().data[0].cs_float64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator==::(::float::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 == processor->call_stack.stack.back().data[0].cs_float32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			//int !=
			else if (rpn_form[i].type_signature == "bool::int::operator!=::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 != processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator!=::(::char::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 != processor->call_stack.stack.back().data[0].cs_int8;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator!=::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 != processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator!=::(::double::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 != processor->call_stack.stack.back().data[0].cs_float64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator!=::(::float::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 != processor->call_stack.stack.back().data[0].cs_float32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			//int &&
			else if (rpn_form[i].type_signature == "bool::int::operator&&::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 && processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator&&::(::char::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 && processor->call_stack.stack.back().data[0].cs_int8;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator&&::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 && processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator&&::(::double::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 && processor->call_stack.stack.back().data[0].cs_float64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator&&::(::float::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 && processor->call_stack.stack.back().data[0].cs_float32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			//int ||
			else if (rpn_form[i].type_signature == "bool::int::operator||::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 || processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator||::(::char::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 || processor->call_stack.stack.back().data[0].cs_int8;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator||::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 || processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator||::(::double::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 || processor->call_stack.stack.back().data[0].cs_float64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "bool::int::operator||::(::float::)") {
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 || processor->call_stack.stack.back().data[0].cs_float32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			//int !
			else if (rpn_form[i].type_signature == "bool::operator!::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block","bool");
				main_data = Lexem("timed obj", int_literal, _char_, 0, "bool","bool");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool","bool");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = !processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			//int %
			else if (rpn_form[i].type_signature == "int::int::operator%::(::int::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 % processor->call_stack.stack.back().data[0].cs_int32;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator%::(::long_long::)")
			{
				mem.data.clear();
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem("timed obj", int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32 % processor->call_stack.stack.back().data[0].cs_int64;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.pop();
				processor->call_stack.pop();
				processor->call_stack.push(mem);
			}
			else if (rpn_form[i].type_signature == "int::int::operator%::(::double::)") {
				throw j_error("ostatok int na double nelzya!");
			}
			else if (rpn_form[i].type_signature == "int::int::operator%::(::float::)") {
				throw j_error("ostatok int na float nelzya!");
			}
			//ostream int
			else if (rpn_form[i].type_signature == "ostream&::operator<<::(::int::)") {
				std::cout << processor->call_stack.top().data[0].cs_int32;
				processor->call_stack.pop();
			}
			else if (rpn_form[i].type_signature == "ostream&::operator<<::(::char::)") {
				std::cout << processor->call_stack.top().data[0].cs_int8;
				processor->call_stack.pop();
			}
			//istream int
			else if (rpn_form[i].type_signature == "ostream&::operator>>::(::int::)") {
				long long index = 0;
				for (long long c = processor->call_stack.size() - 2; c > -1; c--) {
					if (processor->call_stack.stack[c].title.text == processor->call_stack.top().title.text) {
						index = c;
						break;
					}
				}
				std::cin >> processor->call_stack.stack[index].data[0].cs_int32;
				processor->call_stack.pop();
			}
			//int copy operator
			else if (rpn_form[i].type_signature == "int&::int::operator=::(::int::)") {
				std::swap(processor->call_stack.stack[processor->call_stack.size() - 1], processor->call_stack.stack[processor->call_stack.size() - 2]);
				long long variable_addr = variable_addr = processor->call_stack.size() - 1;
				long long temp_variable_addr = -1;
				auto obj = processor->call_stack.top();

				for (long long stack_ind = processor->call_stack.size() - 1; stack_ind > -1; stack_ind--) {
					if (processor->call_stack.stack[stack_ind].title.text == obj.title.text) {
						if (processor->call_stack.stack[stack_ind].new_var == false && temp_variable_addr == -1) {
							temp_variable_addr = stack_ind;
							//processor->call_stack.stack.erase(processor->call_stack.stack.begin() + stack_ind);
						}
						else if (processor->call_stack.stack[stack_ind].new_var == true) {
							variable_addr = stack_ind;
							break;
						}
					}
				}

				if (temp_variable_addr == -1) temp_variable_addr = variable_addr;

				processor->call_stack.stack[temp_variable_addr].data = processor->call_stack.stack[processor->call_stack.size() - 2].data;
				std::swap(processor->call_stack.stack[temp_variable_addr].data, processor->call_stack.stack[variable_addr].data);

				if (!processor->call_stack.top().new_var && !processor->call_stack.stack[processor->call_stack.size() - 2].new_var) {
					processor->call_stack.pop();
					processor->call_stack.pop();
				}
				else if (processor->call_stack.stack[processor->call_stack.size() - 2].new_var) {
					processor->call_stack.pop();
				}
				else if (processor->call_stack.stack[processor->call_stack.size() - 1].new_var) {
					std::swap(processor->call_stack.stack[processor->call_stack.size() - 1], processor->call_stack.stack[processor->call_stack.size() - 2]);
					processor->call_stack.pop();
				}
			}
			else if (rpn_form[i].type_signature == "int&::int::operator=::(::char::)") {
				std::swap(processor->call_stack.stack[processor->call_stack.size() - 1], processor->call_stack.stack[processor->call_stack.size() - 2]);
				long long variable_addr = variable_addr = processor->call_stack.size() - 1;
				long long temp_variable_addr = -1;
				auto obj = processor->call_stack.top();

				for (long long stack_ind = processor->call_stack.size() - 1; stack_ind > -1; stack_ind--) {
					if (processor->call_stack.stack[stack_ind].title.text == obj.title.text) {
						if (processor->call_stack.stack[stack_ind].new_var == false && temp_variable_addr == -1) {
							temp_variable_addr = stack_ind;
							//processor->call_stack.stack.erase(processor->call_stack.stack.begin() + stack_ind);
						}
						else if (processor->call_stack.stack[stack_ind].new_var == true) {
							variable_addr = stack_ind;
							break;
						}
					}
				}

				if (temp_variable_addr == -1) temp_variable_addr = variable_addr;
				processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int32 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8;
				processor->call_stack.stack[temp_variable_addr].data = processor->call_stack.stack[processor->call_stack.size() - 2].data;
				std::swap(processor->call_stack.stack[temp_variable_addr].data, processor->call_stack.stack[variable_addr].data);

				if (!processor->call_stack.top().new_var && !processor->call_stack.stack[processor->call_stack.size() - 2].new_var) {
					processor->call_stack.pop();
					processor->call_stack.pop();
				}
				else if (processor->call_stack.stack[processor->call_stack.size() - 2].new_var) {
					processor->call_stack.pop();
				}
				else if (processor->call_stack.stack[processor->call_stack.size() - 1].new_var) {
					std::swap(processor->call_stack.stack[processor->call_stack.size() - 1], processor->call_stack.stack[processor->call_stack.size() - 2]);
					processor->call_stack.pop();
				}
			}
			else if (rpn_form[i].type_signature == "int&::int::operator=::(::long_long::)") {
				std::swap(processor->call_stack.stack[processor->call_stack.size() - 1], processor->call_stack.stack[processor->call_stack.size() - 2]);
				long long variable_addr = variable_addr = processor->call_stack.size() - 1;
				long long temp_variable_addr = -1;
				auto obj = processor->call_stack.top();

				for (long long stack_ind = processor->call_stack.size() - 1; stack_ind > -1; stack_ind--) {
					if (processor->call_stack.stack[stack_ind].title.text == obj.title.text) {
						if (processor->call_stack.stack[stack_ind].new_var == false && temp_variable_addr == -1) {
							temp_variable_addr = stack_ind;
							//processor->call_stack.stack.erase(processor->call_stack.stack.begin() + stack_ind);
						}
						else if (processor->call_stack.stack[stack_ind].new_var == true) {
							variable_addr = stack_ind;
							break;
						}
					}
				}

				if (temp_variable_addr == -1) temp_variable_addr = variable_addr;
				processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int32 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int64;
				processor->call_stack.stack[temp_variable_addr].data = processor->call_stack.stack[processor->call_stack.size() - 2].data;
				std::swap(processor->call_stack.stack[temp_variable_addr].data, processor->call_stack.stack[variable_addr].data);

				if (!processor->call_stack.top().new_var && !processor->call_stack.stack[processor->call_stack.size() - 2].new_var) {
					processor->call_stack.pop();
					processor->call_stack.pop();
				}
				else if (processor->call_stack.stack[processor->call_stack.size() - 2].new_var) {
					processor->call_stack.pop();
				}
				else if (processor->call_stack.stack[processor->call_stack.size() - 1].new_var) {
					std::swap(processor->call_stack.stack[processor->call_stack.size() - 1], processor->call_stack.stack[processor->call_stack.size() - 2]);
					processor->call_stack.pop();
				}
			}
			else if (rpn_form[i].type_signature == "int&::int::operator=::(::float::)") {
				std::swap(processor->call_stack.stack[processor->call_stack.size() - 1], processor->call_stack.stack[processor->call_stack.size() - 2]);
				long long variable_addr = variable_addr = processor->call_stack.size() - 1;
				long long temp_variable_addr = -1;
				auto obj = processor->call_stack.top();

				for (long long stack_ind = processor->call_stack.size() - 1; stack_ind > -1; stack_ind--) {
					if (processor->call_stack.stack[stack_ind].title.text == obj.title.text) {
						if (processor->call_stack.stack[stack_ind].new_var == false && temp_variable_addr == -1) {
							temp_variable_addr = stack_ind;
							//processor->call_stack.stack.erase(processor->call_stack.stack.begin() + stack_ind);
						}
						else if (processor->call_stack.stack[stack_ind].new_var == true) {
							variable_addr = stack_ind;
							break;
						}
					}
				}

				if (temp_variable_addr == -1) temp_variable_addr = variable_addr;
				processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int32 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float32;
				processor->call_stack.stack[temp_variable_addr].data = processor->call_stack.stack[processor->call_stack.size() - 2].data;
				std::swap(processor->call_stack.stack[temp_variable_addr].data, processor->call_stack.stack[variable_addr].data);

				if (!processor->call_stack.top().new_var && !processor->call_stack.stack[processor->call_stack.size() - 2].new_var) {
					processor->call_stack.pop();
					processor->call_stack.pop();
				}
				else if (processor->call_stack.stack[processor->call_stack.size() - 2].new_var) {
					processor->call_stack.pop();
				}
				else if (processor->call_stack.stack[processor->call_stack.size() - 1].new_var) {
					std::swap(processor->call_stack.stack[processor->call_stack.size() - 1], processor->call_stack.stack[processor->call_stack.size() - 2]);
					processor->call_stack.pop();
				}
			}
			else if (rpn_form[i].type_signature == "int&::int::operator=::(::double::)") {
				std::swap(processor->call_stack.stack[processor->call_stack.size() - 1], processor->call_stack.stack[processor->call_stack.size() - 2]);
				long long variable_addr = variable_addr = processor->call_stack.size() - 1;
				long long temp_variable_addr = -1;
				auto obj = processor->call_stack.top();

				for (long long stack_ind = processor->call_stack.size() - 1; stack_ind > -1; stack_ind--) {
					if (processor->call_stack.stack[stack_ind].title.text == obj.title.text) {
						if (processor->call_stack.stack[stack_ind].new_var == false && temp_variable_addr == -1) {
							temp_variable_addr = stack_ind;
							//processor->call_stack.stack.erase(processor->call_stack.stack.begin() + stack_ind);
						}
						else if (processor->call_stack.stack[stack_ind].new_var == true) {
							variable_addr = stack_ind;
							break;
						}
					}
				}

				if (temp_variable_addr == -1) temp_variable_addr = variable_addr;
				processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int32 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float64;
				processor->call_stack.stack[temp_variable_addr].data = processor->call_stack.stack[processor->call_stack.size() - 2].data;
				std::swap(processor->call_stack.stack[temp_variable_addr].data, processor->call_stack.stack[variable_addr].data);

				if (!processor->call_stack.top().new_var && !processor->call_stack.stack[processor->call_stack.size() - 2].new_var) {
					processor->call_stack.pop();
					processor->call_stack.pop();
				}
				else if (processor->call_stack.stack[processor->call_stack.size() - 2].new_var) {
					processor->call_stack.pop();
				}
				else if (processor->call_stack.stack[processor->call_stack.size() - 1].new_var) {
					std::swap(processor->call_stack.stack[processor->call_stack.size() - 1], processor->call_stack.stack[processor->call_stack.size() - 2]);
					processor->call_stack.pop();
				}
			}
			//--------------------------------------------------
			//					| ___| |   / _ \  / \  |_   _|
			//					| |_ | |  | | | |/ _ \   | |
			//					|  _|| |__| |_| / ___ \  | |
			//					|_|  |_____\__ /__/ \__\_|_|
			// -------------------------------------------------

			//--------------------------------------------------
			//					/ ___| | | |   / \   |  _ \
			//					| |  | |_| |  / _ \  | |_) |
			//					| |__|  _  | / ___ \ |  _ <
			//					\____|_| |_|/__/ \__\| | \_\
			//--------------------------------------------------


							//return
			else if (rpn_form[i].type == _return_) {

				mem = processor->call_stack.top();
				while (processor->call_stack.stack[processor->call_stack.size() - 2].data[0].type != _ret_from_func_mark) {
					std::swap(processor->call_stack.stack[processor->call_stack.size() - 1], processor->call_stack.stack[processor->call_stack.size() - 2]);
					processor->call_stack.pop();
				}
				std::swap(processor->call_stack.stack[processor->call_stack.size() - 1], processor->call_stack.stack[processor->call_stack.size() - 2]);
				size_t ret_addr = processor->call_stack.top().data[0].cs_int64;
				size_t arg_cnt = processor->call_stack.top().data[0].cs_int32;
				processor->call_stack.pop();
				for (size_t c = 0; c < arg_cnt; c++) {
					std::swap(processor->call_stack.stack[processor->call_stack.size() - 1], processor->call_stack.stack[processor->call_stack.size() - 2]);
					processor->call_stack.pop();
				}
				processor->call_stack.stack[processor->call_stack.size() - 1].title.text = "timed obj";
				processor->code_segment.set_index(ret_addr);

				//пытаемся продолжить выполнятся в той же строчке
				lexem_queue = processor->Prev_Expr.back();
				processor->Prev_Expr.pop_back();
				lexem_queue_asm.instruction_definer();

			}
			//if
			else if (rpn_form[i].type == _if_) {
				processor->if_signals.push_back((bool)processor->call_stack.top().data[0].cs_int8);
				processor->call_stack.pop();
			}
			//while
			else if (rpn_form[i].type == _while_) {
				processor->if_signals.push_back((bool)processor->call_stack.top().data[0].cs_int8);
				processor->call_stack.pop();
			}
			//call
			else {

				size_t func_addr = processor->Function_names_list.GetPosFunc(rpn_form[i].type_signature);
				size_t this_addr = processor->code_segment.get_index() + 1;
				for (size_t ind_swp = 0; ind_swp < rpn_form[i].arg_c; ind_swp++) {
					processor->call_stack.stack[processor->call_stack.size() - rpn_form[i].arg_c + ind_swp].title.text = processor->Function_names_list.get_Args(rpn_form[i].type_signature)[ind_swp];
					processor->call_stack.stack[processor->call_stack.size() - rpn_form[i].arg_c + ind_swp].new_var = true;
				}
				//add ret addr
				end_of_block = Lexem("end block", _timed_memory_block_end, _void_, 1, "end block","void");
				main_data = Lexem("ret mark", _ret_from_func_mark, _void_, 0, "ret","void");
				begin_of_block = Lexem("ret mark", _timed_memory_block_begin, _void_, 1, "ret","void");
				main_data.cs_int64 = this_addr;
				main_data.cs_int32 = rpn_form[i].arg_c;
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.push(mem);
				//------------

				processor->code_segment.set_index(func_addr);

				//Решаем задачу продолжения выражения после вызова
				std::vector<Lexem> this_expr;
				for (size_t j = i + 1; j < rpn_form.size(); j++) {
					this_expr.push_back(rpn_form[j]);
				}
				processor->Prev_Expr.push_back(this_expr);	//запихнули в текущее выполнение данное выражение

				return;
			}

		}

	}

};