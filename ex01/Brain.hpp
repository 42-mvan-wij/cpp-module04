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

		void addIdea(std::string idea);
		void printIdeas() const;

	private:
		int ideaIndex;
		int ideaCount;
		std::string ideas[IDEAS];

};

#endif
