#include <iostream>
#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Default Animal constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &src) : type(src.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs) {
	if (this == &rhs)
		return *this;
	this->type = rhs.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string const &Animal::getType() const {
	return this->type;
}
