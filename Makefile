NAME		= cub3D

TMP			= tmp

SRCS		= $(wildcard ./srcs/*.c)

OBJS		= $(patsubst ./srcs/%.c, ./tmp/%.o, $(SRCS))

BONUS_		= 0

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

LIB			= ./lib

LIBFT		= $(LIB)/libft

LIBGNL		= $(LIB)/get_next_line

LIBMLX_L	= $(LIB)/mlx_linux
#LIBMLX_		= lib/mlx_linux
#MLX			= -L$(LIBMLX) -lmlx -framework OpenGL -framework AppKit
#MACH_EXTRA	= install_name_tool -change @loader_path/libbass.dylib @loader_path/bass/libbass.dylib $(NAME) \
				&& install_name_tool -change libmlx.dylib @loader_path/${LIBMLX_}/libmlx.dylib $(NAME)

INCLUDES	= -I./includes -I$(LIBMLX_L)

LINKERS		= -L$(LIBGNL) -lgnl -L$(LIBFT) -lft -L$(LIBMLX_L) -lmlx_Linux \
			  -lXext -lX11 -lm -lz

RM			= rm -rf

.PHONY:		all clean fclean re bonus bonus_on

./tmp/%.o:	./srcs/%.c ./includes/cub3D.h
			$(CC) $(CFLAGS) $(INCLUDES) -D BONUS=$(BONUS_) -o $@ -c $<

all:		bonus

bonus:		bonus_on $(NAME) 

bonus_on:
			$(eval BONUS_ = 1)

$(TMP):
			@mkdir $(TMP)

$(NAME):	$(TMP) $(OBJS)
			@$(MAKE) -C $(LIBFT) all
			@$(MAKE) -C $(LIBGNL) all
			@$(MAKE) -C $(LIBMLX_L) all
			@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LINKERS) -o $(NAME)
			#@$(MACH_EXTRA)

clean:
			@$(MAKE) -C $(LIBFT) clean
			@$(MAKE) -C $(LIBGNL) clean
			@$(MAKE) -C $(LIBMLX_L) clean
			@$(RM) $(TMP)

fclean:		clean
			@$(MAKE) -C $(LIBFT) fclean
			@$(MAKE) -C $(LIBGNL) fclean
			@$(RM) $(NAME)

re:			fclean all
