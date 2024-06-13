#pragma once
#include <iostream>

class Brain {
	public:
		Brain(void);
		Brain(std::string const & idea);
		Brain(Brain const & src);
		~Brain(void);

		Brain &		operator=(Brain const & src);
		void		setIdea(std::string const & idea, int const index);
		void		printIdeas(void) const;

		std::string	ideas[100];
};
