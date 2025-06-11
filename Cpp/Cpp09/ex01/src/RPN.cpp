/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:05:46 by jcallejo          #+#    #+#             */
/*   Updated: 2025/06/06 11:00:00 by jcallejo         ###   ########.fr       */
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

int RPN::topop(void)
{
	int top = this->_stack.top();
	this->_stack.pop();
	return top;
}

void RPN::calculate(const std::string &op)
{
	int num1;
	int num2;

	for (int i = 0; i < (int)op.size(); i++)
	{
		if (isspace(op[i]))
			continue;
		if (!(op[i] >= '0' && op[i] <= '9') && op[i] != '+' && op[i] != '-' && op[i] != '*' && op[i] != '/')
			return std::cerr << RED << "Error: Invalid character in expression." << DEFAULT << std::endl, (void)-1;
		if (op[i] >= '0' && op[i] <= '9')
			this->_stack.push((int)op[i] - '0');
		if (op[i] == '+' || op[i] == '-' || op[i] == '*' || op[i] == '/')
		{
			if (this->_stack.size() < 2)
				return std::cerr << RED << "Error: Not enough operands." << DEFAULT << std::endl, (void)-1;
			num2 = topop();
			num1 = topop();
			if (op[i] == '+')
				this->_stack.push(num1 + num2);
			else if (op[i] == '-')
				this->_stack.push(num1 - num2);
			else if (op[i] == '*')
				this->_stack.push(num1 * num2);
			else if (op[i] == '/')
			{
				if (num2 == 0)
					return std::cerr << RED << "Error: Division by zero." << DEFAULT << std::endl, (void)-1;
				this->_stack.push(num1 / num2);
			}
		}
	}
	std::cout << GREEN << "Result: " << this->_stack.top() << DEFAULT << std::endl;
	
}
