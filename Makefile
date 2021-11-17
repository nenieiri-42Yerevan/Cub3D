NAME		= cub3D

TMP			= tmp

SRCS		= $(wildcard ./srcs/*.c)

OBJS		= $(patsubst ./srcs/%.c, ./tmp/%.o, $(SRCS))

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

LIB			= ./lib

LIBFT		= $(LIB)/libft

LIBGNL		= $(LIB)/get_next_line

#LIBMLX		= $(LIB)/mlx_linux
#LIBMLX_		= lib/mlx_linux
#MLX			= -L$(LIBMLX) -lmlx -framework OpenGL -framework AppKit
#MACH_EXTRA	= install_name_tool -change @loader_path/libbass.dylib @loader_path/bass/libbass.dylib $(NAME) \
				&& install_name_tool -change libmlx.dylib @loader_path/${LIBMLX_}/libmlx.dylib $(NAME)

INCLUDES	= -I./includes #-Imlx_linux

LINKERS		= -L$(LIBGNL) -lgnl -L$(LIBFT) -lft #-L$(LIBMLX) -lmlx_Linux -lXext -lX11 -lm -lz

RM			= rm -rf

.PHONY:		all clean fclean re

./tmp/%.o:	./srcs/%.c ./includes/cub3D.h
			@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

all:		$(TMP) $(NAME)

$(TMP):
			@mkdir $(TMP)

$(NAME):	$(OBJS)
			@$(MAKE) -C $(LIBFT) all
			@$(MAKE) -C $(LIBGNL) all
			#@$(MAKE) -C $(LIBMLX) all
			$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LINKERS) -o $(NAME)
			#@$(MACH_EXTRA)

clean:
			@$(MAKE) -C $(LIBFT) clean
			@$(MAKE) -C $(LIBGNL) clean
			#@$(MAKE) -C $(LIBMLX) clean
			@$(RM) $(TMP)

fclean:		clean
			@$(MAKE) -C $(LIBFT) fclean
			@$(MAKE) -C $(LIBGNL) fclean
			@$(RM) $(NAME)

re:			fclean all
