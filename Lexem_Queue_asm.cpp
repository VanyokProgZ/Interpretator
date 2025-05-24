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
	else {	//тут я сначала мудрил, а потом выдумал что-то что работает как автомат (ей богу, 4 раза переписывал)
		for (long long iteration_index = 0; iteration_index < 1; iteration_index++)//сделал цикл, т.к в некоторых случаях нужно пустить лексему по кругу
		{
			//new function
			if (lexem.type == new_function && state == 0) {
				state = 1;//ожидание открывающейся скобки аргумента
				processor->Function_names_list.NewFunc(lexem.type_signature, processor->code_segment.get_index());
				args.clear();
				lexem_queue.push_back(lexem);
				return;
			}
			else if (state == 1 && lexem.type == round_bracket_open) {
				state = 2;//сбор аргументов и ожидание закрывающей скобки аргументов
				arg_brackets_is_working = 1;
				return;
			}
			else if (state == 2 && (lexem.type == new_var || lexem.type == new_static_array)) {
				args.push_back(lexem.text); // всасываем имена аргументов
				lexem_queue.push_back(lexem);
				return;
			}
			else if (state == 2 && lexem.type == round_bracket_open) {
				arg_brackets_is_working++;	//отслеживаем 'правильную' скобочную последовательность (открытие)
				return;
			}
			else if (state == 2 && lexem.type == round_bracket_close) {
				arg_brackets_is_working--;	//отслеживаем 'правильную' скобочную последовательность (закрытие)
				if (arg_brackets_is_working == 0) {
					processor->Function_names_list.set_Args(processor->Function_names_list.last_function_signature, args);	//кладем в хэнлер имена переменных в аргументе
					args.clear();
					state = 3;//ожидание фигурной скобки начала тела функции
				}
				return;
			}
			else if (state == 2 && lexem.type != _data_type_) {
				lexem_queue.push_back(lexem); //тут может быть что угодно - числа и что-нибудь что я не придумал
				return;
			}
			else if (state == 3 && lexem.type == fig_bracket_open) {
				state = 4; //ждем начала текста тела функции
				arg_brackets_is_working = 1; //опять смотрим правильную скобочную последовательность чтобы корректно определить конец
				return;
			}
			else if (state == 4) {
				processor->Function_names_list.NewFunc(processor->Function_names_list.last_function_signature, processor->code_segment.get_index());
				//установили корректный адрес начала текста тела функции
				state = 5;//ждем конечной }
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
				if (!arg_brackets_is_working) state = 0; //установили в свободное считывание
				return;
			}
			//-------------------------------

			//if-----------------------------
			
			else if (state == 11 && lexem.type == _while_) {//логика для while, чтоб его не сьел if
				if (states.back() == 4 || states.back() == 7 || states.back()==34 || states.back() == 35) {
					if (states.back() == 34) {
						while_addr.push_back(processor->code_segment.get_index());//получаем адрес куда если что зациклит while
						if (processor->if_signals.back()) {
							lexem_queue.push_back(lexem);
							states.push_back(31);//ждем открывающей скобки начала аргументов
						}
						states[states.size() - 2] = 35;
					}
					else if (states.back() == 35) {
						if (processor->if_signals.back()) {
							lexem_queue.push_back(lexem);
							states.push_back(31);//ждем открывающей скобки начала аргументов
						}
					}
					if (states.back() == 4 && processor->if_signals.back()) {
						lexem_queue.push_back(lexem);
						states.push_back(31);//ждем открывающей скобки начала аргументов
					}
					else if (states.back() == 7 && !processor->if_signals.back()) {
						lexem_queue.push_back(lexem);
						states.push_back(31);//ждем открывающей скобки начала аргументов
					}

					
				}
				return;
			}
			else if ((state == 0) && lexem.type == _if_) {
				state = 11;//Первое оборачивание - помещаем наше состояние в массив состояний для всех обертываний
				states.push_back(1);//ожидаем открывающейся скобки (начало аргументов)
				lexem_queue.push_back(lexem);
				return;
			}
			else if ((state == 11) && lexem.type == _if_) {
				if (states.back() == 4 || states.back() == 7 || states.back() == 34 || states.back() == 35) {
					if (states.back() == 34) {
						while_addr.push_back(processor->code_segment.get_index());//получаем адрес куда если что зациклит while
						if (processor->if_signals.back()) {
							lexem_queue.push_back(lexem);
							states.push_back(1);//ждем открывающей скобки начала аргументов
						}
						states[states.size() - 2] = 35;
					}
					else if (states.back() == 35) {
						if (processor->if_signals.back()) {
							lexem_queue.push_back(lexem);
							states.push_back(1);//ждем открывающей скобки начала аргументов
						}
					}
					if (states.back() == 4 && processor->if_signals.back()) {
						lexem_queue.push_back(lexem);
						states.push_back(1);//ждем открывающей скобки начала аргументов
					}
					else if (states.back() == 7 && !processor->if_signals.back()) {
						lexem_queue.push_back(lexem);
						states.push_back(1);//ждем открывающей скобки начала аргументов
					}
					
				}			
				return;
			}
			else if (state == 11 && states.back() == 1 && lexem.type == round_bracket_open) {
				lexem_queue.push_back(lexem);
				brackets.push_back(1);//теперь в аргументах будем следить за правильной скобочной последовательностью
				states[states.size() - 1] = 2; //ждем конца аргументов
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
					states[states.size() - 1] = 3;//ждем фигурную скобку начала тела if
					brackets.pop_back();//убрали отработавшие скобки
					//----------------------ПОЛУЧАЕМ СИГНАЛ ОТРАБОТАВШЕГО IF----------------
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
				brackets.push_back(1);//опять вводим подсчет правильной скобочной последовательности для тела if
				states[states.size() - 1] = 4;//в ожидании закрывающей скобки тела if
				return;
			}
			else if (state == 11 && states.back() == 4 && lexem.type == fig_bracket_open) {
				brackets[brackets.size() - 1]++;
				return;
			}
			else if (state == 11 && states.back() == 4 && lexem.type == fig_bracket_close) {
				brackets[brackets.size() - 1]--;
				if (brackets.back() == 0) {
					brackets.pop_back();//убираем отработавшую скобку
					states[states.size() - 1] = 5;//ищем else
				}
				return;
			}
			else if (state == 11 && states.back() == 4 && lexem.type != _data_type_) {
				//ТУТ СЧИТЫВАЕМ СОСТОЯНИЕ ПОСЛЕДНЕГО СИГНАЛА И СМОТРИМ СЧИТЫВАТЬ ИЛИ НЕТ
				if (processor->if_signals.back()) {
					/*iteration_index--;
					continue;*/
					lexem_queue.push_back(lexem);
				}
				return;
			}
			else if (state == 11 && states.back() == 5 && lexem.type == _else_) {
				states[states.size() - 1] = 6;//ждем открывающую скобку начала тела else
				return;
			}
			else if (state == 11 && states.back() == 5 && lexem.type != _else_) {
				//переводим в свободное считывание или внешнюю обертку
				states.pop_back();//зачистили состояние
				if (states.size() == 0) state = 0; //если это была первая обертка, то переводим в свободное считывание
				processor->if_signals.pop_back();//зачистили сигнал
				//ТУТ ПОКА СПОРНО, НО ПУСТЬ БУДЕТ ПОВТОР, ДЛЯ ЭТОГО ИСПОЛЬЗУЮ ЦИКЛ НА ОДНУ ИТЕРАЦИЮ И ЕСЛИ ЧТО...
				iteration_index--;
				continue;
			}
			else if (state == 11 && states.back() == 6 && lexem.type == fig_bracket_open) {
				states[states.size() - 1] = 7;//ждем закрывающую скобку тела else
				brackets.push_back(1);//следим за скобочной последовательностью
				return;
			}
			else if (state == 11 && states.back() == 7 && lexem.type == fig_bracket_open) {
				brackets[brackets.size() - 1]++;
				return;
			}
			else if (state == 11 && states.back() == 7 && lexem.type == fig_bracket_close) {
				brackets[brackets.size() - 1]--;
				if (brackets.back() == 0) {
					brackets.pop_back();//зачистили скобку
					states.pop_back();//зачистили состояние
					if (states.size() == 0) state = 0; //если первая обертка то перевели в свободное считывание
					processor->if_signals.pop_back();//зачистили сигнал
				}
				return;
			}
			else if (state == 11 && states.back() == 7 && lexem.type != _data_type_) {
				//ТУТ СЧИТЫВАЕМ СОСТОЯНИЕ ПОСЛЕДНЕГО СИГНАЛА И СМОТРИМ ЕГО !ИНВЕРТИРОВАННЫМ! - СЧИТЫВАТЬ ИЛИ НЕТ
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
				states.push_back(31);//ждем открывающуюся скобку начала аргументов
				lexem_queue.push_back(lexem);
				state = 11;
				return;
			}
			else if (state == 11 && lexem.type == round_bracket_open && states.back() == 31) {
				states[states.size() - 1] = 32;//теперь считываем аргументы - пока не будет сделана правильная скобочная последовательность
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
					brackets.pop_back();//очистили скобку
					states[states.size() - 1] = 33;//ждем фигурную скобку начала тела while
					expressions.push_back(lexem_queue);//добавили выражение из скобок while чтоб каждый раз не пересобирать его а проверять в конце тела и только тогда возвращаться
					instruction_definer();//получаем сигнал
				}
				return;
			}
			else if (state == 11 && states.back() == 32) {
				lexem_queue.push_back(lexem);
				return;
			}
			else if (state == 11 && states.back() == 33 && lexem.type == fig_bracket_open) {
				brackets.push_back(1);//опять следим за правильной скобочной последовательностью
				states[states.size() - 1] = 34;//ждем первой инструкции в теле while
				return;
			}
			else if (state == 11 && states.back() == 34) {
				while_addr.push_back(processor->code_segment.get_index());//получаем адрес куда если что зациклит while
				states[states.size() - 1] = 35;//ждем конца тела (выполняем правильную скобочную последовательность)
				
				//не забываем про скобочную последовательность
				if (lexem.type == fig_bracket_open) {
					brackets[brackets.size() - 1]++;
					return;
				}
				else if (lexem.type == fig_bracket_close) {
					brackets[brackets.size() - 1]--;
					if (brackets[brackets.size() - 1] == 0) {
						//если у нас while(..) {}, то нет смысла проверять условие для пустого тела
						brackets.pop_back();
						states.pop_back();
						expressions.pop_back();
						processor->if_signals.pop_back();
						if (processor->if_signals.size() == 0) {
							state = 0;//перевели в свободное считывание
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
					//готовимся к получению сигнала
					lexem_queue.clear();
					processor->if_signals.pop_back();
					lexem_queue = expressions.back();
					instruction_definer();//получаем сигнал
					if (processor->if_signals.back()) {
						processor->code_segment.set_index(while_addr.back());
						brackets.push_back(1);//представим что начали с начала тела и запишем {
						states[states.size() - 1] = 34;
						while_addr.pop_back();//в 34 state добавляется адрес первой инструкции, поэтому удалим тут.
					}
					else {
						states.pop_back();
						expressions.pop_back();
						while_addr.pop_back();
						processor->if_signals.pop_back();
						if (states.size() == 0) {
							state = 0;//в свободное считывание
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

			//свободное считывание
			if (state == 0) {
				lexem_queue.push_back(lexem);
				return;
			}
		}
	}
}

Lexem_Queue_Assembler::Lexem_Queue_Assembler(Processor* p) :processor(p), arg_brackets_is_working(0),signature(""),cnt_brackets_eq(0) {};