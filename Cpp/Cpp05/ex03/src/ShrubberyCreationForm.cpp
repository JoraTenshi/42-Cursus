/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:18:38 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/08 12:49:24 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", _gradeToSign, _gradeToExecute), _target("default_target")
{
	std::cout << "Default constructor called for ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", _gradeToSign, _gradeToExecute), _target(target)
{
	std::cout << "Parameterized constructor called for ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src), _target(src._target)
{
	std::cout << "Copy constructor called for ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called for ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	std::cout << "Assignment operator called for ShrubberyCreationForm" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	std::ofstream file;
	std::string filename = _target;
	

	if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();

	filename.append("_shrubbery");
	file.open(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return;
	}
	file << "       _-_" << std::endl;
	file << "    /~~   ~~\\" << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\\\ //  ~" << std::endl;
	file << "_- -   | | _- _" << std::endl;
	file << "  _ -  | |   -_" << std::endl;
	file << "      // \\\\" << std::endl;
	file.close();
	std::cout << "Shrubbery created in file: " << filename << std::endl;
}