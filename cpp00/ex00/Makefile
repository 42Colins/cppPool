# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 09:54:40 by cprojean          #+#    #+#              #
#    Updated: 2023/11/23 16:54:52 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CPP	 =	c++ -std=c++98

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o: $(DIR_SRCS)%.cpp
	$(CPP) $(CPPFLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re