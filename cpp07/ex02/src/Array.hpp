#pragma once
#include <iostream>
#include <exception>
#include "colours.hpp"

template <typename T>
class Array{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &src);
		~Array();

		Array &			operator=(Array const &rhs);
		T &				operator[](unsigned int i);

		unsigned int	getSize() const;
		T *				getArray() const;

		class OutOfBoundsException : public std::exception{
			public:
				virtual const char * what() const throw(){
					return "Out of bounds";
				}
		};

	private:
		T *				_array;
		unsigned int	_size;
};

#include "Array.tpp"
