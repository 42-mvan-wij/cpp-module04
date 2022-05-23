#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat::WrongCat() called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) {
	std::cout << "WrongCat::WrongCat(const WrongCat &) called" << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
	this->type = rhs.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Mauw" << std::endl;
}
