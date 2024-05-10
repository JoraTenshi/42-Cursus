CSERVER = src/server/main.c
CCLIENT = src/client/main.c
CSERVER_BONUS = src/server/main_bonus.c
CCLIENT_BONUS = src/client/main_bonus.c

LIBFT = libft/libft.a

all: client server

client: $(LIBFT)
	@gcc -Wall -Wextra -Werror $(CCLIENT) $(LIBFT) -o client

server: $(LIBFT)
	@gcc -Wall -Wextra -Werror $(CSERVER) $(LIBFT) -o server

bonus: $(LIBFT) client_bonus server_bonus

client_bonus: $(LIBFT)
	@gcc -Wall -Wextra -Werror $(CCLIENT_BONUS) $(LIBFT) -o client

server_bonus: $(LIBFT)
	@gcc -Wall -Wextra -Werror $(CSERVER_BONUS) $(LIBFT) -o server

$(LIBFT):
	@make -C Libft

clean:
	@rm -rf client server

fclean: clean
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re