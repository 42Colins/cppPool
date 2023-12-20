# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 16:36:09 by cprojean          #+#    #+#              #
#    Updated: 2023/12/19 11:32:25 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Farm

CPP	 =	c++ -std=c++98 -g3

SRCS =		main.cpp	\
			Animal.cpp  \
			Dog.cpp 	\
			Cat.cpp 	\
			WrongCat.cpp\
			WrongAnimal.cpp\
			Brain.cpp


HEADER =	Animal.hpp	\
			Dog.hpp		\
			Cat.hpp		\
			WrongAnimal.hpp\
			WrongCat.hpp\
			Brain.hpp	\
			Polymorphism.h


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