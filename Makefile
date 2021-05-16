CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
REG_SRCS =	ft_printf.c \
			ft_proc_of_per.c\
			ft_printf_utils.c\
			ft_proc_precision.c\
			ft_proc_flags.c\
			ft_transition_of_integer.c
BONUS_SRCS = ft_printf_bonus.c \
			ft_proc_of_per_bonus.c\
			ft_printf_utils_bonus.c\
			ft_proc_precision_bonus.c\
			ft_tailgate_bonus.c\
			ft_transition_of_integer_bonus.c\
			ft_transition_of_long_bonus.c\
			ft_proc_specifier_bonus.c\
			ft_transition_n.c
REG_OBJS = $(REG_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
DEPS = $(REG_SRCS:.c=.d) $(BONUS_SRCS:.c=.d)

ifdef WITH_BONUS
OBJS = $(BONUS_OBJS)
else
OBJS = $(REG_OBJS)
endif

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft bonus
	cp libft/libft.a $(NAME)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus:
	$(MAKE) WITH_BONUS=1 all

%.o: %.c
	${CC} ${CFLAGS} -c -MMD -MP -o $@ $<

-include $(DEPS)

.PHONY:clean
clean:
	$(MAKE) -C ./libft clean
	rm -f $(REG_OBJS) $(BONUS_OBJS) $(DEPS)

.PHONY: fclean
fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

.PHONY: re
re: fclean all
