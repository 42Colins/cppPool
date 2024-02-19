# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 16:36:09 by cprojean          #+#    #+#              #
#    Updated: 2024/02/19 18:12:12 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Abracadabra

CPP	 =	c++ -std=c++98

SRCS =		main.cpp	\
			Bureaucrat.cpp  \
			Form.cpp

HEADER =	Bureaucrat.hpp	\
			Form.hpp

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