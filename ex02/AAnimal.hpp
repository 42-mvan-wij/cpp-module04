#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal {
	public:
		AAnimal();
		AAnimal(AAnimal const &src);
		virtual ~AAnimal();

		AAnimal &operator=(AAnimal const &rhs);

		virtual void makeSound() const = 0;
		virtual std::string const &getType() const;

	protected:
		std::string type;
};

#endif
