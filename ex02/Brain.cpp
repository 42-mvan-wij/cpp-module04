#include <iostream>
#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain::Brain() called" << std::endl;
	this->ideaIndex = 0;
}

Brain::Brain(const Brain &src) {
	std::cout << "Brain::Brain(const Brain &) called" << std::endl;
	*this = src;
}

Brain &Brain::operator=(Brain const &rhs) {
	for (int i = 0; i < IDEAS; i++) {
		this->ideas[i] = rhs.ideas[i];
	}
	this->ideaIndex = rhs.ideaIndex;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::addIdea(std::string idea) {
	this->ideas[this->ideaIndex] = idea;
	this->ideaIndex++;
	this->ideaIndex %= IDEAS;
}
