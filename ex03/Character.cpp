#include <iostream>
#include "Character.hpp"

Character::Character() {
	std::cout << "Default Character constructor called" << std::endl;
	for (int i = 0; i < INV_SLOTS; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(const Character &src) {
	std::cout << "Character copy constructor called" << std::endl;
	*this = src;
}

Character::Character(std::string const & name) : name(name) {
	std::cout << "Character::Character(std::string const &) constructor called" << std::endl;
	for (int i = 0; i < INV_SLOTS; i++) {
		inventory[i] = NULL;
	}
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < INV_SLOTS; i++) {
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
}

Character &Character::operator=(Character const &rhs) {
	if (this == &rhs)
		return *this;
	this->name = rhs.name;
	for (int i = 0; i < INV_SLOTS; i++) {
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
		if (rhs.inventory[i] == NULL)
			this->inventory[i] = NULL;
		else
			this->inventory[i] = rhs.inventory[i]->clone();
	}
	return *this;
}

std::string const & Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < INV_SLOTS; i++) {
		if (inventory[i] == NULL) {
			inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= INV_SLOTS)
		return ;
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= INV_SLOTS)
		return ;
	if (inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
}
