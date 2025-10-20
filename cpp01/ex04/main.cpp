/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 18:42:33 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/12 19:13:06 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceInLine(std::string line, std::string s1, std::string s2)
{
    std::string result;
    std::size_t pos = 0;
    std::size_t found;

    while ((found = line.find(s1, pos)) != std::string::npos)
    {
        result.append(line.substr(pos, found - pos));
        result.append(s2);
        pos = found + s1.length();
    }
    result.append(line.substr(pos));
    return result;
}

int processFile(std::string filename, std::string s1, std::string s2)
{
    std::ifstream input(filename.c_str());
    if (!input)
    {
        std::cerr << "Error: could not open input file: " << filename << "\n";
        return 1;
    }

    std::ofstream output((filename + ".replace").c_str());
    if (!output)
    {
        std::cerr << "Error: could not open output file." << "\n";
        input.close();
        return 1;
    }

    std::string line;
    while (std::getline(input, line))
    {
        output << replaceInLine(line, s1, s2);
        if (!input.eof())
            output << "\n";
    }

    input.close();
    output.close();
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << "\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return 1;
    }

    return processFile(filename, s1, s2);
}
