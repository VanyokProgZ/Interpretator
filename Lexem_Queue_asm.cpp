#include "Lexem_Queue_asm.h"
#include "ALU.h"

size_t Lexem_Queue_Assembler::instruction_definer() {
	auto rpn_form = translate_to_rpn(lexem_queue);
	Ariphmetic_module calculator(rpn_form, processor);
	calculator.Calculate(lexem_queue, *this);
	lexem_queue.clear();
	return 0;
}

void Lexem_Queue_Assembler::push_back(const Lexem& lexem) {
	if (lexem.type == _semicolon_ && (!arg_brackets_is_working || state==11)) {
		instruction_definer();
	}
	else {	//��� � ������� ������, � ����� ������� ���-�� ��� �������� ��� ������� (�� ����, 4 ���� �����������)
		for (long long iteration_index = 0; iteration_index < 1; iteration_index++)//������ ����, �.� � ��������� ������� ����� ������� ������� �� �����
		{
			//new function
			if (lexem.type == new_function && state == 0) {
				state = 1;//�������� ������������� ������ ���������
				processor->Function_names_list.NewFunc(lexem.type_signature, processor->code_segment.get_index());
				args.clear();
				lexem_queue.push_back(lexem);
				return;
			}
			else if (state == 1 && lexem.type == round_bracket_open) {
				state = 2;//���� ���������� � �������� ����������� ������ ����������
				arg_brackets_is_working = 1;
				return;
			}
			else if (state == 2 && (lexem.type == new_var || lexem.type == new_static_array)) {
				args.push_back(lexem.text); // ��������� ����� ����������
				lexem_queue.push_back(lexem);
				return;
			}
			else if (state == 2 && lexem.type == round_bracket_open) {
				arg_brackets_is_working++;	//����������� '����������' ��������� ������������������ (��������)
				return;
			}
			else if (state == 2 && lexem.type == round_bracket_close) {
				arg_brackets_is_working--;	//����������� '����������' ��������� ������������������ (��������)
				if (arg_brackets_is_working == 0) {
					processor->Function_names_list.set_Args(processor->Function_names_list.last_function_signature, args);	//������ � ������ ����� ���������� � ���������
					args.clear();
					state = 3;//�������� �������� ������ ������ ���� �������
				}
				return;
			}
			else if (state == 2 && lexem.type != _data_type_) {
				lexem_queue.push_back(lexem); //��� ����� ���� ��� ������ - ����� � ���-������ ��� � �� ��������
				return;
			}
			else if (state == 3 && lexem.type == fig_bracket_open) {
				state = 4; //���� ������ ������ ���� �������
				arg_brackets_is_working = 1; //����� ������� ���������� ��������� ������������������ ����� ��������� ���������� �����
				return;
			}
			else if (state == 4) {
				processor->Function_names_list.NewFunc(processor->Function_names_list.last_function_signature, processor->code_segment.get_index());
				//���������� ���������� ����� ������ ������ ���� �������
				state = 5;//���� �������� }
				if (lexem.type == fig_bracket_close) {
					arg_brackets_is_working--;
					throw j_error("String num " + std::to_string(processor->code_segment.get_index()) + ". For empty function please write return <datatype> in it");
				}
				else if (lexem.type == fig_bracket_open) arg_brackets_is_working++;
				return;
			}
			else if (state == 5 && lexem.type == fig_bracket_open) {
				arg_brackets_is_working++;
				return;
			}
			else if (state == 5 && lexem.type == fig_bracket_close) {
				arg_brackets_is_working--;
				lexem_queue.clear();
				if (!arg_brackets_is_working) state = 0; //���������� � ��������� ����������
				return;
			}
			//-------------------------------

			//if-----------------------------
			
			else if (state == 11 && lexem.type == _while_) {//������ ��� while, ���� ��� �� ���� if
				if (states.back() == 4 || states.back() == 7 || states.back()==34 || states.back() == 35) {
					if (states.back() == 34) {
						while_addr.push_back(processor->code_segment.get_index());//�������� ����� ���� ���� ��� �������� while
						if (processor->if_signals.back()) {
							lexem_queue.push_back(lexem);
							states.push_back(31);//���� ����������� ������ ������ ����������
						}
						states[states.size() - 2] = 35;
					}
					else if (states.back() == 35) {
						if (processor->if_signals.back()) {
							lexem_queue.push_back(lexem);
							states.push_back(31);//���� ����������� ������ ������ ����������
						}
					}
					if (states.back() == 4 && processor->if_signals.back()) {
						lexem_queue.push_back(lexem);
						states.push_back(31);//���� ����������� ������ ������ ����������
					}
					else if (states.back() == 7 && !processor->if_signals.back()) {
						lexem_queue.push_back(lexem);
						states.push_back(31);//���� ����������� ������ ������ ����������
					}

					
				}
				return;
			}
			else if ((state == 0) && lexem.type == _if_) {
				state = 11;//������ ������������ - �������� ���� ��������� � ������ ��������� ��� ���� �����������
				states.push_back(1);//������� ������������� ������ (������ ����������)
				lexem_queue.push_back(lexem);
				return;
			}
			else if ((state == 11) && lexem.type == _if_) {
				if (states.back() == 4 || states.back() == 7 || states.back() == 34 || states.back() == 35) {
					if (states.back() == 34) {
						while_addr.push_back(processor->code_segment.get_index());//�������� ����� ���� ���� ��� �������� while
						if (processor->if_signals.back()) {
							lexem_queue.push_back(lexem);
							states.push_back(1);//���� ����������� ������ ������ ����������
						}
						states[states.size() - 2] = 35;
					}
					else if (states.back() == 35) {
						if (processor->if_signals.back()) {
							lexem_queue.push_back(lexem);
							states.push_back(1);//���� ����������� ������ ������ ����������
						}
					}
					if (states.back() == 4 && processor->if_signals.back()) {
						lexem_queue.push_back(lexem);
						states.push_back(1);//���� ����������� ������ ������ ����������
					}
					else if (states.back() == 7 && !processor->if_signals.back()) {
						lexem_queue.push_back(lexem);
						states.push_back(1);//���� ����������� ������ ������ ����������
					}
					
				}			
				return;
			}
			else if (state == 11 && states.back() == 1 && lexem.type == round_bracket_open) {
				lexem_queue.push_back(lexem);
				brackets.push_back(1);//������ � ���������� ����� ������� �� ���������� ��������� �������������������
				states[states.size() - 1] = 2; //���� ����� ����������
				return;
			}
			else if (state == 11 && states.back() == 2 && lexem.type == round_bracket_open) {
				brackets[brackets.size() - 1]++;
				lexem_queue.push_back(lexem);
				return;
			}
			else if (state == 11 && states.back() == 2 && lexem.type == round_bracket_close) {
				lexem_queue.push_back(lexem);
				brackets[brackets.size() - 1]--;
				if (brackets[brackets.size() - 1] == 0) {
					states[states.size() - 1] = 3;//���� �������� ������ ������ ���� if
					brackets.pop_back();//������ ������������ ������
					//----------------------�������� ������ ������������� IF----------------
					instruction_definer();
					//----------------------------------------------------------------------
				}
				return;
			}
			else if (state == 11 && states.back() == 2) {
				lexem_queue.push_back(lexem);
				return;
			}
			else if (state == 11 && states.back() == 3 && lexem.type == fig_bracket_open) {
				brackets.push_back(1);//����� ������ ������� ���������� ��������� ������������������ ��� ���� if
				states[states.size() - 1] = 4;//� �������� ����������� ������ ���� if
				return;
			}
			else if (state == 11 && states.back() == 4 && lexem.type == fig_bracket_open) {
				brackets[brackets.size() - 1]++;
				return;
			}
			else if (state == 11 && states.back() == 4 && lexem.type == fig_bracket_close) {
				brackets[brackets.size() - 1]--;
				if (brackets.back() == 0) {
					brackets.pop_back();//������� ������������ ������
					states[states.size() - 1] = 5;//���� else
				}
				return;
			}
			else if (state == 11 && states.back() == 4 && lexem.type != _data_type_) {
				//��� ��������� ��������� ���������� ������� � ������� ��������� ��� ���
				if (processor->if_signals.back()) {
					/*iteration_index--;
					continue;*/
					lexem_queue.push_back(lexem);
				}
				return;
			}
			else if (state == 11 && states.back() == 5 && lexem.type == _else_) {
				states[states.size() - 1] = 6;//���� ����������� ������ ������ ���� else
				return;
			}
			else if (state == 11 && states.back() == 5 && lexem.type != _else_) {
				//��������� � ��������� ���������� ��� ������� �������
				states.pop_back();//��������� ���������
				if (states.size() == 0) state = 0; //���� ��� ���� ������ �������, �� ��������� � ��������� ����������
				processor->if_signals.pop_back();//��������� ������
				//��� ���� ������, �� ����� ����� ������, ��� ����� ��������� ���� �� ���� �������� � ���� ���...
				iteration_index--;
				continue;
			}
			else if (state == 11 && states.back() == 6 && lexem.type == fig_bracket_open) {
				states[states.size() - 1] = 7;//���� ����������� ������ ���� else
				brackets.push_back(1);//������ �� ��������� �������������������
				return;
			}
			else if (state == 11 && states.back() == 7 && lexem.type == fig_bracket_open) {
				brackets[brackets.size() - 1]++;
				return;
			}
			else if (state == 11 && states.back() == 7 && lexem.type == fig_bracket_close) {
				brackets[brackets.size() - 1]--;
				if (brackets.back() == 0) {
					brackets.pop_back();//��������� ������
					states.pop_back();//��������� ���������
					if (states.size() == 0) state = 0; //���� ������ ������� �� �������� � ��������� ����������
					processor->if_signals.pop_back();//��������� ������
				}
				return;
			}
			else if (state == 11 && states.back() == 7 && lexem.type != _data_type_) {
				//��� ��������� ��������� ���������� ������� � ������� ��� !���������������! - ��������� ��� ���
				if (!processor->if_signals.back()) {
					/*iteration_index--;
					continue;*/
					lexem_queue.push_back(lexem);
				}
				return;
			}
			//-------------------------------

			//while-------------------------
			if (state == 0 && lexem.type == _while_) {
				states.push_back(31);//���� ������������� ������ ������ ����������
				lexem_queue.push_back(lexem);
				state = 11;
				return;
			}
			else if (state == 11 && lexem.type == round_bracket_open && states.back() == 31) {
				states[states.size() - 1] = 32;//������ ��������� ��������� - ���� �� ����� ������� ���������� ��������� ������������������
				lexem_queue.push_back(lexem);
				brackets.push_back(1);
				return;
			}
			else if (state == 11 && states.back() == 32 && lexem.type == round_bracket_open) {
				brackets[brackets.size() - 1]++;
				lexem_queue.push_back(lexem);
				return;
			}
			else if (state == 11 && states.back() == 32 && lexem.type == round_bracket_close) {
				brackets[brackets.size() - 1]--;
				lexem_queue.push_back(lexem);
				if (brackets.back() == 0) {
					brackets.pop_back();//�������� ������
					states[states.size() - 1] = 33;//���� �������� ������ ������ ���� while
					expressions.push_back(lexem_queue);//�������� ��������� �� ������ while ���� ������ ��� �� ������������ ��� � ��������� � ����� ���� � ������ ����� ������������
					instruction_definer();//�������� ������
				}
				return;
			}
			else if (state == 11 && states.back() == 32) {
				lexem_queue.push_back(lexem);
				return;
			}
			else if (state == 11 && states.back() == 33 && lexem.type == fig_bracket_open) {
				brackets.push_back(1);//����� ������ �� ���������� ��������� �������������������
				states[states.size() - 1] = 34;//���� ������ ���������� � ���� while
				return;
			}
			else if (state == 11 && states.back() == 34) {
				while_addr.push_back(processor->code_segment.get_index());//�������� ����� ���� ���� ��� �������� while
				states[states.size() - 1] = 35;//���� ����� ���� (��������� ���������� ��������� ������������������)
				
				//�� �������� ��� ��������� ������������������
				if (lexem.type == fig_bracket_open) {
					brackets[brackets.size() - 1]++;
					return;
				}
				else if (lexem.type == fig_bracket_close) {
					brackets[brackets.size() - 1]--;
					if (brackets[brackets.size() - 1] == 0) {
						//���� � ��� while(..) {}, �� ��� ������ ��������� ������� ��� ������� ����
						brackets.pop_back();
						states.pop_back();
						expressions.pop_back();
						processor->if_signals.pop_back();
						if (processor->if_signals.size() == 0) {
							state = 0;//�������� � ��������� ����������
						}
					}
					return;
				}
				if(processor->if_signals.back())
				lexem_queue.push_back(lexem);
				return;
			}
			else if (state == 11 && states.back() == 35 && lexem.type == fig_bracket_open) {
				brackets[brackets.size() - 1]++;
				return;
			}
			else if (state == 11 && states.back() == 35 && lexem.type == fig_bracket_close) {
				brackets[brackets.size() - 1]--;
				if (brackets[brackets.size() - 1] == 0) {
					brackets.pop_back();
					//��������� � ��������� �������
					lexem_queue.clear();
					processor->if_signals.pop_back();
					lexem_queue = expressions.back();
					instruction_definer();//�������� ������
					if (processor->if_signals.back()) {
						processor->code_segment.set_index(while_addr.back());
						brackets.push_back(1);//���������� ��� ������ � ������ ���� � ������� {
						states[states.size() - 1] = 34;
						while_addr.pop_back();//� 34 state ����������� ����� ������ ����������, ������� ������ ���.
					}
					else {
						states.pop_back();
						expressions.pop_back();
						while_addr.pop_back();
						processor->if_signals.pop_back();
						if (states.size() == 0) {
							state = 0;//� ��������� ����������
						}
					}
				}
				return;
			}
			else if (state == 11 && states.back() == 35) {
				if (processor->if_signals.back())
				lexem_queue.push_back(lexem);
				return;
			}
			//------------------------------

			//��������� ����������
			if (state == 0) {
				lexem_queue.push_back(lexem);
				return;
			}
		}
	}
}

Lexem_Queue_Assembler::Lexem_Queue_Assembler(Processor* p) :processor(p), arg_brackets_is_working(0),signature(""),cnt_brackets_eq(0) {};