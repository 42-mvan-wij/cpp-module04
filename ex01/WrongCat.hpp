#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat const &src);
		virtual ~WrongCat();

		WrongCat &operator=(WrongCat const &rhs);

		void makeSound() const;
};

#endif
