/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:07:39 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/12 12:08:02 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return 1;
    }

    std::string expression = argv[1];

    try {
        RPN rpn;
        int result = rpn.evaluate(expression);
        std::cout << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}