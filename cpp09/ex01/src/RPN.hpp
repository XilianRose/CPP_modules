#pragma once
#include <stack>

class RPN {
	public:
		RPN();
		~RPN();
	
	private:
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);

		std::stack<int> _stack;
};
