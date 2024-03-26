CC			= c++
CFLAGS		= -Wall -Wextra -Werror

NAME		= polymorphism

SRCS		= main.cpp \
			Animal.cpp \
			Brain.cpp \
			Dog.cpp \
			Cat.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp

OBJS		= $(SRCS:.cpp=.o)

INCLUDES	= Animal.hpp \
			Brain.hpp \
			Dog.hpp \
			Cat.hpp \
			WrongAnimal.hpp \
			WrongCat.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(INCLUDES)

%.o: %.cpp
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all bonus clean fclean re