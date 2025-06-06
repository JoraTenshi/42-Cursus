/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:02:51 by jcallejo          #+#    #+#             */
/*   Updated: 2025/06/06 10:55:11 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include "colors.hpp"

class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN();
		RPN(const RPN& src);
		~RPN();
		
		RPN& operator=(const RPN& other);

		void calculate(const std::string &op);
		int topop(void);
};