C_SERVER = src/server/main.c
C_CLIENT = src/client/main.c

LIBFT = Libft/libft.a

all: client server 

client: $(LIBFT)

server: $(LIBFT)

$(LIBFT):
	@make Libft

clean:
	@rm -rf client server

fclean:
	@make fclean libft

re: fclean all

.PHONY: all cleanmm fclean re