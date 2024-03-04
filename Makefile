NAME := miniRT
NAME_AR := miniRT.a
TEST_NAME := test_miniRT
CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
DEBUG := -g -fsanitize=address -fno-omit-frame-pointer

SRCS_DIR := srcs
SRCS := $(SRCS_DIR)/main.c\

CAMERA_DIR := camera
SRCS += $(SRCS_DIR)/$(CAMERA_DIR)/camera.c\

ERROR_DIR = error
SRCS += $(SRCS_DIR)/$(ERROR_DIR)/error.c\

LIGHT_DIR := light
SRCS += $(SRCS_DIR)/$(LIGHT_DIR)/light.c\

PARSER_DIR := parser
SRCS += $(SRCS_DIR)/$(PARSER_DIR)/parser.c\
		$(SRCS_DIR)/$(PARSER_DIR)/minirt_list.c\

READ_RTFILE_DIR := read_rtfile
SRCS += $(SRCS_DIR)/$(PARSER_DIR)/$(READ_RTFILE_DIR)/is_target_file_extension.c\
		$(SRCS_DIR)/$(PARSER_DIR)/$(READ_RTFILE_DIR)/load_file_into_minirt_list.c\
		$(SRCS_DIR)/$(PARSER_DIR)/$(READ_RTFILE_DIR)/read_rt_file.c\
		$(SRCS_DIR)/$(PARSER_DIR)/$(READ_RTFILE_DIR)/convert_one_line_to_minirt_list.c\

VALIDATION_DIR := validation
SRCS += $(SRCS_DIR)/$(PARSER_DIR)/$(VALIDATION_DIR)/validate.c\
		$(SRCS_DIR)/$(PARSER_DIR)/$(VALIDATION_DIR)/validate_ambient_lighting.c\
		$(SRCS_DIR)/$(PARSER_DIR)/$(VALIDATION_DIR)/validate_camera.c\
		$(SRCS_DIR)/$(PARSER_DIR)/$(VALIDATION_DIR)/validate_light.c\
		$(SRCS_DIR)/$(PARSER_DIR)/$(VALIDATION_DIR)/validate_plane.c\
		$(SRCS_DIR)/$(PARSER_DIR)/$(VALIDATION_DIR)/validate_sphere.c\
		$(SRCS_DIR)/$(PARSER_DIR)/$(VALIDATION_DIR)/validate_cylinder.c\
		$(SRCS_DIR)/$(PARSER_DIR)/$(VALIDATION_DIR)/check_parameter_count.c\

CONVERT_DIR := convert
SRCS += $(SRCS_DIR)/$(PARSER_DIR)/$(CONVERT_DIR)/convert_string_to_double_in_range.c\
		$(SRCS_DIR)/$(PARSER_DIR)/$(CONVERT_DIR)/convert_string_to_unint8_in_range.c\
		$(SRCS_DIR)/$(PARSER_DIR)/$(CONVERT_DIR)/convert_value_to_vector_in_range.c\
		$(SRCS_DIR)/$(PARSER_DIR)/$(CONVERT_DIR)/convert_value_to_rgb.c\

SCENE_DIR = scene
SRCS += $(SRCS_DIR)/$(SCENE_DIR)/scene.c\
		$(SRCS_DIR)/$(SCENE_DIR)/shading.c\

SHAPE_DIR = shape
SRCS += $(SRCS_DIR)/$(SHAPE_DIR)/shape.c\

COLOR_DIR = color
SRCS += $(SRCS_DIR)/$(COLOR_DIR)/color.c\
		$(SRCS_DIR)/$(COLOR_DIR)/pixel_put.c

UNTIL_DIR = until
SRCS += $(SRCS_DIR)/$(UNTIL_DIR)/determine_intersection_of_ray_and_object.c\
		$(SRCS_DIR)/$(UNTIL_DIR)/ray.c\
		$(SRCS_DIR)/$(UNTIL_DIR)/vector.c\
		$(SRCS_DIR)/$(UNTIL_DIR)/verify_single_argument.c\
		$(SRCS_DIR)/$(UNTIL_DIR)/get_string_array_size.c\
		$(SRCS_DIR)/$(UNTIL_DIR)/set_error_and_return_null.c\
		$(SRCS_DIR)/$(UNTIL_DIR)/mlx.c \
		$(SRCS_DIR)/$(UNTIL_DIR)/clamp.c\

GNL_DIR := $(SRCS_DIR)/$(PARSER_DIR)/get_next_line
SRCS += $(GNL_DIR)/get_next_line.c\
		$(GNL_DIR)/get_next_line_until.c\

OBJS_DIR := ./objs
OBJS := $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

DEPS =	$(OBJS:.o=.d)

## libft settings
# libft
LIBFT_DIR := ./libft
LIBFT_AR := ./libft/libft.a
LIBFT_LIB_DIR := ./libft
LIBFT_LIB_NAME := ft
LIBFT_INC_DIR := ./libft

# minilibx
MINILIBX_DIR := ./minilibx-linux
MINILIBX_AR := ./minilibx-linux/libmlx.a
MINILIBX_LIB_DIR := ./minilibx-linux
MINILIBX := mlx
MINILIBX_INC_DIR := ./minilibx-linux

# test
TEST_DIR := ./test

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

LIBS := $(MINILIBX) $(X_WINDOW_LIB_NAME)
LIBS := $(addprefix -l, $(LIBS))

LDFLAGS := $(LIB_DIR) $(LIBS)

INC_DIR := ./includes $(MINILIBX_INC_DIR) $(X_WINDOW_INC_DIR) $(LIBFT_INC_DIR) $(GNL_DIR)
INCLUDES := $(addprefix -I, $(INC_DIR))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_AR)
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit $(OBJS) $(LIBFT_AR) $(LDFLAGS) -o $@

$(NAME_AR): $(OBJS)
	$(AR) -r $(NAME_AR) $^

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME_AR) $(MINILIBX) $(LIBFT_AR)

debug: CFLAGS += $(DEBUG)
debug: re

re: fclean all

test: fclean $(TEST_NAME)
	$(TEST_DIR)/$(TEST_NAME)

$(OBJS_DIR)/%.o: $(UNITY_DIR)/$(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(LIBFT_AR):
	make -C $(LIBFT_DIR)

$(TEST_NAME): $(NAME_AR)
	$(RM) -r $(TEST_DIR)/$(OBJS_DIR)
	@make -C $(TEST_DIR)

-include $(DEPS)
