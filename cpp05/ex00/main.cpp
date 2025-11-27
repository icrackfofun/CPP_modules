/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:18:48 by psantos-          #+#    #+#             */
/*   Updated: 2025/11/27 14:24:15 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"

int main()
{
    //valid construction
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;

        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-----------------------" << std::endl;

    //too low
    try {
        Bureaucrat bad1("BadLow", 200);
        std::cout << bad1 << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------" << std::endl;

    //too high
    try {
        Bureaucrat bad2("BadHigh", 0);
        std::cout << bad2 << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------" << std::endl;

    //increment past limit
    try {
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        top.incrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------" << std::endl;

    //decrement past limit (empty constructor)
    try {
        Bureaucrat low;
        std::cout << low << std::endl;
        low.decrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
