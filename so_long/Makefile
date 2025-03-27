CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = mandatory
UTILS_DIR = $(SRC_DIR)/utils
SRC_DIR_B = bonus
UTILS_DIR_B = $(SRC_DIR_B)/utils

SRC = $(UTILS_DIR)/ft_bzero.c $(UTILS_DIR)/ft_calloc.c $(UTILS_DIR)/ft_putchar_fd.c \
       $(UTILS_DIR)/ft_strjoin.c $(UTILS_DIR)/ft_putnbr_fd.c $(UTILS_DIR)/ft_putstr_fd.c \
       $(UTILS_DIR)/ft_split.c $(UTILS_DIR)/ft_strchr.c $(UTILS_DIR)/ft_strdup.c \
       $(UTILS_DIR)/ft_strlcpy.c $(UTILS_DIR)/ft_strlen.c $(UTILS_DIR)/ft_strncmp.c \
       $(UTILS_DIR)/ft_substr.c $(UTILS_DIR)/get_next_line.c \
       $(SRC_DIR)/check_map.c $(SRC_DIR)/draw_map.c $(SRC_DIR)/put_img.c $(SRC_DIR)/so_long.c

SRC_B = $(UTILS_DIR_B)/ft_bzero_bonus.c $(UTILS_DIR_B)/ft_calloc_bonus.c $(UTILS_DIR_B)/ft_putchar_fd_bonus.c \
   		$(UTILS_DIR_B)/ft_strjoin_bonus.c $(UTILS_DIR_B)/ft_putnbr_fd_bonus.c $(UTILS_DIR_B)/ft_putstr_fd_bonus.c \
   		$(UTILS_DIR_B)/ft_split_bonus.c $(UTILS_DIR_B)/ft_strchr_bonus.c $(UTILS_DIR_B)/ft_strdup_bonus.c \
   		$(UTILS_DIR_B)/ft_strlcpy_bonus.c $(UTILS_DIR_B)/ft_strlen_bonus.c $(UTILS_DIR_B)/ft_strncmp_bonus.c \
   		$(UTILS_DIR_B)/ft_substr_bonus.c $(UTILS_DIR_B)/get_next_line_bonus.c $(UTILS_DIR_B)/ft_itoa_bonus.c \
   		$(SRC_DIR_B)/check_map_bonus.c $(SRC_DIR_B)/draw_map_bonus.c $(SRC_DIR_B)/put_img_bonus.c $(SRC_DIR_B)/so_long_bonus.c

OBJS = $(SRC:.c=.o)
OBJS_B = $(SRC_B:.c=.o)

NAME = so_long
NAME_B = so_long_bonus

MLX = -lmlx -framework OpenGL -framework AppKit

HEADERS = mandatory/so_long.h mandatory/utils/libft.h
HEADERS_B = bonus/so_long.h bonus/utils/libft.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS) -o $@

bonus: $(NAME_B)

$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) $(MLX) $(OBJS_B) -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR_B)/%.o: $(SRC_DIR_B)/%.c $(HEADERS_B)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY: clean
