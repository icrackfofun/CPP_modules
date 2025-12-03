/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:33:48 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/03 17:36:38 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    Data d = {42, "Hello"};

    uintptr_t raw = Serializer::serialize(&d);

    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << &d << "\n";
    std::cout << "Deserialized pointer: " << ptr << "\n";

    if (ptr == &d)
        std::cout << "Pointers match!\n";
    else
        std::cout << "Pointers do NOT match!\n";

    std::cout << "Data: " << ptr->value << ", " << ptr->name << "\n";

    return 0;
}
