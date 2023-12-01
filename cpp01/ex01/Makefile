# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 18:44:17 by cprojean          #+#    #+#              #
#    Updated: 2023/11/24 10:16:43 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MoreBrrrrrrrrrraaaaaaaaaaaaaaaaaaiiiiiiiiiiiiiiinnnnnnnnnnnnnnnnnnnnnzzzzzzZZZZZZZZZZZZZZZZZZZZ

CPP	 =	c++ -std=c++98

SRCS = 		Zombie.cpp		\
			zombieHorde.cpp	\
			main.cpp		

HEADER = 	Zombie.hpp

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