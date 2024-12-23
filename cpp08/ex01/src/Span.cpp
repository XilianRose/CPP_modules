#include "Span.hpp"
#include <algorithm>
#include <numeric>

/*	Constructors & destructors	*/
Span::Span(unsigned int n) : _n(n){
	return ;
}

Span::Span(Span const & src){
	*this = src;
}

Span::~Span(void){
	return ;
}

Span &	Span::operator=(Span const & src){
	if (this != &src){
		this->_n = src._n;
		this->_numbers = src._numbers;
	}
	return *this;
}

/*	Member functions	*/
void	Span::addNumber(int n){
	if (this->_numbers.size() >= this->_n)
		throw Span::ContainerFullException();
	this->_numbers.push_back(n);
	return ;
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	if (this->_numbers.size() + std::distance(begin, end) > this->_n)
		throw Span::ContainerFullException();
	this->_numbers.insert(this->_numbers.end(), begin, end);
	return ;
}

// int	Span::shortestSpan(void){
// 	if (this->_numbers.size() < 2)
// 		throw Span::TooFewNumbersException();
// 	std::vector<int> sorted = this->_numbers;
// 	std::sort(sorted.begin(), sorted.end());
// 	int min = sorted[1] - sorted[0];
// 	for (size_t i = 1; i < sorted.size() - 1; i++){
// 		if (sorted[i + 1] - sorted[i] < min)
// 			min = sorted[i + 1] - sorted[i];
// 	}
// 	return min;
// }

int	Span::shortestSpan(void){
	if (this->_numbers.size() < 2)
		throw Span::TooFewNumbersException();
	std::vector<int> sorted = this->_numbers;
	std::sort(sorted.begin(), sorted.end());
	std::vector<int> differences(sorted.size() - 1);
	std::adjacent_difference(sorted.begin(), sorted.end(), differences.begin());
	int min = *std::min_element(differences.begin() + 1, differences.end());
	return min;
}

int Span::longestSpan(void){
	if (this->_numbers.size() < 2)
		throw Span::TooFewNumbersException();
	std::vector<int> sorted = this->_numbers;
	std::sort(sorted.begin(), sorted.end());
	return sorted[sorted.size() - 1] - sorted[0];
}
