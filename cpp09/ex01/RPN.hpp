/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:55:45 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/12 12:02:52 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cctype>

class RPN
{
	private:
		std::stack<int> _stack;

		int applyOperator(int a, int b, const std::string& op) const;
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
	
		int evaluate(const std::string& expression);
};