NAME		=	brain
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Wall -std=c++98

SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CXX) $(CXXFLAGS) $< -o $@

%.o	:	%.cpp
		$(CXX) $(CXXFLAGS) -c $^

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re		:	fclean all