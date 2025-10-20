/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:32:35 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/19 23:34:30 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ScavTrap s1("Sigma");
    ScavTrap s2("Omega");

    s1.attack("Omega");
    s2.takeDamage(20);

    s2.attack("Sigma");
    s1.takeDamage(20);

    std::cout << "\n";

    s1.beRepaired(15);
    s2.beRepaired(10);

    std::cout << "\n";

    s1.guardGate();
    s2.guardGate();

	std::cout << "\n";

    return 0;
}
