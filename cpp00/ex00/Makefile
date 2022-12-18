NAME =     		megaphone
CC =			c++
CFLAGS =		-Wall -Wextra -Werror -std=c++98 -pedantic-errors
RM =			rm -f

SRCS =			main.cpp
OBJS =			$(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

t: all
	./$(NAME) "salut les amis !"

san:
	@$(CC) $(CFLAGS) -fsanitize=address $(SRCS) -o $(NAME)
	./$(NAME) "salut les amis !"

.PHONY: all clean fclean re
