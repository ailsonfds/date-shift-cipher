#include "decifrar.hpp"

decifrar::decifrar() {}

std::string &decifrar::decipher(std::string msg, std::string date) {
	int i = 0;
	int j = 0;
	std::string* result = new std::string();

	for(char c : msg) {
		char c_upper = std::toupper(c);
		if (c_upper >= 'A' && c_upper <= 'Z') {
			char value = c_upper - (date[j] - '0');
			*result = (*result) + char(value < 'A' ? (value - 'A') + 'Z' + 1 : value);
			j >= date.size() - 1 ? j = 0 : j++;
		} else {
			*result = (*result) + c;
		}
	}
	return *result;
}

