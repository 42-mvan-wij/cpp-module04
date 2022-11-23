#include <iostream>
#include <cstdlib>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q animals");
}

int main() {
	std::atexit(&check_leaks);
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	animal->makeSound();

	{
		std::cout << "\n\n " << std::endl;

		const WrongAnimal* wrong_animal = new WrongAnimal();
		const WrongAnimal* wrong_cat = new WrongCat();

		std::cout << wrong_cat->getType() << " " << std::endl;
		wrong_cat->makeSound();
		wrong_animal->makeSound();

		delete wrong_animal;
		delete wrong_cat;
	}
	delete animal;
	delete dog;
	delete cat;
	return (0);
}
