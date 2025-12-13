/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 23:46:22 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/12 00:23:49 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc <input_file>\n";
        return 1;
	}

    BitcoinExchange btc;
    try
    {
        btc.loadDatabase("data.csv");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::ifstream infile(argv[1]);
    if (!infile.is_open())
    {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }

    std::string line;
    std::getline(infile, line);

    while (std::getline(infile, line))
    {
        std::string date;
        float value;

        try
        {
            parseInput(line, date, value);
            float rate = btc.getRate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << " => " << line << std::endl;
        }
    }

    return 0;
}
