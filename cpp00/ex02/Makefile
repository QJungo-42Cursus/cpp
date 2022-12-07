NAME =     		test
CC =			c++
CFLAGS =		-Wall -Wextra -Werror -std=c++98 -no-pie
RM =			rm -f

SRCS =			tests.cpp Account.cpp
OBJS =			$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

t:
	make all
	./$(NAME)

san: $(OBJS)
	@$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o $(NAME) || make fclean
	./$(NAME)

.PHONY: all clean fclean re
