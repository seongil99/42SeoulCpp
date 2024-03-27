CC				= c++
CFLAGS			= -Wall -Wextra -Werror

NAME			= account_test

SRCS			= tests.cpp \
				Account.cpp
OBJS			= $(SRCS:.cpp=.o)
INCLUDES		= Account.hpp

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
