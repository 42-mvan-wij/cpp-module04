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
	for (int i = 0; i < NUM_MATERIAS; i++) {
		if (this->materias[i] != nullptr)
			delete this->materias[i];
		if (rhs.materias[i] == nullptr)
			this->materias[i] = nullptr;
		else
			this->materias[i] = rhs.materias[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < NUM_MATERIAS; i++) {
		if (this->materias[i] == nullptr)
			continue ;
		delete this->materias[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < NUM_MATERIAS; i++) {
		if (this->materias[i] == nullptr) {
			this->materias[i] = materia;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < NUM_MATERIAS; i++) {
		if (this->materias[i] == nullptr)
			continue ;
		if (this->materias[i]->getType() == type)
			return this->materias[i]->clone();
	}
	return nullptr;
}
