/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:44:52 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/22 15:49:30 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int main(void)
{
	Data data;
    uintptr_t serialized;
    Data *deserialized;

    data.dataStr = "Cuarenta y dos";
    data.dataInt = 42;

    std::cout << "Original: " << &data << std::endl;
    std::cout << "dataStr: " << data.dataStr << std::endl;
    std::cout << "dataInt: " << data.dataInt << std::endl;

    serialized = Serializer::serialize(&data);
    std::cout << "Serialized: " << serialized << std::endl;
    std::cout << "dataStr: " << data.dataStr << std::endl;
    std::cout << "dataInt: " << data.dataInt << std::endl;

    deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized: " << deserialized << std::endl;
    std::cout << "dataStr: " << deserialized->dataStr << std::endl;
    std::cout << "dataInt: " << deserialized->dataInt << std::endl;
}