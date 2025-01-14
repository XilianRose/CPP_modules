#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	return;
}

PmergeMe::~PmergeMe() {
	return;
}

template <typename T>
static void print(T & container) {
	for (auto it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
static void merge(T & container, T & left, T & right) {
	container.clear();
	auto leftIt = left.begin();
	auto rightIt = right.begin();
	while (leftIt != left.end() && rightIt != right.end()) {
		if (*leftIt < *rightIt) {
			container.push_back(*leftIt);
			leftIt++;
		}
		else {
			container.push_back(*rightIt);
			rightIt++;
		}
	}
	while (leftIt != left.end()) {
		container.push_back(*leftIt);
		leftIt++;
	}
	while (rightIt != right.end()) {
		container.push_back(*rightIt);
		rightIt++;
	}
}

template <typename T>
static void miSort(T & container) {
	if (container.size() <= 1) {
		return;
	}
	auto middle = container.begin() + container.size() / 2;
	T left(container.begin(), middle);
	T right(middle, container.end());
	miSort(left);
	miSort(right);
	merge(container, left, right);
}

template <typename T>
static T	parse(const T & containerType, int argc, char **argv) {
	T filledContainer;
	for (int i = 1; i < argc; i++) {
		try {
			unsigned int ui = std::stoi(argv[i]);
		}
		catch (std::exception &e) {
			throw PmergeMe::InvalidInput();
		}
		filledContainer.push_back(std::atoi(argv[i]));
	}
	return filledContainer;
}

template <typename T>
void	PmergeMe::run(const T & containerType, int argc, char **argv) {
	T container = parse(containerType, argc, argv);
	miSort(container);

	return;
}
