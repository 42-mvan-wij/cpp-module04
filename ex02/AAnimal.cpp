#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Unknown Animal") {
	std::cout << "Default AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) : type(src.type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs) {
	if (this == &rhs)
		return *this;
	this->type = rhs.type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string const &AAnimal::getType() const {
	return this->type;
}
