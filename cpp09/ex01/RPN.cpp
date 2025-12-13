/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:00:03 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/12 12:04:47 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::applyOperator(int a, int b, const std::string& op) const
{
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/") {
		if (b == 0) throw std::runtime_error("Division by zero");
		return a / b;
	}
	throw std::runtime_error("Invalid operator");
}

int RPN::evaluate(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (token.size() == 1 && std::isdigit(token[0])) {
			_stack.push(token[0] - '0');
		} else if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (_stack.size() < 2) throw std::runtime_error("Error: insufficient operands");
			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
			int result = applyOperator(a, b, token);
			_stack.push(result);
		} else {
			throw std::runtime_error("Error: invalid token");
		}
	}

	if (_stack.size() != 1) throw std::runtime_error("Error: invalid expression");
	return _stack.top();
}