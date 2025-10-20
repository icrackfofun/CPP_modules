/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:32:35 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/20 00:12:11 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== ClapTrap Tests ===\n";
    ClapTrap a("Alpha");
    ClapTrap b("Bravo");

    a.setAttackDamage(3);
    b.setAttackDamage(2);

    std::cout << "\n";

    a.attack("Bravo");
    b.takeDamage(3);

    b.attack("Alpha");
    a.takeDamage(2);

    std::cout << "\n";

    a.beRepaired(5);
    b.beRepaired(2);

    std::cout << "\n=== ScavTrap Tests ===\n";
    ScavTrap s1("Sigma");
    ScavTrap s2("Omega");

    s1.attack("Omega");
    s2.takeDamage(20);

    s2.attack("Sigma");
    s1.takeDamage(20);

    std::cout << "\n";

    s1.beRepaired(15);
    s2.beRepaired(10);

    s1.guardGate();
    s2.guardGate();

    std::cout << "\n=== FragTrap Tests ===\n";
    FragTrap f1("Foxtrot");
    FragTrap f2("Golf");

    f1.attack("Golf");
    f2.takeDamage(30);

    f2.attack("Foxtrot");
    f1.takeDamage(25);
	
	f1.highFivesGuys();
	f2.highFivesGuys();

	std::cout << "\n";
	return 0;
}
