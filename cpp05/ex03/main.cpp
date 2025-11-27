/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:18:48 by psantos-          #+#    #+#             */
/*   Updated: 2025/11/27 17:18:34 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* f1 = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << std::endl;
    AForm* f2 = someRandomIntern.makeForm("shrubbery creation", "Home");
	std::cout << std::endl;
    AForm* f3 = someRandomIntern.makeForm("unknown form", "Nobody");
	std::cout << std::endl;

    delete f1;
	std::cout << std::endl;
    delete f2;
	std::cout << std::endl;
    delete f3;

    return 0;
}
