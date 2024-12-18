#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>(){
	return ;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const & src) : std::stack<T>(src){
	return ;
}

template <typename T>
MutantStack<T>::~MutantStack(){
	return ;
}

template <typename T>
MutantStack<T> &	MutantStack<T>::operator=(MutantStack const & src){
	if (this != &src){
		std::stack<T>::operator=(src);
	}
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void){
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void){
	return this->c.end();
}
