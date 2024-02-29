# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 13:32:50 by hsawamur          #+#    #+#              #
#    Updated: 2024/02/29 13:21:47 by hsawamur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := library.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
AR := ar
ARFLAGS := r
SRCS :=  ft_isalpha.c \
		ft_isspace.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		\
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_strtod.c \
		\
		ft_calloc.c \
		ft_strdup.c \
		ft_strndup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		\
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c
		\
		ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c

.c.o:
	$(CC) $(CFLAGS) -c $^ -o $@ -I.

# $@ target名
$(NAME): $(SRCS:.c=.o)
	$(AR) $(ARFLAGS) $(NAME) $(SRCS:.c=.o)

all: 
	$(NAME)

clean: $(SRCS:.c=.o)
	rm $(SRCS:.c=.o)
 
fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make

.PHONY: all clean fclean re

