NAME =     	convert
CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98
RM =		rm -f
OBJS =		$(SRCS:.cpp=.o)
SRCS =		main.cpp

%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

t: all
	./$(NAME) 0
	./$(NAME) nan
	./$(NAME) 42.0f
	./$(NAME) 0.5
	./$(NAME) inf
	./$(NAME) 2000000000000001
	./$(NAME) ""

.PHONY: all clean fclean re
