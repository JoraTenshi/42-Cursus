/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:21:39 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/11 12:08:28 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *_brain;
	public:

		Dog();
		Dog(const Dog &src);
		Dog(Brain &brain);
		~Dog();
		
		Dog &operator=(const Dog &src);
		
		void makeSound() const;
};