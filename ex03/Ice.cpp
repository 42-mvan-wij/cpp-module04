#include <iostream>
#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice &src) : AMateria("ice") {
	*this = src;
}

Ice &Ice::operator=(Ice const &rhs) {
	(void)rhs;
	return *this;
}

Ice::~Ice() {

}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& c) {
	std::cout << "* shoots an ice bolt at " << c.getName() << " *" << std::endl;
}
