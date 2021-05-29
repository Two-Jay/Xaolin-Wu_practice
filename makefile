NAME = xaolinwu
CC = gcc

LIBDIR = ../libft/
MLXDIR = ../minimlx_opengl/

CCFLAG = -Wall -Wextra -Werror -g3
LIBFLAG = -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MLXDIR) -framework OpenGL -framework AppKit
INCLUDES = -I.

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEADERS = $(LIBFT_DIR)

MINILIBX = $(MLXDIR)libmlx.a
MLXDIR = ./mlx_opengl/
MLX_HEAD = $(MLXDIR)

HEADFILE = xaolinwu.h
INCDIR = ./
HEADS = $(addprefix $(INCDIR), $(HEADFILE))

SRCFILE = ./main.c

OBJECTS = $(SRCFILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_DIR)
	make -C $(MLXDIR)
	$(CC) $(FLAGS) $(LIBFLAG) $(INCLUDES) $(OBJECTS) -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLXDIR) clean
	rm -rf $(OBJECTS)
	
fclean: clean
	rm -f $(MINILIBX)
	rm -f $(LIBFT)
	rm -f $(NAME)

re:	fclean all

debug: fclean all
	lldb $(NAME)

.PHONY : all, clean, fclean, re;