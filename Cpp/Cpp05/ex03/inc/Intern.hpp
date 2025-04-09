/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:15:05 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/09 10:24:12 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator=(const Intern &src);

		class FormNotFoundException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		AForm *makeForm(std::string formName, std::string target);
};