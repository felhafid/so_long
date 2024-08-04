NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c utils_map.c utils_map1.c get_next_line.c get_next_line_utils.c correct_map.c keys.c key1.c correct_map1.c
MLX = ../MLX42/build/libmlx42.a -I"../../MLX42/include/MLX42/MLX42.h" -lglfw -L"/Users/felhafid/.brew/opt/glfw/lib/"
OBJS = ${SRC:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS) so_long.h
	@$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re