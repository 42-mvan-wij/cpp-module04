#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
// # include "AMateria.hpp"

# define INV_SLOTS 4

class AMateria;

class Character : public ICharacter {
	public:
		Character();
		Character(Character const &src);
		~Character();
		Character &operator=(Character const &rhs);

		Character(std::string const & name);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	protected:
		AMateria *inventory[INV_SLOTS];
		std::string name;
};

#endif
