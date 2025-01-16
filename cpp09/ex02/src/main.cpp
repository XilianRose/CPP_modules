#include "PmergeMe.hpp"
#include "colours.hpp"


int	main(int argc, char **argv){
	PmergeMe pm;

	if (argc <= 1){
		std::cerr << "usage: ./pmerge [sequence of positive integers]" << std::endl;
		return 1;
	}
	std::vector<int> vContainer;
	std::deque<int> dContainer;
	std::list<int> lContainer;
	try {
		pm.run(vContainer, argc, argv);
		pm.run(dContainer, argc, argv);
		pm.run(lContainer, argc, argv);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << NC << std::endl;
		return 1;
	}
	return 0;
}
