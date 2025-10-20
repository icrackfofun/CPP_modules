/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:01:52 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/12 12:52:42 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cctype>
#include <iostream>
#include <string>

bool is_alpha_space(const std::string &s)
{
	for (std::string::size_type i = 0; i < s.length(); i++)
	{
		unsigned char c = s[i];
		if (!std::isalpha(c) && !std::isspace(c))
			return false;
	}
	return true;
}

bool is_digit_space(const std::string &s)
{
	for (std::string::size_type i = 0; i < s.length(); i++)
	{
		unsigned char c = s[i];
		if (!std::isdigit(c) && !std::isspace(c))
			return false;
	}
	return true;
}

std::string trim(const std::string &s)
{
	std::string::size_type start = 0;
	while (start < s.length() && std::isspace(static_cast<unsigned char>(s[start])))
		start++;

	std::string::size_type end = s.length();
	while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
		end--;

	return s.substr(start, end - start);
}

std::string	present_prompt(std::string message)
{
	std::string input;
	std::cout << message << ": ";
	while (1)
	{
		if (!std::getline(std::cin, input))
        {
            std::cout << "Unexpected Signal" << std::endl;
			exit (1);
		}
		if (!input.empty())
			return (input);
		std::cout << message << " (Non-Empty): ";
	}
}

int	main (void)
{
	PhoneBook	book;
	std::string input;
	
	while (1)
	{
		while (1)
		{
			std::cout << "Please Insert a Command (ADD, SEARCH or EXIT): ";
			if (!std::getline(std::cin, input))
        	{
            	std::cout << "Unexpected Signal" << std::endl;
				exit (1);
			}
			if (input == "ADD" || input == "SEARCH" || input == "EXIT")
				break ;
		}
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
		{
			std::string first_name;
			do {
				first_name = present_prompt("First Name");
				first_name = trim(first_name);
				if (!is_alpha_space(first_name))
					std::cout << "(Only letters)\n";
			} while (!is_alpha_space(first_name));

			std::string last_name;
			do {
				last_name = present_prompt("Last Name");
				last_name = trim(last_name);
				if (!is_alpha_space(last_name))
					std::cout << "(Only letters)\n";
			} while (!is_alpha_space(last_name));

			std::string nickname;
			do {
				nickname = present_prompt("Nickname");
				nickname = trim(nickname);
				if (!is_alpha_space(nickname))
					std::cout << "(Only letters)\n";
			} while (!is_alpha_space(nickname));

			std::string phone_number;
			do {
				phone_number = present_prompt("Phone Number");
				phone_number = trim(phone_number);
				if (!is_digit_space(phone_number))
					std::cout << "(Only Numbers)\n";
			} while (!is_digit_space(phone_number));
			
			std::string darkest_secret = present_prompt("Darkest Secret");
			darkest_secret = trim(darkest_secret);
			
			Contact add(first_name, last_name, nickname, phone_number, darkest_secret);
			book.add_contact(add);
		}
		else if (input == "SEARCH")
		{
			book.list_contacts(); 
			int max = book.return_count();
			if (max != 0)
			{
				input = present_prompt("Index to Print");
				while (input.length() > 1 || !std::isdigit(input[0]) || input[0] - '0' >= max)
					input = present_prompt("Index to Print (Out of Range)");
				book.list_contact(input[0] - '0');
			}
		}
	}
}
