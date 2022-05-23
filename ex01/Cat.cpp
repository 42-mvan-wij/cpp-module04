#include <iostream>
#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat::Cat() called" << std::endl;
	this->type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &src) {
	std::cout << "Cat::Cat(const Cat &) called" << std::endl;
	brain = new Brain(*src.brain);
}

Cat &Cat::operator=(Cat const &rhs) {
	this->type = rhs.type;
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
