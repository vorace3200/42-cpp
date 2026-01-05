#include "RPN.hpp"
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN& src) {
	*this = src;
}

RPN& RPN::operator=(const RPN& src) {
	if (this != &src) {
		stack = src.stack;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::is_operator(const std::string& token) const {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::apply_op(int a, int b, char op) {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("division by zero");
			return a / b;
	}
	return 0;
}

int RPN::calculate(const std::string& expr) {
	std::istringstream iss(expr);
	std::string token;

	while (iss >> token) {
		if (is_operator(token)) {
			if (stack.size() < 2)
				throw std::runtime_error("not enough operands");
			
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			stack.push(apply_op(a, b, token[0]));
		}
		else {
			if (token.length() != 1 || !std::isdigit(token[0]))
				throw std::runtime_error("invalid token");
			stack.push(token[0] - '0');
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error("invalid expression");

	return stack.top();
}
