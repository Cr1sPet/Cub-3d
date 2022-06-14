NAME			= cub3D

SRCS			=	./src/main.c\
					./src/get_next_line/get_next_line.c\
					./src/utils.c\
					./src/parsing/parsing.c\
					./src/parsing/validation.c\
					./src/parsing/parsing_utils.c\
					./src/parsing/config_identifier.c\
					./src/parsing/parse_map.c\
					./src/parsing/parse_map_utils.c\
					./src/drawing/draw.c\
					./src/drawing/draw_3d.c\
					# ./src/draw.c\
					# ./src/get_next_line/get_next_line_utils.c\

SRCS_B			=

HEADER			= ./includes/

LIBFT			= libft/libft.a


OBJ				= $(SRCS:.c=.o)

OBJ_B			= $(SRCS_B:.c=.o)

CC				= gcc -g

RM				= @rm -f

# FLAGS			= -Wall -Wextra -Werror

.PHONY:			all clean fclean re bonus

all:			$(NAME)


$(NAME):		$(OBJ) ./includes/cub3d.h ./includes/parsing.h
				@$(MAKE) all -C ./libft
				$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -I${HEADER} ${LIBFT} -o $(NAME)
				# $(CC) $(OBJ) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -I${HEADER} ${LIBFT} -o $(NAME)
# $(CC) $(OBJ) -I${HEADER} ${LIBFT} -o $(NAME)


%.o:			%.c $(HEADER)
				#$(CC) -g $(FLAGS) -I/usr/include -Imlx -O3 -I${HEADER} -c $< -o $@
				 $(CC) -g $(FLAGS) -I${HEADER} -c $< -o $@
#				$(CC) -g $(FLAGS) -Imlx -I${HEADER} -c $< -o $@

bonus:
				make OBJ="$(OBJ_B)" all

clean:
				@$(MAKE) clean -C ./libft
				$(RM) $(OBJ) $(OBJ_B)

fclean:			clean
				@$(MAKE) fclean -C ./libft
				$(RM) $(NAME)

re:				fclean $(NAME)