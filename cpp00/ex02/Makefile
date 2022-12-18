NAME =     		test
CC =			c++
RM =			rm -f
CFLAGS =		-Wall -Wextra -Werror -std=c++98 -pedantic-errors

SRCS =			tests.cpp Account.cpp
OBJS =			$(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

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
