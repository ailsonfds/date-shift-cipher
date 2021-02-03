#include "cifrar.hpp"
#include <iostream>
#include <cassert>

int main(int argc, char* argv[]) {
	cifrar* cif = new cifrar();
	assert(cif->get_cipher("Eu gosto dos filmes de Steven Spielberg", "181246").compare("FC HQWZP LPU JOMUFU HK TBFXIT TXJGPHFZH") == 0);
	std::cout << "Everything good on cifrar class" << std::endl;
	return 0;
}
