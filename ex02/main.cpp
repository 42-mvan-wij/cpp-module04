#include <iostream>
#include <cstdlib>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ANIMALS_HALF 2

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q smart-animals");
}

int main() {
	std::atexit(&check_leaks);

	std::cout << std::boolalpha;

	// AAnimal animal; // NOTE: Will not work with this line in
	// AAnimal *animal = new AAnimal(); // NOTE: Will not work with this line in

	const AAnimal* animals[ANIMALS_HALF * 2];
	for (int i = 0; i < ANIMALS_HALF; i++) {
		animals[i] = new Dog();
		std::cout << "----------" << std::endl;
	}
	for (int i = 0; i < ANIMALS_HALF; i++) {
		animals[i + ANIMALS_HALF] = new Cat();
		std::cout << "----------" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\x1b[34m" << "START MIDDLE" << "\x1b[0m" << std::endl;
	{
		const Dog d;
		d.giveIdea("Food");
		d.giveIdea("Cuddles");
		std::cout << "\x1b[32m" << "Thoughts:" << "\x1b[0m" << std::endl;
		d.getBrain()->printIdeas();

		std::cout << std::endl;

		const Dog dd(d);
		std::cout << "Is shallow dog copy: " << "\x1b[33m" << (d.getBrain() == dd.getBrain()) << "\x1b[0m" << std::endl;
		std::cout << "\x1b[32m" << "Thoughts:" << "\x1b[0m" << std::endl;
		dd.getBrain()->printIdeas();

		std::cout << std::endl;

		const Cat c;
		c.giveIdea("Food");
		c.giveIdea("World Domination");
		std::cout << "\x1b[32m" << "Thoughts:" << "\x1b[0m" << std::endl;
		c.getBrain()->printIdeas();

		std::cout << std::endl;

		const Cat cc(c);
		std::cout << "Is shallow cat copy: " << "\x1b[33m" << (c.getBrain() == cc.getBrain()) << "\x1b[0m" << std::endl;
		std::cout << "\x1b[32m" << "Thoughts:" << "\x1b[0m" << std::endl;
		cc.getBrain()->printIdeas();

		std::cout << std::endl;
	}
	std::cout << "\x1b[34m" << "END MIDDLE" << "\x1b[0m" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < ANIMALS_HALF * 2; i++) {
		delete animals[i];
		std::cout << "----------" << std::endl;
	}
	return (0);
}
