/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 23:17:23 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/11 12:05:42 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cmath>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _values = other._values;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (_values.size() >= _maxSize)
        throw std::runtime_error("Span is full");
    _values.push_back(n);
}

int Span::shortestSpan() const
{
    if (_values.size() < 2)
        throw std::runtime_error("Not enough elements");

    std::vector<int> tmp = _values;
    std::sort(tmp.begin(), tmp.end());

    long shortest = std::abs(tmp[1] - tmp[0]);
    for (std::size_t i = 1; i < tmp.size() - 1; ++i)
    {
        long diff = std::abs(tmp[i + 1] - tmp[i]);
        if (diff < shortest)
            shortest = diff;
    }
    return static_cast<int>(shortest);
}

int Span::longestSpan() const
{
    if (_values.size() < 2)
        throw std::runtime_error("Not enough elements");

    int minVal = *std::min_element(_values.begin(), _values.end());
    int maxVal = *std::max_element(_values.begin(), _values.end());
    return maxVal - minVal;
}

unsigned int Span::size() const
{
    return _values.size();
}
