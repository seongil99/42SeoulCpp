CC				= c++
CFLAGS			= -Wall -Wextra -Werror

NAME			= sifl

SRCS			= main.cpp
OBJS			= $(SRCS:.cpp=.o)
INCLUDES		=

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
