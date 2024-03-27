CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME			= clapTrap

SRCS			= main.cpp \
				ClapTrap.cpp
OBJS			= $(SRCS:.cpp=.o)
INCLUDES		= ClapTrap.hpp

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
