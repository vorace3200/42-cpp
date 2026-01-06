#include "PmergeMe.hpp"
#include <stdexcept>
#include <iomanip>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) {
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
	if (this != &src) {
		vec = src.vec;
		deq = src.deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parse(int ac, char **av) {
	for (int i = 1; i < ac; i++) {
		std::string arg = av[i];
		
		for (size_t j = 0; j < arg.length(); j++) {
			if (!std::isdigit(arg[j]))
				throw std::runtime_error("invalid argument");
		}
		
		long num = std::atol(arg.c_str());
		if (num <= 0 || num > 2147483647)
			throw std::runtime_error("invalid number");
		
		vec.push_back(static_cast<int>(num));
		deq.push_back(static_cast<int>(num));
	}
	
	if (vec.empty())
		throw std::runtime_error("no input");
}

template <typename T>
void PmergeMe::binary_insert(T& arr, int value, int end) {
	int left = 0;
	int right = end;
	
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] > value)
			right = mid;
		else
			left = mid + 1;
	}
	arr.insert(arr.begin() + left, value);
}

void PmergeMe::ford_johnson_vec(std::vector<int>& arr) {
	int n = arr.size();
	if (n <= 1) return;  // 1 seul dans le vect = deja trie

	std::vector<std::pair<int, int> > pairs; // (grand, petit)
	std::vector<int> main_chain;
	std::vector<int> pend; // petis restants

	// former les pairs (grand, petit)
	for (int i = 0; i + 1 < n; i += 2) {
		int a = arr[i];
		int b = arr[i + 1];
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	bool has_retenue = (n % 2 == 1);
	int retenue = has_retenue ? arr[n - 1] : 0;

	if (pairs.size() > 1) {
		std::vector<int> largers;
		for (size_t i = 0; i < pairs.size(); i++)
			largers.push_back(pairs[i].first);
		// on garde ques les "grands" nombre pour les triers
		
		ford_johnson_vec(largers); // on reforme les grands tries (grand, petit) 

		// reordonner les paires selon les grands tries : (grand, petit) -> (petit, grand) []
		std::vector<std::pair<int, int> > sorted_pairs;
		for (size_t i = 0; i < largers.size(); i++) {
			for (size_t j = 0; j < pairs.size(); j++) {
				if (pairs[j].first == largers[i]) {
					// on a trouve notre larger, du coup on a notre petit, on l'ajoute a sorted_pairs.
					sorted_pairs.push_back(pairs[j]); 
					pairs.erase(pairs.begin() + j);
					break;
				}
			}
		}
		pairs = sorted_pairs;
	}

	// plus petit 1er pair (b1)
	main_chain.push_back(pairs[0].second);
	for (size_t i = 0; i < pairs.size(); i++)
		main_chain.push_back(pairs[i].first);  // + tous les grands

	// les petits restants vont dans pend
	for (size_t i = 1; i < pairs.size(); i++)
		pend.push_back(pairs[i].second);


	size_t jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845};
	size_t j_idx = 0;
	size_t inserted = 0;

	while (inserted < pend.size()) {
		size_t group_end = (j_idx < 15) ? jacobsthal[j_idx] : pend.size();
		if (group_end > pend.size()) 
			group_end = pend.size();

		for (size_t i = group_end; i > inserted; ) {
			--i;
			// on insert le petit dans le main_chain
			binary_insert(main_chain, pend[i], main_chain.size());
		}
		inserted = group_end;
		j_idx++;
	}

	if (has_retenue)
		binary_insert(main_chain, retenue, main_chain.size());

	arr = main_chain;
}

void PmergeMe::ford_johnson_deq(std::deque<int>& arr) {
	int n = arr.size();
	if (n <= 1) return;

	std::deque<std::pair<int, int> > pairs;
	std::deque<int> main_chain;
	std::deque<int> pend;

	for (int i = 0; i + 1 < n; i += 2) {
		int a = arr[i];
		int b = arr[i + 1];
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	bool has_retenue = (n % 2 == 1);
	int retenue = has_retenue ? arr[n - 1] : 0;

	if (pairs.size() > 1) {
		std::deque<int> largers;
		for (size_t i = 0; i < pairs.size(); i++)
			largers.push_back(pairs[i].first);
		ford_johnson_deq(largers);

		std::deque<std::pair<int, int> > sorted_pairs;
		for (size_t i = 0; i < largers.size(); i++) {
			for (size_t j = 0; j < pairs.size(); j++) {
				if (pairs[j].first == largers[i]) {
					sorted_pairs.push_back(pairs[j]);
					pairs.erase(pairs.begin() + j);
					break;
				}
			}
		}
		pairs = sorted_pairs;
	}

	main_chain.push_back(pairs[0].second);
	for (size_t i = 0; i < pairs.size(); i++)
		main_chain.push_back(pairs[i].first);

	for (size_t i = 1; i < pairs.size(); i++)
		pend.push_back(pairs[i].second);

	size_t jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845};
	size_t j_idx = 0;
	size_t inserted = 0;

	while (inserted < pend.size()) {
		size_t group_end = (j_idx < 15) ? jacobsthal[j_idx] : pend.size();
		if (group_end > pend.size()) group_end = pend.size();

		for (size_t i = group_end; i > inserted; ) {
			--i;
			binary_insert(main_chain, pend[i], main_chain.size());
		}
		inserted = group_end;
		j_idx++;
	}

	if (has_retenue)
		binary_insert(main_chain, retenue, main_chain.size());

	arr = main_chain;
}

void PmergeMe::sort() {
	std::cout << "Before:";
	for (size_t i = 0; i < vec.size() && i < 5; i++)
		std::cout << " " << vec[i];
	if (vec.size() > 5) std::cout << " [...]";
	std::cout << std::endl;

	clock_t start_vec = clock();
	ford_johnson_vec(vec);
	clock_t end_vec = clock();

	clock_t start_deq = clock();
	ford_johnson_deq(deq);
	clock_t end_deq = clock();

	std::cout << "After:";
	for (size_t i = 0; i < vec.size() && i < 5; i++)
		std::cout << " " << vec[i];
	if (vec.size() > 5) std::cout << " [...]";
	std::cout << std::endl;

	double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;
	double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << vec.size()
			  << " elements with std::vector : " << std::fixed << std::setprecision(5) 
			  << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
			  << " elements with std::deque  : " << std::fixed << std::setprecision(5) 
			  << time_deq << " us" << std::endl;
}

void PmergeMe::display() const {
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}
