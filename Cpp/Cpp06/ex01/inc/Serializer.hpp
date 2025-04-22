/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:37:31 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/22 15:50:08 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct s_data
{
	std::string 	dataStr;
	int				dataInt;
} Data;

class Serializer
{

	private:
		Serializer();
		Serializer(const Serializer &src);
		~Serializer();

		Serializer &operator=(const Serializer &src);
		
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};