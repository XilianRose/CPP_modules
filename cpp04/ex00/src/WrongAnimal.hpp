#pragma once
#include <iostream>

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(std::string const & type);
		WrongAnimal(WrongAnimal const & src);
		virtual ~WrongAnimal(void);

		WrongAnimal &	operator=(WrongAnimal const & src);
		void			makeSound(void) const;
		std::string		getType(void) const;

	protected:
		std::string	_type;
};
