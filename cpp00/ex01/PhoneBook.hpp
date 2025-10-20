/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:59:07 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/10 18:59:40 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
	private:
		int 	count;
		Contact	contacts[8];
	public:
		PhoneBook();
		~PhoneBook();

		int		return_count();
		void	add_contact(Contact new_contact);
		void	list_contacts();
		void	list_contact(int i);
};

#endif