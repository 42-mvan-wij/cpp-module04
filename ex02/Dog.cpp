#include <iostream>
#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Default Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*src.brain);
}

Dog &Dog::operator=(Dog const &rhs) {
	if (this == &rhs)
		return *this;
	Animal::operator=(rhs);
	delete this->brain;
	this->brain = new Brain(*rhs.brain);
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}

void Dog::giveIdea(std::string idea) const {
	this->brain->addIdea(idea);
}

const Brain *Dog::getBrain() const {
	return this->brain;
}
