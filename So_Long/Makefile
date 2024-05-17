CFILES = 

LIBFT = Libft/libft.a
MLX42 = MLX42/libmlx42.a

NAME = so_long

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42)

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