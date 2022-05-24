#include <iostream>
#include "Character.hpp"

Character::Character() {
	for (int i = 0; i < INV_SLOTS; i++) {
		inventory[i] = nullptr;
	}
}

Character::Character(const Character &src) {
	*this = src;
}

Character::~Character() {
	for (int i = 0; i < INV_SLOTS; i++) {
		if (this->inventory[i] != nullptr)
			delete this->inventory[i];
	}
}

Character &Character::operator=(Character const &rhs) {
	this->name = rhs.name;
	for (int i = 0; i < INV_SLOTS; i++) {
		if (this->inventory[i] != nullptr)
			delete this->inventory[i];
		if (rhs.inventory[i] == nullptr)
			this->inventory[i] = nullptr;
		else
			this->inventory[i] = rhs.inventory[i]->clone();
	}
	return *this;
}

Character::Character(std::string const & name) : name(name) {
	for (int i = 0; i < INV_SLOTS; i++) {
		inventory[i] = nullptr;
	}
}

std::string const & Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < INV_SLOTS; i++) {
		if (inventory[i] == nullptr) {
			inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= INV_SLOTS)
		return ;
	inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= INV_SLOTS)
		return ;
	if (inventory[idx] == nullptr)
		return ;
	inventory[idx]->use(target);
}
