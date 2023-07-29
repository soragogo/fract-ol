NAME = fractol

SRC_DIR = src/
INC_DIR = includes/
OBJ_DIR = obj/

SRCS = $(SRC_DIR)main.c \
		$(SRC_DIR)julia_and_mandelbrot.c \
		$(SRC_DIR)rgb_generator.c \
		$(SRC_DIR)err_hand_arg_conv.c \
		$(SRC_DIR)new_image.c \
		$(SRC_DIR)events_by_users.c \
		$(SRC_DIR)ft_strncmp.c

OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

MINILIB_DIR = minilibx-linux/
LDFLAGS = -L$(MINILIB_DIR)
# LDLIBS = -lmlx -framework OpenGL -framework AppKit -lm -L/usr/X11R6/lib
LDLIBS = -lm -L/usr/X11R6/lib -L minilibx-linux -lmlx -lX11 -lXext -framework OpenGL -framework AppKit

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS) minilibx-linux/libmlx.a

# Create rule for object files creation
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re: fclean all
