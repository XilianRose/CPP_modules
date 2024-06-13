#pragma once
#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		Dog(Dog const & src);
		~Dog(void);

		Dog &			operator=(Dog const & src);
		virtual void	makeSound(void) const;

	protected:
		std::string	_type;
};
