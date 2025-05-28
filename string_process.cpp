#include "string_process.h"

int next_class_name = 0;
int next_var_name = 0;
long long brackets = 0;
bool next_char = 0;
bool next_string = 0;


std::map<std::string, std::string> temp_vars_types;
std::map<std::string, size_t> temp_vars_types_int;


std::string delete_std(const std::string& s) {
    std::regex pattern("std::");
    return std::regex_replace(s, pattern, "");
}

std::vector<std::string> split(const std::string& s, const std::string& d, bool del) {//не использовать комбинации с \ в качестве делиметра
    std::vector<std::string> res;
    bool text_ = 0;
    std::string c = "";
    for (size_t i = 0; i < s.size(); i++) {
        
        if (s[i] == '\"') {
            if ((i > 0 && s[i - 1] != '\\')||i==0) {
                text_ = !text_;
            }
        }
        if (text_) {
            c += s[i];
            continue;
        }
        c += s[i];
        if (c.size() >= d.size()) {
            bool join = 1;
            for (long long j = c.size() - 1, u = d.size() - 1; u >= 0; u--, j--) {
                if (c[j] != d[u]) { 
                    join = 0; 
                    break; 
                }
            }
            if (join) {
                c.resize(c.size() - d.size());
                if (c.size() > 0)
                    if (del)
                        res.push_back(c);
                    else res.push_back(c + d);
                c = "";
            }
        }
        
    }
    if (c.size()) res.push_back(c);
    return res;
}

std::vector<std::string> grab_file(const std::string& path) {    //возвращает вектор строк

    std::ifstream file(path);
    if (!file.is_open()) throw j_error("error while open file in <grab_file>");

    std::vector<std::string> res;
    std::string line;

    while (std::getline(file, line)) {
        
        auto tmp = split(line, ";",0);
        for(auto& el : tmp)
            res.push_back(delete_std(el));
    }
    file.close();
    return res;
}

void insert_space(std::string& s, size_t pos) { //вставляет пробел по индексу
    s += " ";
    for (size_t i = s.size()-1; i > pos; i--) {
        s[i] = s[i - 1];
    }
    s[pos] = ' ';
}

void ecran_symbols_in_string(std::string& s) {
    for (long long i = s.size() - 1; i > -1; i--) {
        if (i > 0 && s[i - 1] == '\\' && in(s[i], {'t','n','\'','\"','b','?','\\','a','f','r','v'})) {
            switch (s[i])
            {
            case 't':
                s[i - 1] = '\t';
                break;
            case 'n':
                s[i - 1] = '\n';
                break;
            case '\'':
                s[i - 1] = '\'';
                break;
            case '\"':
                s[i - 1] = '\"';
                break;
            case 'b':
                s[i - 1] = '\b';
                break;
            case '?':
                s[i - 1] = '\?';
                break;
            case '\\':
                s[i - 1] = '\\';
                break;
            case 'a':
                s[i - 1] = '\a';
                break;
            case 'f':
                s[i - 1] = '\f';
                break;
            case 'r':
                s[i - 1] = '\r';
                break;
            case 'v':
                s[i - 1] = '\v';
                break;
            }
            s.erase(s.begin() + i);
        }
    }
}

void past_spaces(std::string& s) {  //вставляет пробелы для удобного парсинга
    bool text_ = false;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '\"') {
            if ((i > 0 && s[i - 1] != '\\') || i == 0){
                text_ = !text_;
                continue;
            }
            else if (i > 0 && s[i - 1] == '\\') {
                continue;
            }
        }
        if (in(s[i], { '+', '-', '=', '&' ,'|','*','/','}','{','(',')','%','!','<','>','~','^','?',',','[',']',';','\'','\"'})) {

            if (i + 1 < s.size() && ((s[i] == s[i + 1] && in(s[i], { '+','-', '&', '|','<','>','=' })) || (in(s[i], { '<','>','=','!','+','-','*','/','&','%','|','^'}) && s[i + 1] == '='))) {
                insert_space(s, i);
                insert_space(s, i+3);
                i += 2;
            }
            else {
                insert_space(s, i);
                insert_space(s, i + 2);
                i++;
            }
        }
    }
}

int check_digit(const std::string& s) {

    bool p = 0;
    for (auto& el : s) {
        if (!in(el, { '0','1','2','3','4','5','6','7','8','9','0' }) && el!='.') return 0;
        if (el == '.') p++;
    }
    if (p > 1)
        throw j_error("Bad digit/variable " + s);
    return 1 + p;
}

void cut_white_begin(std::string& s) {  //обрезает пробелы в начале
    
    std::string res = "";
    size_t pos = 0;
    while (s[pos] == '\t' || s[pos] == '\n' || s[pos] == ' ')pos++;
    while (pos < s.size())res += s[pos++];
    s = std::move(res);
}

