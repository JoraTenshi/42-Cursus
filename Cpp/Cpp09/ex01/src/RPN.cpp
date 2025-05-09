/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:05:46 by jcallejo          #+#    #+#             */
/*   Updated: 2025/05/07 10:32:12 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& src) 
{
	*this = src;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return *this;
}

static int topop(std::stack<int>&s)
{
	int top = s.top();
	s.pop();
	return top;
}

void RPN::calculate(const std::string &op)
{
	int num1;
	int num2;

	for (int i = 0; i < (int)op.length(); i++)
	{
		if (isspace(op[i]))
			continue;
		if (!isdigit(op[i]) && op[i] != '+' && op[i] != '-' && op[i] != '*' && op[i] != '/')
			return std::cerr << RED << "Error: Invalid character in expression." << DEFAULT << std::endl, (void)-1;
		if (isdigit(op[i]))
			this->_stack.push(op[i] - '0');
		if (op[i] == '+' || op[i] == '-' || op[i] == '*' || op[i] == '/')
		{
			if (this->_stack.size() != 2)
				return std::cerr << RED << "Error: Not enough operands." << DEFAULT << std::endl, (void)-1;
			num1 = topop(this->_stack);
			num2 = topop(this->_stack);
			if (op[i] == '+')
				this->_stack.push(num2 + num1);
			else if (op[i] == '-')
				this->_stack.push(num2 - num1);
			else if (op[i] == '*')
				this->_stack.push(num2 * num1);
			else if (op[i] == '/')
			{
				if (num1 == 0)
					return std::cerr << RED << "Error: Division by zero." << DEFAULT << std::endl, (void)-1;
				this->_stack.push(num2 / num1);
			}
		}
	}
	std::cout << GREEN << "Result: " << this->_stack.top() << DEFAULT << std::endl;
	
}