NAME = push_swap
COMPILER = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRCS = 	main.c\
		swap_push.c\
		rotate.c\
		reverse_rotate.c\
		atol.c\
		utils.c\

OBJS = $(SRCS:%.c=%.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME):$(OBJS) $(LIBFT)
	$(COMPILER) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(COMPILER) $(CFLAGS) -g -c $< -o $@

clean:
		@rm -f *.o
		@echo "removing object files"

fclean: clean
		@rm -f $(NAME)
		@echo "removing executable file"

re: fclean all

.PHONY: all clean fclean re