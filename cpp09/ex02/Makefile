NAME =     		PmergeMe
CC =			c++
RM =			rm -f
SRCS =			main.cpp PmergeMe.cpp

CFLAGS =		-Wall -Wextra -Werror -std=c++98 -pedantic-errors

%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

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
	./$(NAME) 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 564 22

.PHONY: all clean fclean re
