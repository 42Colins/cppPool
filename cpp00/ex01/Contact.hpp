/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:00:45 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/21 12:52:40 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "inc.hpp"

class Contact 
{
    private :
    
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone;
        std::string darkest_secret;
    
    public :
    //First name
        const std::string get_first_name() const;
        void set_first_name();
        
    //Last name
        const std::string get_last_name() const;
        void  set_last_name();
        
    //Nickname
        const std::string get_nickname() const;
        void set_nickname();

    //Birth date
        const std::string get_phone() const;
        void set_phone();
        
    //Secret
        const std::string get_secret() const;
        void set_secret();
};

#endif