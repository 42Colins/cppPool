/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:18:59 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/22 16:09:41 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class   PhoneBook 
{

  private :
  
		Contact _contact[8];
		int     number;

  public :
	  
		void search();
		void add(void);
		void init(void);
		void display(void);
		void display_info(std::string array);
		void display_info(int i);
		PhoneBook (void);
		~PhoneBook (void);
};

#endif