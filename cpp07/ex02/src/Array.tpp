#include "Array.hpp"

/*	Constructors & destructors	*/

template <typename T>
Array<T>::Array() {
	std::cout << GRAY "Default constructor called" NC << std::endl;
	_array = new T[0];
	_size = 0;
	return;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	std::cout << GRAY "Parametric constructor called" NC << std::endl;
	_array = new T[n];
	_size = n;
	return;
}

template <typename T>
Array<T>::Array(Array const & src) {
	std::cout << GRAY "Copy constructor called" NC << std::endl;
	_array = new T[src._size];
	_size = src._size;
	for (unsigned int i = 0; i < _size; i++) {
		_array[i] = src._array[i];
	}
	return;
}

template <typename T>
Array<T>::~Array() {
	std::cout << GRAY "Destructor called" NC << std::endl;
	delete [] _array;
	return;
}

/*	Operators	*/

template <typename T>
Array<T> & Array<T>::operator=(Array const & src) {
	std::cout << GRAY "Copy assignment operator called" NC << std::endl;
	if (this == &src) {
		return *this;
	}
	delete [] _array;
	_array = new T[src._size];
	_size = src._size;
	for (unsigned int i = 0; i < _size; i++) {
		_array[i] = src._array[i];
	}
	return *this;
}

template <typename T>
T & Array<T>::operator[](unsigned int i) {
	if (i >= _size) {
		throw Array<T>::OutOfBoundsException();
	}
	return _array[i];
}

/*	Member functions	*/

template <typename T>
unsigned int Array<T>::getSize() const {
	return _size;
}

template <typename T>
T * Array<T>::getArray() const {
	return _array;
}
