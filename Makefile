SRCS	= srcs/push_swap.c srcs/init.c srcs/exit.c

SRCS	+= srcs/utils/utils.c

OBJS	= $(SRCS:.c=.o)

NAME	= push_swap

CLANG	= clang

FLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

.PHONY:	clean fclean re

$(NAME): $(OBJS)
	$(CLANG) $(FLAGS) -o $(NAME) $(OBJS) $(INCLUDE)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CLANG) $(FLAGS) -c $< -o $(<:.c=.o)