# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 16:36:09 by cprojean          #+#    #+#              #
#    Updated: 2024/03/15 16:40:13 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ExecutingForms

CPP	 =	c++ -std=c++98

SRCS =		main.cpp			\
			Bureaucrat.cpp  	\
			AForm.cpp 			\
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp 	\
			PresidentialPardonForm.cpp \
			Intern.cpp

HEADER =	Bureaucrat.hpp	\
			AForm.hpp		\
			ShrubberyCreationForm.hpp \
			RobotomyRequestForm.hpp 	\
			PresidentialPardonForm.hpp 	\
			Intern.hpp

OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o: $(DIR_SRCS)%.cpp $(HEADER)
	$(CPP) $(CPPFLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS)
	rm -rf *_shrubbery

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re