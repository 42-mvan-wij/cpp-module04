#include <iostream>
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Default Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &src) : AMateria("cure") {
	std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
}

Cure &Cure::operator=(Cure const &rhs) {
	if (this == &rhs)
		return *this;
	this->type = rhs.type;
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
