# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 16:36:09 by cprojean          #+#    #+#              #
#    Updated: 2024/04/12 11:34:49 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = WorstSortingAlgorithm

CPP	 =	c++ -std=c++98 -g3

SRCS =		main.cpp \
			PmergeMe.cpp

HEADER =	PmergeMe.hpp \

OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o: %.cpp $(HEADER)
	$(CPP) $(CPPFLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re