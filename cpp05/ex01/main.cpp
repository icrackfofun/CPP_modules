/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:18:48 by psantos-          #+#    #+#             */
/*   Updated: 2025/11/27 15:48:56 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try {
        // Create bureaucrats
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 1);
        Bureaucrat charlie("Charlie", 150);

        // Create forms
        Form taxForm("TaxForm", 45, 30);
        Form leaveForm("LeaveForm", 100, 50);
        Form topSecret("TopSecret", 1, 1);

        std::cout << std::endl << "=== Initial States ===" << std::endl;
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << charlie << std::endl;
        std::cout << taxForm << std::endl;
        std::cout << leaveForm << std::endl;
        std::cout << topSecret << std::endl;

        std::cout << std::endl << "=== Signing Forms ===" << std::endl;

        // Bob tries to sign forms
        bob.signForm(taxForm);       
        bob.signForm(leaveForm);     

        // Alice tries to sign topSecret
        alice.signForm(topSecret);

        // Charlie tries to sign LeaveForm
        charlie.signForm(leaveForm);

        std::cout << std::endl << "=== After Signing ===" << std::endl;
        std::cout << taxForm << std::endl;
        std::cout << leaveForm << std::endl;
        std::cout << topSecret << std::endl;

        std::cout << std::endl << "=== Exceptions on Form Creation ===" << std::endl;
        Form invalidHigh("InvalidHigh", 0, 50);

    }
    catch (std::exception &e) {
        std::cerr << "Exception caught during main execution: " << e.what() << std::endl;
    }

    try {
        Form invalidLow("InvalidLow", 50, 200);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught during main execution: " << e.what() << std::endl;
    }

    return 0;
}