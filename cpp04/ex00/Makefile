NAME		=	polymorphism
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Wall -std=c++98 $(INFLAGS)
INFLAGS		=	-I$(INCDIR)
INCDIR		=	./includes/
SRCDIR		=	./srcs/

SRCS	=	main.cpp \
			$(addprefix $(SRCDIR), \
			Animal.cpp \
			Dog.cpp \
			Cat.cpp \
			WrongAnimal.cpp \
			WrongDog.cpp \
			WrongCat.cpp)
			
OBJS 	=	$(SRCS:.cpp=.o)

$(NAME)	:	$(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $@

all	:	$(NAME)

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re
