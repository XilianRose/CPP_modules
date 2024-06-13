#pragma once
#include <iostream>

class WrongAAnimal {
	public:
		WrongAAnimal(void);
		WrongAAnimal(std::string const & type);
		WrongAAnimal(WrongAAnimal const & src);
		virtual ~WrongAAnimal(void);

		WrongAAnimal &	operator=(WrongAAnimal const & src);
		void			makeSound(void) const;
		std::string		getType(void) const;

	protected:
		std::string	_type;
};
