CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME			= aCXXount_test

SRCS			= tests.cpp \
				ACXXount.cpp
OBJS			= $(SRCS:.cpp=.o)
INCLUDES		= ACXXount.hpp

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
