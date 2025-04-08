/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:35:42 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/08 12:37:51 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &src);

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		static int const maxGrade = 1;
		static int const minGrade = 150;

		void signForm(AForm &form) const;
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

	std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);