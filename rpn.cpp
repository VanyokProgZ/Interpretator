#include "rpn.h"

std::map<size_t, size_t> OPERATION_PRIORITY
({
	{round_bracket_open,0},
	{_return_, 1},
	{_operator_is_, 2},
	{_operator_os_, 2},
	{_if_, 2},
	{_while_, 2},
	{operator_copy, 2},
	{operator_logic_or,4},
	{operator_logic_and,5},
	{operator_eq,9},
	{operator_ne,9},
	{operator_gr,10},
	{operator_ge,10},
	{operator_ls,10},
	{operator_le,10},
	{operator_plus,12},
	{operator_minus,12},
	{operator_multiply,13},
	{operator_division,13},
	{operator_ostatok,13},
	{operator_logic_not,14},
	{sq_bracket_open,17},
	{sq_bracket_close,17},
	{call_function,20}
	});

std::vector<Lexem> translate_to_rpn(const std::vector<Lexem>& infix) {

	std::vector<Lexem> res;
	std::stack<Lexem> stack;

	for (auto& el : infix) {
		if (el.type == _comma_ || el.type==_data_type_) continue;
		if (el.type == round_bracket_close) {
			while (stack.top().type != round_bracket_open) {
				res.push_back(stack.top());
				stack.pop();
			}
			stack.pop();
		}
		else if (el.type == round_bracket_open) {
			stack.push(el);
		}
		else if (/*el.type == 53 || */el.type == var_name || el.type==new_var || el.type==double_literal || el.type==int_literal || el.type == char_symbol) {
			res.push_back(el);
		}
		else if(el.type!=_comma_) {
			while (!stack.empty() && OPERATION_PRIORITY[el.type] <= OPERATION_PRIORITY[stack.top().type]) {
				if (!in(stack.top().type, {sq_bracket_close,sq_bracket_open}))
				res.push_back(stack.top());
				stack.pop();
			}
			stack.push(el);
		}
		
	}
	while (!stack.empty()) {
		if (!in(stack.top().type, { sq_bracket_close,sq_bracket_open }))
		res.push_back(stack.top());
		stack.pop();
	}
	return res;
}