#include "PmergeMe.hpp"
#include <iomanip>
#include "colours.hpp"

PmergeMe::PmergeMe() {
	_isPrinted = false;
	return;
}

PmergeMe::~PmergeMe() {
	return;
}

template <typename T>
void	PmergeMe::printDuration(const T & container, std::chrono::microseconds duration) {
	std::string containerType = typeid(container).name();
	containerType = containerType.erase(0, containerType.find_last_of("0123456789") + 1);
	containerType = containerType.erase(containerType.find("I", 0), containerType.size());
	std::cout << "Time to process a range of " << container.size();
	std::cout << " elements with	std::" << containerType;
	std::cout << "	: " << std::fixed << std::setprecision(8) << duration.count() << " us" << std::endl;
	return ;

}

template <typename T>
void	PmergeMe::printSequences(const T & filledContainer, const T & sortedContainer) {
	if (_isPrinted)
		return ;

	std::cout << "Before:	";
	for (auto it = filledContainer.begin(); it != filledContainer.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "After:	";
	for (auto it = sortedContainer.begin(); it != sortedContainer.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	_isPrinted = true;
	return ;
}

// merge sort implementation
// template <typename T>
// void	PmergeMe::merge(T & container, T & left, T & right) {
// 	auto leftIt = left.begin();
// 	auto rightIt = right.begin();
// 	while (leftIt != left.end() && rightIt != right.end()) {
// 		if (*leftIt < *rightIt) {
// 			container.push_back(*leftIt);
// 			leftIt++;
// 		}
// 		else {
// 			container.push_back(*rightIt);
// 			rightIt++;
// 		}
// 	}
// 	while (leftIt != left.end()) {
// 		container.push_back(*leftIt);
// 		leftIt++;
// 	}
// 	while (rightIt != right.end()) {
// 		container.push_back(*rightIt);
// 		rightIt++;
// 	}
// }

// template <typename T>
// T PmergeMe::miSort(T & container) {
// 	if (container.size() <= 1) {
// 		return container;
// 	}
// 	auto middle = container.begin();
// 	std::advance(middle, container.size() / 2);
// 	T left(container.begin(), middle);
// 	T right(middle, container.end());
// 	left = miSort(left);
// 	right = miSort(right);
// 	T sortedContainer;
// 	merge(sortedContainer, left, right);
// 	return sortedContainer;
// }

// template <typename T>
// void PmergeMe::binarySearch(T & sortedContainer, int value, int start, int end) {
// 	auto it = sortedContainer.begin();
// 	if (start >= end){
// 		std::advance(it, start);
// 		sortedContainer.insert(it, value);
// 		return ;
// 	}
// 	int mid = start + (end - start) / 2;
// 	auto middle = sortedContainer.begin();
// 	std::advance(middle, mid);
// 	if (*middle == value) {
// 		std::advance(it, mid);
// 		sortedContainer.insert(it, value);
// 		return ;
// 	}
// 	if (*middle > value)
// 		binarySearch(sortedContainer, value, start, mid);
// 	else
// 		binarySearch(sortedContainer, value, mid + 1, end);
// }

int PmergeMe::jacobsthal(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void	PmergeMe::bubbleSort(std::vector<std::pair<int, int>> & pairs) {
	for (size_t i = 0; i < pairs.size(); ++i) {
		for (size_t j = 0; j < pairs.size() - 1; ++j) {
			if (pairs[j].second > pairs[j + 1].second) {
				std::swap(pairs[j], pairs[j + 1]);
			}
		}
	}
	return ;
}

template <typename T>
std::vector<std::pair<int, int>>	PmergeMe::makePairs(T & container) {
	std::vector<std::pair<int, int>> pairs;
	for (auto it = container.begin(); it != container.end();) {
		auto first = *it;
		++it;
		if (it != container.end()) {
			auto second = *it;
			if (first > second) 
				std::swap(first, second);
			pairs.push_back(std::make_pair(first, second));
			++it;
		}
	}
	return pairs;
}

template <typename T>
void PmergeMe::insertUsingJacobsthal(T &sortedContainer, std::vector<std::pair<int, int>> &pairs) {
	int i = 1;
	int j = 1;
	int len = pairs.size();
	while (i < len) {
		for (int jacob = jacobsthal(j); jacob > 0 && jacob > jacobsthal(j - 1); jacob--) {
			auto it = pairs.begin();
			if (jacob >= len)
				jacob = len - 1;
			std::advance(it, jacob);
			auto pos = std::lower_bound(sortedContainer.begin(), sortedContainer.end(), it->first);
			sortedContainer.insert(pos, it->first);
			++i;
		}
		++j;
	}
}

template <typename T>
T PmergeMe::miSort(T &container) {
	if (container.size() <= 1) {
		return container;
	}

	bool isUneven = false;
	int singleElement = 0;
	if (container.size() % 2 != 0) {
		isUneven = true;
		singleElement = container.back();
		container.pop_back();
	}

	std::vector<std::pair<int, int>> pairs = makePairs(container);
	bubbleSort(pairs);

	T sortedContainer;
	sortedContainer.push_back(pairs.begin()->first);

	for (auto it = pairs.begin(); it != pairs.end(); ++it) {
		sortedContainer.push_back(it->second);
	}

	insertUsingJacobsthal(sortedContainer, pairs);

	if (isUneven) {
		auto pos = std::lower_bound(sortedContainer.begin(), sortedContainer.end(), singleElement);
		sortedContainer.insert(pos, singleElement);
		container.push_back(singleElement);
	}

	return sortedContainer;
}

template <typename T>
T	PmergeMe::parse(T & filledContainer, int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		try {
			int num = std::stoi(argv[i]);
			if (num < 0)
				throw PmergeMe::ValueOutOfRange();
			filledContainer.push_back(num);
		}
		catch (std::invalid_argument &e) {
			throw PmergeMe::InvalidInput();
		}
		catch (std::out_of_range &e) {
			throw PmergeMe::ValueOutOfRange();
		}
	}
	return filledContainer;
}


template <typename T>
void	PmergeMe::run(T & container, int argc, char **argv) {
	// static_assert(std::is_same<typename T::value_type, int>::value, "T must be a container of int");
	static_assert(std::is_same<T, std::vector<int>>::value || std::is_same<T, std::deque<int>>::value || std::is_same<T, std::list<int>>::value, "T must be a sequence container of int");
	auto start = std::chrono::high_resolution_clock::now();
	container = parse(container, argc, argv);
	T sortedContainer = miSort(container);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	printSequences(container, sortedContainer);
	printDuration(sortedContainer, duration);
	return ;
}

const char * PmergeMe::InvalidInput::what() const throw() {
	return "Error: Invalid input";
}

const char * PmergeMe::ValueOutOfRange::what() const throw() {
	return "Error: Value out of range";
}

template void PmergeMe::run<std::vector<int>>(std::vector<int>&, int, char**);
template void PmergeMe::run<std::deque<int>>(std::deque<int>&, int, char**);
template void PmergeMe::run<std::list<int>>(std::list<int>&, int, char**);

template void PmergeMe::printDuration<std::vector<int>>(const std::vector<int>&, std::chrono::microseconds);
template void PmergeMe::printDuration<std::deque<int>>(const std::deque<int>&, std::chrono::microseconds);
template void PmergeMe::printDuration<std::list<int>>(const std::list<int>&, std::chrono::microseconds);
