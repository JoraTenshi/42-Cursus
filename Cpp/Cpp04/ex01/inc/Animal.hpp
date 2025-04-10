/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:18:10 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 12:26:56 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Colors.hpp"

class Animal
{
	protected:
		std::string _type;

	public:

		Animal();
		Animal(std::string type);
		Animal(const Animal &src);
		virtual ~Animal();

		Animal &operator=(const Animal &src);

		virtual void makeSound() const;

		std::string getType() const;
		void setType(std::string type);
};