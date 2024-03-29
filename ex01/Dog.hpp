#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(Dog const &src);
		virtual ~Dog();

		Dog &operator=(Dog const &rhs);

		void makeSound() const;
		void giveIdea(std::string idea) const;

		const Brain *getBrain() const;

	private:
		Brain *brain;
};

#endif
