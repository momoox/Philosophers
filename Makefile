# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 14:21:10 by mgeisler          #+#    #+#              #
#    Updated: 2023/08/08 12:32:05 by mgeisler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c check_args.c init.c start_threads.c philo_actions.c \
		error_manage.c utils.c \

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