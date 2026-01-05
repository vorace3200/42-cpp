#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <ctime>
# include <iostream>
# include <sstream>
# include <cstdlib>
# include <algorithm>

class PmergeMe {
	private:
		std::vector<int>	vec;
		std::deque<int>		deq;

		void	ford_johnson_vec(std::vector<int>& arr);
		void	ford_johnson_deq(std::deque<int>& arr);

		template <typename T>
		void	binary_insert(T& arr, int value, int end);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();

		void	parse(int ac, char **av);
		void	sort();
		void	display() const;
};

#endif
