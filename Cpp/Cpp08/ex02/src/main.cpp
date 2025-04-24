/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:46:14 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/24 15:03:17 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

int	main()
{
	std::cout << PURPLE << "Mutant Stack" << DEFAULT << std::endl;
	MutantStack<int> mutant;
	mutant.push(5);
	mutant.push(17);
	std::cout << "Top of the stack: " << mutant.top() << std::endl;
	mutant.pop();
	std::cout << "Size of the stack: " << mutant.size() << std::endl;
	mutant.push(3);
	mutant.push(5);
	mutant.push(737);
	mutant.push(0);
	MutantStack<int>::iterator it = mutant.begin();
	MutantStack<int>::iterator itend = mutant.end();
	++it;
	--it;
	std::cout << "Mutant Stack: ";
	while (it != itend)
	{
		std::cout << *it << " ";
		++it;
	}
	std::stack<int> s(mutant);
	std::cout << std::endl << std::endl;

	std::cout << PURPLE << "Normal List" << DEFAULT << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Back of the list: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Size of the list: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator it2 = lst.begin();
	std::list<int>::iterator itend2 = lst.end();
	++it2;
	--it2;
	std::cout << "List: ";
	while (it2 != itend2)
	{
		std::cout << *it2 << " ";
		++it2;
	}
	std::cout << std::endl << std::endl;

	return (0);
}