NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
    ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
    ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
    ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
    ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
    ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
    ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_atol.c ft_putchar.c ft_putnbr.c \


SRCSBONUS = ft_lstnew.c \
      ft_lstsize.c \
      ft_lstlast.c \
      ft_lstadd_back.c \
      ft_lstadd_front.c \
      ft_lstdelone.c \
      ft_lstclear.c \
      ft_lstiter.c \

OBJS = $(SRCS:.c=.o)

OBJSBONUS = $(SRCSBONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJSBONUS)
	ar rcs $(NAME) $(OBJS) $(OBJSBONUS)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJSBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus