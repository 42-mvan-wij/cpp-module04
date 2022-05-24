#include <iostream>

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks -q interface");
}

int main() {
	return (0);
}
