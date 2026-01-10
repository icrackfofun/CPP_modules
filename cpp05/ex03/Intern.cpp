/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:02:47 by psantos-          #+#    #+#             */
/*   Updated: 2026/01/10 23:33:36 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }
Intern::~Intern() {}

//free functions
static AForm* createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
    struct FormEntry {
        const char* name;
        AForm* (*create)(const std::string &target);
    };

    FormEntry forms[] = {
        { "shrubbery creation", &createShrubbery },
        { "robotomy request", &createRobotomy },
        { "presidential pardon", &createPresidential }
    };

    for (int i = 0; i < 3; i++) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << forms[i].name << std::endl;
            return forms[i].create(target);
        }
    }

    std::cerr << "Error: form \"" << formName << "\" does not exist." << std::endl;
    return NULL;
}