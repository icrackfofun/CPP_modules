/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:18:48 by psantos-          #+#    #+#             */
/*   Updated: 2025/11/27 16:52:08 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(nullptr));
	Bureaucrat alice("Alice", 1);
    Bureaucrat bob("Bob", 50); 
    Bureaucrat charlie("Charlie", 150);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Marvin");
    PresidentialPardonForm pardon("Ford");

    std::cout << "\n--- Signing Forms ---\n";
    alice.signForm(shrub);
    bob.signForm(robot);  
    charlie.signForm(pardon);

    std::cout << "\n--- Executing Forms ---\n";
    bob.executeForm(shrub);
    alice.executeForm(robot);
    charlie.executeForm(pardon);

    std::cout << "\n--- Direct execution attempt ---\n";
    
	try {
		robot.execute(bob);
	} 
    catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

    return 0;
}