#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# define NUM_MATERIAS 4

class AMateria;

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &src);
		~MateriaSource();

		MateriaSource &operator=(MateriaSource const &rhs);

		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const& type);

	protected:
		AMateria* materias[NUM_MATERIAS];
};

#endif
