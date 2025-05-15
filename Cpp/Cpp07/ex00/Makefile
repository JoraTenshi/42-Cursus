CNAMES = main 

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = src/
OBJ = obj/

CFILES = $(addprefix $(SRC), $(addsuffix .cpp, $(CNAMES)))
OFILES = $(addprefix $(OBJ), $(addsuffix .o, $(CNAMES)))
HEADER = inc/whatever.hpp inc/colors.hpp

NAME = template

all: $(NAME)

$(NAME): $(OFILES) $(HEADER)
	@c++ $(CFLAGS) $(OFILES) -o $(NAME)
	@echo "Exercise compiled"

$(OFILES): $(CFILES) $(HEADER)
	@mkdir -p $(OBJ)
	@c++ $(CFLAGS) -c $(CFILES)
	@mv *.o $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re