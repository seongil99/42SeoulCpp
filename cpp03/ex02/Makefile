CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME			= fragTrap

SRCS			= main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp
OBJS			= $(SRCS:.cpp=.o)
INCLUDES		= ClapTrap.hpp \
				ScavTrap.hpp \
				FragTrap.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

$(OBJS): $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all bonus clean fclean re
