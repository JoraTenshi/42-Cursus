/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:48:07 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/09 10:43:45 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
	Bureaucrat	elon("Elon", 1);
	Bureaucrat	musk("Musk", 150);
	Intern		intern;
	
	AForm	*shrubberyform;
	AForm	*robotomyform;
	AForm	*presidentialpardonform;
	AForm	*errorform;

	std::cout << elon << std::endl;
	std::cout << musk << std::endl;

	shrubberyform = intern.makeForm("shrubbery creation", "tree");
	robotomyform = intern.makeForm("robotomy request", "Arale");
	presidentialpardonform = intern.makeForm("presidential pardon", "Miyamoto");
	errorform = intern.makeForm("error form", "error");

	delete shrubberyform;
	delete robotomyform;
	delete presidentialpardonform;
	delete errorform;
	
	return 0;
}
