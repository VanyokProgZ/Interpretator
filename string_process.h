#pragma once
#include <vector>
#include "fstream"
#include "Lexem.h"
#include "handlers.h"
#include "j_error.h"
#include "string"
#include <regex>

template <typename T, class cont>
bool in(const T& target, const cont& v) {
    for (const auto& el : v) {
        if (el == target) return 1;
    }return 0;
}

std::string delete_std(const std::string& s);

std::vector<std::string> split(const std::string&, const std::string& d = " ",bool y = 1);

std::vector<std::string> grab_file(const std::string&);

void insert_space(std::string&, size_t);

void past_spaces(std::string&);

void Hide_Strings(std::string&, size_t, handleStrings&);

void cut_white_begin(std::string&);

std::vector<Lexem> lexemize_row(const std::string& row, handleClassNames& hC);