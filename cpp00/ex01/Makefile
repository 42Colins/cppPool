# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 12:11:38 by cprojean          #+#    #+#              #
#    Updated: 2023/11/23 16:55:14 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

CPP	 =	c++ -std=c++98

SRCS = PhoneBook.cpp		\
		Contact.cpp			\
		main.cpp

HEADER = PhoneBook.hpp		\
		Contact.hpp			\
		inc.hpp

OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o: $(DIR_SRCS)%.cpp $(HEADER) 
	$(CPP) $(CPPFLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re