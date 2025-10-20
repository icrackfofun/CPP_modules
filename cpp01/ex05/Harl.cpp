/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:25:22 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/12 20:11:52 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>

Harl::Harl()
{
    funcs[0] = &Harl::debug;
    funcs[1] = &Harl::info;
    funcs[2] = &Harl::warning;
    funcs[3] = &Harl::error;
}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout << "[DEBUG] I love having extra bacon for my cheese burger!\n";
}

void	Harl::info(void)
{
	std::cout << "[INFO] I cannot believe adding extra bacon costs more!\n";
}

void	Harl::warning(void)
{
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free\n";
}

void	Harl::error(void)
{
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now!\n";
}

void   Harl::complain(std::string level)
{
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for (int i = 0; i < 4; ++i)
    {
        if (levels[i] == level)
        {
            (this->*funcs[i])();
            return;
        }
    }
    std::cout << "[UNKNOWN] Harl doesn't know this level!\n";
}