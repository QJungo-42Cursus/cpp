NAME =     		test
CC =			c++
CFLAGS =		-Wall -Wextra -Werror -std=c++98
RM =			rm -f
SRCS =			main.cpp Fixed.cpp
OBJS =			$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

t: all
	./$(NAME)

san: $(OBJS)
	@$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o $(NAME)
	./$(NAME)

.PHONY: all clean fclean re
