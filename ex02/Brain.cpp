#include <iostream>
#include "Brain.hpp"

Brain::Brain() : ideaIndex(0), ideaCount(0) {
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &src) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain &Brain::operator=(Brain const &rhs) {
	if (this == &rhs)
		return *this;
	for (int i = 0; i < rhs.ideaCount; i++) {
		this->ideas[i] = rhs.ideas[i];
	}
	this->ideaIndex = rhs.ideaIndex;
	this->ideaCount = rhs.ideaCount;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::addIdea(std::string idea) {
	this->ideas[this->ideaIndex] = idea;
	this->ideaIndex++;
	if (this->ideaCount < IDEAS)
		this->ideaCount++;
	this->ideaIndex %= IDEAS;
}

void Brain::printIdeas() const {
	if (this->ideaCount < IDEAS) {
		for (int i = 0; i < this->ideaCount; i++) {
			std::cout << this->ideas[i] << std::endl;
		}
	}
	else {
		for (int i = 0; i < this->ideaCount; i++) {
			std::cout << this->ideas[(i + this->ideaIndex) % IDEAS] << std::endl;
		}
	}
}
