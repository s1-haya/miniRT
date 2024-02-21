TEST_NAME := test_miniRT
CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP

MINIRT_DIR := ..
MINIRT_AR := $(MINIRT_DIR)/miniRT.a

LIBFT_DIR := $(MINIRT_DIR)/libft
LIBFT_AR := $(MINIRT_DIR)/libft/libft.a

TEST_SRCS := test.c \

PARSER_DIR := parser
TEST_SRCS += $(PARSER_DIR)/test_is_target_file_extension.c\
			$(PARSER_DIR)/test_load_file_into_minirt_list.c\
			$(PARSER_DIR)/test_convert_one_line_to_minirt_list.c\
			$(PARSER_DIR)/test_read_rt_file.c\
			$(PARSER_DIR)/test_validate.c\

TEST_OBJS_DIR := ./objs
TEST_OBJS := $(patsubst %.c, $(TEST_OBJS_DIR)/%.o, $(TEST_SRCS))

UNITY_DIR := $(MINIRT_DIR)/Unity
UNITY_SRCS := $(UNITY_DIR)/src/unity.c
UNITY_OBJS := $(patsubst $(UNITY_DIR)/src/%.c, $(TEST_OBJS_DIR)/%.o, $(UNITY_SRCS))

INC_DIR := ./ $(UNITY_DIR)/src $(MINIRT_DIR)/includes
INCLUDES := $(addprefix -I, $(INC_DIR))

DEPS := $(TEST_OBJS_DIR:.d=.o)

.PHONY: all clean fclean

all: $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJS) $(UNITY_OBJS) $(MINIRT_AR) $(LIBFT_AR)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(UNITY_OBJS) $(MINIRT_AR) $(LIBFT_AR) -o $(TEST_NAME)
	$(RM) -r $(TEST_OBJS_DIR)

$(TEST_OBJS_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEST_OBJS_DIR)/%.o: $(UNITY_DIR)/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(TEST_OBJS_DIR)

fclean: clean
	$(RM) $(TEST_NAME) $(MINIRT_AR) $(LIBFT_AR)

$(LIBFT_AR):
	make -C $(LIBFT_DIR)

-include $(DEPS)
