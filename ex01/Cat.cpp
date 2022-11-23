#include <iostream>
#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*src.brain);
}

Cat &Cat::operator=(Cat const &rhs) {
	if (this == &rhs)
		return *this;
	Animal::operator=(rhs);
	delete brain;
	brain = new Brain(*rhs.brain);
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const {
	std::cout << "Mauw" << std::endl;
}

void Cat::giveIdea(std::string idea) const {
	this->brain->addIdea(idea);
}

const Brain *Cat::getBrain() const {
	return this->brain;
}
