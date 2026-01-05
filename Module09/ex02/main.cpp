#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe sorter;
	try {
		sorter.parse(ac, av);
		sorter.sort();
	} catch (std::exception& e) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	return 0;
}
