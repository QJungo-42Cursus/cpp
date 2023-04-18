NAME =     	whatever
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

.PHONY: all clean fclean re
