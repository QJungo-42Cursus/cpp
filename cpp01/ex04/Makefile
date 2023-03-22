NAME =     	ft_sed
CC =			c++
RM =			rm -f
SRCS =			main.cpp

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
	./$(NAME)

san:
	$(CC) $(CFLAGS) -fsanitize=address $(SRCS) -o $(NAME)
	./$(NAME)

.PHONY: all clean fclean re
