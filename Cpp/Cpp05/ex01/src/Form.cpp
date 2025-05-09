/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:04:50 by jcallejo          #+#    #+#             */
/*   Updated: 2025/05/09 10:05:46 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(Bureaucrat::minGrade), _gradeToExecute(Bureaucrat::minGrade)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form constructor called" << std::endl;
	if (gradeToSign < Bureaucrat::maxGrade || gradeToExecute < Bureaucrat::maxGrade)
		throw Form::GradeTooHighException();
	else if (gradeToSign > Bureaucrat::minGrade || gradeToExecute > Bureaucrat::minGrade)
		throw Form::GradeTooLowException();
	else
	{
		_isSigned = false;
		_gradeToSign = gradeToSign;
		_gradeToExecute = gradeToExecute;
	}
}

Form::Form(Form const &src) : _name(src.getName()), _isSigned(src.getIsSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(Form const &src)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &src)
	{
		_isSigned = src.getIsSigned();
		_gradeToSign = src.getGradeToSign();
		_gradeToExecute = src.getGradeToExecute();
	}
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else
	{
		_isSigned = true;
		std::cout << bureaucrat.getName() << " has signed " << getName() << std::endl;
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << "Form " << i.getName() << ", is signed: " << (i.getIsSigned() ? "yes" : "no") << ", grade to sign: " << i.getGradeToSign() << ", grade to execute: " << i.getGradeToExecute();
	return o;
}