CNAMES = megaphone

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = obj/

CFILES = $(addsuffix .cpp, $(CNAMES))
OFILES = $(addprefix $(OBJ), $(addsuffix .o, $(CNAMES)))

NAME = megaphone

all: $(NAME)

$(NAME): $(OFILES)
	@c++ $(CFLAGS) $(OFILES) -o $(NAME)
	@echo "Megaphone compiled"

$(OFILES): $(CFILES)
	@mkdir -p $(OBJ)
	@c++ $(CFLAGS) -c $(CFILES)
	@mv *.o $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re