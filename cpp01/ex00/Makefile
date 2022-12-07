NAME =     		zombie
CC =			c++
CFLAGS =		-Wall -Wextra -Werror -std=c++98
RM =			rm -f

SRCS =			Zombie.cpp main.cpp newZombie.cpp randomChump.cpp
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

.PHONY: all clean fclean re
