/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:04:50 by jcallejo          #+#    #+#             */
/*   Updated: 2025/05/08 11:22:57 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(Bureaucrat::minGrade), _gradeToExecute(Bureaucrat::minGrade)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "AForm constructor called" << std::endl;
	if (gradeToSign < Bureaucrat::maxGrade || gradeToExecute < Bureaucrat::maxGrade)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > Bureaucrat::minGrade || gradeToExecute > Bureaucrat::minGrade)
		throw AForm::GradeTooLowException();
	else
	{
		_isSigned = false;
		_gradeToSign = gradeToSign;
		_gradeToExecute = gradeToExecute;
	}
}

AForm::AForm(AForm const &src) : _name(src.getName()), _isSigned(src.getIsSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &src)
{
	std::cout << "AForm assignment operator called" << std::endl;
	if (this != &src)
	{
		_isSigned = src.getIsSigned();
		_gradeToSign = src.getGradeToSign();
		_gradeToExecute = src.getGradeToExecute();
	}
	return *this;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else if (_isSigned)
		throw AForm::FormAlreadySignedException();
	else
	{
		_isSigned = true;
		std::cout << GREEN << bureaucrat.getName() << " has signed " << getName() << DEFAULT << std::endl;
	}
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	o << "Form " << i.getName() << ", is signed: " << (i.getIsSigned() ? "yes" : "no") << ", grade to sign: " << i.getGradeToSign() << ", grade to execute: " << i.getGradeToExecute();
	return o;
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed";
}