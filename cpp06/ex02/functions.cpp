/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:46:02 by psantos-          #+#    #+#             */
/*   Updated: 2026/01/10 23:41:37 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

Base* generate(void) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int r = std::rand() % 3;

    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown\n";
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    } catch (const std::exception &e) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    } catch (const std::exception &e) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    } catch (const std::exception &e) {}

    std::cout << "Unknown\n";
}
