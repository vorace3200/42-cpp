#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>

class RPN {
	private:
		std::stack<int>	stack;

		bool	is_operator(const std::string& token) const;
		int		apply_op(int a, int b, char op);

	public:
		RPN();
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);
		~RPN();

		int		calculate(const std::string& expr);
};

#endif
