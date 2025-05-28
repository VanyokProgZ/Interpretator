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

	{"bool::operator&::(::int::)", "bool"},
	{"bool::operator&::(::char::)", "bool"},
	{"bool::operator&::(::long_long::)", "bool"},
	{"bool::operator&::(::bool::)", "bool"},

	{"bool::operator|::(::int::)", "bool"},
	{"bool::operator|::(::char::)", "bool"},
	{"bool::operator|::(::long_long::)", "bool"},
	{"bool::operator|::(::bool::)", "bool"},

	{"bool::operator^::(::int::)", "bool"},
	{"bool::operator^::(::char::)", "bool"},
	{"bool::operator^::(::long_long::)", "bool"},
	{"bool::operator^::(::bool::)", "bool"},

	{"bool::operator-::(::)", "bool"},

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
	{"bool::operator[]::(::long_long::)", "bool&"},
	{"bool::operator[]::(::char::)", "bool&"},
	{"bool::operator[]::(::bool::)", "bool&"},

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
	{ "int::operator+::(::uchar::)", "int" },
	{"int::operator+::(::long_long::)", "int"},
	{"int::operator+::(::bool::)", "int" },

	{ "int::operator&::(::int::)", "int" },
	{ "int::operator&::(::char::)", "int" },
	{ "int::operator&::(::long_long::)", "int" },
	{ "int::operator&::(::bool::)", "int" },

	{ "int::operator|::(::int::)", "int" },
	{ "int::operator|::(::char::)", "int" },
	{ "int::operator|::(::long_long::)", "int" },
	{ "int::operator|::(::bool::)", "int" },

	{ "int::operator^::(::int::)", "int" },
	{ "int::operator^::(::char::)", "int" },
	{ "int::operator^::(::long_long::)", "int" },
	{ "int::operator^::(::bool::)", "int" },

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
	{ "int::operator-::(::uchar::)", "int" },
	{"int::operator-::(::long_long::)", "int"},
	{"int::operator-::(::bool::)", "int" },

	{ "int::operator-::(::)", "int" },

	{"int::operator*::(::int::)", "int"},
	{"int::operator*::(::float::)", "int"},
	{"int::operator*::(::double::)", "int"},
	{"int::operator*::(::char::)", "int"},
	{ "int::operator*::(::uchar::)", "int" },
	{"int::operator*::(::long_long::)", "int"},
	{"int::operator*::(::bool::)", "int" },

	{"int::operator/::(::int::)", "int"},
	{"int::operator/::(::float::)", "int"},
	{"int::operator/::(::double::)", "int"},
	{"int::operator/::(::char::)", "int"},
	{ "int::operator/::(::uchar::)", "int" },
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
	{ "int::operator[]::(::long_long::)", "int&" },
	{ "int::operator[]::(::char::)", "int&" },
	{ "int::operator[]::(::bool::)", "int&" },

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

	{"double::operator-::(::)", "double" },

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
	{ "double::operator[]::(::char::)", "double&" },
	{ "double::operator[]::(::long_long::)", "double&" },
	{ "double::operator[]::(::bool::)", "double&" },

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

	{"float::operator-::(::)", "float" },

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
	{ "float::operator[]::(::char::)", "float&" },
	{ "float::operator[]::(::bool::)", "float&" },
	{ "float::operator[]::(::long_long::)", "float&" },

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

	{ "char::operator=::(::string::)", "char&" },
	{ "char::operator=::(::int::)", "char&" },
	{ "char::operator=::(::float::)", "char&" },
	{ "char::operator=::(::double::)", "char&" },
	{ "char::operator=::(::char::)", "char&" },
	{ "char::operator=::(::long_long::)", "char&" },

	{ "char::operator&::(::int::)", "char" },
	{ "char::operator&::(::char::)", "char" },
	{ "char::operator&::(::long_long::)", "char" },
	{ "char::operator&::(::bool::)", "char" },

	{ "char::operator|::(::int::)", "char" },
	{ "char::operator|::(::char::)", "char" },
	{ "char::operator|::(::long_long::)", "char" },
	{ "char::operator|::(::bool::)", "char" },

	{ "char::operator^::(::int::)", "char" },
	{ "char::operator^::(::char::)", "char" },
	{ "char::operator^::(::long_long::)", "char" },
	{ "char::operator^::(::bool::)", "char" },

	{ "char&::operator=::(::string::)", "char&" },
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

	{"char::operator-::(::)", "char" },

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
	{ "char::operator[]::(::char::)", "char&" },
	{ "char::operator[]::(::bool::)", "char&" },
	{ "char::operator[]::(::long_long::)", "char&" },

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

	//unsigned char
	{ "uchar::operator+::(::int::)", "uchar" },
	{ "uchar::operator+::(::float::)", "uchar" },
	{ "uchar::operator+::(::double::)", "uchar" },
	{ "uchar::operator+::(::char::)", "uchar" },
	{ "uchar::operator+::(::uchar::)", "uchar" },
	{ "uchar::operator+::(::long_long::)", "uchar" },

	{ "uchar::operator=::(::string::)", "uchar&" },
	{ "uchar::operator=::(::int::)", "uchar&" },
	{ "uchar::operator=::(::float::)", "uchar&" },
	{ "uchar::operator=::(::double::)", "uchar&" },
	{ "uchar::operator=::(::char::)", "uchar&" },
	{ "uchar::operator=::(::uchar::)", "uchar&" },
	{ "uchar::operator=::(::long_long::)", "uchar&" },


	{ "uchar::operator&::(::int::)", "uchar" },
	{ "uchar::operator&::(::char::)", "uchar" },
	{ "uchar::operator&::(::uchar::)", "uchar" },
	{ "uchar::operator&::(::long_long::)", "uchar" },
	{ "uchar::operator&::(::bool::)", "uchar" },

	{ "uchar::operator|::(::int::)", "uchar" },
	{ "uchar::operator|::(::char::)", "uchar" },
	{ "uchar::operator|::(::uchar::)", "uchar" },
	{ "uchar::operator|::(::long_long::)", "uchar" },
	{ "uchar::operator|::(::bool::)", "uchar" },

	{ "uchar::operator^::(::int::)", "uchar" },
	{ "uchar::operator^::(::char::)", "uchar" },
	{ "uchar::operator^::(::uchar::)", "uchar" },
	{ "uchar::operator^::(::long_long::)", "uchar" },
	{ "uchar::operator^::(::bool::)", "uchar" },

	{ "uchar&::operator=::(::string::)", "uchar&" },
	{ "uchar&::operator=::(::int::)", "uchar&" },
	{ "uchar&::operator=::(::float::)", "uchar&" },
	{ "uchar&::operator=::(::double::)", "uchar&" },
	{ "uchar&::operator=::(::char::)", "uchar&" },
	{ "uchar&::operator=::(::uchar::)", "uchar&" },
	{ "uchar&::operator=::(::long_long::)", "uchar&" },

	{ "uchar::operator-::(::int::)", "uchar" },
	{ "uchar::operator-::(::float::)", "uchar" },
	{ "uchar::operator-::(::double::)", "uchar" },
	{ "uchar::operator-::(::char::)", "uchar" },
	{ "uchar::operator-::(::uchar::)", "uchar" },
	{ "uchar::operator-::(::long_long::)", "uchar" },

	{ "uchar::operator-::(::)", "char" },

	{ "uchar::operator*::(::int::)", "uchar" },
	{ "uchar::operator*::(::float::)", "uchar" },
	{ "uchar::operator*::(::double::)", "uchar" },
	{ "uchar::operator*::(::char::)", "uchar" },
	{ "uchar::operator*::(::uchar::)", "uchar" },
	{ "uchar::operator*::(::long_long::)", "uchar" },

	{ "uchar::operator/::(::int::)", "uchar" },
	{ "uchar::operator/::(::float::)", "uchar" },
	{ "uchar::operator/::(::double::)", "uchar" },
	{ "uchar::operator/::(::char::)", "uchar" },
	{ "uchar::operator/::(::uchar::)", "uchar" },
	{ "uchar::operator/::(::long_long::)", "uchar" },

	{ "uchar::operator>::(::int::)", "bool" },
	{ "uchar::operator>::(::float::)", "bool" },
	{ "uchar::operator>::(::double::)", "bool" },
	{ "uchar::operator>::(::char::)", "bool" },
	{ "uchar::operator>::(::uchar::)", "bool" },
	{ "uchar::operator>::(::long_long::)", "bool" },

	{ "uchar::operator<::(::int::)", "bool" },
	{ "uchar::operator<::(::float::)", "bool" },
	{ "uchar::operator<::(::double::)", "bool" },
	{ "uchar::operator<::(::char::)", "bool" },
	{ "uchar::operator<::(::uchar::)", "bool" },
	{ "uchar::operator<::(::long_long::)", "bool" },

	{ "uchar::operator>=::(::int::)", "bool" },
	{ "uchar::operator>=::(::float::)", "bool" },
	{ "uchar::operator>=::(::double::)", "bool" },
	{ "uchar::operator>=::(::char::)", "bool" },
	{ "uchar::operator>=::(::uchar::)", "bool" },
	{ "uchar::operator>=::(::long_long::)", "bool" },

	{ "uchar::operator<=::(::int::)", "bool" },
	{ "uchar::operator<=::(::float::)", "bool" },
	{ "uchar::operator<=::(::double::)", "bool" },
	{ "uchar::operator<=::(::char::)", "bool" },
	{ "uchar::operator<=::(::uchar::)", "bool" },
	{ "uchar::operator<=::(::long_long::)", "bool" },

	{ "uchar::operator&&::(::int::)", "bool" },
	{ "uchar::operator&&::(::float::)", "bool" },
	{ "uchar::operator&&::(::double::)", "bool" },
	{ "uchar::operator&&::(::char::)", "bool" },
	{ "uchar::operator&&::(::uchar::)", "bool" },
	{ "uchar::operator&&::(::long_long::)", "bool" },

	{ "uchar::operator||::(::int::)", "bool" },
	{ "uchar::operator||::(::float::)", "bool" },
	{ "uchar::operator||::(::double::)", "bool" },
	{ "uchar::operator||::(::char::)", "bool" },
	{ "uchar::operator||::(::uchar::)", "bool" },
	{ "uchar::operator||::(::long_long::)", "bool" },

	{ "operator!::(::uchar::)", "bool" },

	{ "operator?*::(::uchar*::)", "uchar" },

	{ "uchar::operator[]::(::int::)", "uchar&" },
	{ "uchar::operator[]::(::char::)", "uchar&" },
	{ "uchar::operator[]::(::bool::)", "uchar&" },
	{ "uchar::operator[]::(::long_long::)", "uchar&" },

	{ "uchar::operator!=::(::int::)", "bool" },
	{ "uchar::operator!=::(::float::)", "bool" },
	{ "uchar::operator!=::(::double::)", "bool" },
	{ "uchar::operator!=::(::char::)", "bool" },
	{ "uchar::operator!=::(::uchar::)", "bool" },
	{ "uchar::operator!=::(::long_long::)", "bool" },

	{ "uchar::operator==::(::int::)", "bool" },
	{ "uchar::operator==::(::float::)", "bool" },
	{ "uchar::operator==::(::double::)", "bool" },
	{ "uchar::operator==::(::char::)", "bool" },
	{ "uchar::operator==::(::uchar::)", "bool" },
	{ "uchar::operator==::(::long_long::)", "bool" },

	{ "uchar::operator%::(::int::)", "uchar" },
	{ "uchar::operator%::(::long_long::)", "uchar" },
	{ "uchar::operator%::(::char::)", "uchar" },
	{ "uchar::operator%::(::bool::)", "uchar" },
	{ "uchar::operator%::(::uchar::)", "uchar" },

	//long long
	{ "long_long::operator+::(::int::)", "long_long" },
	{ "long_long::operator+::(::float::)", "long_long" },
	{ "long_long::operator+::(::double::)", "long_long" },
	{ "long_long::operator+::(::char::)", "long_long" },
	{ "long_long::operator+::(::long_long::)", "long_long" },

	{ "long_long::operator&::(::int::)", "long_long" },
	{ "long_long::operator&::(::char::)", "long_long" },
	{ "long_long::operator&::(::long_long::)", "long_long" },
	{ "long_long::operator&::(::bool::)", "long_long" },

	{ "long_long::operator|::(::int::)", "long_long" },
	{ "long_long::operator|::(::char::)", "long_long" },
	{ "long_long::operator|::(::long_long::)", "long_long" },
	{ "long_long::operator|::(::bool::)", "long_long" },

	{ "long_long::operator^::(::int::)", "long_long" },
	{ "long_long::operator^::(::char::)", "long_long" },
	{ "long_long::operator^::(::long_long::)", "long_long" },
	{ "long_long::operator^::(::bool::)", "long_long" },

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

	{ "long_long::operator-::(::)", "long_long" },

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
	{ "long_long::operator[]::(::char::)", "long_long&" },
	{ "long_long::operator[]::(::long_long::)", "long_long&" },
	{ "long_long::operator[]::(::bool::)", "long_long&" },

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
	//string
	{ "string::operator=::(::char::)", "string&" },
};

