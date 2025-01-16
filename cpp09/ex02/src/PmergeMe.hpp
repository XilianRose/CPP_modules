#pragma once
#include <exception>
#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <chrono>

class PmergeMe{
	public:
		PmergeMe();
		~PmergeMe();

		template <typename T>
		void		run(const T & containerType, int argc, char **argv);

		class InvalidInput : public std::exception{
			public:
				virtual const char * what() const throw();
		};

	private:
		PmergeMe(const PmergeMe &src);

		PmergeMe &	operator=(const PmergeMe &src);

		template <typename T>
		void	printDuration(const T & container, std::chrono::microseconds duration);
		template <typename T>
		void	printSequences(const T & filledContainer, const T & sortedContainer);
		template <typename T>
		void	merge(T & container, T & left, T & right);
		template <typename T>
		T		miSort(T & container);
		template <typename T>
		T		parse(const T & containerType, int argc, char **argv);

		bool	_isPrinted;
};
