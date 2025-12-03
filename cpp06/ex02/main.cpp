/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:50:56 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/03 17:52:49 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "functions.hpp"
#include <iostream>

int main() {
    Base* obj = generate();

    std::cout << "Identify with pointer: ";
    identify(obj);

    std::cout << "Identify with reference: ";
    identify(*obj);

    delete obj;
    return 0;
}
