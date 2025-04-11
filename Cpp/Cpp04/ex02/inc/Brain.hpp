/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:55:03 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 12:56:57 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Colors.hpp"

class Brain
{
	private:
		std::string _ideas[100];

	public:

		Brain();
		Brain(const Brain &src);
		~Brain();

		Brain &operator=(const Brain &src);

		bool addIdea(std::string idea);
		std::string getIdea(int index);
};