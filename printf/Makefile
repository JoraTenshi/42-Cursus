C_NAMES = ft_itoa ft_printf ft_putchar ft_puthex ft_putnbr_base ft_putnbr ft_putptr ft_putstr ft_putunbr ft_strlen ft_utoa

CC = gcc
CFLAGS = -Wall -Wextra -Werror

ARCHIVER = ar rcs
NAME = libftprintf.a
CSRC = src/
OBJ = obj/
HEADER_FILE = printf.h

CFILES = $(addprefix $(CSRC), $(addsuffix .c, $(C_NAMES)))
OFILES = $(addprefix $(OBJ), $(addsuffix .o, $(C_NAMES)))

RM = rm -f

all: $(NAME)

$(NAME): $(OFILES) $(HEADER_FILE)
	$(ARCHIVER) $(NAME) $(OFILES)

$(OFILES): $(CFILES)
	@mkdir -p $(OBJ)
	@gcc -Wall -Wextra -Werror -c $(CFILES)
	@mv $(addsuffix .o, $(C_NAMES)) $(OBJ)

clean:
	rm -rf obj/

fclean:
	rm -rf $(NAME) obj/

re: fclean all

.PHONY : all clean fclean re