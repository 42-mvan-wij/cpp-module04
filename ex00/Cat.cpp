#include <iostream>
#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs) {
	if (this == &rhs)
		return *this;
	Animal::operator=(rhs);
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
