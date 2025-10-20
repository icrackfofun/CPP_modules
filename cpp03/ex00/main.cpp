/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:32:35 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/16 22:38:17 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
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

    std::cout << "\n";

    for (int i = 0; i < 10; ++i)
        a.attack("Bravo");
    a.attack("Bravo");

    std::cout << "\n";

    b.takeDamage(20);
    b.beRepaired(5);

    std::cout << "\n";

    return 0;
}
