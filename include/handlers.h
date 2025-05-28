#pragma once

#include <map>
#include <set>
#include "iostream"
#include <vector>

class handleFuncNames {
std::map<std::string, size_t> Position;
std::map<std::string, std::vector<std::string>> Args;
public:
	std::string last_function_signature;

	void NewFunc(const std::string& signa, size_t pos);
	void DelFunc(const std::string& signa);
	bool FuncExist(const std::string& signa);
	size_t GetPosFunc(const std::string& signa);

	std::vector<std::string> get_Args(const std::string& signa);
	void set_Args(const std::string& signa, const std::vector<std::string>& args);
};


class handleClassNames {
	std::set<std::string> class_names;
	std::map<std::string, size_t> class_sizes;
public:
	handleClassNames();
	void add_class_name(const std::string& name);
	bool isClass(const std::string& name);
	void add_class_size(const std::string& name, size_t sz);
	size_t get_class_size(const std::string& name);
};