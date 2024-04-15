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
ft_split\
ft_itoa\
ft_strmapi\
ft_striteri\
ft_putchar_fd\
ft_putnbr_fd\
ft_putstr_fd\
ft_putendl_fd\

LIBFT_NAMEB = #ft_lstnew_bonus\
ft_lstadd_front_bonus\
ft_lstsize_bonus\
ft_lstlast_bonus\
ft_lstadd_back_bonus\
ft_lstdelone_bonus\
ft_lstclear_bonus\
ft_lstiter_bonus\
ft_lstmap_bonus\


LIBFT_SRC = ./
LIBFT_OBJ = ./

LIBFT_FILES = $(addprefix $(LIBFT_SRC), $(addsuffix .c, $(LIBFT_NAME)))
LIBFT_OBJECT = $(addprefix $(LIBFT_OBJ), $(addsuffix .o, $(LIBFT_NAME)))
LIBFT_FILESB = $(addprefix $(LIBFT_SRC), $(addsuffix .c, $(LIBFT_NAMEB)))
LIBFT_OBJECTB = $(addprefix $(LIBFT_OBJ), $(addsuffix .o, $(LIBFT_NAMEB)))

ARC = ar rcs
NAME = libft.a

all: $(NAME)

$(NAME): $(LIBFT_OBJECT)
	@$(ARC) $(NAME) $(LIBFT_OBJECT)

$(LIBFT_OBJECT): $(LIBFT_FILES)
	@mkdir -p $(LIBFT_OBJ)
	@gcc -Wall -Wextra -Werror -c $(LIBFT_FILES)

bonus: $(LIBFT_OBJECTB) $(LIBFT_OBJECT)
	@$(ARC) $(NAME) $(LIBFT_OBJECT) $(LIBFT_OBJECTB)

$(LIBFT_OBJECTB): $(LIBFT_FILESB)
	@mkdir -p $(LIBFT_OBJB)
	@gcc -Wall -Wextra -Werror -c $(LIBFT_FILESB)

clean:
	@rm -rf *.o

fclean:
	@rm -rf $(NAME) *.o

re: fclean all

.PHONY : all clean fclean re