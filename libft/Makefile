CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	  ft_itoa.c \
	  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	  ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
	  ft_split.c \
	  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strchr.c ft_strdup.c ft_strtrim.c \
	  ft_strjoin.c ft_strncmp.c ft_striteri.c ft_strnstr.c ft_strrchr.c \
	  ft_substr.c \
	  ft_toupper.c ft_tolower.c ft_printf.c  ft_putnbr_printf.c    ft_putstr_printf.c\
	  ft_putchar_printf.c  ft_putnbr_hexa.c    ft_putnbr_unsigned.c\
	  ft_putnbr_adress.c
BONUS_SRC = ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c \
			ft_lstiter.c ft_lstclear.c ft_lstlast.c \
			ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)
OBJ = $(SRC:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(BONUS_OBJ)
		ar rcs $(NAME) $(BONUS_OBJ)
	
.PHONY: all clean fclean re