NAME	 	=	zombie
CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

SRCS	=	main.cpp \
			newZombie.cpp \
			randomChump.cpp \
			Zombie.cpp

OBJS 	=	$(SRCS:.cpp=.o)

$(NAME)	:	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

all		:	$(NAME)

clean 	:
	rm -rf $(OBJS)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re