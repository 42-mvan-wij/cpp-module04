#include <iostream>
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure &src) : AMateria("cure") {
	*this = src;
}

Cure &Cure::operator=(Cure const &rhs) {
	(void)rhs;
	return *this;
}

Cure::~Cure() {

}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
