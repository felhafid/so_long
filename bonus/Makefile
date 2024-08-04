NAME = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = main_bonus.c utils_map_bonus.c utils_map1_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c \
	correct_map_bonus.c keys_bonus.c key1_bonus.c correct_map1_bonus.c utils_key_bonus.c put_string_bonus.c
MLX = ../MLX42/build/libmlx42.a -I"../../MLX42/include/MLX42/MLX42.h" -lglfw -L"/Users/felhafid/.brew/opt/glfw/lib/"
OBJS = ${SRC:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS) so_long_bonus.h
	@$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re