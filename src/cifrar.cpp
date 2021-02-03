#include "cifrar.hpp"

cifrar::cifrar() {}

std::string &cifrar::get_cipher(std::string msg, std::string date) {
	int i = 0;
	int j = 0;
	std::string* result = new std::string();

	for(char c : msg) {
		char c_upper = std::toupper(c);
		if (c_upper >= 'A' && c_upper <= 'Z') {
			char value = c_upper + (date[j] - '0');
			*result = (*result) + char(value > 'Z' ? (value - 'Z' - 1) + 'A' : value);
			j >= date.size() - 1 ? j = 0 : j++;
		} else {
			*result = (*result) + c;
		}
	}
	return *result;
}

