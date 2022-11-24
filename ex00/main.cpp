#include <iostream>
#include <cstdlib>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define ESCAPE "\x1b"
#define CSI ESCAPE "["
#define BLUE CSI "34m"
#define RESET CSI "0m"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q animals");
}

int main() {
	std::atexit(&check_leaks);

	{
		std::cout << BLUE << "TEST BLOCK 1" << RESET << std::endl;
		const Animal* animal = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << std::endl;

		std::cout << "dog type: " << dog->getType() << std::endl;
		std::cout << "cat type: " << cat->getType() << std::endl;
		std::cout << "animal type: " << animal->getType() << std::endl;

		std::cout << std::endl;

		std::cout << "cat sound: "; cat->makeSound();
		std::cout << "dog sound: "; dog->makeSound();
		std::cout << "animal sound: "; animal->makeSound();

		std::cout << std::endl;

		delete animal;
		delete dog;
		delete cat;
	}

	std::cout << std::endl;

	{
		std::cout << BLUE << "TEST BLOCK 2" << RESET << std::endl;
		const WrongAnimal* wrong_animal = new WrongAnimal();
		const WrongAnimal* wrong_cat = new WrongCat();

		std::cout << std::endl;

		std::cout << "wrong_cat type: " << wrong_cat->getType() << std::endl;
		std::cout << "wrong_animal type: " << wrong_animal->getType() << std::endl;

		std::cout << std::endl;

		std::cout << "wrong_cat sound: "; wrong_cat->makeSound();
		std::cout << "wrong_animal sound: "; wrong_animal->makeSound();

		std::cout << std::endl;

		delete wrong_animal;
		delete wrong_cat;
	}

	return (0);
}
