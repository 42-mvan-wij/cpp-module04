#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(Cure const &src);
		virtual ~Cure();

		Cure &operator=(Cure const &rhs);

		AMateria* clone() const = 0;
		void use(ICharacter& target);

	protected:

};

#endif
