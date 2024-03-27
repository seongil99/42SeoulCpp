CC				= c++
CFLAGS			= -Wall -Wextra -Werror

NAME			= zombie

SRCS			= main.cpp \
				Zombie.cpp \
				zombieHorde.cpp
OBJS			= $(SRCS:.cpp=.o)
INCLUDES		= Zombie.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJS): $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all bonus clean fclean re
