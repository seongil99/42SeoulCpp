CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

NAME		= polymorphism

SRCS		= main.cpp \
				AMateria.cpp \
				Character.cpp \
				Cure.cpp \
				Ice.cpp \
				MateriaSource.cpp

OBJS		= $(SRCS:.cpp=.o)

INCLUDES	= AMateria.hpp \
				Character.hpp \
				Cure.hpp \
				Ice.hpp \
				ICharacter.hpp \
				IMateriaSource.hpp \
				MateriaSource.hpp

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
