#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type) {

}

std::string const & AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter &target) {
	(void)target;
}
