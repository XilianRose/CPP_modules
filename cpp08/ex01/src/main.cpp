#include "Span.hpp"
#include <iostream>
#include "colours.hpp"

int	main(){
	std::cout << LILAC "~	test main from subject	~" NC << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << LILAC "~	filling the span with 10000 numbers using addNumber with a range of iterators	~" NC << std::endl;
	{
		Span sp = Span(10000);
		std::vector<int> vec;
		for (int i = 0; i < 10000; i++)
			vec.push_back(i);
		try{
			sp.addNumber(vec.begin(), vec.end());
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e){
			std::cout << RED << e.what() << NC << std::endl;
		}
	}
		std::cout << LILAC "~	testing exceptions	~" NC << std::endl;
	{
		Span sp = Span(5);
		try{
			sp.addNumber(2);
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e){
			std::cout << RED << e.what() << NC << std::endl;
		}
		try{
			sp.addNumber(2);
			sp.addNumber(10);
			sp.addNumber(4);
			sp.addNumber(5);
			sp.addNumber(15);
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e){
			std::cout << RED << e.what() << NC << std::endl;
		}
		try{
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e){
			std::cout << RED << e.what() << NC << std::endl;
		}
	}
	return 0;
}
