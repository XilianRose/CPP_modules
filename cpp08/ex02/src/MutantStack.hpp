#pragma once
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>{
	public:
		MutantStack();
		MutantStack(MutantStack const & src);
		~MutantStack();

		MutantStack &	operator=(MutantStack const & src);

		typedef typename std::deque<T>::iterator iterator;

		iterator	begin(void);
		iterator	end(void);
};

#include "MutantStack.tpp"
