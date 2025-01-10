#pragma once

class PmergeMe{
	public:
		PmergeMe();
		~PmergeMe();

	private:
		PmergeMe(const PmergeMe &src);

		PmergeMe &	operator=(const PmergeMe &src);
};
