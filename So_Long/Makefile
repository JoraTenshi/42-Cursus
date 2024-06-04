CFILES = src/ft_check_map.c  src/ft_clean.c  src/ft_init.c  src/ft_movement.c  src/ft_read_map.c  src/ft_render.c  src/ft_render_map.c  src/ft_sprites.c  src/main.c

LIBFT = Libft/libft.a
MLX42 = MLX42/libmlx42.a

NAME = so_long

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42)
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME) -fsanitize=address

debug: $(LIBFT) $(MLX42)
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME) -g -fsanitize=address

$(LIBFT):
	@make -C Libft

$(MLX42):
	@make -C MLX42/

clean:
	@rm -rf $(NAME)

fclean: clean
	@make fclean -C Libft
	@make clean -C MLX42/

re: fclean all

.PHONY: all clean fclean re
