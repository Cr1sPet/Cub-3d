NAME			= cub3D

SRCS			=	./src/main.c\
					./src/get_next_line/get_next_line.c\
					./src/utils.c\
					./src/parsing/parsing.c\
					./src/parsing/validation.c\
					./src/parsing/parsing_utils.c\
					./src/parsing/config_identifier.c\
					./src/parsing/config_identifier2.c\
					./src/parsing/init.c\
					./src/parsing/init_cub.c\
					./src/parsing/parse_map.c\
					./src/parsing/parse_map_utils.c\
					./src/drawing/draw_3d.c\
					./src/drawing/draw_minimap.c\
					./src/moving/move.c\
					./src/moving/utils.c\
					./src/drawing/utils.c\

SRCS_B			=

MLX_DIR			=	./mlx/
MLX_LIB			=	./mlx/libmlx.a

HEADER			= ./includes/

LIBFT			= libft/libft.a


OBJ				= $(SRCS:.c=.o)

OBJ_B			= $(SRCS_B:.c=.o)

CC				= gcc -g

RM				= @rm -f

FLAGS			= -Wall -Wextra -Werror

.PHONY:			all clean fclean re bonus

all:			$(NAME)


$(NAME):		$(OBJ) ./includes/cub3d.h ./includes/parsing.h
				@($(MAKE)	-C		$(MLX_DIR))
				@$(MAKE) all -C ./libft
				$(CC) $(OBJ) $(MLX_LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -I${HEADER} ${LIBFT} -o $(NAME)


%.o:			%.c $(HEADER)
				$(CC) -g $(FLAGS) -I${HEADER} -c $< -o $@

bonus:
				make OBJ="$(OBJ_B)" all

clean:
				@$(MAKE) clean -C ./libft
				@(make	clean -C	$(MLX_DIR))
				$(RM) $(OBJ) $(OBJ_B)

fclean:			clean
				@$(MAKE) fclean -C ./libft
				$(RM) $(NAME)

re:				fclean $(NAME)