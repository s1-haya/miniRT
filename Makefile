# source file settings
SRCS := 
SRCS_DIR := ./srcs
OBJS_DIR := ./objs
OBJS := $(SRCS:.c=.o)
SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS := $(addprefix $(OBJS_DIR)/, $(OBJS))

## Library settings
# libft
LIBFT_DIR := ./libft
LIBFT := ./libft/libft.a
LIBFT_LIB_DIR := ./libft
LIBFT_LIB_NAME := ft
LIBFT_INC_DIR := ./libft/includes

# minilibx
MINILIBX_DIR := ./minilibx-linux
MINILIBX := ./minilibx-linux/libmlx.a
MINILIBX_LIB_DIR := ./minilibx-linux
MINILIBX_LIB_NAME := mlx
MINILIBX_INC_DIR := ./minilibx-linux

# Get target OS name
UNAME := $(shell uname)
# X Window system
ifeq ($(UNAME), Darwin)
    X_WINDOW_LIB_DIR := /usr/X11/lib
    X_WINDOW_LIB_NAME := X11 Xext
    X_WINDOW_INC_DIR := /usr/X11/include
else
    X_WINDOW_LIB_DIR := /usr/lib
    X_WINDOW_LIB_NAME := X11 Xext m z
    X_WINDOW_INC_DIR := /usr/include
endif

## Library search path
LIB_DIR := $(LIBFT_LIB_DIR) $(MINILIBX_LIB_DIR) $(X_WINDOW_LIB_DIR)
LIB_DIR := $(addprefix -L, $(LIB_DIR))

## Library names
LIBS := $(LIBFT_LIB_NAME) $(MINILIBX_LIB_NAME) $(X_WINDOW_LIB_NAME)
LIBS := $(addprefix -l, $(LIBS))

LDFLAGS := $(LIB_DIR) $(LIBS)

## include settings
INC_DIR := ./includes $(LIBFT_INC_DIR) $(MINILIBX_INC_DIR) $(X_WINDOW_INC_DIR)
INCLUDES := $(addprefix -I, $(INC_DIR))

# Command settings
CC := cc
CFLAGS := -Wall -Wextra -Werror -O3
# CFLAGS += -g -fsanitize=address -fsanitize=undefined
MAKE := make
RM := rm -rf

# Makefile rules
all: $(NAME)

$(OBJS_DIR)/%o: $(SRCS_DIR)/%c
    @if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
    $(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
    $(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
    $(MAKE) clean -C $(LIBFT_DIR)
    $(MAKE) clean -C $(MINILIBX_DIR)
    $(RM) $(OBJS_DIR)

fclean: clean
    $(MAKE) fclean -C $(LIBFT_DIR)
    $(RM) $(NAME)

re: fclean all

bonus: all

$(MINILIBX):
    $(MAKE) -C $(MINILIBX_DIR)

$(LIBFT):
    $(MAKE) -C $(LIBFT_DIR)
norm:
    -@norminette includes/ | grep -v "INVALID_HEADER"
    -@norminette srcs/ | grep -v "INVALID_HEADER"
# -@norminette libft/ | grep -v "INVALID_HEADER"

.PHONY: all clean fclean re bonus
