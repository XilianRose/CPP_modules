#pragma once
#include <iostream>

class AAnimal {
	public:
		AAnimal(void);
		AAnimal(std::string const & type);
		AAnimal(AAnimal const & src);
		virtual ~AAnimal(void);

		AAnimal &		operator=(AAnimal const & src);
		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
		void			setType(std::string const & type);

	protected:
		std::string	_type;
};
