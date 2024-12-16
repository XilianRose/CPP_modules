#pragma once
#include <vector>

class Span{
	public:
		Span(void) = delete;
		Span(unsigned int n);
		Span(Span const & src);
		~Span(void);

		Span &	operator=(Span const & src);

		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);

		class ContainerFullException : public std::exception{
			public:
				virtual const char * what() const throw(){
					return "Container is full";
				}
		};

		class TooFewNumbersException : public std::exception{
			public:
				virtual const char * what() const throw(){
					return "Too few numbers to calculate span";
				}
		};

	private:
		unsigned int		_n;
		std::vector<int>	_numbers;
};
