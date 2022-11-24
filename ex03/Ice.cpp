#include <iostream>
#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src) {
	std::cout << "Ice copy constructor called" << std::endl;
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

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
