#include <iostream>
#include <cstdlib>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ESCAPE "\x1b"
#define CSI ESCAPE "["
#define GREEN CSI "32m"
#define YELLOW CSI "33m"
#define BLUE CSI "34m"
#define RESET CSI "0m"

#define ANIMALS_HALF 2

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q smart-animals");
}

int main() {
	std::atexit(&check_leaks);

	std::cout << std::boolalpha;

	const Animal* animals[ANIMALS_HALF * 2];
	for (int i = 0; i < ANIMALS_HALF; i++) {
		animals[i] = new Dog();
		std::cout << "----------" << std::endl;
	}
	for (int i = 0; i < ANIMALS_HALF; i++) {
		animals[i + ANIMALS_HALF] = new Cat();
		std::cout << "----------" << std::endl;
	}

	std::cout << std::endl;
	std::cout << BLUE << "START MIDDLE" << RESET << std::endl;
	{
		const Dog d;
		d.giveIdea("Food");
		d.giveIdea("Cuddles");
		std::cout << GREEN << "Thoughts:" << RESET << std::endl;
		d.getBrain()->printIdeas();

		std::cout << std::endl;

		const Dog dd(d);
		std::cout << "Is shallow dog copy: " << YELLOW << (d.getBrain() == dd.getBrain()) << RESET << std::endl;
		std::cout << GREEN << "Thoughts:" << RESET << std::endl;
		dd.getBrain()->printIdeas();

		std::cout << std::endl;

		const Cat c;
		c.giveIdea("Food");
		c.giveIdea("World Domination");
		std::cout << GREEN << "Thoughts:" << RESET << std::endl;
		c.getBrain()->printIdeas();

		std::cout << std::endl;

		const Cat cc(c);
		std::cout << "Is shallow cat copy: " << YELLOW << (c.getBrain() == cc.getBrain()) << RESET << std::endl;
		std::cout << GREEN << "Thoughts:" << RESET << std::endl;
		cc.getBrain()->printIdeas();

		std::cout << std::endl;
	}
	std::cout << BLUE << "END MIDDLE" << RESET << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < ANIMALS_HALF * 2; i++) {
		delete animals[i];
		std::cout << "----------" << std::endl;
	}
	return (0);
}
