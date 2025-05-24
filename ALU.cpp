#include "ALU.h"

std::map<std::string, std::string> operators_ret_types = {
	//bool
	{"bool::operator+::(::int::)", "bool"},
	{"bool::operator+::(::float::)", "bool"},
	{"bool::operator+::(::double::)", "bool"},
	{"bool::operator+::(::char::)", "bool"},
	{"bool::operator+::(::long_long::)", "bool"},
	{"bool::operator+::(::bool::)", "bool"},

	{"bool::operator=::(::int::)", "bool&"},
	{"bool::operator=::(::float::)", "bool&"},
	{"bool::operator=::(::double::)", "bool&"},
	{"bool::operator=::(::char::)", "bool&"},
	{"bool::operator=::(::long_long::)", "bool&"},
	{"bool::operator=::(::bool::)", "bool&"},

	{"bool&::operator=::(::int::)", "bool&"},
	{"bool&::operator=::(::float::)", "bool&"},
	{"bool&::operator=::(::double::)", "bool&"},
	{"bool&::operator=::(::char::)", "bool&"},
	{"bool&::operator=::(::long_long::)", "bool&"},
	{"bool&::operator=::(::bool::)", "bool&"},

	{"bool::operator-::(::int::)", "bool"},
	{"bool::operator-::(::float::)", "bool"},
	{"bool::operator-::(::double::)", "bool"},
	{"bool::operator-::(::char::)", "bool"},
	{"bool::operator-::(::long_long::)", "bool"},
	{"bool::operator-::(::bool::)", "bool"},

	{"bool::operator*::(::int::)", "bool"},
	{"bool::operator*::(::float::)", "bool"},
	{"bool::operator*::(::double::)", "bool"},
	{"bool::operator*::(::char::)", "bool"},
	{"bool::operator*::(::long_long::)", "bool"},
	{"bool::operator*::(::bool::)", "bool"},

	{"bool::operator/::(::int::)", "bool"},
	{"bool::operator/::(::float::)", "bool"},
	{"bool::operator/::(::double::)", "bool"},
	{"bool::operator/::(::char::)", "bool"},
	{"bool::operator/::(::long_long::)", "bool"},
	{"bool::operator/::(::bool::)", "bool"},

	{"bool::operator>::(::int::)", "bool"},
	{"bool::operator>::(::float::)", "bool"},
	{"bool::operator>::(::double::)", "bool"},
	{"bool::operator>::(::char::)", "bool"},
	{"bool::operator>::(::long_long::)", "bool"},
	{"bool::operator>::(::bool::)", "bool"},

	{"bool::operator<::(::int::)", "bool"},
	{"bool::operator<::(::float::)", "bool"},
	{"bool::operator<::(::double::)", "bool"},
	{"bool::operator<::(::char::)", "bool"},
	{"bool::operator<::(::long_long::)", "bool"},
	{"bool::operator<::(::bool::)", "bool"},

	{"bool::operator>=::(::int::)", "bool"},
	{"bool::operator>=::(::float::)", "bool"},
	{"bool::operator>=::(::double::)", "bool"},
	{"bool::operator>=::(::char::)", "bool"},
	{"bool::operator>=::(::long_long::)", "bool"},
	{"bool::operator>=::(::bool::)", "bool"},

	{"bool::operator<=::(::int::)", "bool"},
	{"bool::operator<=::(::float::)", "bool"},
	{"bool::operator<=::(::double::)", "bool"},
	{"bool::operator<=::(::char::)", "bool"},
	{"bool::operator<=::(::long_long::)", "bool"},
	{"bool::operator<=::(::bool::)", "bool"},

	{"bool::operator&&::(::int::)", "bool"},
	{"bool::operator&&::(::float::)", "bool"},
	{"bool::operator&&::(::double::)", "bool"},
	{"bool::operator&&::(::char::)", "bool"},
	{"bool::operator&&::(::long_long::)", "bool"},
	{"bool::operator&&::(::bool::)", "bool"},

	{"bool::operator||::(::int::)", "bool"},
	{"bool::operator||::(::float::)", "bool"},
	{"bool::operator||::(::double::)", "bool"},
	{"bool::operator||::(::char::)", "bool"},
	{"bool::operator||::(::long_long::)", "bool"},
	{"bool::operator||::(::bool::)", "bool"},

	{"operator!::(::bool::)", "bool"},

	{"operator?*::(::bool*::)", "bool"},

	{"bool::operator[]::(::int::)", "bool&"},

	{"bool::operator!=::(::int::)", "bool"},
	{"bool::operator!=::(::float::)", "bool"},
	{"bool::operator!=::(::double::)", "bool"},
	{"bool::operator!=::(::char::)", "bool"},
	{"bool::operator!=::(::long_long::)", "bool"},
	{"bool::operator!=::(::bool::)", "bool"},

	{"bool::operator==::(::int::)", "bool"},
	{"bool::operator==::(::float::)", "bool"},
	{"bool::operator==::(::double::)", "bool"},
	{"bool::operator==::(::char::)", "bool"},
	{"bool::operator==::(::long_long::)", "bool"},
	{"bool::operator==::(::bool::)", "bool"},

	{"bool::operator%::(::int::)", "bool"},
	{"bool::operator%::(::long_long::)", "bool"},
	{"bool::operator%::(::char::)", "bool"},
	{"bool::operator%::(::bool::)", "bool"},
	
	//int
	{"int::operator+::(::int::)", "int"},
	{"int::operator+::(::float::)", "int"},
	{"int::operator+::(::double::)", "int"},
	{"int::operator+::(::char::)", "int"},
	{"int::operator+::(::long_long::)", "int"},
	{"int::operator+::(::bool::)", "int" },

	{"int::operator=::(::int::)", "int&"},
	{"int::operator=::(::float::)", "int&"},
	{"int::operator=::(::double::)", "int&"},
	{"int::operator=::(::char::)", "int&"},
	{"int::operator=::(::long_long::)", "int&"},
	{"int::operator=::(::bool::)", "int&" },

	{ "int&::operator=::(::int::)", "int&" },
	{ "int&::operator=::(::float::)", "int&" },
	{ "int&::operator=::(::double::)", "int&" },
	{ "int&::operator=::(::char::)", "int&" },
	{ "int&::operator=::(::long_long::)", "int&" },
	{ "int&::operator=::(::bool::)", "int&" },

	{"int::operator-::(::int::)", "int"},
	{"int::operator-::(::float::)", "int"},
	{"int::operator-::(::double::)", "int"},
	{"int::operator-::(::char::)", "int"},
	{"int::operator-::(::long_long::)", "int"},
	{"int::operator-::(::bool::)", "int" },

	{"int::operator*::(::int::)", "int"},
	{"int::operator*::(::float::)", "int"},
	{"int::operator*::(::double::)", "int"},
	{"int::operator*::(::char::)", "int"},
	{"int::operator*::(::long_long::)", "int"},
	{"int::operator*::(::bool::)", "int" },

	{"int::operator/::(::int::)", "int"},
	{"int::operator/::(::float::)", "int"},
	{"int::operator/::(::double::)", "int"},
	{"int::operator/::(::char::)", "int"},
	{"int::operator/::(::long_long::)", "int"},
	{ "int::operator/::(::bool::)", "int" },

	{"int::operator>::(::int::)", "bool"},
	{"int::operator>::(::float::)", "bool"},
	{"int::operator>::(::double::)", "bool"},
	{"int::operator>::(::char::)", "bool"},
	{"int::operator>::(::long_long::)", "bool"},
	{"int::operator>::(::bool::)", "bool" },

	{"int::operator<::(::int::)", "bool"},
	{"int::operator<::(::float::)", "bool"},
	{"int::operator<::(::double::)", "bool"},
	{"int::operator<::(::char::)", "bool"},
	{"int::operator<::(::long_long::)", "bool"},
	{"int::operator<::(::bool::)", "bool" },

	{"int::operator>=::(::int::)", "bool"},
	{"int::operator>=::(::float::)", "bool"},
	{"int::operator>=::(::double::)", "bool"},
	{"int::operator>=::(::char::)", "bool"},
	{"int::operator>=::(::long_long::)", "bool"},
	{ "int::operator>=::(::bool::)", "bool" },

	{"int::operator<=::(::int::)", "bool"},
	{"int::operator<=::(::float::)", "bool"},
	{"int::operator<=::(::double::)", "bool"},
	{"int::operator<=::(::char::)", "bool"},
	{"int::operator<=::(::long_long::)", "bool"},
	{"int::operator<=::(::bool::)", "bool" },

	{"int::operator&&::(::int::)", "bool"},
	{"int::operator&&::(::float::)", "bool"},
	{"int::operator&&::(::double::)", "bool"},
	{"int::operator&&::(::char::)", "bool"},
	{"int::operator&&::(::long_long::)", "bool"},
	{"int::operator&&::(::bool::)", "bool" },

	{"int::operator||::(::int::)", "bool"},
	{"int::operator||::(::float::)", "bool"},
	{"int::operator||::(::double::)", "bool"},
	{"int::operator||::(::char::)", "bool"},
	{"int::operator||::(::long_long::)", "bool"},
	{"int::operator||::(::bool::)", "bool" },

	{"operator!::(::int::)", "bool"},

	{"operator?*::(::int*::)", "int"},

	{ "int::operator[]::(::int::)", "int&" },

	{"int::operator!=::(::int::)", "bool"},
	{"int::operator!=::(::float::)", "bool"},
	{"int::operator!=::(::double::)", "bool"},
	{"int::operator!=::(::char::)", "bool"},
	{"int::operator!=::(::long_long::)", "bool"},
	{"int::operator!=::(::bool::)", "bool" },

	{"int::operator==::(::int::)", "bool"},
	{"int::operator==::(::float::)", "bool"},
	{"int::operator==::(::double::)", "bool"},
	{"int::operator==::(::char::)", "bool"},
	{"int::operator==::(::long_long::)", "bool"},
	{"int::operator==::(::bool::)", "bool" },

	{"int::operator%::(::int::)", "int"},
	{"int::operator%::(::long_long::)", "int"},
	{"int::operator%::(::char::)", "int"},
	{"int::operator%::(::bool::)", "int" },

	//double
	{"double::operator+::(::int::)", "double"},
	{"double::operator+::(::float::)", "double"},
	{"double::operator+::(::double::)", "double"},
	{"double::operator+::(::char::)", "double"},
	{"double::operator+::(::long_long::)", "double"},

	{"double::operator=::(::int::)", "double&"},
	{"double::operator=::(::float::)", "double&"},
	{"double::operator=::(::double::)", "double&"},
	{"double::operator=::(::char::)", "double&"},
	{"double::operator=::(::long_long::)", "double&"},

	{ "double&::operator=::(::int::)", "double&" },
	{ "double&::operator=::(::float::)", "double&" },
	{ "double&::operator=::(::double::)", "double&" },
	{ "double&::operator=::(::char::)", "double&" },
	{ "double&::operator=::(::long_long::)", "double&" },

	{"double::operator-::(::int::)", "double"},
	{"double::operator-::(::float::)", "double"},
	{"double::operator-::(::double::)", "double"},
	{"double::operator-::(::char::)", "double"},
	{"double::operator-::(::long_long::)", "double"},

	{"double::operator*::(::int::)", "double"},
	{"double::operator*::(::float::)", "double"},
	{"double::operator*::(::double::)", "double"},
	{"double::operator*::(::char::)", "double"},
	{"double::operator*::(::long_long::)", "double"},

	{"double::operator/::(::int::)", "double"},
	{"double::operator/::(::float::)", "double"},
	{"double::operator/::(::double::)", "double"},
	{"double::operator/::(::char::)", "double"},
	{"double::operator/::(::long_long::)", "double"},

	{"double::operator>::(::int::)", "bool"},
	{"double::operator>::(::float::)", "bool"},
	{"double::operator>::(::double::)", "bool"},
	{"double::operator>::(::char::)", "bool"},
	{"double::operator>::(::long_long::)", "bool"},

	{"double::operator<::(::int::)", "bool"},
	{"double::operator<::(::float::)", "bool"},
	{"double::operator<::(::double::)", "bool"},
	{"double::operator<::(::char::)", "bool"},
	{"double::operator<::(::long_long::)", "bool"},

	{"double::operator>=::(::int::)", "bool"},
	{"double::operator>=::(::float::)", "bool"},
	{"double::operator>=::(::double::)", "bool"},
	{"double::operator>=::(::char::)", "bool"},
	{"double::operator>=::(::long_long::)", "bool"},

	{"double::operator<=::(::int::)", "bool"},
	{"double::operator<=::(::float::)", "bool"},
	{"double::operator<=::(::double::)", "bool"},
	{"double::operator<=::(::char::)", "bool"},
	{"double::operator<=::(::long_long::)", "bool"},

	{ "double::operator&&::(::int::)", "bool" },
	{ "double::operator&&::(::float::)", "bool" },
	{ "double::operator&&::(::double::)", "bool" },
	{ "double::operator&&::(::char::)", "bool" },
	{ "double::operator&&::(::long_long::)", "bool" },

	{ "double::operator||::(::int::)", "bool" },
	{ "double::operator||::(::float::)", "bool" },
	{ "double::operator||::(::double::)", "bool" },
	{ "double::operator||::(::char::)", "bool" },
	{ "double::operator||::(::long_long::)", "bool" },

	{ "operator!::(::double::)", "bool" },

	{ "operator?*::(::double*::)", "double" },

	{ "double::operator[]::(::int::)", "double&" },

	{ "double::operator!=::(::int::)", "bool" },
	{ "double::operator!=::(::float::)", "bool" },
	{ "double::operator!=::(::double::)", "bool" },
	{ "double::operator!=::(::char::)", "bool" },
	{ "double::operator!=::(::long_long::)", "bool" },

	{ "double::operator==::(::int::)", "bool" },
	{ "double::operator==::(::float::)", "bool" },
	{ "double::operator==::(::double::)", "bool" },
	{ "double::operator==::(::char::)", "bool" },
	{ "double::operator==::(::long_long::)", "bool" },

	//float
	{ "float::operator+::(::int::)", "float" },
	{ "float::operator+::(::float::)", "float" },
	{ "float::operator+::(::double::)", "float" },
	{ "float::operator+::(::char::)", "float" },
	{ "float::operator+::(::long_long::)", "float" },

	{ "float::operator=::(::int::)", "float&" },
	{ "float::operator=::(::float::)", "float&" },
	{ "float::operator=::(::double::)", "float&" },
	{ "float::operator=::(::char::)", "float&" },
	{ "float::operator=::(::long_long::)", "float&" },

	{ "float&::operator=::(::int::)", "float&" },
	{ "float&::operator=::(::float::)", "float&" },
	{ "float&::operator=::(::double::)", "float&" },
	{ "float&::operator=::(::char::)", "float&" },
	{ "float&::operator=::(::long_long::)", "float&" },

	{ "float::operator-::(::int::)", "float" },
	{ "float::operator-::(::float::)", "float" },
	{ "float::operator-::(::double::)", "float" },
	{ "float::operator-::(::char::)", "float" },
	{ "float::operator-::(::long_long::)", "float" },

	{ "float::operator*::(::int::)", "float" },
	{ "float::operator*::(::float::)", "float" },
	{ "float::operator*::(::double::)", "float" },
	{ "float::operator*::(::char::)", "float" },
	{ "float::operator*::(::long_long::)", "float" },

	{ "float::operator/::(::int::)", "float" },
	{ "float::operator/::(::float::)", "float" },
	{ "float::operator/::(::double::)", "float" },
	{ "float::operator/::(::char::)", "float" },
	{ "float::operator/::(::long_long::)", "float" },

	{ "float::operator>::(::int::)", "bool" },
	{ "float::operator>::(::float::)", "bool" },
	{ "float::operator>::(::double::)", "bool" },
	{ "float::operator>::(::char::)", "bool" },
	{ "float::operator>::(::long_long::)", "bool" },

	{ "float::operator<::(::int::)", "bool" },
	{ "float::operator<::(::float::)", "bool" },
	{ "float::operator<::(::double::)", "bool" },
	{ "float::operator<::(::char::)", "bool" },
	{ "float::operator<::(::long_long::)", "bool" },

	{ "float::operator>=::(::int::)", "bool" },
	{ "float::operator>=::(::float::)", "bool" },
	{ "float::operator>=::(::double::)", "bool" },
	{ "float::operator>=::(::char::)", "bool" },
	{ "float::operator>=::(::long_long::)", "bool" },

	{ "float::operator<=::(::int::)", "bool" },
	{ "float::operator<=::(::float::)", "bool" },
	{ "float::operator<=::(::double::)", "bool" },
	{ "float::operator<=::(::char::)", "bool" },
	{ "float::operator<=::(::long_long::)", "bool" },

	{ "float::operator&&::(::int::)", "bool" },
	{ "float::operator&&::(::float::)", "bool" },
	{ "float::operator&&::(::double::)", "bool" },
	{ "float::operator&&::(::char::)", "bool" },
	{ "float::operator&&::(::long_long::)", "bool" },

	{ "float::operator||::(::int::)", "bool" },
	{ "float::operator||::(::float::)", "bool" },
	{ "float::operator||::(::double::)", "bool" },
	{ "float::operator||::(::char::)", "bool" },
	{ "float::operator||::(::long_long::)", "bool" },

	{ "operator!::(::float::)", "bool" },

	{ "operator?*::(::float*::)", "float" },

	{ "float::operator[]::(::int::)", "float&" },

	{ "float::operator!=::(::int::)", "bool" },
	{ "float::operator!=::(::float::)", "bool" },
	{ "float::operator!=::(::double::)", "bool" },
	{ "float::operator!=::(::char::)", "bool" },
	{ "float::operator!=::(::long_long::)", "bool" },

	{ "float::operator==::(::int::)", "bool" },
	{ "float::operator==::(::float::)", "bool" },
	{ "float::operator==::(::double::)", "bool" },
	{ "float::operator==::(::char::)", "bool" },
	{ "float::operator==::(::long_long::)", "bool" },

	//char
	{ "char::operator+::(::int::)", "char" },
	{ "char::operator+::(::float::)", "char" },
	{ "char::operator+::(::double::)", "char" },
	{ "char::operator+::(::char::)", "char" },
	{ "char::operator+::(::long_long::)", "char" },

	{ "char::operator=::(::int::)", "char&" },
	{ "char::operator=::(::float::)", "char&" },
	{ "char::operator=::(::double::)", "char&" },
	{ "char::operator=::(::char::)", "char&" },
	{ "char::operator=::(::long_long::)", "char&" },

	{ "char&::operator=::(::int::)", "char&" },
	{ "char&::operator=::(::float::)", "char&" },
	{ "char&::operator=::(::double::)", "char&" },
	{ "char&::operator=::(::char::)", "char&" },
	{ "char&::operator=::(::long_long::)", "char&" },

	{ "char::operator-::(::int::)", "char" },
	{ "char::operator-::(::float::)", "char" },
	{ "char::operator-::(::double::)", "char" },
	{ "char::operator-::(::char::)", "char" },
	{ "char::operator-::(::long_long::)", "char" },

	{ "char::operator*::(::int::)", "char" },
	{ "char::operator*::(::float::)", "char" },
	{ "char::operator*::(::double::)", "char" },
	{ "char::operator*::(::char::)", "char" },
	{ "char::operator*::(::long_long::)", "char" },

	{ "char::operator/::(::int::)", "char" },
	{ "char::operator/::(::float::)", "char" },
	{ "char::operator/::(::double::)", "char" },
	{ "char::operator/::(::char::)", "char" },
	{ "char::operator/::(::long_long::)", "char" },

	{ "char::operator>::(::int::)", "bool" },
	{ "char::operator>::(::float::)", "bool" },
	{ "char::operator>::(::double::)", "bool" },
	{ "char::operator>::(::char::)", "bool" },
	{ "char::operator>::(::long_long::)", "bool" },

	{ "char::operator<::(::int::)", "bool" },
	{ "char::operator<::(::float::)", "bool" },
	{ "char::operator<::(::double::)", "bool" },
	{ "char::operator<::(::char::)", "bool" },
	{ "char::operator<::(::long_long::)", "bool" },

	{ "char::operator>=::(::int::)", "bool" },
	{ "char::operator>=::(::float::)", "bool" },
	{ "char::operator>=::(::double::)", "bool" },
	{ "char::operator>=::(::char::)", "bool" },
	{ "char::operator>=::(::long_long::)", "bool" },

	{ "char::operator<=::(::int::)", "bool" },
	{ "char::operator<=::(::float::)", "bool" },
	{ "char::operator<=::(::double::)", "bool" },
	{ "char::operator<=::(::char::)", "bool" },
	{ "char::operator<=::(::long_long::)", "bool" },

	{ "char::operator&&::(::int::)", "bool" },
	{ "char::operator&&::(::float::)", "bool" },
	{ "char::operator&&::(::double::)", "bool" },
	{ "char::operator&&::(::char::)", "bool" },
	{ "char::operator&&::(::long_long::)", "bool" },

	{ "char::operator||::(::int::)", "bool" },
	{ "char::operator||::(::float::)", "bool" },
	{ "char::operator||::(::double::)", "bool" },
	{ "char::operator||::(::char::)", "bool" },
	{ "char::operator||::(::long_long::)", "bool" },

	{ "operator!::(::char::)", "bool" },

	{ "operator?*::(::char*::)", "char" },

	{ "char::operator[]::(::int::)", "char&" },

	{ "char::operator!=::(::int::)", "bool" },
	{ "char::operator!=::(::float::)", "bool" },
	{ "char::operator!=::(::double::)", "bool" },
	{ "char::operator!=::(::char::)", "bool" },
	{ "char::operator!=::(::long_long::)", "bool" },

	{ "char::operator==::(::int::)", "bool" },
	{ "char::operator==::(::float::)", "bool" },
	{ "char::operator==::(::double::)", "bool" },
	{ "char::operator==::(::char::)", "bool" },
	{ "char::operator==::(::long_long::)", "bool" },

	{ "char::operator%::(::int::)", "char" },
	{ "char::operator%::(::long_long::)", "char" },
	{ "char::operator%::(::char::)", "char" },

	//long long
	{ "long_long::operator+::(::int::)", "long_long" },
	{ "long_long::operator+::(::float::)", "long_long" },
	{ "long_long::operator+::(::double::)", "long_long" },
	{ "long_long::operator+::(::char::)", "long_long" },
	{ "long_long::operator+::(::long_long::)", "long_long" },

	{ "long_long::operator=::(::int::)", "long_long&" },
	{ "long_long::operator=::(::float::)", "long_long&" },
	{ "long_long::operator=::(::double::)", "long_long&" },
	{ "long_long::operator=::(::char::)", "long_long&" },
	{ "long_long::operator=::(::long_long::)", "long_long&" },

	{ "long_long&::operator=::(::int::)", "long_long&" },
	{ "long_long&::operator=::(::float::)", "long_long&" },
	{ "long_long&::operator=::(::double::)", "long_long&" },
	{ "long_long&::operator=::(::char::)", "long_long&" },
	{ "long_long&::operator=::(::long_long::)", "long_long&" },

	{ "long_long::operator-::(::int::)", "long_long" },
	{ "long_long::operator-::(::float::)", "long_long" },
	{ "long_long::operator-::(::double::)", "long_long" },
	{ "long_long::operator-::(::char::)", "long_long" },
	{ "long_long::operator-::(::long_long::)", "long_long" },

	{ "long_long::operator*::(::int::)", "long_long" },
	{ "long_long::operator*::(::float::)", "long_long" },
	{ "long_long::operator*::(::double::)", "long_long" },
	{ "long_long::operator*::(::char::)", "long_long" },
	{ "long_long::operator*::(::long_long::)", "long_long" },

	{ "long_long::operator/::(::int::)", "long_long" },
	{ "long_long::operator/::(::float::)", "long_long" },
	{ "long_long::operator/::(::double::)", "long_long" },
	{ "long_long::operator/::(::char::)", "long_long" },
	{ "long_long::operator/::(::long_long::)", "long_long" },

	{ "long_long::operator>::(::int::)", "bool" },
	{ "long_long::operator>::(::float::)", "bool" },
	{ "long_long::operator>::(::double::)", "bool" },
	{ "long_long::operator>::(::char::)", "bool" },
	{ "long_long::operator>::(::long_long::)", "bool" },

	{ "long_long::operator<::(::int::)", "bool" },
	{ "long_long::operator<::(::float::)", "bool" },
	{ "long_long::operator<::(::double::)", "bool" },
	{ "long_long::operator<::(::char::)", "bool" },
	{ "long_long::operator<::(::long_long::)", "bool" },

	{ "long_long::operator>=::(::int::)", "bool" },
	{ "long_long::operator>=::(::float::)", "bool" },
	{ "long_long::operator>=::(::double::)", "bool" },
	{ "long_long::operator>=::(::char::)", "bool" },
	{ "long_long::operator>=::(::long_long::)", "bool" },

	{ "long_long::operator<=::(::int::)", "bool" },
	{ "long_long::operator<=::(::float::)", "bool" },
	{ "long_long::operator<=::(::double::)", "bool" },
	{ "long_long::operator<=::(::char::)", "bool" },
	{ "long_long::operator<=::(::long_long::)", "bool" },

	{ "long_long::operator&&::(::int::)", "bool" },
	{ "long_long::operator&&::(::float::)", "bool" },
	{ "long_long::operator&&::(::double::)", "bool" },
	{ "long_long::operator&&::(::char::)", "bool" },
	{ "long_long::operator&&::(::long_long::)", "bool" },

	{ "long_long::operator||::(::int::)", "bool" },
	{ "long_long::operator||::(::float::)", "bool" },
	{ "long_long::operator||::(::double::)", "bool" },
	{ "long_long::operator||::(::char::)", "bool" },
	{ "long_long::operator||::(::long_long::)", "bool" },

	{ "operator!::(::long_long::)", "bool" },

	{ "operator?*::(::long_long*::)", "long_long" },

	{ "long_long::operator[]::(::int::)", "long_long&" },

	{ "long_long::operator!=::(::int::)", "bool" },
	{ "long_long::operator!=::(::float::)", "bool" },
	{ "long_long::operator!=::(::double::)", "bool" },
	{ "long_long::operator!=::(::char::)", "bool" },
	{ "long_long::operator!=::(::long_long::)", "bool" },

	{ "long_long::operator==::(::int::)", "bool" },
	{ "long_long::operator==::(::float::)", "bool" },
	{ "long_long::operator==::(::double::)", "bool" },
	{ "long_long::operator==::(::char::)", "bool" },
	{ "long_long::operator==::(::long_long::)", "bool" },

	{ "long_long::operator%::(::int::)", "long_long" },
	{ "long_long::operator%::(::long_long::)", "long_long" },
	{ "long_long::operator%::(::char::)", "long_long" },
};

