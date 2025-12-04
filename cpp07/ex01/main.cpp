/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:45:34 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/04 16:51:02 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// Functions used to test iter

void printInt(int x)
{
    std::cout << "Value: " << x << std::endl;
}

void doubleInt(int &x)
{
    x *= 2;
}

void printString(const std::string &s)
{
    std::cout << "String: " << s << std::endl;
}

int main()
{
    int numbers[4] = {1, 2, 3, 4};
    std::string words[2] = {"Hello", "World"};

    std::cout << "Printing ints:" << std::endl;
    iter(numbers, 4, printInt);

    std::cout << "\nDoubling ints:" << std::endl;
    iter(numbers, 4, doubleInt);
    iter(numbers, 4, printInt);

    std::cout << "\nPrinting strings:" << std::endl;
    iter(words, 2, printString);

    return 0;
}

