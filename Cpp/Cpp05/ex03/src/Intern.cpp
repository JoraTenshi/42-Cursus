/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:18:51 by jcallejo          #+#    #+#             */
/*   Updated: 2025/05/08 11:21:33 by jcallejo         ###   ########.fr       */
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

static int formName(std::string name)
{
	std::string names[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
			return (i);
	}
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	int	form = -1;

	try
	{
		form = formName(name);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
		return (NULL);
	}
	switch (form)
	{
		case 0:
			std::cout << GREEN << "Intern creates " << name << " form" << DEFAULT << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << CYAN << "Intern creates " << name << " form" << DEFAULT << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << BLUE << "Intern creates " << name << " form" << DEFAULT << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			return (NULL);
	}
}
