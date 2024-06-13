#include "Brain.hpp"
#include <string>
#include "colours.hpp"

Brain::Brain(void){
	std::cout << "... with a brain" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "idea " + std::to_string(i);
	return;
}

Brain::Brain(std::string const & idea){
	std::cout << "... with a brain" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea + " " + std::to_string(i);
	return;
}

Brain::Brain(Brain const & src){
	std::cout << "... also with a brain" << std::endl;
	*this = src;
	return;
}

Brain::~Brain(void){
	std::cout << "There's no more brain activity" << std::endl;
	return;
}

Brain &	Brain::operator=(Brain const & src){
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return *this;
}

void	Brain::setIdea(std::string const & idea, int const index){
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
	return;
}

void	Brain::printIdeas(void) const {
	for (int i = 0; i < 100; i++)
		std::cout << GRAY << this->ideas[i] << NC << std::endl;
	return;
}
