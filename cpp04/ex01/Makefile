NAME =     	burn
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

SAN =	-fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all \
		-fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow \
		-fno-sanitize=null -fno-sanitize=alignment
san:
	$(CC) -g $(SAN) $(SRCS) -o $(NAME)
	./$(NAME)

.PHONY: all clean fclean re
