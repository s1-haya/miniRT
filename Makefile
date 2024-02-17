# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 13:55:33 by hsawamur          #+#    #+#              #
#    Updated: 2024/02/18 08:22:05 by hsawamur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -g
DEBUG := -g -fsanitize=address -fno-omit-frame-pointer

SRCS_DIR = srcs
SRCS = $(SRCS_DIR)/main.c\

CAMERA_DIR = camera
SRCS += $(SRCS_DIR)/$(CAMERA_DIR)/camera.c\

ERROR_DIR = error
SRCS += $(SRCS_DIR)/$(ERROR_DIR)/error.c\

LIGHT_DIR = light
SRCS += $(SRCS_DIR)/$(LIGHT_DIR)/light.c\

PARSE_DIR = parser
SRCS += $(SRCS_DIR)/$(PARSE_DIR)/parser.c\

SCENE_DIR = scene
SRCS += $(SRCS_DIR)/$(SCENE_DIR)/scene.c\
		$(SRCS_DIR)/$(SCENE_DIR)/cast_a_shadow.c\

SHAPE_DIR = shape
SRCS += $(SRCS_DIR)/$(SHAPE_DIR)/shape.c\

COLOR_DIR = color
SRCS += $(SRCS_DIR)/$(COLOR_DIR)/color.c\
		$(SRCS_DIR)/$(COLOR_DIR)/pixel_put.c

UNTIL_DIR = until
SRCS += $(SRCS_DIR)/$(UNTIL_DIR)/determine_intersection_of_ray_and_object.c\
		$(SRCS_DIR)/$(UNTIL_DIR)/ray.c\
		$(SRCS_DIR)/$(UNTIL_DIR)/vector.c\
		$(SRCS_DIR)/$(UNTIL_DIR)/get_value_in_range.c\
		$(SRCS_DIR)/$(UNTIL_DIR)/mlx.c

TEST_SRCS_DIR := test
TEST_SRCS := $(TEST_SRCS_DIR)/test.c\

OBJS_DIR := objs
OBJS := $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

TEST_OBJS_DIR := objs
TEST_OBJS := $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(filter-out $(SRCS_DIR)/main.c, $(SRCS))) $(patsubst $(TEST_SRCS_DIR)/%.c, $(TEST_OBJS_DIR)/%.o, $(TEST_SRCS))

# INCLUDES_DIR := includes
# INCLUDES := -I$(INCLUDES_DIR)

DEPS =	$(OBJS:.o=.d)

## Library settings
# libft
# LIBFT_DIR := ./libft
# LIBFT := ./libft/libft.a
# LIBFT_LIB_DIR := ./libft
# LIBFT_LIB_NAME := ft
# LIBFT_INC_DIR := ./libft/includes

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

LIB_DIR := $(MINILIBX_LIB_DIR) $(X_WINDOW_LIB_DIR)
LIB_DIR := $(addprefix -L, $(LIB_DIR))

LIBS := $(MINILIBX_LIB_NAME) $(X_WINDOW_LIB_NAME)
LIBS := $(addprefix -l, $(LIBS))

LDFLAGS := $(LIB_DIR) $(LIBS)

INC_DIR := ./includes $(MINILIBX_INC_DIR) $(X_WINDOW_INC_DIR)
INCLUDES := $(addprefix -I, $(INC_DIR))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

debug: CFLAGS += $(DEBUG)
debug: re

re: fclean all

test: $(TEST_OBJS) $(MINILIBX)
	@$(CC) $(CFLAGS) $(TEST_OBJS) $(LDFLAGS) -o test_miniRT
	@./test_miniRT
	@$(RM) -r $(TEST_OBJS_DIR) test_miniRT

$(TEST_OBJS_DIR)/%.o: $(TEST_SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -I./Unity/src -c $< -o $@

$(MINILIBX):
	make -C $(MINILIBX_DIR)

-include $(DEPS)
