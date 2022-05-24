#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < NUM_MATERIAS; i++) {
		this->materias[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	*this = src;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {

	return *this;
}

MateriaSource::~MateriaSource() {

}

void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < NUM_MATERIAS; i++) {
		if (this->materias[i] == nullptr) {
			this->materias[i] = materia->clone();
			break ;
		}
	}
}
