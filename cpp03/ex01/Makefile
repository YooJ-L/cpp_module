NAME		=	claptrap
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Wall -std=c++98

SRCS	=	main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp
			
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