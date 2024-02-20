/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:03:44 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/20 15:56:57 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm;

class Intern
{
	private :
		std::string _name;
	public :
		Intern(void);
		Intern(std::string name);
		Intern(const Intern &toCopy);
		~Intern(void);

		AForm *makeForm(std::string nameForm, std::string target);
};

#endif