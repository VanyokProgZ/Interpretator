#include "handlers.h"


//имена функций
handleFuncNames::handleFuncNames() {};
void handleFuncNames::NewFunc(const std::string& signa, size_t pos) {
	Position[signa] = pos + 1;
	last_function_signature = signa;
}
bool handleFuncNames::FuncExist(const std::string& signa) {
	return Position[signa];
}
size_t handleFuncNames::GetPosFunc(const std::string& signa) {
	return Position[signa] - 1;
}
void handleFuncNames::DelFunc(const std::string& signa) {
	Position.erase(signa);
}
std::vector<std::string> handleFuncNames::get_Args(const std::string& signa) { return Args[signa]; }
void handleFuncNames::set_Args(const std::string& signa, const std::vector<std::string>& args) {Args[signa] = args;}

//изначальные строки
handleStrings::handleStrings() {};
void handleStrings::NewString(const std::string& str, size_t pos) {
	Strings[pos + 1].push_back(str);
}
bool handleStrings::StringExist(size_t pos) {
	return Strings[pos + 1].size();
}
std::string handleStrings::GetString(size_t pos, size_t arrpos) {
	return Strings[pos + 1][arrpos];
}


//имена классов
handleClassNames::handleClassNames() {
	class_sizes["int"] = 1;
	class_sizes["double"] = 1;
	class_sizes["char"] = 1;
	class_sizes["float"] = 1;
	class_sizes["long_long"] = 1;
	class_sizes["bool"] = 1;
	class_sizes["string"] = 1;
};
void handleClassNames::add_class_name(const std::string& name) {
	class_names.insert(name);
}
bool handleClassNames::isClass(const std::string& name) { return class_names.count(name); }

void handleClassNames::add_class_size(const std::string& name, size_t sz) {
	class_sizes[name] = sz;
}
size_t handleClassNames::get_class_size(const std::string& name) {
	return class_sizes[name];
}