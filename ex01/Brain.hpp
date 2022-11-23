#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

# define IDEAS 100

class Brain {
	public:
		Brain();
		Brain(Brain const &src);
		virtual ~Brain();

		Brain &operator=(Brain const &rhs);

		std::string ideas[IDEAS];

		void addIdea(std::string idea);

	private:
		int ideaIndex;
};

#endif
