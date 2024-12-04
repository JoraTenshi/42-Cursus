MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
WHITE   = \033[37;1m
RESET   = \033[0m
GRAY 	= \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
BOLD	= \033[1m
RED		= \033[31;1m

CFILES = ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_isprint.c \
ft_isdigit.c ft_isascii.c ft_isalpha.c ft_isalnum.c ft_memcmp.c ft_bzero.c ft_memchr.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line_bonus.c ft_is_in_str.c ft_putstr.c

BONUS_CFILES = ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstdelone_bonus.c \
ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

OFILES = $(CFILES:.c=.o)
BONUS_OFILES = $(BONUS_CFILES:.c=.o)

CC = gcc
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
%.o : %.c
	@ $(CC) $(CFLAGS) -c $< -o $@
all: $(NAME)
$(NAME): compiling $(OFILES)
	@ ar rcs $(NAME) $(OFILES)

clean:
	@ echo "$(RED)CLEANING LIBFT ... $(RESET)"
	@ rm -f $(OFILES)

fclean: clean
	@ rm -f $(NAME) $(BONUS_OFILES)

re: fclean all

bonus: all $(BONUS_OFILES)
	@ ar rcs $(NAME) $(BONUS_OFILES)

compiling:
	@ echo "$(GREEN)COMPILING LIBFT ...$(RESET)"

.PHONY: all clean fclean re bonus