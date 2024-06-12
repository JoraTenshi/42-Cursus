CFILES = src/ft_check_map.c  src/ft_clean.c  src/ft_init.c  src/ft_movement.c  src/ft_read_map.c  src/ft_render.c  src/ft_render_map.c  src/ft_sprites.c  src/main.c

CBONUS = src_bonus/ft_check_map.c  src_bonus/ft_clean.c  src_bonus/ft_init.c  src_bonus/ft_movement.c  src_bonus/ft_read_map.c  src_bonus/ft_render.c  src_bonus/ft_render_map.c  src_bonus/ft_sprites.c  src_bonus/main.c src_bonus/ft_moves.c src_bonus/ft_animation.c src_bonus/ft_enemies.c

LIBFT = Libft/libft.a
MLX42 = MLX42/build/libmlx42.a

NAME = so_long

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42)
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

bonus:
	@gcc -Wall -Wextra -Werror $(CBONUS) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

debug: $(LIBFT) $(MLX42)
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME) -g -fsanitize=address

$(LIBFT):
	@make -C Libft

$(MLX42):
	@make -C MLX42/build/

clean:
	@rm -rf $(NAME)

fclean: clean
	@make fclean -C Libft
	@make clean -C MLX42/build/

re: fclean all
rebug: fclean debug

.PHONY: all clean fclean re
