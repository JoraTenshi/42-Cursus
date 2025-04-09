/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:18:51 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/09 10:45:49 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void)src;
	return *this;
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	int i = 0;

	try
	{
		std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
		AForm *forms[3] = {new RobotomyRequestForm(target), new PresidentialPardonForm(target), new ShrubberyCreationForm(target)};
		
		while (i < 3)
		{
			if (formName == formNames[i])
			{
				std::cout << "Intern creates " << formName << std::endl;
				return forms[i];
			}
			i++;
		}
		throw FormNotFoundException();
		delete forms[i];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return NULL;
}