/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:11:44 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/10 18:44:10 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook()
{
	count = 0;
}

PhoneBook::~PhoneBook() {}

int		PhoneBook::return_count()
{
	return (count < 8 ? count : 8);
}

void	PhoneBook::add_contact(Contact new_contact)
{
	int index = (count % 8);
	contacts[index] = new_contact;
	count++;
}

std::string format_field(const std::string &str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return (std::string(10 - str.length(), ' ') + str);
}

void	PhoneBook::list_contacts()
{
	int num_print = (count < 8) ? count : 8;
	std::cout << "     Index|First Name| Last Name|  Nickname\n";
	for (int i = 0; i < num_print; i++)
	{
		std::cout << format_field(std::to_string(i)) << "|";
        std::cout << format_field(contacts[i].get_first_name()) << "|";
        std::cout << format_field(contacts[i].get_last_name()) << "|";
        std::cout << format_field(contacts[i].get_nickname()) << "\n";
	}
}

void	PhoneBook::list_contact(int i)
{
	std::cout << "First Name: " << contacts[i].get_first_name() << "\n";
	std::cout << "Last Name: " << contacts[i].get_last_name() << "\n";
	std::cout << "Nickname: " << contacts[i].get_nickname() << "\n";
	std::cout << "Phone Number: " << contacts[i].get_phone_number() << "\n";
	std::cout << "Darkest Secret: " << contacts[i].get_darkest_secret() << "\n";
}
