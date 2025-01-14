#pragma once
#include <exception>
#include <iostream>
#include <vector>
#include <deque>

class PmergeMe{
	public:
		PmergeMe();
		~PmergeMe();

		template <typename T>
		void	run(const T & containerType, int argc, char **argv);

		class InvalidInput : public std::exception{
			public:
				virtual const char * what() const throw();
		};

	private:
		PmergeMe(const PmergeMe &src);

		PmergeMe &	operator=(const PmergeMe &src);
};
