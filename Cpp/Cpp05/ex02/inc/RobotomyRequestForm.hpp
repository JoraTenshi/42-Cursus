/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:55:28 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/08 12:17:08 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>


class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		static const int _gradeToSign = 72;
		static const int _gradeToExecute = 45;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual ~RobotomyRequestForm();
		
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

		std::string getTarget() const;
		
		void execute(Bureaucrat const &bureaucrat) const;
};