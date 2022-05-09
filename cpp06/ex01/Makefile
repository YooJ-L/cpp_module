NAME		=	Serialization
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Wall -std=c++98

SRCS	=	main.cpp \
			Data.cpp \
			
OBJS 	=	$(SRCS:.cpp=.o)

$(NAME)	:	$(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $@

all	:	$(NAME)

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re		:
	make fclean
	make all

.PHONY	: all clean fclean re
