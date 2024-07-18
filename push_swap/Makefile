SRC = src/
SRCCHK = src_bonus/
OBJ = obj/push_swap/
CHECKOBJ = obj/checker/

CNAMES = main ft_atol ft_push ft_rotate ft_rrotate ft_swap ft_clean ft_cost ft_errors ft_init ft_position ft_sort ft_utils 

CHECKNAMES = main ft_atol ft_clean ft_errors ft_init ft_push ft_rotate ft_rrotate ft_swap ft_utils

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
	@mkdir -p $(OBJ)/moves
	@gcc -Wall -Wextra -Werror -c $(CFILES)
	@mv *.o $(OBJ)

checker: $(OCHECK) $(LIBFT)
	@gcc -Wall -Wextra -Werror $(OCHECK) $(LIBFT) -o checker

$(OCHECK): $(CHECKFILES)
	@mkdir -p $(CHECKOBJ)
	@gcc -Wall -Wextra -Werror -c $(CHECKFILES)
	@mv *.o $(CHECKOBJ)

$(LIBFT):
	@make -C Libft

debug: $(LIBFT)
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) -o $(NAME) -g -fsanitize=address

clean:
	@rm -rf $(NAME)
	@rm checker
	@rm -rf obj/

fclean: clean
	@make fclean -C Libft

re: fclean all

rebug: fclean debug

.PHONY: all clean fclean re debug rebug