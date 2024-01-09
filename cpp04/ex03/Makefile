# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 16:36:09 by cprojean          #+#    #+#              #
#    Updated: 2024/01/08 16:10:12 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Abracadabra

CPP	 =	c++ -std=c++98 -g3

SRCS =		main.cpp	\
			AMateria.cpp  \
			Ice.cpp 	\
			Cure.cpp 	\
			Character.cpp \
			MateriaSource.cpp


HEADER =	AMateria.hpp	\
			Ice.hpp		\
			Cure.hpp		\
			Character.hpp\
			ICharacter.hpp\
			IMateriaSource.hpp	\
			Headers.h 			\
			MateriaSource.hpp


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