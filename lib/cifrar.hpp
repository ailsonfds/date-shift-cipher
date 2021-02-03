#ifndef __CIFRAR_HPP__
#define __CIFRAR_HPP__

#include <string>

class cifrar {
	public:
		cifrar();
		std::string &get_cipher(std::string msg, std::string date);
};

#endif /** __CIFRAR_HPP__ **/
