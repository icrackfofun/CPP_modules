/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:07:03 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/13 15:09:04 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>

int main(int argc, char** argv)
{
	try
	{
		std::vector<int> vec;
		std::deque<int>  deq;

		parseInput(argc, argv, vec, deq);

		PmergeMe pm;
		pm.setData(vec, deq);
		pm.sortAndDisplay();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}