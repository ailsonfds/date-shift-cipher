#include "decifrar.hpp"
#include <iostream>
#include <cassert>

int main(int argc, char* argv[]) {
	decifrar* decif = new decifrar();
	assert(decif->decipher("FC HQWZP LPU JOMUFU HK TBFXIT TXJGPHFZH", "181246").compare("EU GOSTO DOS FILMES DE STEVEN SPIELBERG") == 0);
	std::cout << "Everything good on decifrar class" << std::endl;
	return 0;
}
