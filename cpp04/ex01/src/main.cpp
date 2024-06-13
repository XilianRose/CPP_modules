#include "Cat.hpp"
#include "Dog.hpp"
#include "colours.hpp"

#define N 4

int	main()
{
	{
		std::cout << BOLD UNDERLINE "\n	Standard subject tests" NC << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;

	}
	{
		std::cout << BOLD UNDERLINE "\n	Array of animals test" NC << std::endl;
		Animal* array[N];
		for (int i = 0; i < N; i++){
			if (i < N / 2)
				array[i] = new Dog();
			else
				array[i] = new Cat();
		}
		for (int i = 0; i < N; i++)
			delete array[i];
	}
	{
		std::cout << BOLD UNDERLINE "\n	Deep copy test /w assignment overload" NC << std::endl;
		Cat src = Cat();
		Cat cpy = src;

		std::cout << "\nBefore setType()	: " << src.getType() << "	" << cpy.getType() << std::endl;
		cpy.setType("Munchkin");
		std::cout << "After setType()		: " << src.getType() << "	" << cpy.getType() << std::endl << std::endl;

	}
	{
		std::cout << BOLD UNDERLINE "\n	Deep copy test /w copy constructor" NC << std::endl;
		Dog src = Dog();
		Dog cpy = Dog(src);

		std::cout << "\nBefore setType()	: " << src.getType() << "	" << cpy.getType() << std::endl;
		cpy.setType("Shiba Inu");
		std::cout << "After setType()		: " << src.getType() << "	" << cpy.getType() << std::endl << std::endl;

	}
	{
		std::cout << BOLD UNDERLINE "\n	Print ideas" NC << std::endl;
		Cat c = Cat();
		Dog d = Dog();
		Brain *catBrain = &c.getBrain();
		Brain *dogBrain = &d.getBrain();

		std::cout << LILAC "\nCat's brain:" NC << std::endl;
		catBrain->printIdeas();
		std::cout << LILAC "\nDog's brain:" NC << std::endl;
		dogBrain->printIdeas();
	}
	{
		std::cout << BOLD UNDERLINE "\n Deep copy test for brain w/ copy constructor" NC << std::endl;
		Dog src = Dog();
		Dog	cpy = Dog(src);
		Brain *srcBrain = &src.getBrain();
		Brain *cpyBrain = &cpy.getBrain();

		std::cout << LILAC "\nDog's brain before modification:" NC << std::endl;
		srcBrain->printIdeas();
		std::cout << LILAC "\nDog-Copy's brain before modification:" NC << std::endl;
		cpyBrain->printIdeas();
		for (int i = 0; i < 100; i++){
			if (i % 2 == 0)
				cpyBrain->setIdea("SQUIRREL!!!", i);
		}
		std::cout << LILAC "\nDog's brain after modification:" NC << std::endl;
		srcBrain->printIdeas();
		std::cout << LILAC "\nDog-Copy's brain after modification:" NC << std::endl;
		cpyBrain->printIdeas();
	}
	return 0;
}
