/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:07:23 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/04 17:07:46 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    // Empty array
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;

    // Array with 5 ints
    Array<int> numbers(5);
    for (std::size_t i = 0; i < numbers.size(); ++i)
        numbers[i] = i * 10;

    std::cout << "Numbers array:" << std::endl;
    for (std::size_t i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << std::endl;

    // Copy constructor
    Array<int> copy(numbers);
    copy[0] = 42;

    std::cout << "Original after copy modification: " << numbers[0] << std::endl;
    std::cout << "Copy first element: " << copy[0] << std::endl;

    // Assignment operator
    Array<int> assign = numbers;
    assign[1] = 99;

    std::cout << "Original after assignment modification: " << numbers[1] << std::endl;
    std::cout << "Assigned array second element: " << assign[1] << std::endl;

    // Out-of-bounds test
    try
    {
        numbers[10] = 5;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
