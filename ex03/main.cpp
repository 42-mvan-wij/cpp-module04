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
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->unequip(2);
	delete tmp;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	delete bob;
	delete me;
	delete src;
	return (0);
}
