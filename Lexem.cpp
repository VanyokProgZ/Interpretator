#include "Lexem.h"

Lexem::Lexem(const std::string& s_, std::size_t t, size_t dat_t, size_t arg_c_, const std::string type_sign_, const std::string& ret_type) :text(s_), type(t),data_type(dat_t),arg_c(arg_c_),type_signature(type_sign_)
,cs_float32(0.0f),cs_float64(0.0),cs_int32(0),cs_int64(0),cs_int8(0),returned_type(ret_type){};

bool in(size_t type, const std::vector<size_t>& v) {
	for (auto& el : v) {
		if (type == el) return true;
	}
	return false;
}
std::vector<size_t> get_eq_indexes(const std::vector<Lexem>& row) {
	std::vector<size_t> res;
	for (size_t i = 0; i < row.size(); i++) {
		if (row[i].type == operator_copy) {
			res.push_back(i);
		}
	}
	return res;
}

Lexem& Lexem::operator=(const Lexem& right) {
	cs_float32 = right.cs_float32;
	cs_float64 = right.cs_float64;
	cs_int32 = right.cs_int32;
	cs_int64 = right.cs_int64;
	cs_int8 = right.cs_int8;
	type = right.type;
	arg_c = right.arg_c;
	data_type = right.data_type;
	text = right.text;
	type_signature = right.type_signature;
	return *this;
}