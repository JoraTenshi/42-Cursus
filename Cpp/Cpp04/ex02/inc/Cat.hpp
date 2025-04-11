/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:21:11 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/11 12:08:23 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain *_brain;
	public:

		Cat();
		Cat(const Cat &src);
		Cat(Brain &brain);
		~Cat();

		Cat &operator=(const Cat &src);
	
		void makeSound() const;
};