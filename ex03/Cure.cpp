#include <iostream>
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Default Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src) {
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &rhs) {
	if (this == &rhs)
		return *this;
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
