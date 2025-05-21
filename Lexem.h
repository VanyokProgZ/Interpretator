#pragma once
#include <string>
#include <vector>

enum LEXEM_TYPES
{
	//адресация
	_ret_from_func_mark = 0,
	_return_ = 1,

	//общий синтаксис
	_semicolon_ = 7,
	_comma_ = 8,

	//функции
	function_name = 51,
	new_function = 52,
	call_function = 53,
	function_data_type = 54,
	function_return_type = 55,
	arg_data_type = 56,

	//литералы
	double_literal = 71,
	int_literal = 72,
	char_symbol = 73,

	//условия
	_if_ = 101,
	_else_ = 102,
	_switch_ = 103,
	_case_ = 104,

	//циклы
	_for_ = 201,
	_while_ = 202,

	//управление
	_break_ = 301,
	_continue_ = 302,

	//арифметика
	operator_plus = 10001,
	operator_minus = 10002,
	operator_multiply = 10003,
	operator_division = 10004,
	operator_plus_plus = 10005,
	operator_minus_minus = 10006,
	operator_ostatok = 10007,

	//логика
	operator_logic_and = 11001,
	operator_logic_or = 11002,
	operator_logic_not = 11003,

	//присвоения арифметика
	operator_plus_eq = 20001,
	operator_minus_eq = 20002,
	operator_multiply_eq = 20003,
	operator_division_eq = 20004,
	operator_ostatok_eq = 20005,

	//присвоение
	operator_copy = 30000,

	//сравнения
	operator_eq = 40001,
	operator_ne = 40002,
	operator_gr = 40003,
	operator_ls = 40004,
	operator_ge = 40005,
	operator_le = 40006,

	//Указатели и массивы
	new_ptr_var_mark = 43001,
	pointer = 43002,
	pointer_mark = 43003,
	deferencing_operator = 43004,
	static_array = 43005,
	new_static_array = 43006,

	//скобки
	round_bracket_open = 401,
	round_bracket_close = 402,
	sq_bracket_open = 403,
	sq_bracket_close = 404,
	fig_bracket_open = 405,
	fig_bracket_close = 406,
	if_body_open_bracket = 407,
	if_body_close_bracket = 408,


	//типы данных
	_void_ = 500,
	_int_ = 501,
	_float_ = 502,
	_double_ = 503,
	_long_long_ = 504,
	_char_ = 505,
	var_name = 599,
	new_var = 598,
	_data_type_ = 597,

	//пользовательская типизация
	_class_ = 550,
	_struct_ = 551,
	class_name = 502,

	//разбиение блоков временной памяти
	_timed_memory_block_begin = 830,
	_timed_memory_block_end = 831,

	//потоки ввода/вывода
	_cin_ = 77001,
	_cout_ = 77002,
	_operator_is_ = 77003,
	_operator_os_ = 77004,

	//спорные вещи
	unknown_name = 11111,
};

bool in(size_t type, const std::vector<size_t>& v);

class Lexem {
public:
	std::string text;
	std::string type_signature;
	std::string returned_type;

	size_t type;
	size_t data_type;
	size_t arg_c;

	//for call stack
	double cs_float64;
	float cs_float32;
	int cs_int32;
	long long cs_int64;
	char cs_int8;

	//

	Lexem() {
		cs_float32 = cs_float64 = cs_int8 = cs_int32 = cs_int64 = 0;
		
		text = type_signature = "";

		type = data_type=unknown_name;
		arg_c = 0;
	}
	Lexem& operator=(const Lexem& right);

	Lexem(const std::string& s_, std::size_t t, size_t dat_t, size_t arg_c_, const std::string type_sign_,const std::string& ret_type);
};

std::vector<size_t> get_eq_indexes(const std::vector<Lexem>& row);