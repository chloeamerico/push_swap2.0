# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: camerico <camerico@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 15:00:20 by chloeameric       #+#    #+#              #
#    Updated: 2025/02/03 18:35:09 by camerico         ###   ########.fr        #
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
	utils.c

OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

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