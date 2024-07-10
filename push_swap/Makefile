SRC = src/
OBJ = obj/push_swap/

CNAMES = main ft_atol

CHECKNAMES = 

CFILES = $(addprefix $(SRC), $(addsuffix .c, $(CNAMES)))
OFILES = $(addprefix $(OBJ), $(addsuffix .o, $(CNAMES)))
CHECKFILES = $(addprefix $(SRCCHK), $(addsuffix .c, $(CHECKNAMES)))
OCHECK = $(addprefix $(CHECKOBJ), $(addsuffix .o, $(CHECKNAMES)))

LIBFT = Libft/libft.a

NAME = push_swap

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT)
	@gcc -Wall -Wextra -Werror $(OFILES) $(LIBFT) -o $(NAME)

$(OFILES): $(CFILES)
	@mkdir -p $(OBJ)
	@gcc -Wall -Wextra -Werror -c $(CFILES)
	@mv *.o $(OBJ)

$(LIBFT):
	@make -C Libft

debug: $(LIBFT)
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) -o $(NAME) -g

clean:
	@rm -rf $(NAME)
	@rm -rf obj/

fclean: clean
	@make fclean -C Libft

re: fclean all

.PHONY: all clean fclean re debug py