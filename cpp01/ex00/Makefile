# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 16:57:23 by cprojean          #+#    #+#              #
#    Updated: 2023/11/24 11:36:11 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BrrrrrrrrrraaaaaaaaaaaaaaaaaaiiiiiiiiiiiiiiinnnnnnnnnnnnnnnnnnnnnzzzzzzZZZZZZZZZZZZZZZZZZZZ

CPP	 =	c++ -std=c++98

SRCS = 		Zombie.cpp		\
			newZombie.cpp	\
			main.cpp		\
			randomChump.cpp	

HEADER = 	Zombie.hpp		\
			newZombie.hpp	\
			randomChump.hpp	

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