/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:48:07 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/08 11:22:42 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
	Bureaucrat	elon("Elon", 1);
	Bureaucrat	musk("Musk", 150);
	
	Form		form("Form24C", 1, 1);
	Form		form2("Form28D", 150, 150);

	std::cout << elon << std::endl;
	std::cout << musk << std::endl;
	std::cout << form << std::endl;
	std::cout << form2 << std::endl;

	musk.signForm(form);
	std::cout << form << std::endl;
	elon.signForm(form);
	std::cout << form << std::endl;
	musk.signForm(form2);
	std::cout << form2 << std::endl;
}
