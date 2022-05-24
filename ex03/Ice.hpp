#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(Ice const &src);
		virtual ~Ice();

		Ice &operator=(Ice const &rhs);

		AMateria* clone() const = 0;
		void use(ICharacter& c);

	protected:

};

#endif
