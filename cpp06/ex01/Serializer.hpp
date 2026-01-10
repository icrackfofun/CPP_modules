/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:25:00 by psantos-          #+#    #+#             */
/*   Updated: 2026/01/10 23:40:26 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Data.hpp"
#include <stdint.h>
#include <string>

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
	public:
    	static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
