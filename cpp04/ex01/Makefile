NAME =     	claptrap
CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98
RM =		rm -f

SRCS =		main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
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

san:
	$(CC) -g -fsanitize=address $(SRCS) -o $(NAME)
	./$(NAME)

.PHONY: all clean fclean re
