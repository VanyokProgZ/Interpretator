#include "preprocess.h"

void INSERT_FILE(std::vector<std::string>& rows) {

	for (long long row_ind = 0; row_ind < rows.size(); row_ind++) {
		if (rows[row_ind].size() == 0)continue;
		auto str_p = split(rows[row_ind]);
		if (str_p[0] == "#" && str_p[1] == "INSERT_FILE") {

			std::string fname = "";
			for (size_t i = 2; i < str_p.size(); i++) fname += str_p[i];
			auto v = grab_file(fname);
			for (auto& el : v) {
				cut_white_begin(el); past_spaces(el);
			}
			std::vector<std::string>::iterator it = rows.begin() + row_ind;
			rows.erase(it);
			it = rows.begin() + row_ind;
			rows.insert(it, v.begin(), v.end());
			row_ind = -1;
		}
	}

}