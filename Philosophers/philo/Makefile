SRC = src/
OBJ = obj/

CNAMES = main

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
	@gcc -Wall -Wextra -Werror $(CFILES) -o $(NAME) -g -fsanitize=address

clean:
	@rm -rf $(NAME)
	@rm -rf obj/
	@echo Cleaning...

fclean: clean

re: fclean all

rebug: fclean debug

.PHONY: all clean fclean re debug rebug