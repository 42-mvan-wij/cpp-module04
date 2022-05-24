#include <iostream>
#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal::Animal() called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &src) {
	std::cout << "Animal::Animal(const Animal &) called" << std::endl;
	*this = src;
}

Animal &Animal::operator=(Animal const &rhs) {
	this->type = rhs.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string const &Animal::getType() const {
	return this->type;
}
