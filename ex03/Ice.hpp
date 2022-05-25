#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria {
	public:
		Ice();
		Ice(Ice const &src);
		virtual ~Ice();

		Ice &operator=(Ice const &rhs);

		AMateria* clone() const;
		void use(ICharacter& c);

	protected:

};

#endif
