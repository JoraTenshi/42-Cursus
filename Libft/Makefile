LIBFT_NAME = \
ft_isalpha\
ft_isdigit\
ft_isalnum\
ft_isascii\
ft_isprint\
ft_strlen\
ft_memset\
ft_bzero\
ft_memcpy\
ft_memmove\
ft_strlcpy\
ft_strlcat\
ft_toupper\
ft_tolower\
ft_strchr\
ft_strrchr\
ft_strncmp\
ft_memchr\
ft_memcmp\
ft_strnstr\
ft_atoi\
ft_calloc\
ft_strdup\
ft_substr\
ft_strjoin\
ft_strtrim\
#ft_split\
ft_itoa\
ft_strmapi\
ft_striteri\
ft_putchar_fd\
ft_putstr_fd\
ft_putendl_fd\
ft_putnbr_fd\


LIBFT_SRC = ./
LIBFT_OBJ = ./

LIBFT_FILES = $(addprefix $(LIBFT_SRC), $(addsuffix .c, $(LIBFT_NAME)))
LIBFT_OBJECT = $(addprefix $(LIBFT_OBJ), $(addsuffix .o, $(LIBFT_NAME)))

ARC = ar rcs
NAME = libft.a

all: $(NAME)

$(NAME): $(LIBFT_OBJECT)
	@$(ARC) $(NAME) $(LIBFT_OBJECT)

$(LIBFT_OBJECT): $(LIBFT_FILES)
	@mkdir -p $(LIBFT_OBJ)
	@gcc -Wall -Wextra -Werror -c $(LIBFT_FILES)
#	@mv $(addsuffix .o, $(LIBFT_NAMES)) $(LIBFT_OBJ)

clean:
	rm -rf obj/

fclean:
	rm -rf $(NAME) obj/

re: fclean all

.PHONY : all clean fclean re