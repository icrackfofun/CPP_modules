/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:03:20 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/04 17:06:59 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array
{
	private:
    	T* _data;
    	std::size_t _size;

public:
    Array() : _data(NULL), _size(0) {}

    Array(unsigned int n) : _data(NULL), _size(n)
    {
        if (n == 0)
            _data = NULL;
        else
            _data = new T[n]();
    }

    Array(const Array &other) : _data(NULL), _size(other._size)
    {
        if (_size > 0)
        {
            _data = new T[_size];
            for (std::size_t i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
    }

    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] _data;

            _size = other._size;
            if (_size > 0)
            {
                _data = new T[_size];
                for (std::size_t i = 0; i < _size; ++i)
                    _data[i] = other._data[i];
            }
            else
                _data = NULL;
        }
        return *this;
    }

    ~Array()
    {
        delete[] _data;
    }

    T &operator[](std::size_t index)
    {
        if (index >= _size)
            throw std::out_of_range("Array index out of bounds");
        return _data[index];
    }

    const T &operator[](std::size_t index) const
    {
        if (index >= _size)
            throw std::out_of_range("Array index out of bounds");
        return _data[index];
    }

    std::size_t size() const
    {
        return _size;
    }
};
