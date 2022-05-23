#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &src);
		virtual ~WrongAnimal();

		WrongAnimal &operator=(WrongAnimal const &rhs);

		void makeSound() const;
		virtual std::string const &getType() const;

	protected:
		std::string type;
};

#endif
