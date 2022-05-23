#include <iostream>
#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog::Dog() called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &src) {
	std::cout << "Dog::Dog(const Dog &) called" << std::endl;
	*this = src;
}

Dog &Dog::operator=(Dog const &rhs) {
	this->type = rhs.type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}
