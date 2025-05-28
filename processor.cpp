#include "processor.h"
#include "Lexem_Queue_asm.h"



#ifdef _WIN32
#include <conio.h>
#define CLS "cls"
#else
#include <curses.h>
#define CLS "clear"
#endif

Processor::Processor(const std::string& input_file)
{
	call_stack.push(MemoryBlock(Lexem("NULL POINTER",NULL_POINER_CALL_STACK_BOTTOM,NULL_POINER_CALL_STACK_BOTTOM,0,"STACK BOTTOM","STACK BOTTOM"), Lexem("NULL POINTER", NULL_POINER_CALL_STACK_BOTTOM, NULL_POINER_CALL_STACK_BOTTOM, 0, "STACK BOTTOM", "STACK BOTTOM"), Lexem("NULL POINTER", NULL_POINER_CALL_STACK_BOTTOM, NULL_POINER_CALL_STACK_BOTTOM, 0, "STACK BOTTOM", "STACK BOTTOM"),0));
	GLOBAL_SECTOR_LAST = 0;
	GLOBAL_SCAN = false;
	from_file_to_code_segment(input_file, code_segment);
}
void Processor::run() {

	std::string current_row;
	Lexem_Queue_Assembler queue_assembler(this);
	code_segment.insert_input_point();
	while (!code_segment.isEmpty()) {

		if (__DEBUG__STATE__) {
			code_segment.print_all();
			std::cout << "\n\n-------------------------------------------------------\n1 - print call_stack\nsth else - next row\n\n";
#ifdef _WIN32
			char key = _getch();
#else
			char key = getch();
#endif
			if (key == '1') {
				call_stack.print_all();
				std::cout << "\n";
#ifdef _WIN32
				key = _getch();
#else
				key = getch();
#endif
			}

			system(CLS);
		}
		current_row = code_segment.get_next_row();
		if (current_row == code_segment.true_main) {
			GLOBAL_SCAN = true;
		}
		cut_white_begin(current_row);
		past_spaces(current_row);

		if (code_segment.isEmpty()) GLOBAL_SCAN = true;

		auto lexems_row = lexemize_row(current_row, Class_names_list);





		for (size_t i = 0; i < lexems_row.size(); i++) {
			queue_assembler.push_back(lexems_row[i]);
		}
	}
	
}