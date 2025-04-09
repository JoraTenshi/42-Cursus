/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:00:33 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/08 12:13:12 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", _gradeToSign, _gradeToExecute), _target("Default")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", _gradeToSign, _gradeToExecute), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src), _target(src._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Hatsune Miku." << std::endl;
}