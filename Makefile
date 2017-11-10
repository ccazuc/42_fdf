NAME = fdf

CFLAGS = -Wall -Wextra -Werror

CC = gcc

INCLUDES_PATH = include/

SRCS_PATH = src/

SRCS_NAME = main.c \
			parser.c \
			list_utils.c \
			init_window.c \
			get_next_line.c \
			get_coordinates.c \
			check_file.c \
			draw_line.c \
			pixel_put.c \
			draw_point.c \
			draw_window.c \
			key_handler.c \
			movement_handler.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -lmlx -L libft -lft -framework OpenGL -framework AppKit

all: odir $(NAME)

$(NAME): $(OBJS)
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) -I$(INCLUDES_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@echo " - Clearing objects files"
	@rm -f $(OBJS)

fclean: clean
	@echo " - Clearing executable file"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir
