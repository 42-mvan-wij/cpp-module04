#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "Default WrongCat constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
	if (this == &rhs)
		return *this;
	WrongAnimal::operator=(rhs);
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Wrong Meow" << std::endl;
}
