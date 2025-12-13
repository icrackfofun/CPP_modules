/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 23:17:26 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/07 23:42:32 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span
{
private:
    unsigned int		_maxSize;
    std::vector<int>	_values;
public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void	addNumber(int value);
    template <typename It>
    void addRange(It begin, It end)
    {
        for (It it = begin; it != end; ++it)
        {
            if (_values.size() >= _maxSize)
                throw std::runtime_error("Span is full");
            _values.push_back(*it);
        }
    }
    int shortestSpan() const;
    int longestSpan() const;
    unsigned int size() const;
};
