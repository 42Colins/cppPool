/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:38:59 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/19 15:40:53 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		std::string _target;
	public :
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &toCopy);
		~RobotomyRequestForm(void);

		RobotomyRequestForm & operator= (const RobotomyRequestForm &);

		void execForm(Bureaucrat const & executor) const;
		
		class GradeTooHighException : public std::exception
				{
					public :
							virtual const char *what() const throw();
				};
				class GradeTooLowException : public std::exception
				{
					public :
							virtual const char *what() const throw();
				};
};

#endif