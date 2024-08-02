SRC = ./
OBJ = obj/

CNAMES = ft_atoi ft_clean ft_errors ft_init ft_routines ft_time ft_utils main

CFILES = $(addprefix $(SRC), $(addsuffix .c, $(CNAMES)))
OFILES = $(addprefix $(OBJ), $(addsuffix .o, $(CNAMES)))

NAME = philo

all: $(NAME)

$(NAME): $(OFILES)
	@gcc -Wall -Wextra -Werror $(OFILES) -o $(NAME)
	@echo Compiling files...

$(OFILES): $(CFILES)
	@mkdir -p $(OBJ)
	@gcc -Wall -Wextra -Werror -c $(CFILES)
	@mv *.o $(OBJ)

debug:
	@gcc -Wall -Wextra -Werror $(CFILES) -o $(NAME) -g

clean:
	@rm -rf $(NAME)
	@echo Cleaning...

fclean: clean
	@rm -rf obj/

re: fclean all

rebug: fclean debug

.PHONY: all clean fclean re debug rebug