# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chloeamerico <chloeamerico@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 15:00:20 by chloeameric       #+#    #+#              #
#    Updated: 2025/01/31 19:33:08 by chloeameric      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ft_atoi.c \
	main.c \
	parsing.c \
	push_swap.c \
	push.c \
	radix.c \
	reverse_rotate.c \
	rotate.c \
	small_sort.c \
	swap.c \
	utils.c \

OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re