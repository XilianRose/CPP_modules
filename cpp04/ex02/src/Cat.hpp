#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
	public:
		Cat(void);
		Cat(Cat const & src);
		~Cat(void);

		Cat &			operator=(Cat const & src);
		virtual void	makeSound(void) const;
		Brain &			getBrain(void) const;

	protected:
		std::string	_type;

	private:
		Brain *		_brain;
};
