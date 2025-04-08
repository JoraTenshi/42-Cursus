/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:43:54 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/08 11:28:27 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > minGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade <= maxGrade)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade >= minGrade)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}

void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
	
}