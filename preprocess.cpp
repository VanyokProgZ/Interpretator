#include "preprocess.h"

void INSERT_FILE(std::vector<std::string>& rows) {

	for (size_t row_ind = 0; row_ind < rows.size(); row_ind++) {
		auto str_p = split(rows[row_ind]);
		if (str_p.size() == 3 && str_p[0] == "#" && str_p[1] == "INSERT_FILE") {

			auto v = grab_file(str_p[2]);
			for (auto& el : v) {
				cut_white_begin(el); past_spaces(el);
			}
			std::vector<std::string>::iterator it = rows.begin() + row_ind;
			rows.erase(it);
			it = rows.begin() + row_ind;
			rows.insert(it, v.begin(), v.end());
			row_ind = 0;
		}
	}

}