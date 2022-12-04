NAME =     	claptrap
CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow
RM =		rm -f

SRCS =		main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS =		$(SRCS:.cpp=.o)

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
