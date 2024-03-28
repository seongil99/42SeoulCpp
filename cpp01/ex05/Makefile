CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME			= harl2.0

SRCS			= main.cpp \
				Harl.cpp
OBJS			= $(SRCS:.cpp=.o)
INCLUDES		= Harl.hpp

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
