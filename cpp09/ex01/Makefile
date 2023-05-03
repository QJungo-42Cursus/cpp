NAME =     		RPN
CC =			c++
RM =			rm -f
SRCS =			main.cpp RPN.cpp

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
	./$(NAME) "5 6 7 * + 1 -"
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./$(NAME) "7 7 * 7 -"
	./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	./$(NAME) "(1 + 1)"


.PHONY: all clean fclean re
