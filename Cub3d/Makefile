# COLORS
MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
WHITE   = \033[37;1m
RESET   = \033[0m
GRAY 	= \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
BOLD	= \033[1m
RED		= \033[31;1m

#---------- BASE ----------#

# FILES 
CFILES = main.c ft_exit.c map.c hooks.c leaks_norm.c\

PARSER_FILES = ft_init.c ft_main_parser.c ft_map_check.c ft_player_position.c ft_texture_check.c

RAY_CASTING_CFILES = movement.c ray_casting.c miscellaneus.c drawing.c ray_vertical_lines.c turn_move.c draw_pj.c\
ray_horizontal_lines.c

# BONUS
CFILES_BONUS =  main_bonus.c ft_exit_bonus.c map_bonus.c hooks_bonus.c animation_bonus.c load_animation_bonus.c leaks_norm_bonus.c

PARSER_FILES_BONUS = ft_init_bonus.c ft_main_parser_bonus.c ft_map_check_bonus.c ft_player_position_bonus.c ft_texture_check_bonus.c

RAY_CASTING_CFILES_BONUS = movement_bonus.c ray_casting_bonus.c miscellaneus_bonus.c drawing_bonus.c ray_vertical_lines_bonus.c turn_move_bonus.c draw_pj_bonus.c\
ray_horizontal_lines_bonus.c

# DIRECTORIES 
SRC_DIR = src/
PARSER_DIR = src/parser/
BUILT_IN_SRC_DIR = src/built_ins/
RAY_CASTING_SRC_DIR = src/ray_casting/
OBJ_DIR = objs/

# OBJECTS
OFILES = $(addprefix $(OBJ_DIR), $(CFILES:.c=.o))
PARSER_OFILES = $(addprefix $(OBJ_DIR)parser/, $(PARSER_FILES:.c=.o))
RAY_CASTING_OFILES = $(addprefix $(OBJ_DIR)ray_casting/, $(RAY_CASTING_CFILES:.c=.o))

# OBJECTS BONUS
OFILES_BONUS = $(addprefix $(OBJ_DIR), $(CFILES_BONUS:.c=.o))
PARSER_OFILES_BONUS = $(addprefix $(OBJ_DIR)parser/, $(PARSER_FILES_BONUS:.c=.o))
RAY_CASTING_OFILES_BONUS = $(addprefix $(OBJ_DIR)ray_casting/, $(RAY_CASTING_CFILES_BONUS:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ mkdir -p $(OBJ_DIR)
	@ echo "$(BLUE)-Compiling File: $(RESET)$(notdir $<)"
	@ $(CC) $(CFLAGS) -c $< -o $@ -g

$(OBJ_DIR)parser/%.o: $(PARSER_DIR)%.c
	@ mkdir -p $(OBJ_DIR)/parser/
	@ echo "$(BLUE)-Compiling File: $(CYAN)parser/$(RESET)$(notdir $<)"
	@ $(CC) $(CFLAGS) -c $< -o $@ -g

$(OBJ_DIR)ray_casting/%.o: $(RAY_CASTING_SRC_DIR)%.c
	@ mkdir -p $(OBJ_DIR)/ray_casting/
	@ echo "$(BLUE)-Compiling File: $(CYAN)ray_casting/$(RESET)$(notdir $<)"
	@ $(CC) $(CFLAGS) -c $< -o $@ -g

$(OBJ_DIR)built_ins/%.o: $(BUILT_IN_SRC_DIR)%.c
	@ mkdir -p $(OBJ_DIR)/built_ins/
	@ echo "$(BLUE)-Compiling File: $(CYAN)built_ins/$(RESET)$(notdir $<)"
	@ $(CC) $(CFLAGS) -c $< -o $@ -g


#---------- FLAGS & COMPILATION ----------#

CC = clang
NAME = cub3D
BONUS_NAME = cub3D_bonus
CFLAGS = -Wall -Werror -Wextra
MLX42 = include/MLX42/build/libmlx42.a

all: libft $(NAME)
$(NAME): compiling $(PARSER_OFILES) $(RAY_CASTING_OFILES) $(BUILT_IN_OFILES) $(OFILES) $(MLX42)
	@ echo
	@ $(CC) $(CFLAGS) $(PARSER_OFILES) $(RAY_CASTING_OFILES) $(BUILT_IN_OFILES) $(OFILES) include/libft/libft.a $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)
	@ echo "$(YELLOW)COMPILATION FINISHED!$(RESET)"

bonus: libft all $(BONUS_NAME)
$(BONUS_NAME): compiling_bonus $(PARSER_OFILES_BONUS) $(RAY_CASTING_OFILES_BONUS) $(BUILT_IN_OFILES_BONUS) $(OFILES_BONUS) $(MLX42)
	@ echo
	@ $(CC) $(CFLAGS) $(PARSER_OFILES_BONUS) $(RAY_CASTING_OFILES_BONUS) $(BUILT_IN_OFILES_BONUS) $(OFILES_BONUS) include/libft/libft.a $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(BONUS_NAME)
	@ echo "$(YELLOW)COMPILATION FINISHED!$(RESET)"

debug: all
	@ echo
	@ $(CC) $(CFLAGS) $(PARSER_OFILES) $(RAY_CASTING_OFILES) $(BUILT_IN_OFILES) $(OFILES) include/libft/libft.a $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME) -g -fsanitize=address
	@ echo "$(RED)DEBUG MODE ACTIVATED!$(RESET)"

libft:
	@ make --silent -C include/libft/ bonus

$(MLX42):
	@ make -C ./include/MLX42/build
	@ make -C ./include/MLX42/build -j4

#---------- CLEAN ----------#

clean:
	@ echo "$(RED)CLEANING PROJECT ... $(RESET)"
	@ rm -rf $(OBJ_DIR)
	@ make --silent -C "include/libft/" fclean
# @ make --silent -C "include/MLX42/build/" clean
	@ echo "$(YELLOW)PROJECT CLEANED!\n $(RESET)"

fclean: clean
	@ rm -f $(NAME) $(BONUS_NAME)

re: fclean all

rebug: re debug
	@ ./cub3D maps/map_2.cub

compiling:
	@ echo "$(MAGENTA)COMPILING PROJECT: $(RESET)"

compiling_bonus:
	@ echo "$(MAGENTA)COMPILING BONUS: $(RESET)"

.PHONY: all clean fclean re bonus compiling libft MLX42 debug rebug
