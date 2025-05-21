#include "processor.h"
#include "Lexem_Queue_asm.h"

Processor::Processor(const std::string& input_file)
{
	GLOBAL_SCAN = false;
	from_file_to_code_segment(input_file, code_segment);
}
void Processor::run() {

	std::string current_row;

	Lexem_Queue_Assembler queue_assembler(this);
	code_segment.insert_input_point();
	while (!code_segment.isEmpty()) {

		current_row = code_segment.get_next_row();
		cut_white_begin(current_row);
		past_spaces(current_row);
		if (code_segment.isEmpty()) GLOBAL_SCAN = true;
		auto lexems_row = lexemize_row(current_row, Class_names_list);

		for (size_t i = 0; i < lexems_row.size(); i++) {
			
			queue_assembler.push_back(lexems_row[i]);

		}

	}
	
}