std::vector<Lexem> lexemize_row(const std::string& row, handleClassNames& hC) { //разбивает строку на лексемы
    std::vector<Lexem> res;
    
    auto v = split(row);
    for (size_t i = 0; i < v.size(); i++) {
        if (next_char && v[i].size() > 2) {
            throw j_error("char symbol "+v[i]+" must has len=1");
        }
        if (v[i][0] == '\"') {
            ecran_symbols_in_string(v[i]);
            res.push_back(Lexem(v[i].substr(1, v[i].size()-2), _string_, _string_, 0, "string", "string"));
            continue;
        }
        if (v[i].size() == 1) {
            if (v[i] == "'" && res.back().text != "\\") {
                if (next_char) next_char = 0;
                else {
                    next_char = 1;
                }
                continue;
            }
            else if (next_char) {
                res.push_back(Lexem(v[i], char_symbol, _char_, 0, "char", "char"));
                continue;
            }
            else if (v[i] == "+") {
                res.push_back(Lexem("+", operator_plus, res.back().data_type,2,"operator+", ""));
            }else if (v[i] == "-") {
                res.push_back(Lexem("-", operator_minus, res.back().data_type, 2, "operator-", ""));
                if (res.size() == 1 || !in(res[res.size() - 2].type, { var_name, call_function, double_literal, int_literal,char_symbol,sq_bracket_close,round_bracket_close })) {
                    res.back().arg_c = 1;
                }
            }
            else if (v[i] == "/") {
                res.push_back(Lexem("/", operator_division, res.back().data_type, 2, "operator/", ""));
            }
            else if (v[i] == "*") {
                res.push_back(Lexem("*", operator_multiply, res.back().data_type, 2, "operator*",""));
            }
            else if (v[i] == "=") {
                res.push_back(Lexem("=", operator_copy, res.back().data_type, 2, "operator=", ""));
            }
            else if (v[i] == "%") {
                res.push_back(Lexem("%", operator_ostatok, res.back().data_type, 2, "operator%", ""));
            }
            else if (v[i] == "(") {
                res.push_back(Lexem("(", round_bracket_open, round_bracket_open, 0, "round_bracket_open",""));
            }
            else if (v[i] == ")") {
                res.push_back(Lexem(")", round_bracket_close, round_bracket_close, 0, "round_bracket_close",""));
            }
            else if (v[i] == "[") {
                res.push_back(Lexem("[", sq_bracket_open, sq_bracket_open, 2, "sq_bracket_open",""));
                res.push_back(Lexem("(", round_bracket_open, round_bracket_open, 0, "round_bracket_open", ""));
            }
            else if (v[i] == "]") {
                res.push_back(Lexem(")", round_bracket_close, round_bracket_close, 0, "round_bracket_close", ""));
                res.push_back(Lexem("]", sq_bracket_close, sq_bracket_close, 2, "sq_bracket_close",""));
            }
            else if (v[i] == "{") {
                res.push_back(Lexem("{", fig_bracket_open, fig_bracket_open, 0, "fig_bracket_open",""));
            }
            else if (v[i] == "}") {
                res.push_back(Lexem("}", fig_bracket_close, fig_bracket_close, 0, "fig_bracket_close",""));
            }
            else if (v[i] == "!") {
                res.push_back(Lexem("!", operator_logic_not, res.back().data_type, 1, "operator!", "bool"));
            }
            else if (v[i] == ";") {
                res.push_back(Lexem(";", _semicolon_, _semicolon_, 0, "semicolon",""));
            }
            else if (v[i] == ",") {
                res.push_back(Lexem(",", _comma_, _comma_, 0, "comma",""));
            }
            else if (v[i] == ">") {
                res.push_back(Lexem(">", operator_gr, res.back().data_type, 2, "operator>","bool"));
            }
            else if (v[i] == "<") {
                if (res.size() && in(res.back().type, { int_literal, double_literal, var_name, new_var, call_function,char_symbol,sq_bracket_close, round_bracket_close })) {
                    res.push_back(Lexem("<", operator_ls, res.back().data_type, 2, "operator<","bool"));
                }
                else{
                std::string func_ret_type = "";
                i++;
                while (v[i] != ">") {
                    func_ret_type += v[i];
                    i++;
                }
                i++;
                size_t funct_ret_type_ = class_name;
                if (func_ret_type == "int") {
                    funct_ret_type_ = _int_;
                }else if (func_ret_type == "float") {
                    funct_ret_type_ = _float_;
                }
                else if (func_ret_type == "long long") {
                    funct_ret_type_ = _long_long_;
                }
                else if (func_ret_type == "double") {
                    funct_ret_type_ = _double_;
                }
                else if (func_ret_type == "char") {
                    funct_ret_type_ = _char_;
                }
                else if (func_ret_type == "bool") {
                    funct_ret_type_ = _bool_;
                }

                long long brackets_cnt = 1;
                size_t args = 0;
                for (size_t j = i + 2;brackets_cnt!=0; j++) {
                    if (v[j] == "(" || v[j] == "{" || v[j] == "[") brackets_cnt++;
                    else if (v[j] == ")" || v[j] == "}" || v[j] == "]") brackets_cnt--;
                    //else if (in(v[j][0], "abcdefghijklmnopqrtuvwxyz_ABCDEFGHIJKLMNOPQRSTUVWXYZ")) args++;
                    else if (brackets_cnt == 1 && v[j] == ",") args++;
                }
                if (v[i + 1] == "(" && v[i + 2] == ")") {
                    args = 0;
                }
                else {
                    args++;
                }
                res.push_back(Lexem(v[i], call_function,funct_ret_type_,args,v[i],func_ret_type));
                }
            }
            else {
                if (next_class_name) {
                    hC.add_class_name(v[i]);
                    res.push_back(Lexem(v[i], _data_type_,class_name,0,v[i],v[i]));
                }
                else if (next_var_name) {
                    if (v[i + 1] == "(") {
                        long long brackets_cnt = 1;
                        size_t args = 0;
                        for (size_t j = i + 2; brackets_cnt != 0; j++) {
                            if (v[j] == "(" || v[j] == "{" || v[j] == "[") brackets_cnt++;
                            else if (v[j] == ")" || v[j] == "}" || v[j] == "]") brackets_cnt--;
                            //else if (in(v[j][0], "abcdefghijklmnopqrtuvwxyz_ABCDEFGHIJKLMNOPQRSTUVWXYZ")) args++;
                            else if (brackets_cnt == 1 && v[j] == ",") args++;
                        }
                        if (v[i + 1] == "(" && v[i + 2] == ")") {
                            args = 0;
                        }
                        else {
                            args++;
                        }
                        res.push_back(Lexem(v[i], new_function, res.back().data_type, args,v[i],res.back().type_signature));
                        //TODO аргументы
                    }
                    else {
                        if (res.back().type != pointer_mark) {
                            res.push_back(Lexem(v[i], new_var, res.back().data_type, 0, res.back().type_signature, res.back().type_signature));
                            temp_vars_types[v[i]] = res.back().type_signature;
                            temp_vars_types_int[v[i]] = res.back().data_type;
                        }
                        else {
                            res.push_back(Lexem(v[i], pointer, res[res.size()-2].data_type, 0, res[res.size() - 2].type_signature + "*", res[res.size() - 2].type_signature+"*"));
                            temp_vars_types[v[i]] = res[res.size() - 2].type_signature;
                            temp_vars_types_int[v[i]] = res[res.size() - 2].data_type;
                            std::swap(res[res.size() - 1], res[res.size() - 2]);
                            res.pop_back();
                        }
                    }
                }
                else {
                    if (temp_vars_types.count(v[i])) {
                        res.push_back(Lexem(v[i], var_name, temp_vars_types_int[v[i]], 0, temp_vars_types[v[i]],temp_vars_types[v[i]]));
                    }
                    else {
                        res.push_back(Lexem(v[i], unknown_name, unknown_name, 0, "unknown","unknown"));
                        
                        if (check_digit(res[res.size()-1].text) == 2) {
                            res[res.size() - 1].type = double_literal;
                            res[res.size() - 1].type_signature = "double";
                            res[res.size() - 1].data_type = _double_;
                            res[res.size() - 1].returned_type = "double";
                        }
                        else if (check_digit(res[res.size() - 1].text) == 1) {
                            res[res.size() - 1].type = int_literal;
                            res[res.size() - 1].type_signature = "int";
                            res[res.size() - 1].data_type = _int_;
                            res[res.size() - 1].returned_type = "int";
                        }
                    }
                }
            }
            next_class_name = next_var_name = 0;
        }
        else if (v[i].size() == 2) {
            if (next_char) {
                if (v[i][0] == '\\') {
                    std::string tmpstr =v[i];
                    ecran_symbols_in_string(tmpstr);
                    if (tmpstr.size() > 1) {
                        throw j_error("unknown ecran char symbol " + tmpstr);
                    }
                    res.push_back(Lexem(tmpstr, char_symbol, _char_, 0, "char", "char"));
                }
                else {
                    throw j_error("char symbol " + v[i] + " must has len=1");
                }
            continue;
            }
            else if (v[i] == "++") {
                res.push_back(Lexem("++", operator_plus_plus,res.back().data_type,1,"operator++", ""));
            }
            else if (v[i] == "--") {
                res.push_back(Lexem("--", operator_minus_minus, res.back().data_type, 1, "operator--", ""));
            }
            else if (v[i] == ">=") {
                res.push_back(Lexem(">=", operator_ge, res.back().data_type, 2, "operator>=","bool"));
            }
            else if (v[i] == "<=") {
                res.push_back(Lexem("<=", operator_le, res.back().data_type, 2,"operator<=","bool"));
            }
            else if (v[i] == ">>") {
                res.push_back(Lexem(">>", _operator_is_, _operator_is_, 2, "operator>>","istream&"));
            }
            else if (v[i] == "<<") {
                res.push_back(Lexem("<<", _operator_os_, _operator_os_, 2, "operator<<","ostream&"));
            }
            else if (v[i] == "+=") {
                res.push_back(Lexem("+=", operator_plus_eq, res.back().data_type, 2,"operator+=", ""));
            }
            else if (v[i] == "-=") {
                res.push_back(Lexem("-=", operator_minus_eq, res.back().data_type, 2,"operator-=", ""));
            }
            else if (v[i] == "*=") {
                res.push_back(Lexem("*=", operator_multiply_eq, res.back().data_type, 2, "operator*=", ""));
            }
            else if (v[i] == "/=") {
                res.push_back(Lexem("/=", operator_division_eq, res.back().data_type, 2, "operator/=",""));
            }
            else if (v[i] == "==") {
                res.push_back(Lexem("==", operator_eq, res.back().data_type, 2, "operator==","bool"));
            }
            else if (v[i] == "!=") {
                res.push_back(Lexem("!=", operator_ne, res.back().data_type, 2, "operator!=","bool"));
            }
            else if (v[i] == "&&") {
                res.push_back(Lexem("&&", operator_logic_and, res.back().data_type, 2, "operator&&", "bool"));
            }
            else if (v[i] == "||") {
                res.push_back(Lexem("||", operator_logic_or, res.back().data_type, 2, "operator||", "bool"));
            }
            else if (v[i] == "%=") {
                res.push_back(Lexem("%=", operator_ostatok_eq, res.back().data_type, 2, "operator%=",""));
            }
            else if (v[i] == "if") {
                res.push_back(Lexem("if", _if_, _void_, 1, "void","void"));
            }
            else {
                if (next_class_name) {
                    hC.add_class_name(v[i]);
                    res.push_back(Lexem(v[i], _data_type_, class_name, 0, v[i],v[i]));
                }
                else if (next_var_name) {
                    if (v[i + 1] == "(") {
                        long long brackets_cnt = 1;
                        size_t args = 0;
                        for (size_t j = i + 2; brackets_cnt != 0; j++) {
                            if (v[j] == "(" || v[j] == "{" || v[j] == "[") brackets_cnt++;
                            else if (v[j] == ")" || v[j] == "}" || v[j] == "]") brackets_cnt--;
                            //else if (in(v[j][0], "abcdefghijklmnopqrtuvwxyz_ABCDEFGHIJKLMNOPQRSTUVWXYZ")) args++;
                            else if (brackets_cnt == 1 && v[j] == ",") args++;
                        }
                        if (v[i + 1] == "(" && v[i + 2] == ")") {
                            args = 0;
                        }
                        else {
                            args++;
                        }
                        res.push_back(Lexem(v[i], new_function, res.back().data_type, args,v[i],res.back().type_signature));
                        //TODO аргументы
                    }
                    else {
                        if (res.back().type != pointer_mark) {
                            res.push_back(Lexem(v[i], new_var, res.back().data_type, 0, res.back().type_signature, res.back().type_signature));
                            temp_vars_types[v[i]] = res.back().type_signature;
                            temp_vars_types_int[v[i]] = res.back().data_type;
                        }
                        else {
                            res.push_back(Lexem(v[i], pointer, res[res.size() - 2].data_type, 0, res[res.size() - 2].type_signature + "*", res[res.size() - 2].type_signature + "*"));
                            temp_vars_types[v[i]] = res[res.size() - 2].type_signature + "*";
                            temp_vars_types_int[v[i]] = res[res.size() - 2].data_type;
                            std::swap(res[res.size() - 1], res[res.size() - 2]);
                            res.pop_back();
                        }
                    }
                }
                else {
                    if (temp_vars_types.count(v[i])) {
                        res.push_back(Lexem(v[i], var_name, temp_vars_types_int[v[i]], 0, temp_vars_types[v[i]],temp_vars_types[v[i]]));
                    }
                    else {
                        res.push_back(Lexem(v[i], unknown_name, unknown_name, 0, "unknown","unknown"));
                        if (check_digit(res[res.size() - 1].text) == 2) {
                            res[res.size() - 1].type = double_literal;
                            res[res.size() - 1].type_signature = "double";
                            res[res.size() - 1].data_type = _double_;
                            res[res.size() - 1].returned_type = "double";
                        }
                        else if (check_digit(res[res.size() - 1].text) == 1) {
                            res[res.size() - 1].type = int_literal;
                            res[res.size() - 1].type_signature = "int";
                            res[res.size() - 1].data_type = _int_;
                            res[res.size() - 1].returned_type = "int";
                        }
                    }
                }
            }
            next_class_name = next_var_name = 0;
        }
        else if (v[i].size() == 3) {
            if (v[i] == "int") {
                res.push_back(Lexem("int", _data_type_,_int_, 0,"int","int"));
                next_var_name = 1;
                continue;
            }
            else if (v[i] == "for") {
                res.push_back(Lexem("for", _for_,_for_,3,"void","void"));
            }
            else if (v[i] == "cin") {
                //res.push_back(Lexem("cin", _cin_, _cin_, 1, "cin","istream&"));
            }
            else {
                if (next_class_name) {
                    hC.add_class_name(v[i]);
                    res.push_back(Lexem(v[i], _data_type_, class_name, 0, v[i],v[i]));
                }
                else if (next_var_name) {
                    if (v[i + 1] == "(") {
                        long long brackets_cnt = 1;
                        size_t args = 0;
                        for (size_t j = i + 2; brackets_cnt != 0; j++) {
                            if (v[j] == "(" || v[j] == "{" || v[j] == "[") brackets_cnt++;
                            else if (v[j] == ")" || v[j] == "}" || v[j] == "]") brackets_cnt--;
                            //else if (in(v[j][0], "abcdefghijklmnopqrtuvwxyz_ABCDEFGHIJKLMNOPQRSTUVWXYZ")) args++;
                            else if (brackets_cnt == 1 && v[j] == ",") args++;
                        }
                        if (v[i + 1] == "(" && v[i + 2] == ")") {
                            args = 0;
                        }
                        else {
                            args++;
                        }
                        res.push_back(Lexem(v[i], new_function, res.back().data_type, args, v[i],res.back().type_signature));
                        //TODO аргументы
                    }
                    else {
                        if (res.back().type != pointer_mark) {
                            res.push_back(Lexem(v[i], new_var, res.back().data_type, 0, res.back().type_signature, res.back().type_signature));
                            temp_vars_types[v[i]] = res.back().type_signature;
                            temp_vars_types_int[v[i]] = res.back().data_type;
                        }
                        else {
                            res.push_back(Lexem(v[i], pointer, res[res.size() - 2].data_type, 0, res[res.size() - 2].type_signature + "*", res[res.size() - 2].type_signature + "*"));
                            temp_vars_types[v[i]] = res[res.size() - 2].type_signature + "*";
                            temp_vars_types_int[v[i]] = res[res.size() - 2].data_type;
                            std::swap(res[res.size() - 1], res[res.size() - 2]);
                            res.pop_back();
                        }
                    }
                }
                else {
                    if (temp_vars_types.count(v[i])) {
                        res.push_back(Lexem(v[i], var_name, temp_vars_types_int[v[i]], 0, temp_vars_types[v[i]],temp_vars_types[v[i]]));
                    }
                    else {
                        res.push_back(Lexem(v[i], unknown_name, unknown_name, 0, "unknown","unknown"));
                        if (check_digit(res[res.size() - 1].text) == 2) {
                            res[res.size() - 1].type = double_literal;
                            res[res.size() - 1].type_signature = "double";
                            res[res.size() - 1].data_type = _double_;
                            res[res.size() - 1].returned_type = "double";
                        }
                        else if (check_digit(res[res.size() - 1].text) == 1) {
                            res[res.size() - 1].type = int_literal;
                            res[res.size() - 1].type_signature = "int";
                            res[res.size() - 1].data_type = _int_;
                            res[res.size() - 1].returned_type = "int";
                        }
                    }
                }
            }
            next_class_name = next_var_name = 0;
        }
        else if (v[i].size() == 4) {
            if (v[i] == "else") {
                res.push_back(Lexem("else", _else_,_else_,0,"void","void"));
            }
            else if (v[i] == "case") {
                res.push_back(Lexem("case", _case_,_case_,1,"void","void"));
            }
            else if (v[i] == "endl") {
                res.push_back(Lexem("\n", char_symbol, _char_, 1, "char", "char"));
            }
            else if (v[i] == "cout") {
                //res.push_back(Lexem("cout", _cout_, _cout_, 1, "cout","ostream&"));
            }
            else if (v[i] == "char") {
                res.push_back(Lexem("char", _data_type_,_char_,0,"char","char"));
                next_var_name = 1;
                continue;
            }
            else if (v[i] == "bool") {
                res.push_back(Lexem("bool", _data_type_, _bool_, 0, "bool", "bool"));
                next_var_name = 1;
                continue;
            }
            else if (v[i] == "void") {
                res.push_back(Lexem("void", _data_type_,_void_,0,"void","void"));
            }
            else {
                    if (next_class_name) {
                        hC.add_class_name(v[i]);
                        res.push_back(Lexem(v[i], _data_type_, class_name, 0, v[i],v[i]));
                    }
                    else if (next_var_name) {
                        if (v[i + 1] == "(") {
                            long long brackets_cnt = 1;
                            size_t args = 0;
                            for (size_t j = i + 2; brackets_cnt != 0; j++) {
                                if (v[j] == "(" || v[j] == "{" || v[j] == "[") brackets_cnt++;
                                else if (v[j] == ")" || v[j] == "}" || v[j] == "]") brackets_cnt--;
                                //else if (in(v[j][0], "abcdefghijklmnopqrtuvwxyz_ABCDEFGHIJKLMNOPQRSTUVWXYZ")) args++;
                                else if (brackets_cnt == 1 && v[j] == ",") args++;
                            }
                            if (v[i + 1] == "(" && v[i + 2] == ")") {
                                args = 0;
                            }
                            else {
                                args++;
                            }
                            res.push_back(Lexem(v[i], new_function, res.back().data_type, args,v[i],res.back().type_signature));
                            //TODO аргументы
                        }
                        else {
                            if (res.back().type != pointer_mark) {
                                res.push_back(Lexem(v[i], new_var, res.back().data_type, 0, res.back().type_signature, res.back().type_signature));
                                temp_vars_types[v[i]] = res.back().type_signature;
                                temp_vars_types_int[v[i]] = res.back().data_type;
                            }
                            else {
                                res.push_back(Lexem(v[i], pointer, res[res.size() - 2].data_type, 0, res[res.size() - 2].type_signature + "*", res[res.size() - 2].type_signature + "*"));
                                temp_vars_types[v[i]] = res[res.size() - 2].type_signature + "*";
                                temp_vars_types_int[v[i]] = res[res.size() - 2].data_type;
                                std::swap(res[res.size() - 1], res[res.size() - 2]);
                                res.pop_back();
                            }
                        }
                    }
                    else {
                        if (temp_vars_types.count(v[i])) {
                            res.push_back(Lexem(v[i], var_name, temp_vars_types_int[v[i]], 0, temp_vars_types[v[i]],temp_vars_types[v[i]]));
                        }
                        else {
                            res.push_back(Lexem(v[i], unknown_name, unknown_name, 0, "unknown","unknown"));
                            if (check_digit(res[res.size() - 1].text) == 2) {
                                res[res.size() - 1].type = double_literal;
                                res[res.size() - 1].type_signature = "double";
                                res[res.size() - 1].data_type = _double_;
                                res[res.size() - 1].returned_type = "double";
                            }
                            else if (check_digit(res[res.size() - 1].text) == 1) {
                                res[res.size() - 1].type = int_literal;
                                res[res.size() - 1].type_signature = "int";
                                res[res.size() - 1].data_type = _int_;
                                res[res.size() - 1].returned_type = "int";
                            }
                        }
                    }
            }
            next_class_name = next_var_name = 0;
        }
        else if (v[i].size() == 5) {
            if (v[i] == "while") {
                res.push_back(Lexem("while", _while_,_while_,1,"void","void"));
            }
            else if (v[i] == "break") {
                res.push_back(Lexem("break", _break_,_break_,0,"void","void"));
            }
            else if (v[i] == "float") {
                res.push_back(Lexem("float", _data_type_,_float_,0,"float","float"));
                next_var_name = 1;
                continue;
            }
            else if (v[i] == "class") {
                res.push_back(Lexem("class", _class_,_class_,0,"void","void"));
                next_class_name = 1;
                continue;
            }
            else {
                if (next_class_name) {
                    hC.add_class_name(v[i]);
                    res.push_back(Lexem(v[i], _data_type_, class_name, 0, v[i],v[i]));
                }
                else if (next_var_name) {
                    if (v[i + 1] == "(") {
                        long long brackets_cnt = 1;
                        size_t args = 0;
                        for (size_t j = i + 2; brackets_cnt != 0; j++) {
                            if (v[j] == "(" || v[j] == "{" || v[j] == "[") brackets_cnt++;
                            else if (v[j] == ")" || v[j] == "}" || v[j] == "]") brackets_cnt--;
                            //else if (in(v[j][0], "abcdefghijklmnopqrtuvwxyz_ABCDEFGHIJKLMNOPQRSTUVWXYZ")) args++;
                            else if (brackets_cnt == 1 && v[j] == ",") args++;
                        }
                        if (v[i + 1] == "(" && v[i + 2] == ")") {
                            args = 0;
                        }
                        else {
                            args++;
                        }
                        res.push_back(Lexem(v[i], new_function, res.back().data_type, args, v[i],res.back().type_signature));
                        //TODO аргументы
                    }
                    else {
                        if (res.back().type != pointer_mark) {
                            res.push_back(Lexem(v[i], new_var, res.back().data_type, 0, res.back().type_signature, res.back().type_signature));
                            temp_vars_types[v[i]] = res.back().type_signature;
                            temp_vars_types_int[v[i]] = res.back().data_type;
                        }
                        else {
                            res.push_back(Lexem(v[i], pointer, res[res.size() - 2].data_type, 0, res[res.size() - 2].type_signature + "*", res[res.size() - 2].type_signature + "*"));
                            temp_vars_types[v[i]] = res[res.size() - 2].type_signature + "*";
                            temp_vars_types_int[v[i]] = res[res.size() - 2].data_type;
                            std::swap(res[res.size() - 1], res[res.size() - 2]);
                            res.pop_back();
                        }
                    }
                }
                else {
                    if (temp_vars_types.count(v[i])) {
                        res.push_back(Lexem(v[i], var_name, temp_vars_types_int[v[i]], 0, temp_vars_types[v[i]], temp_vars_types[v[i]]));
                    }
                    else {
                        res.push_back(Lexem(v[i], unknown_name, unknown_name, 0, "unknown","unknown"));
                        if (check_digit(res[res.size() - 1].text) == 2) {
                            res[res.size() - 1].type = double_literal;
                            res[res.size() - 1].type_signature = "double";
                            res[res.size() - 1].data_type = _double_;
                            res[res.size() - 1].returned_type = "double";
                        }
                        else if (check_digit(res[res.size() - 1].text) == 1) {
                            res[res.size() - 1].type = int_literal;
                            res[res.size() - 1].type_signature = "int";
                            res[res.size() - 1].data_type = _int_;
                            res[res.size() - 1].returned_type = "int";
                        }
                    }
                }
            }
            next_class_name = next_var_name = 0;
        }
        else if (v[i].size() == 6) {
            if (v[i] == "struct") {
                res.push_back(Lexem("struct", _struct_,_struct_,0,"void","void"));
                next_class_name = -1;
                continue;
            }
            else if (v[i] == "delete") {
                res.push_back(Lexem("delete", delete_operator, delete_operator, 1, "delete", "void"));
            }
            else if (v[i] == "double") {
                res.push_back(Lexem("double", _data_type_,_double_,0,"double","double"));
                next_var_name = 1;
                continue;
            }
            else if (v[i] == "string") {
                res.push_back(Lexem("string", _data_type_, _string_, 0, "string", "string"));
                next_var_name = 1;
                continue;
            }
            else if (v[i] == "return") {
                res.push_back(Lexem("return", _return_, _void_, 1, "return","void"));
                continue;
            }
            else {
                if (next_class_name) {
                    hC.add_class_name(v[i]);
                    res.push_back(Lexem(v[i], _data_type_, class_name, 0, v[i],v[i]));
                }
                else if (next_var_name) {
                    if (v[i + 1] == "(") {
                        long long brackets_cnt = 1;
                        size_t args = 0;
                        for (size_t j = i + 2; brackets_cnt != 0; j++) {
                            if (v[j] == "(" || v[j] == "{" || v[j] == "[") brackets_cnt++;
                            else if (v[j] == ")" || v[j] == "}" || v[j] == "]") brackets_cnt--;
                            //else if (in(v[j][0], "abcdefghijklmnopqrtuvwxyz_ABCDEFGHIJKLMNOPQRSTUVWXYZ")) args++;
                            else if (brackets_cnt == 1 && v[j] == ",") args++;
                        }
                        if (v[i + 1] == "(" && v[i + 2] == ")") {
                            args = 0;
                        }
                        else {
                            args++;
                        }
                        res.push_back(Lexem(v[i], new_function, res.back().data_type, args,v[i],res.back().type_signature));
                        //TODO аргументы
                    }
                    else {
                        if (res.back().type != pointer_mark) {
                            res.push_back(Lexem(v[i], new_var, res.back().data_type, 0, res.back().type_signature, res.back().type_signature));
                            temp_vars_types[v[i]] = res.back().type_signature;
                            temp_vars_types_int[v[i]] = res.back().data_type;
                        }
                        else {
                            res.push_back(Lexem(v[i], pointer, res[res.size() - 2].data_type, 0, res[res.size() - 2].type_signature + "*", res[res.size() - 2].type_signature + "*"));
                            temp_vars_types[v[i]] = res[res.size() - 2].type_signature + "*";
                            temp_vars_types_int[v[i]] = res[res.size() - 2].data_type;
                            std::swap(res[res.size() - 1], res[res.size() - 2]);
                            res.pop_back();
                        }
                    }
                }
                else {
                    if (temp_vars_types.count(v[i])) {
                        res.push_back(Lexem(v[i], var_name, temp_vars_types_int[v[i]], 0, temp_vars_types[v[i]], temp_vars_types[v[i]]));
                    }
                    else {
                        res.push_back(Lexem(v[i], unknown_name, unknown_name, 0, "unknown", "unknown"));
                        if (check_digit(res[res.size() - 1].text) == 2) {
                            res[res.size() - 1].type = double_literal;
                            res[res.size() - 1].type_signature = "double";
                            res[res.size() - 1].data_type = _double_;
                            res[res.size() - 1].returned_type = "double";
                        }
                        else if (check_digit(res[res.size() - 1].text) == 1) {
                            res[res.size() - 1].type = int_literal;
                            res[res.size() - 1].type_signature = "int";
                            res[res.size() - 1].data_type = _int_;
                            res[res.size() - 1].returned_type = "int";
                        }
                    }
                }
            }
            next_class_name = next_var_name = 0;
        }
        else if (v[i] == "long_long") {
            res.push_back(Lexem("long_long", _data_type_, _long_long_, 0, "long_long", "long_long"));
            next_var_name = 1;
            continue;
        }
        else {
                if (next_class_name) {
                    hC.add_class_name(v[i]);
                    res.push_back(Lexem(v[i], _data_type_, class_name, 0, v[i],v[i]));
                }
                else if (next_var_name) {
                    if (v[i + 1] == "(") {
                        long long brackets_cnt = 1;
                        size_t args = 0;
                        for (size_t j = i + 2; brackets_cnt != 0; j++) {
                            if (v[j] == "(" || v[j] == "{" || v[j] == "[") brackets_cnt++;
                            else if (v[j] == ")" || v[j] == "}" || v[j] == "]") brackets_cnt--;
                            //else if (in(v[j][0], "abcdefghijklmnopqrtuvwxyz_ABCDEFGHIJKLMNOPQRSTUVWXYZ")) args++;
                            else if (brackets_cnt == 1 && v[j] == ",") args++;
                        }
                        if (v[i + 1] == "(" && v[i + 2] == ")") {
                            args = 0;
                        }
                        else {
                            args++;
                        }
                        res.push_back(Lexem(v[i], new_function, res.back().data_type, args,v[i],res.back().type_signature));
                        //TODO аргументы
                    }
                    else {
                        if (res.back().type != pointer_mark) {
                            res.push_back(Lexem(v[i], new_var, res.back().data_type, 0, res.back().type_signature, res.back().type_signature));
                            temp_vars_types[v[i]] = res.back().type_signature;
                            temp_vars_types_int[v[i]] = res.back().data_type;
                        }
                        else {
                            res.push_back(Lexem(v[i], pointer, res[res.size() - 2].data_type, 0, res[res.size() - 2].type_signature + "*", res[res.size() - 2].type_signature + "*"));
                            temp_vars_types[v[i]] = res[res.size() - 2].type_signature + "*";
                            temp_vars_types_int[v[i]] = res[res.size() - 2].data_type;
                            std::swap(res[res.size() - 1], res[res.size() - 2]);
                            res.pop_back();
                        }
                    }
                }
                else {
                    if (temp_vars_types.count(v[i])) {
                        res.push_back(Lexem(v[i], var_name, temp_vars_types_int[v[i]], 0, temp_vars_types[v[i]],temp_vars_types[v[i]]));
                    }
                    else {
                        res.push_back(Lexem(v[i], unknown_name, unknown_name, 0, "unknown","unknown"));
                        if (check_digit(res[res.size() - 1].text) == 2) {
                            res[res.size() - 1].type = double_literal;
                            res[res.size() - 1].type_signature = "double";
                            res[res.size() - 1].data_type = _double_;
                            res[res.size() - 1].returned_type = "double";
                        }
                        else if (check_digit(res[res.size() - 1].text) == 1) {
                            res[res.size() - 1].type = int_literal;
                            res[res.size() - 1].type_signature = "int";
                            res[res.size() - 1].data_type = _int_;
                            res[res.size() - 1].returned_type = "int";
                        }
                    }
                }
                next_class_name = next_var_name = 0;
        }
    }
    for (size_t i = 0; i < res.size(); i++) {
        if (res[i].type == var_name && res[i].type_signature.back() == '*') {
            res[i].type = pointer;
        }
        if (res[i].type == pointer_mark) {
            res[i].type = deferencing_operator;
            res[i].arg_c = 1;
            res[i].returned_type.pop_back();
            res[i].type_signature = "operator?*::(::" + res[i].returned_type + "*::)";
        }
    }
    for (size_t i = 0; i<res.size(); i++) {
        if ((res[i].type == unknown_name || res[i].type == var_name) && i < res.size() - 1 && res[i + 1].type == round_bracket_open) {
            res[i].type = function_name;
        }
        else if(res[i].type==unknown_name) {
            res[i].type = var_name;
            //res[i].type_signature = temp_vars_types[res[i].text];
            if (check_digit(res[i].text)==2) {
                res[i].type = double_literal;
                res[i].type_signature = "double";
                res[i].data_type = _double_;
                res[i].returned_type = "double";
            }
            else if (check_digit(res[i].text) == 1) {
                res[i].type = int_literal;
                res[i].type_signature = "int";
                res[i].data_type = _int_;
                res[i].returned_type = "double";
            }
        }
    }

    //переделываем new_var в new_static_array
    for (size_t i = 0; i < res.size(); i++) {
        if (i > 0 && i<res.size()-1 && res[i - 1].type == new_var && res[i].type == sq_bracket_open) {
            res[i - 1].type = new_static_array;
            res[i - 1].arg_c = 1;
            res[i - 1].type_signature;// += "?array";
        }
        else if (i > 0 && res[i - 1].type == var_name && res[i].type == sq_bracket_open) {
            res[i - 1].type = static_array;
            res[i - 1].arg_c = 1;
            res[i - 1].type_signature;// += "?array";
        }
        else if (res[i].type == sq_bracket_open) {
            res[i].cs_int64 = 0;
            for (long long index = i - 1; index > -1; index--) {
                if (in(res[index].type, { static_array, new_static_array })) {
                    break;
                }
                else if (res[index].type == sq_bracket_open) {
                    res[index].cs_int64++;
                }
            }
        }
    }

    //сигнатуры новых функций
    for (size_t i = 0; i < res.size(); i++) {

        if (res[i].type == new_function) {
            res[i].type_signature = res[i].returned_type +"::"+ res[i].type_signature;
            std::string arg_signa = "::(::";
            for (size_t j = 0, pos = i + 2; j < res[i].arg_c; pos++) {
                if (res[pos].type == _data_type_ && res[pos].data_type != _void_) {
                    j++;
                    arg_signa += res[pos].type_signature + "::";
                }
            }
            res[i].type_signature += arg_signa + ")";
        }
    }
    
    return res;
}