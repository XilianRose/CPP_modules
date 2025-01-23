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
		void		run(T & containerType, int argc, char **argv);

		class InvalidInput : public std::exception{
			public:
				virtual const char * what() const throw();
		};

		class ValueOutOfRange : public std::exception{
			public:
				virtual const char * what() const throw();
		};
		
	private:
		PmergeMe(const PmergeMe &src);

		PmergeMe &	operator=(const PmergeMe &src);

		// merge sort implementation
		// template <typename T>
		// void	merge(T & container, T & left, T & right);
		// template <typename T>
		// T		miSort(T & container);
		template <typename T>
		void	printDuration(const T & container, std::chrono::microseconds duration);
		template <typename T>
		void	printSequences(const T & filledContainer, const T & sortedContainer);
		int		jacobsthal(int n);
		// template <typename T>
		// void	binarySearch(T & sortedContainer, int value, int start, int end);
		template <typename T>
		void	sortElements(T & container);
		template <typename T>
		T		miSort(T & container);
		template <typename T>
		T		parse(T & filledContainer, int argc, char **argv);

		bool	_isPrinted;
};