Ariphmetic_module::Ariphmetic_module(const std::vector<Lexem>& rpn, Processor* p) :rpn_form(rpn), processor(p){};

			//----------------------------------------------------
			//					 |_ _| \ | |_   _|
			//					  | ||  \| | | |  
			//					  | || |\  | | |  
			//					 |___|_| \_| |_|  
			//----------------------------------------------------
size_t Ariphmetic_module::int_calc2(Lexem& rpn_obj) {//int 2
	Lexem end_of_block("", unknown_name, unknown_name, 0, "", "");
	Lexem main_data("", unknown_name, unknown_name, 0, "", "");
	Lexem begin_of_block("", unknown_name, unknown_name, 0, "", "");
	MemoryBlock mem;
	std::vector<Lexem> data;
	if (rpn_obj.type_signature == "int::int::operator+::(::uchar::)")
	{
		int left_ = 0; unsigned char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
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
	else if (rpn_obj.type_signature == "int::int::operator-::(::uchar::)")
	{
		int left_ = 0; unsigned  char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
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
	else if (rpn_obj.type_signature == "int::int::operator*::(::uchar::)")
	{
		int left_ = 0; unsigned  char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
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
	else if (rpn_obj.type_signature == "int::int::operator/::(::uchar::)")
	{
		int left_ = 0; unsigned char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
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
	else {
		return 1;
	}
	return 0;
}
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
	else if (rpn_obj.type_signature == "int::int::operator+::(::bool::)")
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
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
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
	else if (rpn_obj.type_signature == "int::int::operator*::(::bool::)")
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
	else if (rpn_obj.type_signature == "int::int::operator-::(::)")
	{
		int left_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block", "int");
		main_data = Lexem("timed obj", int_literal, _int_, 0, "int", "int");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _int_, 1, "int", "int");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = -left_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
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
	else if (rpn_obj.type_signature == "int::int::operator-::(::bool::)")
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
	else if (rpn_obj.type_signature == "int::int::operator/::(::bool::)")
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
	else if (rpn_obj.type_signature == "int::int::operator&::(::uchar::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
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
	else if (rpn_obj.type_signature == "int::int::operator&::(::bool::)")
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
	else if (rpn_obj.type_signature == "int::int::operator|::(::uchar::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
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
	else if (rpn_obj.type_signature == "int::int::operator|::(::bool::)")
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
	else if (rpn_obj.type_signature == "int::int::operator^::(::uchar::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
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
	else if (rpn_obj.type_signature == "int::int::operator^::(::bool::)")
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
	else if (rpn_obj.type_signature == "bool::int::operator<::(::bool::)")
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
	else if (rpn_obj.type_signature == "bool::int::operator<=::(::bool::)")
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
	else if (rpn_obj.type_signature == "bool::int::operator>::(::bool::)")
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
	else if (rpn_obj.type_signature == "bool::int::operator>=::(::bool::)")
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
	else if (rpn_obj.type_signature == "bool::int::operator==::(::uchar::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
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
	else if (rpn_obj.type_signature == "bool::int::operator==::(::bool::)")
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
	else if (rpn_obj.type_signature == "bool::int::operator!=::(::uchar::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
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
	else if (rpn_obj.type_signature == "bool::int::operator!=::(::bool::)")
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
	else if (rpn_obj.type_signature == "bool::int::operator&&::(::uchar::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
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
	else if (rpn_obj.type_signature == "bool::int::operator&&::(::bool::)")
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
	else if (rpn_obj.type_signature == "bool::int::operator||::(::uchar::)")
	{
		int left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int32;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
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
	else if (rpn_obj.type_signature == "bool::int::operator||::(::bool::)")
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
	else if (rpn_obj.type_signature == "int::int::operator%::(::bool::)")
	{
		int left_ = 0; bool right_ = 0;
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
	else if (rpn_obj.type_signature == "int&::int::operator=::(::uchar::)") {
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int32 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_uint8;
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
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int32 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_uint8;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "int&::int::operator=::(::bool::)") {
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
	else if (rpn_obj.type_signature == "int&::int::operator[]::(::long_long::)") {
		long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int64;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig * right_;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature=="int&::int::operator[]::(::char::)") {
		char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size()-2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int8;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig*right_;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature=="int&::int::operator[]::(::uchar::)") {
		unsigned char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size()-2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_uint8;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig*right_;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature=="int&::int::operator[]::(::bool::)") {
		bool right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size()-2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int8;
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
	else if (rpn_obj.type_signature == "bool::bool::operator-::(::)")
	{
		bool left_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = -left_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
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
	else if (rpn_obj.type_signature == "bool::bool::operator<::(::bool::)")
	{
		bool left_ = 0; bool right_ = 0;
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
	else if (rpn_obj.type_signature == "bool::bool::operator<=::(::bool::)")
	{
		bool left_ = 0; bool right_ = 0;
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
	else if (rpn_obj.type_signature == "bool::bool::operator>::(::bool::)")
	{
		bool left_ = 0; bool right_ = 0;
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
	else if (rpn_obj.type_signature == "bool::bool::operator>=::(::bool::)")
	{
		bool left_ = 0; bool right_ = 0;
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
	else if (rpn_obj.type_signature == "bool::bool::operator==::(::bool::)")
	{
		bool left_ = 0; bool right_ = 0;
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
	else if (rpn_obj.type_signature == "bool::bool::operator!=::(::bool::)")
	{
		bool left_ = 0; bool right_ = 0;
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
	else if (rpn_obj.type_signature == "bool::bool::operator&&::(::bool::)")
	{
		bool left_ = 0; bool right_ = 0;
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
	else if (rpn_obj.type_signature == "bool::bool::operator||::(::bool::)")
	{
		bool left_ = 0; bool right_ = 0;
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
	else if (rpn_obj.type_signature=="bool&::bool::operator[]::(::int::)") {
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
	else if (rpn_obj.type_signature == "bool&::bool::operator[]::(::long_long::)") {
		long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int64;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig * right_;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature=="bool&::bool::operator[]::(::char::)") {
		char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size()-2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int8;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig*right_;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature=="bool&::bool::operator[]::(::bool::)") {
		bool right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size()-2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int8;
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
	else if (rpn_obj.type_signature == "char::char::operator-::(::)")
	{
		char left_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _char_, 1, "char", "char");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = -left_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
	else if (rpn_obj.type_signature == "char&::char::operator=::(::string::)") {
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			throw j_error("string can be copy to array!");
		}
		else {
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			std::string right_name = processor->call_stack.stack[addr].title.text;
			size_t now_addr = addr;
			while (processor->call_stack.stack[now_addr].title.text == right_name && processor->call_stack.stack[now_addr].new_var) {
				if (now_addr - addr >= processor->call_stack.top().data[0].text.size()) break;
				processor->call_stack.stack[now_addr].data[0].text = processor->call_stack.stack[now_addr].data[0].cs_int8 = processor->call_stack.stack[processor->call_stack.size()-1].data[0].text[now_addr - addr];
				now_addr++;
			}
			
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	//char operator[]
	else if (rpn_obj.type_signature=="char&::char::operator[]::(::int::)") {
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
	else if (rpn_obj.type_signature == "char&::char::operator[]::(::long_long::)") {
		long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int64;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig * right_;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature=="char&::char::operator[]::(::char::)") {
		char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size()-2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int8;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig*right_;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature=="char&::char::operator[]::(::bool::)") {
		bool right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size()-2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int8;
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


//------------------------------------------------------------------
			//					| |	 | |/ ___| | | |   / \   |  _ \
			//					| |	 | || |  | |_| |  / _ \  | |_) |
			//					| |__| || |__|  _  | / ___ \ |  _ <
			//					|______|\____|_| |_|/__/ \__\| | \_\
			//------------------------------------------------------
size_t Ariphmetic_module::uchar_calc(Lexem& rpn_obj) {
	Lexem end_of_block("", unknown_name, unknown_name, 0, "", "");
	Lexem main_data("", unknown_name, unknown_name, 0, "", "");
	Lexem begin_of_block("", unknown_name, unknown_name, 0, "", "");
	MemoryBlock mem;
	std::vector<Lexem> data;
	//uchar +
	if (rpn_obj.type_signature == "uchar::uchar::operator+::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "uchar");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "uchar", "uchar");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "uchar", "uchar");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator+::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator+::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator+::(::double::)") {
		unsigned char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator+::(::float::)") {
		unsigned char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//uchar *
	else if (rpn_obj.type_signature == "uchar::uchar::operator*::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator*::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator*::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator*::(::double::)") {
		unsigned char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator*::(::float::)") {
		unsigned char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//uchar -
	else if (rpn_obj.type_signature == "uchar::uchar::operator-::(::)")
	{
		unsigned char left_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = -left_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator-::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator-::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator-::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator-::(::double::)") {
		unsigned char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator-::(::float::)") {
		unsigned char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//uchar /
	else if (rpn_obj.type_signature == "uchar::uchar::operator/::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator/::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator/::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator/::(::double::)") {
		unsigned char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator/::(::float::)") {
		unsigned char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//uchar &
	else if (rpn_obj.type_signature == "uchar::uchar::operator&::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ & right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator&::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ & right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator&::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ & right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator&::(::double::)") {
		throw  j_error("Nelzya & between int and double");
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator&::(::float::)") {
		throw  j_error("Nelzya & between int and float");
	}
	//uchar |
	else if (rpn_obj.type_signature == "uchar::uchar::operator|::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ | right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator|::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ | right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator|::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ | right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator|::(::double::)") {
		throw  j_error("Nelzya | between int and double");
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator|::(::float::)") {
		throw  j_error("Nelzya | between int and float");
	}
	//uchar ^
	else if (rpn_obj.type_signature == "uchar::uchar::operator^::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ ^ right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator^::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ ^ right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator^::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ ^ right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator^::(::double::)") {
		throw  j_error("Nelzya ^ between bool and double");
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator^::(::float::)") {
		throw  j_error("Nelzya ^ between bool and float");
	}
	//uchar <
	else if (rpn_obj.type_signature == "bool::uchar::operator<::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator<::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator<::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator<::(::double::)") {
		unsigned char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator<::(::float::)") {
		unsigned char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ < right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//uchar <=
	else if (rpn_obj.type_signature == "bool::uchar::operator<=::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator<=::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator<=::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator<=::(::double::)") {
		unsigned char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator<=::(::float::)") {
		unsigned char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ <= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//uchar >
	else if (rpn_obj.type_signature == "bool::uchar::operator>::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator>::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator>::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator>::(::double::)") {
		unsigned char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator>::(::float::)") {
		unsigned char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ > right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//uchar >=
	else if (rpn_obj.type_signature == "bool::uchar::operator>=::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator>=::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator>=::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator>=::(::double::)") {
		unsigned char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator>=::(::float::)") {
		unsigned char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ >= right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//uchar ==
	else if (rpn_obj.type_signature == "bool::uchar::operator==::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator==::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator==::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator==::(::double::)") {
		unsigned char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator==::(::float::)") {
		unsigned char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ == right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//uchar !=
	else if (rpn_obj.type_signature == "bool::uchar::operator!=::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator!=::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator!=::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator!=::(::double::)") {
		unsigned char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator!=::(::float::)") {
		unsigned char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ != right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//uchar &&
	else if (rpn_obj.type_signature == "bool::uchar::operator&&::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator&&::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator&&::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator&&::(::double::)") {
		unsigned char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator&&::(::float::)") {
		unsigned char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ && right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//uchar ||
	else if (rpn_obj.type_signature == "bool::uchar::operator||::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator||::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _bool_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _bool_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _bool_, 1, "bool", "bool");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator||::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator||::(::double::)") {
		unsigned char left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "bool::uchar::operator||::(::float::)") {
		unsigned char left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
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
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ || right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//uchar !
	else if (rpn_obj.type_signature == "bool::operator!::(::uchar::)")
	{
		unsigned char arg;
		if (processor->call_stack.stack.back().title.link) {
			arg = processor->call_stack.stack[processor->call_stack.stack.back().title.link].data[0].cs_uint8;
		}
		else {
			arg = processor->call_stack.stack.back().data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "bool");
		main_data = Lexem("timed obj", int_literal, _u_char_, 0, "bool", "bool");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "bool", "bool");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = !arg;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//uchar %
	else if (rpn_obj.type_signature == "uchar::uchar::operator%::(::int::)")
	{
		unsigned char left_ = 0; int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ % right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator%::(::char::)")
	{
		unsigned char left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_uint8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_uint8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ % right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator%::(::long_long::)")
	{
		unsigned char left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_uint8;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_uint8;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _u_char_, 1, "end block", "char");
		main_data = Lexem("timed obj", char_symbol, _u_char_, 0, "char", "char");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _u_char_, 1, "char", "char");
		main_data.cs_uint8 = main_data.cs_int32 = main_data.cs_int64 = left_ % right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator%::(::double::)") {
		throw j_error("ostatok int na double nelzya!");
	}
	else if (rpn_obj.type_signature == "uchar::uchar::operator%::(::float::)") {
		throw j_error("ostatok int na float nelzya!");
	}
	//ostream uchar
	else if (rpn_obj.type_signature == "ostream&::operator<<::(::ostream&::uchar::)") {
		unsigned char arg;
		if (processor->call_stack.stack.back().title.link) {
			arg = processor->call_stack.stack[processor->call_stack.stack.back().title.link].data[0].cs_uint8;
		}
		else {
			arg = processor->call_stack.stack.back().data[0].cs_uint8;
		}
		std::cout << arg;
		processor->call_stack.pop();
	}
	//istream uchar
	else if (rpn_obj.type_signature == "istream&::operator>>::(::istream&::uchar::)") {
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
		std::cin >> processor->call_stack.stack[index].data[0].cs_uint8;
		processor->call_stack.stack[index].data[0].cs_int32 = processor->call_stack.stack[index].data[0].cs_int64 = processor->call_stack.stack[index].data[0].cs_uint8;
		processor->call_stack.pop();
	}
	//uchar copy operator
	else if (rpn_obj.type_signature == "uchar&::uchar::operator=::(::int::)") {
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_uint8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int32;
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
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_uint8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int32;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "uchar&::uchar::operator=::(::char::)") {
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_uint8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8;
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
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_uint8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "uchar&::uchar::operator=::(::uchar::)") {
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_uint8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_uint8;
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
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_uint8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_uint8;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "uchar&::uchar::operator=::(::long_long::)") {
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_uint8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int64;
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
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_uint8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int64;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "uchar&::uchar::operator=::(::float::)") {
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_uint8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float32;
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
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_uint8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float32;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "uchar&::uchar::operator=::(::double::)") {
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_uint8 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float64;
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
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_uint8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float64;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "uchar&::uchar::operator=::(::string::)") {
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
		if (!processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			throw j_error("string can be copy to array!");
		}
		else {
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			std::string right_name = processor->call_stack.stack[addr].title.text;
			size_t now_addr = addr;
			while (processor->call_stack.stack[now_addr].title.text == right_name && processor->call_stack.stack[now_addr].new_var) {
				if (now_addr - addr >= processor->call_stack.top().data[0].text.size()) break;
				processor->call_stack.stack[now_addr].data[0].text = processor->call_stack.stack[now_addr].data[0].cs_uint8 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].text[now_addr - addr];
				now_addr++;
			}

			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	//char operator[]
	else if (rpn_obj.type_signature == "uchar&::uchar::operator[]::(::int::)") {
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
	else if (rpn_obj.type_signature == "uchar&::uchar::operator[]::(::long_long::)") {
		long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int64;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig * right_;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature == "uchar&::uchar::operator[]::(::char::)") {
		char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int8;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig * right_;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature == "uchar&::uchar::operator[]::(::bool::)") {
		bool right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int8;
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

	else if (rpn_obj.type_signature == "float::float::operator-::(::)")
	{
		float left_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float32;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _float_, 1, "end block", "float");
		main_data = Lexem("timed obj", double_literal, _float_, 0, "float", "float");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _float_, 1, "float", "float");
		main_data.cs_float32 = main_data.cs_float64  = -left_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
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
		float arg;
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
	else if (rpn_obj.type_signature=="float&::float::operator[]::(::int::)") {
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
	else if (rpn_obj.type_signature == "float&::float::operator[]::(::long_long::)") {
		long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int64;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig * right_;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature=="float&::float::operator[]::(::char::)") {
		char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size()-2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int8;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig*right_;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature=="float&::float::operator[]::(::bool::)") {
		bool right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size()-2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int8;
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
	else if (rpn_obj.type_signature == "double::double::operator-::(::)")
	{
		double left_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_float64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _double_, 1, "end block", "double");
		main_data = Lexem("timed obj", double_literal, _double_, 0, "double", "double");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _double_, 1, "double", "double");
		main_data.cs_float32 = main_data.cs_float64 = -left_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
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
		double arg;
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
	else if (rpn_obj.type_signature=="double&::double::operator[]::(::int::)") {
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
	else if (rpn_obj.type_signature == "double&::double::operator[]::(::long_long::)") {
		long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int64;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig * right_;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature=="double&::double::operator[]::(::char::)") {
		char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size()-2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int8;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig*right_;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature=="double&::double::operator[]::(::bool::)") {
		bool right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size()-2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int8;
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

//------------------------------------------
/// ___ | _   _ |  _ \ |__ __| |  | || ____|
//\___ \   | |  | |_) |  | | |  \ | || |  _
// ___) |  | |  |  < |  _| |_| \ \| || |_| |
//|____/   | |  | | \_\|_____| |\   ||_____|
//------------------------------------------
size_t Ariphmetic_module::string_calc(Lexem& rpn_obj) {
	Lexem end_of_block("", unknown_name, unknown_name, 0, "", "");
	Lexem main_data("", unknown_name, unknown_name, 0, "", "");
	Lexem begin_of_block("", unknown_name, unknown_name, 0, "", "");
	MemoryBlock mem;
	std::vector<Lexem> data;

	if (rpn_obj.type_signature == "ostream&::operator<<::(::ostream&::string::)") {
		std::string arg;
		if (processor->call_stack.stack.back().title.link) {
			arg = processor->call_stack.stack[processor->call_stack.stack.back().title.link].data[0].text;
		}
		else {
			arg = processor->call_stack.stack.back().data[0].text;
		}
		std::cout << arg;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature == "string&::string::operator=::(::char::)") {
		if (!processor->call_stack.top().title.link) {
			throw j_error("right op must be linked");
		}

		auto addr = processor->call_stack.top().title.link;
		size_t cur_addr = addr;
		processor->call_stack.stack[processor->call_stack.size() - 2].data[0].text = "";
		while (processor->call_stack.stack[cur_addr].title.text == processor->call_stack.stack[addr].title.text && processor->call_stack.stack[cur_addr].new_var) {
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].text+=processor->call_stack.stack[cur_addr].data[0].cs_int8;
			cur_addr++;
		}
		addr = processor->call_stack.size() - 2;
		if (processor->call_stack.stack[addr].title.link) addr = processor->call_stack.stack[addr].title.link;
		if (!processor->call_stack.stack[addr].new_var) {
			while (processor->call_stack.stack[addr].title.text != processor->call_stack.stack[processor->call_stack.size() - 2].title.text && !processor->call_stack.stack[addr].new_var) {
				addr--;
			}
		}
		processor->call_stack.stack[addr].data = processor->call_stack.stack[processor->call_stack.size() - 2].data;
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
		return 1;
	}

	return 0;
}

//---------------------------------------
//| |   | |
//| |   | |
//| |___| |___
//|_____|_____|
//-----------------------------------------
size_t Ariphmetic_module::long_long_calc(Lexem& rpn_obj) {
	Lexem end_of_block("", unknown_name, unknown_name, 0, "", "");
	Lexem main_data("", unknown_name, unknown_name, 0, "", "");
	Lexem begin_of_block("", unknown_name, unknown_name, 0, "", "");
	MemoryBlock mem;
	std::vector<Lexem> data;

	//ll +
	if (rpn_obj.type_signature == "long_long::long_long::operator+::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator+::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator+::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator+::(::double::)") {
		long long left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator+::(::float::)") {
		long long left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ + right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//ll *
	else if (rpn_obj.type_signature == "long_long::long_long::operator*::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator*::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator*::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator*::(::double::)") {
		long long left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator*::(::float::)") {
		long long left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ * right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//ll -
	else if (rpn_obj.type_signature == "long_long::long_long::operator-::(::)")
	{
		long long left_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = -left_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator-::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator-::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator-::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator-::(::double::)") {
		long long left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator-::(::float::)") {
		long long left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ - right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//ll /
	else if (rpn_obj.type_signature == "long_long::long_long::operator/::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator/::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator/::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator/::(::double::)") {
		long long left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator/::(::float::)") {
		long long left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_float32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_float32;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ / right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	//ll &
	else if (rpn_obj.type_signature == "long_long::long_long::operator&::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ & right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator&::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ & right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator&::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ & right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator&::(::double::)") {
		throw  j_error("Nelzya & between int and double");
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator&::(::float::)") {
		throw  j_error("Nelzya & between int and float");
	}
	//ll |
	else if (rpn_obj.type_signature == "long_long::long_long::operator|::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ | right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator|::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ | right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator|::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ | right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator|::(::double::)") {
		throw  j_error("Nelzya | between int and double");
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator|::(::float::)") {
		throw  j_error("Nelzya | between int and float");
	}
	//ll ^
	else if (rpn_obj.type_signature == "long_long::long_long::operator^::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ ^ right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator^::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ ^ right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator^::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ ^ right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator^::(::double::)") {
		throw  j_error("Nelzya ^ between int and double");
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator^::(::float::)") {
		throw  j_error("Nelzya ^ between int and float");
	}
	//ll <
	else if (rpn_obj.type_signature == "bool::long_long::operator<::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator<::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator<::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator<::(::double::)") {
		long long left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator<::(::float::)") {
		long long left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	//ll <=
	else if (rpn_obj.type_signature == "bool::long_long::operator<=::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator<=::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator<=::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator<=::(::double::)") {
		long long left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator<=::(::float::)") {
		long long left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	//ll >
	else if (rpn_obj.type_signature == "bool::long_long::operator>::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator>::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator>::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator>::(::double::)") {
		long long left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator>::(::float::)") {
		long long left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	//ll >=
	else if (rpn_obj.type_signature == "bool::long_long::operator>=::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator>=::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator>=::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator>=::(::double::)") {
		long long left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator>=::(::float::)") {
		long long left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	//ll ==
	else if (rpn_obj.type_signature == "bool::long_long::operator==::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator==::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator==::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator==::(::double::)") {
		long long left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator==::(::float::)") {
		long long left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	//ll !=
	else if (rpn_obj.type_signature == "bool::long_long::operator!=::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator!=::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator!=::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator!=::(::double::)") {
		long long left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator!=::(::float::)") {
		long long left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	//ll &&
	else if (rpn_obj.type_signature == "bool::long_long::operator&&::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator&&::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator&&::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator&&::(::double::)") {
		long long left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator&&::(::float::)") {
		long long left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	//ll ||
	else if (rpn_obj.type_signature == "bool::long_long::operator||::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator||::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator||::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator||::(::double::)") {
		long long left_ = 0; double right_ = 0.0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	else if (rpn_obj.type_signature == "bool::long_long::operator||::(::float::)") {
		long long left_ = 0; float right_ = 0.0f;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
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
	//ll !
	else if (rpn_obj.type_signature == "bool::operator!::(::long_long::)")
	{
		long long arg;
		if (processor->call_stack.stack.back().title.link) {
			arg = processor->call_stack.stack[processor->call_stack.stack.back().title.link].data[0].cs_int64;
		}
		else {
			arg = processor->call_stack.stack.back().data[0].cs_int64;
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
	//ll %
	else if (rpn_obj.type_signature == "long_long::long_long::operator%::(::int::)")
	{
		long long left_ = 0;int right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int32;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int32;
		}

		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ % right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator%::(::char::)")
	{
		long long left_ = 0; char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int8;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ % right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator%::(::long_long::)")
	{
		long long left_ = 0; long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link) {
			left_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].data[0].cs_int64;
		}
		else {
			left_ = processor->call_stack.stack[processor->call_stack.stack.size() - 2].data[0].cs_int64;
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.stack[processor->call_stack.stack.size() - 1].data[0].cs_int64;
		}
		mem.data.clear();
		end_of_block = Lexem("end block", _timed_memory_block_end, _long_long_, 1, "end block", "long_long");
		main_data = Lexem("timed obj", int_literal, _long_long_, 0, "long_long", "long_long");
		begin_of_block = Lexem("timed obj", _timed_memory_block_begin, _long_long_, 1, "long_long", "long_long");
		main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = left_ % right_;
		mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
		processor->call_stack.pop();
		processor->call_stack.pop();
		processor->call_stack.push(mem);
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator%::(::double::)") {
		throw j_error("ostatok ll na double nelzya!");
	}
	else if (rpn_obj.type_signature == "long_long::long_long::operator%::(::float::)") {
		throw j_error("ostatok ll na float nelzya!");
	}
	//ostream ll
	else if (rpn_obj.type_signature == "ostream&::operator<<::(::ostream&::long_long::)") {
		long long arg;
		if (processor->call_stack.stack.back().title.link) {
			arg = processor->call_stack.stack[processor->call_stack.stack.back().title.link].data[0].cs_int64;
		}
		else {
			arg = processor->call_stack.stack.back().data[0].cs_int64;
		}
		std::cout << arg;
		processor->call_stack.pop();
	}
	//istream ll
	else if (rpn_obj.type_signature == "istream&::operator>>::(::istream&::long_long::)") {
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
		std::cin >> processor->call_stack.stack[index].data[0].cs_int64;
		processor->call_stack.stack[index].data[0].cs_int8 = processor->call_stack.stack[index].data[0].cs_int32 = processor->call_stack.stack[index].data[0].cs_int64;
		processor->call_stack.pop();
	}
	//ll copy operator
	else if (rpn_obj.type_signature == "long_long&::long_long::operator=::(::int::)") {
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int64 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int32;
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
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int64 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int32;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "long_long&::long_long::operator=::(::char::)") {
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int64 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int8;
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
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int64 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int8;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "long_long&::long_long::operator=::(::long_long::)") {
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int64 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int64;
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
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int64 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int64;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "long_long&::long_long::operator=::(::float::)") {
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int64 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float32;
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
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int64 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float32;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	else if (rpn_obj.type_signature == "long_long&::long_long::operator=::(::double::)") {
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) { processor->call_stack.stack[processor->call_stack.size() - 1] = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link]; processor->call_stack.stack[processor->call_stack.size() - 1].new_var = false; }
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
			processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_int64 = processor->call_stack.stack[processor->call_stack.size() - 2].data[0].cs_float64;
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
			processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_int64 = processor->call_stack.stack[processor->call_stack.size() - 1].data[0].cs_float64;
			size_t addr = processor->call_stack.stack[processor->call_stack.size() - 2].title.link;
			processor->call_stack.stack[addr].data = processor->call_stack.top().data;
			processor->call_stack.pop();
			processor->call_stack.pop();
		}
	}
	//ll operator[]
	else if (rpn_obj.type_signature=="long_long&::long_long::operator[]::(::int::)") {
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
	else if (rpn_obj.type_signature == "long_long&::long_long::operator[]::(::long_long::)") {
		long long right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size() - 2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int64;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int64;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig * right_;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature=="long_long&::long_long::operator[]::(::char::)") {
		char right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size()-2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int8;
		}
		size_t next_dimensions_cnt = rpn_obj.cs_int64;
		size_t sdvig = 1;
		for (long long i = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size() - next_dimensions_cnt; i < processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz.size(); i++) {
			sdvig *= processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 2].title.link].title.static_array_sz[i];
		}
		processor->call_stack.stack[processor->call_stack.size() - 2].title.link += sdvig*right_;
		processor->call_stack.pop();
	}
	else if (rpn_obj.type_signature=="long_long&::long_long::operator[]::(::bool::)") {
		bool right_ = 0;
		if (processor->call_stack.stack[processor->call_stack.size()-2].title.link == 0) {
			throw j_error("ne validnaya link to static array");
		}
		if (processor->call_stack.stack[processor->call_stack.size() - 1].title.link) {
			right_ = processor->call_stack.stack[processor->call_stack.stack[processor->call_stack.size() - 1].title.link].data[0].cs_int8;
		}
		else {
			right_ = processor->call_stack.top().data[0].cs_int8;
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

		if (in(rpn_form[i].type, { double_literal,int_literal, var_name,new_var,char_symbol,new_static_array,static_array,_string_ })) {

			switch (rpn_form[i].type)
			{
			case int_literal:
				end_of_block = Lexem("end block", _timed_memory_block_end, _int_, 1, "end block","int");
				main_data = Lexem(rpn_form[i].text, int_literal, _int_, 0, "int","int");
				begin_of_block = Lexem(rpn_form[i].text, _timed_memory_block_begin, _int_, 1, "int","int");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = std::stoll(rpn_form[i].text);
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.push(mem);
				break;
			case _string_:
				end_of_block = Lexem("end block", _timed_memory_block_end, _string_, 1, "end block", "string");
				main_data = Lexem(rpn_form[i].text, _string_, _string_, 0, "string", "string");
				begin_of_block = Lexem("", _timed_memory_block_begin, _string_, 1, "string", "string");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = rpn_form[i].text.size();;
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
				begin_of_block = Lexem("", _timed_memory_block_begin, _double_, 1, "char", "char");
				main_data.cs_int8 = main_data.cs_int32 = main_data.cs_int64 = rpn_form[i].text[0];
				mem = MemoryBlock(begin_of_block, main_data, end_of_block, 1);
				processor->call_stack.push(mem);
				break;
			case new_var:
				for (size_t stack_index = processor->call_stack.size() - 1; stack_index > 0; stack_index--) {
					if (processor->call_stack.stack[stack_index].title.text == rpn_form[i].text) {
						throw j_error("Variable " + rpn_form[i].text + " already exist");
					}
					else if (processor->call_stack.stack[stack_index].data[0].type==_ret_from_func_mark) {
						bool found_si2 = 0;
						for (size_t si2 = stack_index - 1; si2 > stack_index - 1 - processor->call_stack.stack[stack_index].data[0].cs_int32; si2--) {
							if (processor->call_stack.stack[si2].title.text == rpn_form[i].text) {
								found_si2 = 1;
								break;
							}
						}
						if (found_si2) {
							throw j_error("Variable " + rpn_form[i].text + " already exist");
						}
						break;
					}
				}
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
				for (size_t stack_index = processor->call_stack.size() - 1; stack_index > 0; stack_index--) {
					if (processor->call_stack.stack[stack_index].title.text == rpn_form[i].text) {
						mem = processor->call_stack.stack[stack_index];
						mem.title.link = stack_index;
						found = 1;
						break;
					}
					else if (processor->call_stack.stack[stack_index].data[0].type == _ret_from_func_mark) {
						bool found_si2 = 0;
						for (size_t si2 = stack_index - 1; si2 > stack_index - 1 - processor->call_stack.stack[stack_index].data[0].cs_int32; si2--) {
							if (processor->call_stack.stack[si2].title.text == rpn_form[i].text) {
								found_si2 = 1;
								mem = processor->call_stack.stack[si2];
								mem.title.link = si2;
								found = 1;
								break;
							}
						}
						if (!found_si2) {
							for (size_t global_index = processor->GLOBAL_SECTOR_LAST; global_index > 0; global_index--) {
								if (processor->call_stack.stack[global_index].title.text == rpn_form[i].text) {
									found_si2 = 1;
									mem = processor->call_stack.stack[global_index];
									mem.title.link = global_index;
									found = 1;
									break;
								}
							}
						}
						if (!found_si2) {
							throw j_error("cant find variable " + rpn_form[i].text);
						}
						break;
					}
				}

				mem.new_var = false;
				processor->call_stack.push(mem);
				break;
			case new_static_array:
				for (size_t stack_index = processor->call_stack.size() - 1; stack_index > 0; stack_index--) {
					if (processor->call_stack.stack[stack_index].title.text == rpn_form[i].text) {
						throw j_error("Variable " + rpn_form[i].text + " already exist");
					}
					else if (processor->call_stack.stack[stack_index].data[0].type == _ret_from_func_mark) {
						bool found_si2 = 0;
						for (size_t si2 = stack_index - 1; si2 > stack_index - 1 - processor->call_stack.stack[stack_index].data[0].cs_int32; si2--) {
							if (processor->call_stack.stack[si2].title.text == rpn_form[i].text) {
								found_si2 = 1;
								break;
							}
						}
						if (found_si2) {
							throw j_error("Variable " + rpn_form[i].text + " already exist");
						}
						break;
					}
				}
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
				for (size_t stack_index = processor->call_stack.size() - 1; stack_index > 0; stack_index--) {
					if (processor->call_stack.stack[stack_index].title.text == rpn_form[i].text) {
						break;
					}
					else if (processor->call_stack.stack[stack_index].data[0].type == _ret_from_func_mark) {
						bool found_si2 = 0;
						for (size_t si2 = stack_index - 1; si2 > stack_index - 1 - processor->call_stack.stack[stack_index].data[0].cs_int32; si2--) {
							if (processor->call_stack.stack[si2].title.text == rpn_form[i].text) {
								found_si2 = 1;
								break;
							}
						}
						if (!found_si2) {
							for (size_t global_index = processor->GLOBAL_SECTOR_LAST; global_index > 0; global_index--) {
								if (processor->call_stack.stack[global_index].title.text == rpn_form[i].text) {
									found_si2 = 1;
									break;
								}
							}
						}
						if (!found_si2) {
							throw j_error("cant find variable " + rpn_form[i].text);
						}
						break;
					}
				}

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
				if (in(rpn_form[i].type, { call_function,operator_logic_not,_operator_is_,_operator_os_ }) ) {
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
			if (in(rpn_form[i].type, { _operator_os_, _operator_is_ })) {
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
				if (result_signal) 
					result_signal = int_calc2(rpn_form[i]);
			}
			else if (processor->call_stack.stack[processor->call_stack.size() - argc].title.returned_type == "bool") {
				result_signal = bool_calc(rpn_form[i]);
			}
			else if (processor->call_stack.stack[processor->call_stack.size() - argc].title.returned_type == "char") {
				result_signal = char_calc(rpn_form[i]);
			}
			else if (processor->call_stack.stack[processor->call_stack.size() - argc].title.returned_type == "string") {
				result_signal = string_calc(rpn_form[i]);
			}
			else if (processor->call_stack.stack[processor->call_stack.size() - argc].title.returned_type == "float") {
				result_signal = float_calc(rpn_form[i]);
			}
			else if (processor->call_stack.stack[processor->call_stack.size() - argc].title.returned_type == "double") {
				result_signal = double_calc(rpn_form[i]);
			}
			else if (processor->call_stack.stack[processor->call_stack.size() - argc].title.returned_type == "long_long") {
				result_signal = long_long_calc(rpn_form[i]);
			}
			else if (processor->call_stack.stack[processor->call_stack.size() - argc].title.returned_type == "uchar") {
				result_signal = uchar_calc(rpn_form[i]);
			}
			

			if(result_signal)
			//return
			if (rpn_form[i].type == _return_) {

				processor->call_stack.stack[processor->call_stack.size() - 1].title.link = 0;
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
				lexem_queue_asm.continue_mode = true;
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
				if (!processor->call_stack.top().data[0].cs_int64) return;
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
			//delete
			else if (rpn_form[i].type == delete_operator) {
				size_t ptr = processor->call_stack.size() - 1;
				if (processor->call_stack.stack[ptr].title.link) {
					ptr = processor->call_stack.stack[ptr].title.link;
				}
				else {
					while (!(processor->call_stack.stack[ptr].title.text != processor->call_stack.top().title.text) && !(processor->call_stack.stack[ptr].new_var)) {
						ptr--;
					}
				}
				while (processor->call_stack.stack[ptr].title.text == processor->call_stack.stack[ptr - 1].title.text && processor->call_stack.stack[ptr - 1].new_var) {
					ptr--;
				}
				size_t cnt_d = 0;
				while (processor->call_stack.stack[ptr].title.text == processor->call_stack.top().title.text && processor->call_stack.stack[ptr].new_var) {
					processor->call_stack.stack[ptr].title.text = "FOR DELETE";
					ptr++;
					cnt_d++;
				}
				bool was_d = 0;
				size_t r = 0;
				for (long long ii = processor->call_stack.size() - 1; ii > -1; ii--) {
					if (processor->call_stack.stack[ii].title.text == "FOR DELETE") {
						was_d = 1;
						processor->call_stack.stack.erase(processor->call_stack.stack.begin() + ii);
					}
					else if (was_d && processor->call_stack.stack[ii].title.text != "FOR DELETE") {
						r = i + 1;
						break;
					}
				}
				processor->call_stack.pop();
				if (r) {
					for (size_t ii = r; ii < processor->call_stack.size(); ii++) {
						if (processor->call_stack.stack[ii].title.link > r) {
							processor->call_stack.stack[ii].title.link -= cnt_d;
						}
					}
				}
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