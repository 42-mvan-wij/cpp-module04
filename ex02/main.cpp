#include <iostream>
#include <cstdlib>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ANIMALS 10

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q abstract-animals");
}

int main() {
	std::atexit(&check_leaks);

	std::cout << std::boolalpha;

	const Animal* animals[ANIMALS];
	for (int i = 0; i < ANIMALS / 2; i++) {
		animals[i] = new Dog();
		animals[i + ANIMALS / 2] = new Cat();
	}

	const Dog d;
	d.giveIdea("Food");
	d.giveIdea("Cuddles");
	const Dog dd(d);
	std::cout << "Is shallow copy: " << (d.getBrain() == dd.getBrain()) << std::endl;

	const Cat c;
	c.giveIdea("Food");
	c.giveIdea("World Domination");
	const Cat cc(c);
	std::cout << "Is shallow copy: " << (c.getBrain() == cc.getBrain()) << std::endl;

	for (int i = 0; i < ANIMALS; i++) {
		delete animals[i];
	}
	return (0);
}
