/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:54:13 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/08 12:04:11 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		static const int _gradeToSign = 145;
		static const int _gradeToExecute = 137;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		virtual ~ShrubberyCreationForm();
		
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

		std::string getTarget() const;
		
		void execute(Bureaucrat const &executor) const;
};