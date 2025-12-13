/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 23:19:51 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/07 23:35:20 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Basic Test ===\n";
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest:  " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== Copy Constructor Test ===\n";
    try
    {
        Span original(3);
        original.addNumber(1);
        original.addNumber(5);
        original.addNumber(10);

        Span copy(original);

        std::cout << "Original shortest: " << original.shortestSpan() << std::endl;
        std::cout << "Copy shortest:     " << copy.shortestSpan() << std::endl;

        original.addNumber(42);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== Assignment Operator Test ===\n";
    try
    {
        Span a(5);
        a.addNumber(100);
        a.addNumber(200);

        Span b(10);
        b.addNumber(2);
        b.addNumber(4);
        b.addNumber(6);

        b = a;

        std::cout << "A shortest: " << a.shortestSpan() << std::endl;
        std::cout << "B (after =) shortest: " << b.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== Range Add Test ===\n";
    try
    {
        Span big(10000);
        std::vector<int> vec;
        for (int i = 0; i < 10000; i++)
            vec.push_back(i);

        big.addRange(vec.begin(), vec.end());

        std::cout << "Shortest: " << big.shortestSpan() << std::endl;
        std::cout << "Longest:  " << big.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
