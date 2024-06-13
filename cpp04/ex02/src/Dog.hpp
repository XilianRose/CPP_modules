#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	public:
		Dog(void);
		Dog(Dog const & src);
		~Dog(void);

		Dog &			operator=(Dog const & src);
		virtual void	makeSound(void) const;
		Brain &			getBrain(void) const;

	protected:
		std::string	_type;

	private:
		Brain *		_brain;
};
