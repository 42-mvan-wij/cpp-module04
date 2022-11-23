#include <iostream>
#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &src) : AMateria("ice") {
	std::cout << "Ice copy constructor called" << std::endl;
	*this = src;
}

Ice &Ice::operator=(Ice const &rhs) {
	if (this == &rhs)
		return *this;
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& c) {
	std::cout << "* shoots an ice bolt at " << c.getName() << " *" << std::endl;
}
