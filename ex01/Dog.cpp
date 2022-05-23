#include <iostream>
#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog::Dog() called" << std::endl;
	this->type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &src) {
	std::cout << "Dog::Dog(const Dog &) called" << std::endl;
	brain = new Brain(*src.brain);
}

Dog &Dog::operator=(Dog const &rhs) {
	this->type = rhs.type;
	delete brain;
	brain = new Brain(*rhs.brain);
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}

void Dog::giveIdea(std::string idea) const {
	this->brain->addIdea(idea);
}
