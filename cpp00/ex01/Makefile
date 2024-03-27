CC				= c++
CFLAGS			= -Wall -Wextra -Werror

NAME			= phonebook

SRCS			= main.cpp \
				Contact.cpp \
				PhoneBook.cpp
OBJS			= $(SRCS:.cpp=.o)
INCLUDES		= Contact.hpp \
				PhoneBook.hpp

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
