#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ANIMALS 10

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks -q abstract-animals");
}

int main() {
	const Animal* animals[ANIMALS];
	for (int i = 0; i < ANIMALS / 2; i++) {
		animals[i] = new Dog();
		animals[i + ANIMALS / 2] = new Cat();
	}

	const Dog d;
	d.giveIdea("Food");
	d.giveIdea("Cuddles");
	const Dog dd(d);

	for (int i = 0; i < ANIMALS; i++) {
		delete animals[i];
	}
	return (0);
}
