/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:48:07 by jcallejo          #+#    #+#             */
/*   Updated: 2025/05/05 20:03:35 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	elon("Elon", 1);
	Bureaucrat	musk("Musk", 150);
	
	ShrubberyCreationForm	form("Ent");
	RobotomyRequestForm		form2("Arale");
	PresidentialPardonForm	form3("Miyamoto");

	std::cout << PURPLE << elon << DEFAULT << std::endl;
	std::cout << CYAN << musk << DEFAULT << std::endl;

	try
	{
		form.execute(elon);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try
	{
		form.beSigned(musk);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		form.beSigned(elon);
		form.execute(elon);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
	try
	{
		form2.beSigned(elon);
		form2.execute(elon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		form3.beSigned(elon);
		form3.execute(elon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
