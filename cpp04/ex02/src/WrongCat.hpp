#pragma once
#include "WrongAAnimal.hpp"

class WrongCat : public WrongAAnimal {
	public:
		WrongCat(void);
		WrongCat(WrongCat const & src);
		~WrongCat(void);

		WrongCat &	operator=(WrongCat const & src);
		virtual void	makeSound(void) const;

	protected:
		std::string	_type;
};
