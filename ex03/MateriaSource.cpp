#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "Default MateriaSource constructor called" << std::endl;
	for (int i = 0; i < NUM_MATERIAS; i++) {
		this->materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = src;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
	if (this == &rhs)
		return *this;
	for (int i = 0; i < NUM_MATERIAS; i++) {
		if (this->materias[i] != NULL)
			delete this->materias[i];
		if (rhs.materias[i] == NULL)
			this->materias[i] = NULL;
		else
			this->materias[i] = rhs.materias[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < NUM_MATERIAS; i++) {
		if (this->materias[i] == NULL)
			continue ;
		delete this->materias[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < NUM_MATERIAS; i++) {
		if (this->materias[i] == NULL) {
			this->materias[i] = materia;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < NUM_MATERIAS; i++) {
		if (this->materias[i] == NULL)
			continue ;
		if (this->materias[i]->getType() == type)
			return this->materias[i]->clone();
	}
	return NULL;
}
