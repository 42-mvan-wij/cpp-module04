#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria {
	public:
		AMateria(std::string const &type);
		virtual ~AMateria() {};

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);

	protected:
		std::string type;
};

#endif
