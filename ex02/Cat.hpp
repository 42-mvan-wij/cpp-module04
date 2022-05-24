#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(Cat const &src);
		virtual ~Cat();

		Cat &operator=(Cat const &rhs);

		void makeSound() const;
		void giveIdea(std::string idea) const;

		const Brain *getBrain() const;

	private:
		Brain *brain;
};

#endif
