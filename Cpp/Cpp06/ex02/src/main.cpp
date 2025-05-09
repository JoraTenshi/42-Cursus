/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:19:06 by jcallejo          #+#    #+#             */
/*   Updated: 2025/05/06 09:44:01 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"

Base *generate(void)
{
	srand(time(NULL));
	int random = rand() % 3;
	switch (random)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return NULL;
	}
}

Base *generate(char c)
{
	switch (std::tolower(c))
	{
		case 'a':
			return new A;
		case 'b':
			return new B;
		case 'c':
			return new C;
		default:
			return NULL;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Object type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Object type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Object type: C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Copy object type: A" << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			std::cout << "Copy object type: B" << std::endl;
			(void)b;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				std::cout << "Copy object type: C" << std::endl;
				(void)c;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
			
		}
		
	}
	
}

int main(void)
{
	Base *base = generate();

	identify(base);
	identify(*base);
	delete base;
	return 0;
}