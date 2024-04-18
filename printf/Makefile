C_NAMES = ft_printf.c ft_hexadecimal.c ft_numbers.c ft_strings.c ft_itoa.c ft_utoa.c ft_strlen.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

ARCHIVER = ar rcs
NAME = libftprintf.a
CSRC = src/
OBJ = obj/
HEADER_FILE = ft_printf.h

CFILES = $(addprefix $(CSRC), $(addsuffix .c, $(C_NAMES)))
OFILES = $(addprefix $(OBJ), $(addsuffix .o, $(C_NAMES)))

RM = rm -f

all: $(NAME)

$(NAME): $(OFILES) $(HEADER_FILE)
	$(ARCHIVER) $(NAME) $(OFILES)

$(OFILES): $(CFILES)
	@mkdir -p $(OBJ)
	@gcc -Wall -Wextra -Werror -c $(CFILES)
	@mv $(addsuffix .o, $(C_NAMES)) $(ONJ)

clean:
	rm -rf obj/

fclean:
	rm -rf $(NAME) obj/

re: fclean all

.PHONY : all clean fclean re