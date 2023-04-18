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
LIBMLX_L_	= -L$(LIBMLX_L) -lmlx_Linux -lXext -lX11 -lm -lz
# LIBMLX_L_	= -L$(LIBMLX_L) -lmlx_Linux -lXext -lX11 -lm

LIBMLX_M	= $(LIB)/mlx
LIBMLX_M_	= -L$(LIBMLX_M) -lmlx -framework OpenGL -framework AppKit
MACH_EXTRA	= install_name_tool -change @loader_path/libbass.dylib @loader_path/bass/libbass.dylib $(NAME) \
				&& install_name_tool -change libmlx.dylib @loader_path/${LIBMLX_M}/libmlx.dylib $(NAME)

UNIX_NAME	= $(shell uname -s)

ifeq ($(UNIX_NAME),Darwin)
LIBMLX		= $(LIBMLX_M)
LIBMLX_LINK	= $(LIBMLX_M_)
else ifeq ($(UNIX_NAME),Linux)
LIBMLX		= $(LIBMLX_L)
LIBMLX_LINK	= $(LIBMLX_L_)
endif

INCLUDES	= -I./includes -I$(LIBMLX)

LINKERS		= -L$(LIBGNL) -lgnl -L$(LIBFT) -lft $(LIBMLX_LINK)

RM			= rm -rf

.PHONY:		all clean fclean re bonus bonus_on

./tmp/%.o:	./srcs/%.c ./includes/cub3D.h
			$(CC) $(CFLAGS) $(INCLUDES) -D OS_NAME=$(UNIX_NAME) \
				-D BONUS=$(BONUS_) -o $@ -c $<

all:		bonus

bonus:		bonus_on $(NAME) 

bonus_on:
			$(eval BONUS_ = 1)

$(TMP):
			@mkdir $(TMP)

$(NAME):	$(TMP) $(OBJS)
			@$(MAKE) -C $(LIBFT) all
			@$(MAKE) -C $(LIBGNL) all
			@$(MAKE) -C $(LIBMLX) all
			# @$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LINKERS) -o $(NAME)
			@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LINKERS) -Wl,--allow-multiple-definition -o $(NAME)
ifeq ($(UNIX_NAME),Darwin)
			@$(MACH_EXTRA)
endif

clean:
			@$(MAKE) -C $(LIBFT) clean
			@$(MAKE) -C $(LIBGNL) clean
			@$(RM) $(TMP)

fclean:		clean
			@$(MAKE) -C $(LIBFT) fclean
			@$(MAKE) -C $(LIBGNL) fclean
			@$(RM) $(NAME)

re:			fclean all