Ariphmetic_module::Ariphmetic_module(const std::vector<Lexem>& rpn, Processor* p) :rpn_form(rpn), processor(p){};

			//----------------------------------------------------
			//					 |_ _| \ | |_   _|
			//					  | ||  \| | | |  
			//					  | || |\  | | |  
			//					 |___|_| \_| |_|  
			//----------------------------------------------------
size_t Ariphmetic_module::int_calc(Lexem& rpn_obj) {
	Lexem end_of_block("", unknown_name, unknown_name, 0, "", "");
	Lexem main_data("", unknown_name, unknown_name, 0, "", "");
	Lexem begin_of_block("", unknown_name, unknown_name, 0, "", "");
	MemoryBlock mem;
	std::vector<Lexem> data;

	//int +
	if (rpn_obj.type_signature == "int::int::operator+::(::int::)")
	{	
		int left_ = 0,right_=0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator+::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_+right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator+::(::long_long::)")
	{
		int left_ = 0;long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator+::(::double::)") {
		int left_ = 0;double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_+right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator+::(::float::)") {
		int left_ = 0;float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_+right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//int *
	else if (rpn_obj.type_signature == "int::int::operator*::(::int::)")
	{
		int left_ = 0, right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator*::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator*::(::long_long::)")
	{
		int left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator*::(::double::)") {
		int left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator*::(::float::)") {
		int left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//int -
	else if (rpn_obj.type_signature == "int::int::operator-::(::int::)")
	{
		int left_ = 0, right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator-::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator-::(::long_long::)")
	{
		int left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator-::(::double::)") {
		int left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator-::(::float::)") {
		int left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//int /
	else if (rpn_obj.type_signature == "int::int::operator/::(::int::)")
	{
		int left_ = 0, right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator/::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator/::(::long_long::)")
	{
		int left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator/::(::double::)") {
		int left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator/::(::float::)") {
		int left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//int &
	else if (rpn_obj.type_signature == "int::int::operator&::(::int::)")
	{
		int left_ = 0, right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ & right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator&::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ & right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator&::(::long_long::)")
	{
		int left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ & right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator&::(::double::)") {
		throw  j_error("Nelzya & between int and double");
	}
	else if (rpn_obj.type_signature == "int::int::operator&::(::float::)") {
		throw  j_error("Nelzya & between int and float");
	}
	//int |
	else if (rpn_obj.type_signature == "int::int::operator|::(::int::)")
	{
		int left_ = 0, right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ | right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator|::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ | right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator|::(::long_long::)")
	{
		int left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ | right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator|::(::double::)") {
		throw  j_error("Nelzya | between int and double");
	}
	else if (rpn_obj.type_signature == "int::int::operator|::(::float::)") {
		throw  j_error("Nelzya | between int and float");
	}
	//int ^
	else if (rpn_obj.type_signature == "int::int::operator^::(::int::)")
	{
		int left_ = 0, right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ ^ right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator^::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ ^ right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator^::(::long_long::)")
	{
		int left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ ^ right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator^::(::double::)") {
		throw  j_error("Nelzya ^ between int and double");
	}
	else if (rpn_obj.type_signature == "int::int::operator^::(::float::)") {
		throw  j_error("Nelzya ^ between int and float");
	}
	//int <
	else if (rpn_obj.type_signature == "bool::int::operator<::(::int::)")
	{
		int left_ = 0, right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator<::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator<::(::long_long::)")
	{
		int left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator<::(::double::)") {
		int left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator<::(::float::)") {
		int left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//int <=
	else if (rpn_obj.type_signature == "bool::int::operator<=::(::int::)")
	{
		int left_ = 0, right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator<=::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator<=::(::long_long::)")
	{
		int left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator<=::(::double::)") {
		int left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator<=::(::float::)") {
		int left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//int >
	else if (rpn_obj.type_signature == "bool::int::operator>::(::int::)")
	{
		int left_ = 0, right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator>::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator>::(::long_long::)")
	{
		int left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator>::(::double::)") {
		int left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator>::(::float::)") {
		int left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//int >=
	else if (rpn_obj.type_signature == "bool::int::operator>=::(::int::)")
	{
		int left_ = 0, right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator>=::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator>=::(::long_long::)")
	{
		int left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator>=::(::double::)") {
		int left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator>=::(::float::)") {
		int left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//int ==
	else if (rpn_obj.type_signature == "bool::int::operator==::(::int::)")
	{
		int left_ = 0, right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator==::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator==::(::long_long::)")
	{
		int left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator==::(::double::)") {
		int left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator==::(::float::)") {
		int left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//int !=
	else if (rpn_obj.type_signature == "bool::int::operator!=::(::int::)")
	{
		int left_ = 0, right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator!=::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator!=::(::long_long::)")
	{
		int left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator!=::(::double::)") {
		int left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator!=::(::float::)") {
		int left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//int &&
	else if (rpn_obj.type_signature == "bool::int::operator&&::(::int::)")
	{
		int left_ = 0, right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator&&::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator&&::(::long_long::)")
	{
		int left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator&&::(::double::)") {
		int left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator&&::(::float::)") {
		int left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//int ||
	else if (rpn_obj.type_signature == "bool::int::operator||::(::int::)")
	{
		int left_ = 0, right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator||::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator||::(::long_long::)")
	{
		int left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator||::(::double::)") {
		int left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::int::operator||::(::float::)") {
		int left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//int !
	else if (rpn_obj.type_signature == "bool::operator!::(::int::)")
	{
		int arg;
		if (processor->call_stack.stack.back().title.link) {
			arg = processor->call_stack.stack[processor->call_stack.stack.back().title.link].data[0].cs_int32;
		}
		else {
			arg = processor->call_stack.stack.back().data[0].cs_int32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _char_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = !arg;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//int %
	else if (rpn_obj.type_signature == "int::int::operator%::(::int::)")
	{
		int left_ = 0, right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ % right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator%::(::char::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ % right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator%::(::long_long::)")
	{
		int left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ % right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "int::int::operator%::(::double::)") {
		throw j_error("ostatok int na double nelzya!");
	}
	else if (rpn_obj.type_signature == "int::int::operator%::(::float::)") {
		throw j_error("ostatok int na float nelzya!");
	}
	//ostream int
	else if (rpn_obj.type_signature == "ostream&::operator<<::(::ostream&::int::)") {
		int arg;
		if (processor->call_stack.stack.back().title.link) {
			arg = processor->call_stack.stack[processor->call_stack.stack.back().title.link].data[0].cs_int32;
		}
		else {
			arg = processor->call_stack.stack.back().data[0].cs_int32;
		}
		std::cout << arg;
		processor->call_stack.pop();
	}
	//istream int
	else if (rpn_obj.type_signature == "istream&::operator>>::(::istream&::int::)") {
		long long index = 0;
		if (processor->call_stack.stack.back().title.link) {
			index = processor->call_stack.stack.back().title.link;
		}
		else {
			for (long long c = processor->call_stack.size() - 2; c > -1; c--) {
				if (processor->call_stack.stack[c].title.text == processor->call_stack.top().title.text) {
					index = c;
					break;
				}
			}
		}
		std::cin >> processor->call_stack.stack[index].data[0].cs_int32;
		processor->call_stack.stack[index].data[0].cs_int8 = processor->call_stack.stack[index].data[0].cs_int64 = processor->call_stack.stack[index].data[0].cs_int32;
		processor->call_stack.pop();
	}
	//int copy operator
	else if (rpn_obj.type_signature == "int&::int::operator=::(::int::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
		else {
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "int&::int::operator=::(::char::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int32 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "int&::int::operator=::(::long_long::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			else {
				processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int32 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int64;
				size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
				processor->call_stack.stack[addr].data = processor->call_stack.top().data;
				processor->call_stack.pop();
				processor->call_stack.pop();
			}
	}
	else if (rpn_obj.type_signature == "int&::int::operator=::(::float::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
				else {
					processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int32 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float32;
					size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
					processor->call_stack.stack[addr].data = processor->call_stack.top().data;
					processor->call_stack.pop();
					processor->call_stack.pop();
				}
	}
	else if (rpn_obj.type_signature == "int&::int::operator=::(::double::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
					else {
						processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int32 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float64;
						size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
						processor->call_stack.stack[addr].data = processor->call_stack.top().data;
						processor->call_stack.pop();
						processor->call_stack.pop();
					}
	}
	//int operator[]
	else if (rpn_obj.type_signature=="int&::int::operator[]::(::int::)") {
		int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size()-2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int32;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig*right_;
		processor->call_stack.pop();
	}
	else {
		return 1;
	}
	return 0;
}

//--------------------------------------------------
//					| __ )/  _  \/  _ \| |
//					|  _ \| | | || | | | |
//					| |_)|| |_| || |_| | |___
//					|____/\_____/\____/|_____|
//--------------------------------------------------
size_t Ariphmetic_module::bool_calc(Lexem& rpn_obj) {
	Lexem end_of_block("", unknown_name, unknown_name, 0, "", "");
	Lexem main_data("", unknown_name, unknown_name, 0, "", "");
	Lexem begin_of_block("", unknown_name, unknown_name, 0, "", "");
	MemoryBlock mem;
	std::vector<Lexem> data;
	//bool +
	if (rpn_obj.type_signature == "bool::bool::operator+::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator+::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator+::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator+::(::double::)") {
		bool left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator+::(::float::)") {
		bool left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//bool *
	else if (rpn_obj.type_signature == "bool::bool::operator*::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator*::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator*::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator*::(::double::)") {
		bool left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator*::(::float::)") {
		bool left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//bool -
	else if (rpn_obj.type_signature == "bool::bool::operator-::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator-::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator-::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator-::(::double::)") {
		bool left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator-::(::float::)") {
		bool left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//bool /
	else if (rpn_obj.type_signature == "bool::bool::operator/::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator/::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator/::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator/::(::double::)") {
		bool left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator/::(::float::)") {
		bool left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//bool &
	else if (rpn_obj.type_signature == "bool::bool::operator&::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ & right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator&::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ & right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator&::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ & right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator&::(::double::)") {
		throw  j_error("Nelzya & between int and double");
	}
	else if (rpn_obj.type_signature == "bool::bool::operator&::(::float::)") {
		throw  j_error("Nelzya & between int and float");
	}
	//bool |
	else if (rpn_obj.type_signature == "bool::bool::operator|::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ | right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator|::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ | right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator|::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ | right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator|::(::double::)") {
		throw  j_error("Nelzya | between int and double");
	}
	else if (rpn_obj.type_signature == "bool::bool::operator|::(::float::)") {
		throw  j_error("Nelzya | between int and float");
	}
	//bool ^
	else if (rpn_obj.type_signature == "bool::bool::operator^::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ ^ right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator^::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ ^ right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator^::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ ^ right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator^::(::double::)") {
		throw  j_error("Nelzya ^ between bool and double");
	}
	else if (rpn_obj.type_signature == "bool::bool::operator^::(::float::)") {
		throw  j_error("Nelzya ^ between bool and float");
	}
	//bool <
	else if (rpn_obj.type_signature == "bool::bool::operator<::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator<::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator<::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator<::(::double::)") {
		bool left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator<::(::float::)") {
		bool left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//bool <=
	else if (rpn_obj.type_signature == "bool::bool::operator<=::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator<=::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator<=::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator<=::(::double::)") {
		bool left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator<=::(::float::)") {
		bool left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//bool >
	else if (rpn_obj.type_signature == "bool::bool::operator>::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator>::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator>::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator>::(::double::)") {
		bool left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator>::(::float::)") {
		bool left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//bool >=
	else if (rpn_obj.type_signature == "bool::bool::operator>=::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator>=::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator>=::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator>=::(::double::)") {
		bool left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator>=::(::float::)") {
		bool left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//bool ==
	else if (rpn_obj.type_signature == "bool::bool::operator==::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator==::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator==::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator==::(::double::)") {
		bool left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator==::(::float::)") {
		bool left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//bool !=
	else if (rpn_obj.type_signature == "bool::bool::operator!=::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator!=::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator!=::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator!=::(::double::)") {
		bool left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator!=::(::float::)") {
		bool left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//bool &&
	else if (rpn_obj.type_signature == "bool::bool::operator&&::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator&&::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator&&::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator&&::(::double::)") {
		bool left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator&&::(::float::)") {
		bool left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//bool ||
	else if (rpn_obj.type_signature == "bool::bool::operator||::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator||::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator||::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator||::(::double::)") {
		bool left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator||::(::float::)") {
		bool left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//bool !
	else if (rpn_obj.type_signature == "bool::operator!::(::bool::)")
	{
		bool arg;
		if (processor->call_stack.stack.back().title.link) {
			arg = processor->call_stack.stack[processor->call_stack.stack.back().title.link].data[0].cs_int8;
		}
		else {
			arg = processor->call_stack.stack.back().data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _char_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = !arg;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//bool %
	else if (rpn_obj.type_signature == "bool::bool::operator%::(::int::)")
	{
		bool left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ % right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator%::(::char::)")
	{
		bool left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ % right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator%::(::long_long::)")
	{
		bool left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ % right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::bool::operator%::(::double::)") {
		throw j_error("ostatok int na double nelzya!");
	}
	else if (rpn_obj.type_signature == "bool::bool::operator%::(::float::)") {
		throw j_error("ostatok int na float nelzya!");
	}
	//ostream bool
	else if (rpn_obj.type_signature == "ostream&::operator<<::(::ostream&::bool::)") {
		bool arg;
		if (processor->call_stack.stack.back().title.link) {
			arg = processor->call_stack.stack[processor->call_stack.stack.back().title.link].data[0].cs_int8;
		}
		else {
			arg = processor->call_stack.stack.back().data[0].cs_int8;
		}
		std::cout << arg;
		processor->call_stack.pop();
	}
	//istream bool
	else if (rpn_obj.type_signature == "istream&::operator>>::(::istream&::bool::)") {
		long long index = 0;
		if (processor->call_stack.stack.back().title.link) {
			index = processor->call_stack.stack.back().title.link;
		}
		else {
			for (long long c = processor->call_stack.size() - 2; c > -1; c--) {
				if (processor->call_stack.stack[c].title.text == processor->call_stack.top().title.text) {
					index = c;
					break;
				}
			}
		}
		std::cin >> processor->call_stack.stack[index].data[0].cs_int8;
		processor->call_stack.stack[index].data[0].cs_int32 = processor->call_stack.stack[index].data[0].cs_int64 = processor->call_stack.stack[index].data[0].cs_int8;
		processor->call_stack.pop();
	}
	//bool copy operator
	else if (rpn_obj.type_signature == "bool&::bool::operator=::(::int::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int32;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int32;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "bool&::bool::operator=::(::char::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			//processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8;
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
		else {
			//processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "bool&::bool::operator=::(::long_long::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int64;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int64;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "bool&::bool::operator=::(::float::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float32;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float32;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "bool&::bool::operator=::(::double::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float64;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float64;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	//bool operator[]
	else if (rpn_obj.type_signature == "bool&::bool::operator[]::(::int::)") {
		int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int32;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig * right_;
		processor->call_stack.pop();
	}
	else {
		return 1;
	}
	return 0;
}

			//--------------------------------------------------
			//					/ ___| | | |   / \   |  _ \
			//					| |  | |_| |  / _ \  | |_) |
			//					| |__|  _  | / ___ \ |  _ <
			//					\____|_| |_|/__/ \__\| | \_\
			//--------------------------------------------------
size_t Ariphmetic_module::char_calc(Lexem& rpn_obj) {
	Lexem end_of_block("", unknown_name, unknown_name, 0, "", "");
	Lexem main_data("", unknown_name, unknown_name, 0, "", "");
	Lexem begin_of_block("", unknown_name, unknown_name, 0, "", "");
	MemoryBlock mem;
	std::vector<Lexem> data;
	//char +
	if (rpn_obj.type_signature == "char::char::operator+::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator+::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator+::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator+::(::double::)") {
		char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator+::(::float::)") {
		char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//char *
	else if (rpn_obj.type_signature == "char::char::operator*::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator*::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator*::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator*::(::double::)") {
		char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator*::(::float::)") {
		char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//char -
	else if (rpn_obj.type_signature == "char::char::operator-::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator-::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator-::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator-::(::double::)") {
		char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator-::(::float::)") {
		char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//char /
	else if (rpn_obj.type_signature == "char::char::operator/::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator/::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator/::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator/::(::double::)") {
		char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator/::(::float::)") {
		char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//char &
	else if (rpn_obj.type_signature == "char::char::operator&::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ & right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator&::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ & right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator&::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ & right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator&::(::double::)") {
		throw  j_error("Nelzya & between int and double");
	}
	else if (rpn_obj.type_signature == "char::char::operator&::(::float::)") {
		throw  j_error("Nelzya & between int and float");
	}
	//char |
	else if (rpn_obj.type_signature == "char::char::operator|::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ | right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator|::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ | right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator|::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ | right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator|::(::double::)") {
		throw  j_error("Nelzya | between int and double");
	}
	else if (rpn_obj.type_signature == "char::char::operator|::(::float::)") {
		throw  j_error("Nelzya | between int and float");
	}
	//char ^
	else if (rpn_obj.type_signature == "char::char::operator^::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ ^ right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator^::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ ^ right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator^::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ ^ right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator^::(::double::)") {
		throw  j_error("Nelzya ^ between bool and double");
	}
	else if (rpn_obj.type_signature == "char::char::operator^::(::float::)") {
		throw  j_error("Nelzya ^ between bool and float");
	}
	//char <
	else if (rpn_obj.type_signature == "bool::char::operator<::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator<::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator<::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator<::(::double::)") {
		char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator<::(::float::)") {
		char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//char <=
	else if (rpn_obj.type_signature == "bool::char::operator<=::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator<=::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator<=::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator<=::(::double::)") {
		char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator<=::(::float::)") {
		char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//char >
	else if (rpn_obj.type_signature == "bool::char::operator>::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator>::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator>::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator>::(::double::)") {
		char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator>::(::float::)") {
		char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//char >=
	else if (rpn_obj.type_signature == "bool::char::operator>=::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator>=::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator>=::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator>=::(::double::)") {
		char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator>=::(::float::)") {
		char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//char ==
	else if (rpn_obj.type_signature == "bool::char::operator==::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator==::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator==::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator==::(::double::)") {
		char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator==::(::float::)") {
		char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//char !=
	else if (rpn_obj.type_signature == "bool::char::operator!=::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator!=::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator!=::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator!=::(::double::)") {
		char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator!=::(::float::)") {
		char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//char &&
	else if (rpn_obj.type_signature == "bool::char::operator&&::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator&&::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator&&::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator&&::(::double::)") {
		char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator&&::(::float::)") {
		char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//char ||
	else if (rpn_obj.type_signature == "bool::char::operator||::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator||::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator||::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator||::(::double::)") {
		char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::char::operator||::(::float::)") {
		char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//char !
	else if (rpn_obj.type_signature == "bool::operator!::(::char::)")
	{
		char arg;
		if (processor->call_stack.stack.back().title.link) {
			arg = processor->call_stack.stack[processor->call_stack.stack.back().title.link].data[0].cs_int8;
		}
		else {
			arg = processor->call_stack.stack.back().data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _char_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = !arg;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//char %
	else if (rpn_obj.type_signature == "char::char::operator%::(::int::)")
	{
		char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ % right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator%::(::char::)")
	{
		char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ % right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator%::(::long_long::)")
	{
		char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ % right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "char::char::operator%::(::double::)") {
		throw j_error("ostatok int na double nelzya!");
	}
	else if (rpn_obj.type_signature == "char::char::operator%::(::float::)") {
		throw j_error("ostatok int na float nelzya!");
	}
	//ostream char
	else if (rpn_obj.type_signature == "ostream&::operator<<::(::ostream&::char::)") {
		char arg;
		if (processor->call_stack.stack.back().title.link) {
			arg = processor->call_stack.stack[processor->call_stack.stack.back().title.link].data[0].cs_int8;
		}
		else {
			arg = processor->call_stack.stack.back().data[0].cs_int8;
		}
		std::cout << arg;
		processor->call_stack.pop();
	}
	//istream char
	else if (rpn_obj.type_signature == "istream&::operator>>::(::istream&::char::)") {
		long long index = 0;
		if (processor->call_stack.stack.back().title.link) {
			index = processor->call_stack.stack.back().title.link;
		}
		else {
			for (long long c = processor->call_stack.size() - 2; c > -1; c--) {
				if (processor->call_stack.stack[c].title.text == processor->call_stack.top().title.text) {
					index = c;
					break;
				}
			}
		}
		std::cin >> processor->call_stack.stack[index].data[0].cs_int8;
		processor->call_stack.stack[index].data[0].cs_int32 = processor->call_stack.stack[index].data[0].cs_int64 = processor->call_stack.stack[index].data[0].cs_int8;
		processor->call_stack.pop();
	}
	//char copy operator
	else if (rpn_obj.type_signature == "char&::char::operator=::(::int::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int32;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int32;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "char&::char::operator=::(::char::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			//processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8;
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
		else {
			//processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "char&::char::operator=::(::long_long::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int64;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int64;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "char&::char::operator=::(::float::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float32;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float32;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "char&::char::operator=::(::double::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float64;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float64;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	//char operator[]
	else if (rpn_obj.type_signature == "char&::char::operator[]::(::int::)") {
		int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int32;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig * right_;
		processor->call_stack.pop();
	}
	else {
		return 1;
	}
	return 0;
}

//--------------------------------------------------
//					| ___| |   / _ \  / \  |_   _|
//					| |_ | |  | | | |/ _ \   | |
//					|  _|| |__| |_| / ___ \  | |
//					|_|  |_____\__ /__/ \__\_|_|
// -------------------------------------------------

size_t Ariphmetic_module::float_calc(Lexem& rpn_obj) {
	Lexem end_of_block("", unknown_name, unknown_name, 0, "", "");
	Lexem main_data("", unknown_name, unknown_name, 0, "", "");
	Lexem begin_of_block("", unknown_name, unknown_name, 0, "", "");
	MemoryBlock mem;
	std::vector<Lexem> data;
	//float +
	if (rpn_obj.type_signature == "float::float::operator+::(::int::)")
	{
		float left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator+::(::char::)")
	{
		float left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator+::(::long_long::)")
	{
		float left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator+::(::double::)") {
		float left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator+::(::float::)") {
		float left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//float *
	else if (rpn_obj.type_signature == "float::float::operator*::(::int::)")
	{
		float left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator*::(::char::)")
	{
		float left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator*::(::long_long::)")
	{
		float left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator*::(::double::)") {
		float left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator*::(::float::)") {
		float left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//float -
	else if (rpn_obj.type_signature == "float::float::operator-::(::int::)")
	{
		float left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator-::(::char::)")
	{
		float left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator-::(::long_long::)")
	{
		float left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator-::(::double::)") {
		float left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator-::(::float::)") {
		float left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//float /
	else if (rpn_obj.type_signature == "float::float::operator/::(::int::)")
	{
		float left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator/::(::char::)")
	{
		float left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator/::(::long_long::)")
	{
		float left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator/::(::double::)") {
		float left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "float::float::operator/::(::float::)") {
		float left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//float &
	else if (rpn_obj.type_signature == "float::float::operator&::(::int::)")
	{
		throw j_error("cant float & ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator&::(::char::)")
	{
		throw j_error("cant float & ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator&::(::long_long::)")
	{
		throw j_error("cant float & ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator&::(::double::)") {
		throw j_error("cant float & ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator&::(::float::)") {
		throw j_error("cant float & ..");
	}
	//float |
	else if (rpn_obj.type_signature == "float::float::operator|::(::int::)")
	{
		throw j_error("cant float | ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator|::(::char::)")
	{
		throw j_error("cant float | ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator|::(::long_long::)")
	{
		throw j_error("cant float | ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator|::(::double::)") {
		throw j_error("cant float | ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator|::(::float::)") {
		throw j_error("cant float | ..");
	}
	//float ^
	else if (rpn_obj.type_signature == "float::float::operator^::(::int::)")
	{
		throw j_error("cant float ^ ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator^::(::char::)")
	{
		throw j_error("cant float ^ ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator^::(::long_long::)")
	{
		throw j_error("cant float ^ ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator^::(::double::)") {
		throw j_error("cant float ^ ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator^::(::float::)") {
		throw j_error("cant float ^ ..");
	}
	//float <
	else if (rpn_obj.type_signature == "bool::float::operator<::(::int::)")
	{
		float left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator<::(::char::)")
	{
		float left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator<::(::long_long::)")
	{
		float left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator<::(::double::)") {
		float left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator<::(::float::)") {
		float left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//float <=
	else if (rpn_obj.type_signature == "bool::float::operator<=::(::int::)")
	{
		float left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator<=::(::char::)")
	{
		float left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator<=::(::long_long::)")
	{
		float left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator<=::(::double::)") {
		float left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator<=::(::float::)") {
		float left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//float >
	else if (rpn_obj.type_signature == "bool::float::operator>::(::int::)")
	{
		float left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator>::(::char::)")
	{
		float left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator>::(::long_long::)")
	{
		float left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator>::(::double::)") {
		float left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator>::(::float::)") {
		float left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//float >=
	else if (rpn_obj.type_signature == "bool::float::operator>=::(::int::)")
	{
		float left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator>=::(::char::)")
	{
		float left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator>=::(::long_long::)")
	{
		float left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator>=::(::double::)") {
		float left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator>=::(::float::)") {
		float left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//float ==
	else if (rpn_obj.type_signature == "bool::float::operator==::(::int::)")
	{
		float left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator==::(::char::)")
	{
		float left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator==::(::long_long::)")
	{
		float left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator==::(::double::)") {
		float left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator==::(::float::)") {
		float left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//float !=
	else if (rpn_obj.type_signature == "bool::float::operator!=::(::int::)")
	{
		float left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator!=::(::char::)")
	{
		float left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator!=::(::long_long::)")
	{
		float left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator!=::(::double::)") {
		float left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator!=::(::float::)") {
		float left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//float &&
	else if (rpn_obj.type_signature == "bool::float::operator&&::(::int::)")
	{
		float left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator&&::(::char::)")
	{
		float left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator&&::(::long_long::)")
	{
		float left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator&&::(::double::)") {
		float left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator&&::(::float::)") {
		float left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//float ||
	else if (rpn_obj.type_signature == "bool::float::operator||::(::int::)")
	{
		float left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator||::(::char::)")
	{
		float left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator||::(::long_long::)")
	{
		float left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator||::(::double::)") {
		float left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::float::operator||::(::float::)") {
		float left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//float !
	else if (rpn_obj.type_signature == "bool::operator!::(::float::)")
	{
		bool arg;
		if (processor->call_stack.stack.back().title.link) {
			arg = processor->call_stack.stack[processor->call_stack.stack.back().title.link].data[0].cs_float32;
		}
		else {
			arg = processor->call_stack.stack.back().data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _char_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = !arg;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//float %
	else if (rpn_obj.type_signature == "float::float::operator%::(::int::)")
	{
		throw j_error("cant float % ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator%::(::char::)")
	{
		throw j_error("cant float % ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator%::(::long_long::)")
	{
		throw j_error("cant float % ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator%::(::double::)") {
		throw j_error("cant float % ..");
	}
	else if (rpn_obj.type_signature == "float::float::operator%::(::float::)") {
		throw j_error("cant float % ..");
	}
	//ostream float
	else if (rpn_obj.type_signature == "ostream&::operator<<::(::ostream&::float::)") {
		float arg;
		if (processor->call_stack.stack.back().title.link) {
			arg = processor->call_stack.stack[processor->call_stack.stack.back().title.link].data[0].cs_float32;
		}
		else {
			arg = processor->call_stack.stack.back().data[0].cs_float32;
		}
		std::cout << arg;
		processor->call_stack.pop();
	}
	//istream float
	else if (rpn_obj.type_signature == "istream&::operator>>::(::istream&::float::)") {
		long long index = 0;
		if (processor->call_stack.stack.back().title.link) {
			index = processor->call_stack.stack.back().title.link;
		}
		else {
			for (long long c = processor->call_stack.size() - 2; c > -1; c--) {
				if (processor->call_stack.stack[c].title.text == processor->call_stack.top().title.text) {
					index = c;
					break;
				}
			}
		}
		std::cin >> processor->call_stack.stack[index].data[0].cs_float32;
		processor->call_stack.stack[index].data[0].cs_float64 = processor->call_stack.stack[index].data[0].cs_float32;
		processor->call_stack.pop();
	}
	//float copy operator
	else if (rpn_obj.type_signature == "float&::float::operator=::(::int::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float32 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int32;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float32 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int32;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "float&::float::operator=::(::char::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float32 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float32 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "float&::float::operator=::(::long_long::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float32 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int64;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float32 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int64;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "float&::float::operator=::(::float::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float32 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float32;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float32 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float32;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "float&::float::operator=::(::double::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float32 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float64;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float32 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float64;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	//float operator[]
	else if (rpn_obj.type_signature == "float&::float::operator[]::(::int::)") {
		int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int32;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig * right_;
		processor->call_stack.pop();
	}
	else {
		return 1;
	}
	return 0;
}
//------------------------------------------
//|  _ \_/ _ \| | | | __ )| |   | ____|
//| | | | | | | | | |  _ \| |   |  _|
//| |_| | |_| | |_| | |_) | |___| |___
//|____/_\___/_\___/|____/|_____|_____|
//-------------------------------------------

size_t Ariphmetic_module::double_calc(Lexem& rpn_obj) {
	Lexem end_of_block("", unknown_name, unknown_name, 0, "", "");
	Lexem main_data("", unknown_name, unknown_name, 0, "", "");
	Lexem begin_of_block("", unknown_name, unknown_name, 0, "", "");
	MemoryBlock mem;
	std::vector<Lexem> data;
	//double +
	if (rpn_obj.type_signature == "double::double::operator+::(::int::)")
	{
		double left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator+::(::char::)")
	{
		double left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator+::(::long_long::)")
	{
		double left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator+::(::double::)") {
		double left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator+::(::float::)") {
		double left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//double *
	else if (rpn_obj.type_signature == "double::double::operator*::(::int::)")
	{
		double left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator*::(::char::)")
	{
		double left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator*::(::long_long::)")
	{
		double left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator*::(::double::)") {
		double left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator*::(::float::)") {
		double left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//double -
	else if (rpn_obj.type_signature == "double::double::operator-::(::int::)")
	{
		double left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator-::(::char::)")
	{
		double left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator-::(::long_long::)")
	{
		double left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator-::(::double::)") {
		double left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator-::(::float::)") {
		double left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//double /
	else if (rpn_obj.type_signature == "double::double::operator/::(::int::)")
	{
		double left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator/::(::char::)")
	{
		double left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator/::(::long_long::)")
	{
		double left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator/::(::double::)") {
		double left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "double::double::operator/::(::float::)") {
		double left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//double &
	else if (rpn_obj.type_signature == "double::double::operator&::(::int::)")
	{
		throw j_error("cant float & ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator&::(::char::)")
	{
		throw j_error("cant float & ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator&::(::long_long::)")
	{
		throw j_error("cant float & ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator&::(::double::)") {
		throw j_error("cant float & ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator&::(::float::)") {
		throw j_error("cant float & ..");
	}
	//double |
	else if (rpn_obj.type_signature == "double::double::operator|::(::int::)")
	{
		throw j_error("cant float | ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator|::(::char::)")
	{
		throw j_error("cant float | ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator|::(::long_long::)")
	{
		throw j_error("cant float | ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator|::(::double::)") {
		throw j_error("cant float | ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator|::(::float::)") {
		throw j_error("cant float | ..");
	}
	//double ^
	else if (rpn_obj.type_signature == "double::double::operator^::(::int::)")
	{
		throw j_error("cant float ^ ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator^::(::char::)")
	{
		throw j_error("cant float ^ ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator^::(::long_long::)")
	{
		throw j_error("cant float ^ ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator^::(::double::)") {
		throw j_error("cant float ^ ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator^::(::float::)") {
		throw j_error("cant float ^ ..");
	}
	//double <
	else if (rpn_obj.type_signature == "bool::double::operator<::(::int::)")
	{
		double left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator<::(::char::)")
	{
		double left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator<::(::long_long::)")
	{
		double left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator<::(::double::)") {
		double left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator<::(::float::)") {
		double left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//double <=
	else if (rpn_obj.type_signature == "bool::double::operator<=::(::int::)")
	{
		double left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator<=::(::char::)")
	{
		double left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator<=::(::long_long::)")
	{
		double left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator<=::(::double::)") {
		double left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator<=::(::float::)") {
		double left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//double >
	else if (rpn_obj.type_signature == "bool::double::operator>::(::int::)")
	{
		double left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator>::(::char::)")
	{
		double left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator>::(::long_long::)")
	{
		double left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator>::(::double::)") {
		double left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator>::(::float::)") {
		double left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//double >=
	else if (rpn_obj.type_signature == "bool::double::operator>=::(::int::)")
	{
		double left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator>=::(::char::)")
	{
		double left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator>=::(::long_long::)")
	{
		double left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator>=::(::double::)") {
		double left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator>=::(::float::)") {
		double left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//double ==
	else if (rpn_obj.type_signature == "bool::double::operator==::(::int::)")
	{
		double left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator==::(::char::)")
	{
		double left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator==::(::long_long::)")
	{
		double left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator==::(::double::)") {
		double left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator==::(::float::)") {
		double left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//double !=
	else if (rpn_obj.type_signature == "bool::double::operator!=::(::int::)")
	{
		double left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator!=::(::char::)")
	{
		double left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator!=::(::long_long::)")
	{
		double left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator!=::(::double::)") {
		double left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator!=::(::float::)") {
		double left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//double &&
	else if (rpn_obj.type_signature == "bool::double::operator&&::(::int::)")
	{
		double left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator&&::(::char::)")
	{
		double left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator&&::(::long_long::)")
	{
		double left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator&&::(::double::)") {
		double left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator&&::(::float::)") {
		double left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//double ||
	else if (rpn_obj.type_signature == "bool::double::operator||::(::int::)")
	{
		double left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator||::(::char::)")
	{
		double left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator||::(::long_long::)")
	{
		double left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator||::(::double::)") {
		double left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::double::operator||::(::float::)") {
		double left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_float64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//double !
	else if (rpn_obj.type_signature == "bool::operator!::(::double::)")
	{
		bool arg;
		if (processor->call_stack.stack.back().title.link) {
			arg = processor->call_stack.stack[processor->call_stack.stack.back().title.link].data[0].cs_float64;
		}
		else {
			arg = processor->call_stack.stack.back().data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _char_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = !arg;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//double %
	else if (rpn_obj.type_signature == "double::double::operator%::(::int::)")
	{
		throw j_error("cant float % ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator%::(::char::)")
	{
		throw j_error("cant float % ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator%::(::long_long::)")
	{
		throw j_error("cant float % ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator%::(::double::)") {
		throw j_error("cant float % ..");
	}
	else if (rpn_obj.type_signature == "double::double::operator%::(::float::)") {
		throw j_error("cant float % ..");
	}
	//ostream double
	else if (rpn_obj.type_signature == "ostream&::operator<<::(::ostream&::double::)") {
		double arg;
		if (processor->call_stack.stack.back().title.link) {
			arg = processor->call_stack.stack[processor->call_stack.stack.back().title.link].data[0].cs_float64;
		}
		else {
			arg = processor->call_stack.stack.back().data[0].cs_float64;
		}
		std::cout << arg;
		processor->call_stack.pop();
	}
	//istream double
	else if (rpn_obj.type_signature == "istream&::operator>>::(::istream&::double::)") {
		long long index = 0;
		if (processor->call_stack.stack.back().title.link) {
			index = processor->call_stack.stack.back().title.link;
		}
		else {
			for (long long c = processor->call_stack.size() - 2; c > -1; c--) {
				if (processor->call_stack.stack[c].title.text == processor->call_stack.top().title.text) {
					index = c;
					break;
				}
			}
		}
		std::cin >> processor->call_stack.stack[index].data[0].cs_float64;
		processor->call_stack.stack[index].data[0].cs_float32 = processor->call_stack.stack[index].data[0].cs_float64;
		processor->call_stack.pop();
	}
	//double copy operator
	else if (rpn_obj.type_signature == "double&::double::operator=::(::int::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float64 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int32;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float64 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int32;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "double&::double::operator=::(::char::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float64 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float64 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "double&::double::operator=::(::long_long::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float64 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int64;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float64 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int64;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "double&::double::operator=::(::float::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float64 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float32;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float64 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float32;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "double&::double::operator=::(::double::)") {
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float64 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float64;
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
		else {
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float64 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float64;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	//double operator[]
	else if (rpn_obj.type_signature == "double&::double::operator[]::(::int::)") {
		int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int32;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig * right_;
		processor->call_stack.pop();
	}
	else {
		return 1;
	}
	return 0;
}

void Ariphmetic_module::Calculate(std::vector<Lexem>& lexem_queue, Lexem_Queue_Assembler& lexem_queue_asm) {

	Lexem end_of_block("", unknown_name, unknown_name, 0, "","");
	Lexem main_data("", unknown_name, unknown_name, 0, "","");
	Lexem begin_of_block("", unknown_name, unknown_name, 0, "","");
	MemoryBlock mem;
	std::vector<Lexem> data;
	bool found = 0;
	std::stack<Lexem> obj;
	for (size_t i = 0; i < rpn_form.size(); i++) {

		if (rpn_form[i].type == _data_type_) continue;

		if (in(rpn_form[i].type, { double_literal,int_literal, var_name,new_var,char_symbol,new_static_array,static_array })) {

			switch (rpn_form[i].type)
			{
			case int_literal:
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem(rpn_form[i].text, int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem(rpn_form[i].text, _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = std::stoi(rpn_form[i].text);
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.push(mem);
				break;
			case double_literal:
				end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block","double");
				main_data = Lexem(rpn_form[i].text, double_literal, _double_, 0, "double","double");
				begin_of_block = Lexem(rpn_form[i].text, _timed_memory_block_begin, _double_, 1, "double","double");
				main_data.cs_float32 = main_data.cs_float64 = std::stod(rpn_form[i].text);
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.push(mem);
				break;
			case char_symbol:
				end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
				main_data = Lexem(rpn_form[i].text, char_symbol, _char_, 0, "char", "char");
				begin_of_block = Lexem(rpn_form[i].text, _timed_memory_block_begin, _double_, 1, "char", "char");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = rpn_form[i].text[0];
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.push(mem);
				break;
			case new_var:

				end_of_block = Lexem("end block", _timed_memory_block_end, rpn_form[i].data_type, 1, "end block", rpn_form[i].returned_type);
				data = std::vector<Lexem>(processor->Class_names_list.get_class_size(rpn_form[i].type_signature));
				begin_of_block = Lexem(rpn_form[i].text, _timed_memory_block_begin, rpn_form[i].data_type, processor->Class_names_list.get_class_size(rpn_form[i].type_signature), rpn_form[i].type_signature,rpn_form[i].returned_type);
				mem.title = begin_of_block;
				mem.data = data;
				mem.end = end_of_block;
				mem.sz = begin_of_block.arg_c;
				mem.new_var = true;
				processor->call_stack.push(mem);
				if (!processor->GLOBAL_SCAN) {
					processor->GLOBAL_SECTOR_LAST++;
				}
				break;
			case var_name:

				found = 0;
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
			case new_static_array:

				end_of_block = Lexem("end block", _timed_memory_block_end, rpn_form[i].data_type, 1, "end block", rpn_form[i].returned_type);
				data = std::vector<Lexem>(processor->Class_names_list.get_class_size(rpn_form[i].type_signature));
				begin_of_block = Lexem(rpn_form[i].text, _timed_memory_block_begin, rpn_form[i].data_type, processor->Class_names_list.get_class_size(rpn_form[i].type_signature), rpn_form[i].type_signature, rpn_form[i].returned_type);
				mem.title = begin_of_block;
				mem.data = data;
				mem.end = end_of_block;
				mem.sz = begin_of_block.arg_c;
				mem.new_var = true;
				processor->call_stack.push(mem);
				if (!processor->GLOBAL_SCAN) {
					processor->GLOBAL_SECTOR_LAST++;
				}
				break;
			case static_array:

				found = 0;
				long long uwu = -1;
				for (long long u = processor->call_stack.size() - 1; u > -1; u--) {
					if (processor->call_stack.stack[u].title.text == rpn_form[i].text && processor->call_stack.stack[u].new_var) {
						mem = processor->call_stack.stack[u];
						uwu = u;
						found = 1;
						break;
					}
				}

				if (!found)
					throw j_error("Cant find variable " + rpn_form[i].text);
				for (long long u = uwu; u > -1; u--) {
					if (processor->call_stack.stack[u].title.text == processor->call_stack.stack[uwu].title.text) {
						uwu = u;
					}
					else {
						break;
					}
				}
				
				mem.new_var = false;
				mem.title.link = uwu;
				if (processor->call_stack.stack[uwu].title.link) {
					mem.title.link = processor->call_stack.stack[uwu].title.link;
				}
				processor->call_stack.push(mem);
				break;
			}
		}
		else {

			size_t argc = rpn_form[i].arg_c;
			//types definition-------------------------------
			if (rpn_form[i].type_signature != "operator[mem]") {
				rpn_form[i].type_signature += "::(::";
				int coef = 1, coef2 = 0;;
				if (in(rpn_form[i].type, { call_function,operator_logic_not,_operator_is_,_operator_os_ })) {
					coef = 0;
					if (in(rpn_form[i].type, { _operator_is_,_operator_os_ })) {
						rpn_form[i].type_signature += rpn_form[i].returned_type + "::";
						coef2 = 1;
					}
				}

				for (size_t ind = processor->call_stack.size() - argc + coef + coef2; ind < processor->call_stack.size(); ind++) {
					rpn_form[i].type_signature += processor->call_stack.stack[ind].title.returned_type + "::";
				}
				rpn_form[i].type_signature += ")";

				if (coef)
					rpn_form[i].type_signature = processor->call_stack.stack[processor->call_stack.size() - argc].title.returned_type + "::" + rpn_form[i].type_signature;

				if (!rpn_form[i].returned_type.size()) {
					rpn_form[i].returned_type = operators_ret_types[rpn_form[i].type_signature];
				}
				rpn_form[i].type_signature = rpn_form[i].returned_type + "::" + rpn_form[i].type_signature;
				//----------------------------------------------------

				//----------------------------------------------------
			}
			if (in(rpn_form[i].type, { _operator_os_ })) {
				argc--;
			}
			size_t result_signal = 1;
			if (!in(rpn_form[i].type, {53}))
			if (rpn_form[i].type == _operator_os_ && i>0 && rpn_form[i-1].type == _operator_os_) {
				std::cout << ' ';
				result_signal = 0;
			}
			else if (processor->call_stack.stack[processor->call_stack.size() - argc].title.returned_type == "int") {
				result_signal = int_calc(rpn_form[i]);
			}
			else if (processor->call_stack.stack[processor->call_stack.size() - argc].title.returned_type == "bool") {
				result_signal = bool_calc(rpn_form[i]);
			}
			else if (processor->call_stack.stack[processor->call_stack.size() - argc].title.returned_type == "char") {
				result_signal = char_calc(rpn_form[i]);
			}
			

			if(result_signal)
			//return
			if (rpn_form[i].type == _return_) {

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
			//new static memory arrays //operator[mem]
			else if (rpn_form[i].type_signature=="operator[mem]") {
				size_t cnt = 0;//считаем кол-во с тем же именем, а потом продублируем cnt*(n-1) раз
				long long index_first = -1;
				for (long long i = processor->call_stack.size() - 2; i > -1; i--) {
					if (processor->call_stack.stack[i].title.text != processor->call_stack.stack[processor->call_stack.size() - 2].title.text) {
						break;
					}
					index_first = i;
					cnt++;
				}
				processor->call_stack.stack[index_first].title.static_array_sz.push_back(processor->call_stack.top().data[0].cs_int64);
				cnt *= processor->call_stack.top().data[0].cs_int64 - 1;
				processor->call_stack.pop();
				mem = processor->call_stack.top();
				for (size_t i = 0; i < cnt; i++) {
					processor->call_stack.push(mem);
				}
			}
			//if
			else if (rpn_form[i].type == _if_) {
				bool arg;
				
				if (processor->call_stack.top().title.link) {
					main_data = processor->call_stack.stack[processor->call_stack.top().title.link].data[0];
				}
				else {
					main_data = processor->call_stack.top().data[0];
				}

					switch (processor->call_stack.top().title.data_type)
					{
					case _int_:
						arg = main_data.cs_int32;
						break;
					case _long_long_:
						arg = main_data.cs_int64;
						break;
					case _bool_:
						arg = main_data.cs_int8;
						break;
					case _float_:
						arg = main_data.cs_float32;
						break;
					case _double_:
						arg = main_data.cs_float64;
						break;
					case _char_:
						arg = main_data.cs_int8;
						break;
					}					
				processor->if_signals.push_back((bool)arg);
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
				if (func_addr > processor->code_segment.size()) {
					throw j_error("Unknown function: " + rpn_form[i].type_signature);
				}
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