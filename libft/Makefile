# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/10 17:18:54 by srakuma           #+#    #+#              #
#    Updated: 2021/04/30 22:28:32 by srakuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c
BONUS_SRCS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c
REG_OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
DEPS = $(SRCS:.c=.d) $(BONUS_SRCS:.c=.d)

ifdef WITH_BONUS
OBJ_FILES = $(REG_OBJS) $(BONUS_OBJS)
else
OBJ_FILES = $(REG_OBJS)
endif

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -cr $(NAME) $(OBJ_FILES)
	ranlib $(NAME)

.PHONY: bonus
bonus:
	$(MAKE) WITH_BONUS=1 all

%.o: %.c
		${CC} ${CFLAGS} -c -MMD -MP -o $@ $<

-include $(DEPS)

.PHONY: clean
clean:
	rm -f $(REG_OBJS) $(BONUS_OBJS) $(DEPS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

