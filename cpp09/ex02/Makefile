CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -MMD -MP -std=c++98

NAME			= PmergeMe

SRCS			= main.cpp \
					PmergeMe.cpp \

OBJS			= $(SRCS:.cpp=.o)

DEP				= $(patsubst %.cpp,%.d,$(SRCS))
-include $(DEP)

rm				= rm -f

.DEFAULT_GOAL	= all

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEP)

fclean:
	$(RM) $(NAME) $(OBJS) $(DEP)

re: fclean
	make all

.PHONY: all bonus clean fclean re

test: $(NAME)
	./$(NAME) $(shell jot -r 3000 1 1000 | tr '\n' ' ')
