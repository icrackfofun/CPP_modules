/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:39:54 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/04 16:55:17 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>

//can modify array
template<typename T, typename F>
void iter(T *array, const std::size_t len, F func)
{
	for (std::size_t i = 0; i < len; i++)
        func(array[i]);
}

//readonly overload, cannot modify array
template <typename T, typename F>
void iter(const T* array, std::size_t len, F func)
{
    for (std::size_t i = 0; i < len; ++i)
        func(array[i]);
}