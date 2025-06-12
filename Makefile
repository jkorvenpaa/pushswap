NAME = push_swap.a
COMPILER = cc
COPILERFLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRCS = push_swap.c\

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(COMPILER) $(COMPILERFLAGS) -c $< -o $@

clean:
		@rm -f *.o
		@echo "removing object files"

fclean: clean
		@rm -f $(NAME)
		@echo "removing executable file"

re: fclean all

.PHONY: all clean fclean re