#include <iostream>
#include <fstream>
#include <algorithm>
#include <regex>
#include <string>
#include "cifrar.hpp"
#include "decifrar.hpp"

void print_help(char*);
std::string &read_input_file(std::string);
bool validate_date(std::string);

int main(int argc, char* argv[]) {

	std::string help("--help");
	std::string cifrar_opt("cifrar");
	std::string decifrar_opt("cifrar");

	if (argc <= 1) {
		print_help(argv[0]);
		return 1;
	} else if (argc == 2 && help.compare(argv[1]) == 0) {
		print_help(argv[0]);
		return 0;
	}



	std::string input_filename(argv[3]);
	std::string date(argv[2]);

	if (!validate_date(date)) {
		std::cerr << "DATE argument format invalid!" << std::endl;
		return 1;
	}

	cifrar cif;

	date.erase(std::remove(date.begin(), date.end(), '/'), date.end());

	std::string input_file_content = read_input_file(input_filename);

	if (cifrar_opt.compare(argv[1]) == 0) {
		std::string output_filename(argv[4]);
		std::string cipher = cif.get_cipher(input_file_content, date);

		std::ofstream outputfile;

		outputfile.open(output_filename);
		outputfile << cipher;
		outputfile.close();

		return 0;
	} else if (decifrar_opt.compare(argv[1]) == 0) {
		return 0;
	}

	print_help(argv[0]);
	return 1;

}

void print_help(char* binapp) {

	std::cout << binapp << " basic usage:" << std::endl << std::endl;
	std::cout << "\tcipher message:   " << binapp << " cifrar DATE INPUT_FILE OUTPUT_FILE" << std::endl;
	std::cout << "\tdecipher message: " << binapp << " decifrar DATE INPUT_FILE" << std::endl;
	std::cout << std::endl << "DATE:" << std::endl << "\tDate string formated as dd/mm/yy" << std::endl;
	std::cout << std::endl << "INPUT_FILE:" << std::endl << "\tFile name with the deciphered/ciphered message to cipher/decipher" << std::endl;
	std::cout << std::endl << "OUTPUT_FILE:" << std::endl << "\tFile name to record the ciphered message created by cifrero" << std::endl;

}

std::string &read_input_file(std::string input_filename) {

	std::string* result = new std::string();
	std::string temp;

	std::ifstream inputfile;
	inputfile.open(input_filename);

	while (std::getline(inputfile,temp)) {
		*result = *result + temp;
		*result = *result + '\n';
	}

	inputfile.close();

	return *result;

}

bool validate_date(std::string date) {

	if (date.size() != 8) return false;

	std::regex rex("([0-9]{2}/){2}[0-9]{2}");

	return std::regex_match(date, rex);

}

