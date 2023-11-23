/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:12:11 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/22 15:59:02 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

const std::string Contact::get_first_name() const {
    return (this->first_name);
}

void Contact::set_first_name() {

    std::cout << "What's your first name ?" << std::endl;
    do
    {
        std::getline(std::cin, this->first_name);
        if (this->first_name.empty() && !std::cin.eof())
            std::cin.clear();
        else if (std::cin.eof())
            exit(0);
    }
    while (this->first_name.empty());
    return;
}

const std::string Contact::get_last_name() const {
    return (this->last_name);
}

void Contact::set_last_name() {
    std::cout << "What's your last name ?" << std::endl;
    do
    {
        std::getline(std::cin, this->last_name);
        if (this->last_name.empty() && !std::cin.eof())
            std::cin.clear();
        else if (std::cin.eof())
            exit(0);
    }
    while (this->last_name.empty());
    return;
}

const std::string Contact::get_nickname() const {
    return (this->nickname);
}

void Contact::set_nickname() {
    std::cout << "What's your nickname ?" << std::endl;
    do
    {
        std::getline(std::cin, this->nickname);
        if (this->nickname.empty() && !std::cin.eof())
            std::cin.clear();
        else if (std::cin.eof())
            exit(0);
    }
    while (this->nickname.empty());
    return;
}

const std::string Contact::get_phone() const {
    return (this->phone);
}

void Contact::set_phone() {
    std::cout << "What's your phone number ?" << std::endl;
    do
    {
        std::getline(std::cin, this->phone);
        if (this->phone.empty() && !std::cin.eof())
            std::cin.clear();
        else if (std::cin.eof())
            exit(0);
        else if (is_nbr(this->phone) == 0)
            std::cout << "A phone number must be numbers !" << std::endl;
        else
            break;
    }
    while (1);
    return;
}

const std::string Contact::get_secret() const {
    return (this->darkest_secret);
}

void Contact::set_secret() {
    std::cout << "What's your darkest secret ?" << std::endl;
    do
    {
        std::getline(std::cin, this->darkest_secret);
        if (this->darkest_secret.empty() && !std::cin.eof())
            std::cin.clear();
        else if (std::cin.eof())
            exit(0);
    }
    while (this->darkest_secret.empty());
    return;
}