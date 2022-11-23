#include <iostream>
#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &src) : AAnimal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*src.brain);
}

Cat &Cat::operator=(Cat const &rhs) {
	if (this == &rhs)
		return *this;
	AAnimal::operator=(rhs);
	delete this->brain;
	this->brain = new Brain(*rhs.brain);
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

void Cat::giveIdea(std::string idea) const {
	this->brain->addIdea(idea);
}

const Brain *Cat::getBrain() const {
	return this->brain;
}
