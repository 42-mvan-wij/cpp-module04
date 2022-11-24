#include <iostream>
#include <cstdlib>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

#define ESCAPE "\x1b"
#define CSI ESCAPE "["
#define YELLOW CSI "33m"
#define BLUE CSI "34m"
#define RESET CSI "0m"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q interface");
}

int main() {
	std::atexit(&check_leaks);

	{
		std::cout << YELLOW;

		IMateriaSource* src = new MateriaSource();
		AMateria* ice = new Ice();
		src->learnMateria(ice);
		src->learnMateria(new Cure());
		src->learnMateria(ice);
		src->learnMateria(ice->clone());
		AMateria* cure = new Cure();
		src->learnMateria(cure); // Should not do anything
		delete cure; // so we have to delete the materia manually

		ICharacter* me = new Character("me");

		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("cure"));
		AMateria* slot_index_2 = src->createMateria("ice");
		me->equip(slot_index_2);
		me->equip(src->createMateria("ice"));
		AMateria* tmp = src->createMateria("cure");
		me->equip(tmp); // should not do anything
		delete tmp; // so we have to delete the materia manually
		me->unequip(2);
		delete slot_index_2;

		ICharacter* bob = new Character("bob");
		std::cout << RESET;

		std::cout << "Using materia at index " << 0 << ":" << std::endl;
		me->use(0, *bob);
		std::cout << std::endl;
		std::cout << "Using materia at index " << 1 << ":" << std::endl;
		me->use(1, *bob);
		std::cout << std::endl;
		std::cout << "Using materia at index " << 2 << " (nothing equipped here):" << std::endl;
		me->use(2, *bob);
		std::cout << std::endl;
		std::cout << "Using materia at index " << 3 << ":" << std::endl;
		me->use(3, *bob);
		std::cout << std::endl;
		std::cout << "Using materia at index " << 4 << " (out of bounds):" << std::endl;
		me->use(4, *bob);
		std::cout << std::endl;

		std::cout << YELLOW;

		delete bob;
		delete me;
		delete src;
	}
	std::cout << RESET;

	return (0);
}
