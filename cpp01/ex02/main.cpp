/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:41:28 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/12 15:52:30 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	//address of the string variable
	std::cout << &string << "\n";
	
	//memory address held by stringPTR
	std::cout << stringPTR << "\n";
	
	//memory address held by stringREF
	std::cout << &stringREF << "\n";

	//value of the string variable
	std::cout << string << "\n";

	//value pointed to by stringPTR
	std::cout << *stringPTR << "\n";

	//value pointed to by stringREF
	std::cout << stringREF << "\n";
}