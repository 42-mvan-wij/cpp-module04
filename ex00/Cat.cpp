#include <iostream>
#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat::Cat() called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &src) {
	std::cout << "Cat::Cat(const Cat &) called" << std::endl;
	*this = src;
}

Cat &Cat::operator=(Cat const &rhs) {
	this->type = rhs.type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Mauw" << std::endl;
}
