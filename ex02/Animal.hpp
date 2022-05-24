#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
	public:
		Animal();
		Animal(Animal const &src);
		virtual ~Animal();

		Animal &operator=(Animal const &rhs);

		virtual void makeSound() const = 0;
		virtual std::string const &getType() const;

	protected:
		std::string type;
};

#endif
