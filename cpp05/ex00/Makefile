CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

NAME		= polymorphism

SRCS		= main.cpp \
				Bureaucrat.cpp

OBJS		= $(SRCS:.cpp=.o)

INCLUDES	= Bureaucrat.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(INCLUDES)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all bonus clean fclean re
