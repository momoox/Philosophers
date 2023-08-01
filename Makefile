# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 22:16:25 by mgeisler          #+#    #+#              #
#    Updated: 2023/08/01 12:08:45 by mgeisler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = philo.c init.c routine.c utils.c philo_actions.c error_manage.c

OBJECTS = $(SRCS:.c=.o)

GCC = gcc -Wall -Werror -Wextra -g3 -fsanitize=address

all : $(NAME)

$(NAME): $(OBJECTS)
		$(GCC) $(SRCS) -o $(NAME)

%.o: %.c 
		$(GCC) -c $?
clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test