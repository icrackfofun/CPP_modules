/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:50:54 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/13 15:08:25 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include <sys/time.h>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::setData(const std::vector<int>& vec, const std::deque<int>& deq)
{
	_vec = vec;
	_deq = deq;
}

void PmergeMe::fordJohnsonVector(std::vector<int>& v)
{
	if (v.size() <= 1)
		return;

	std::vector<int> mainChain;
	std::vector<int> pend;

	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		if (v[i] < v[i + 1])
		{
			mainChain.push_back(v[i + 1]);
			pend.push_back(v[i]);
		}
		else
		{
			mainChain.push_back(v[i]);
			pend.push_back(v[i + 1]);
		}
	}

	if (v.size() % 2 != 0)
		pend.push_back(v.back());

	std::sort(mainChain.begin(), mainChain.end());

	for (size_t i = 0; i < pend.size(); ++i)
	{
		std::vector<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
		mainChain.insert(pos, pend[i]);
	}

	v = mainChain;
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& d)
{
	if (d.size() <= 1)
		return;

	std::deque<int> mainChain;
	std::deque<int> pend;

	for (size_t i = 0; i + 1 < d.size(); i += 2)
	{
		if (d[i] < d[i + 1])
		{
			mainChain.push_back(d[i + 1]);
			pend.push_back(d[i]);
		}
		else
		{
			mainChain.push_back(d[i]);
			pend.push_back(d[i + 1]);
		}
	}

	if (d.size() % 2 != 0)
		pend.push_back(d.back());

	std::sort(mainChain.begin(), mainChain.end());

	for (size_t i = 0; i < pend.size(); ++i)
	{
		std::deque<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
		mainChain.insert(pos, pend[i]);
	}

	d = mainChain;
}

void PmergeMe::sortAndDisplay()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	struct timeval start, end;
	gettimeofday(&start, NULL);
	fordJohnsonVector(_vec);
	gettimeofday(&end, NULL);

	double vecTime =
		(end.tv_sec - start.tv_sec) * 1000000.0 +
		(end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	fordJohnsonDeque(_deq);
	gettimeofday(&end, NULL);

	double deqTime =
		(end.tv_sec - start.tv_sec) * 1000000.0 +
		(end.tv_usec - start.tv_usec);

	std::cout << "After:  ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of "
			  << _vec.size()
			  << " elements with std::vector : "
			  << vecTime << " us" << std::endl;

	std::cout << "Time to process a range of "
			  << _deq.size()
			  << " elements with std::deque  : "
			  << deqTime << " us" << std::endl;
}

bool isPositiveInteger(const std::string& s)
{
	if (s.empty())
		return false;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (!std::isdigit(s[i]))
			return false;
	}
	return true;
}

int toInt(const std::string& s)
{
	std::istringstream iss(s);
	long value;
	iss >> value;

	if (iss.fail() || value <= 0 || value > INT_MAX)
		throw std::runtime_error("Error");

	return static_cast<int>(value);
}

void parseInput(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq)
{
	if (argc < 2)
		throw std::runtime_error("Error");

	for (int i = 1; i < argc; ++i)
	{
		std::string arg(argv[i]);

		if (!isPositiveInteger(arg))
			throw std::runtime_error("Error");

		int value = toInt(arg);
		vec.push_back(value);
		deq.push_back(value);
	}
}