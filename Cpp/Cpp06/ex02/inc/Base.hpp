/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:58:29 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/22 18:34:50 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "colors.hpp"

class Base
{
	public:
		virtual ~Base();
};
	class A : public Base {};
	class B : public Base {};
	class C : public Base {};

	Base *generate(void);
	Base *generate(char c);

	void identify(Base *p);
	void identify(Base &p);