CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME			= violence

SRCS			= main.cpp \
				HumanA.cpp \
				HumanB.cpp \
				Weapon.cpp
OBJS			= $(SRCS:.cpp=.o)
INCLUDES		= HumanA.hpp \
				HumanB.hpp \
				Weapon.hpp

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
