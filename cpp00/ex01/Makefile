.PHONY			:	all re clean fclean

NAME			=	phonebook
CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS			=	main.cpp \
					phonebook.cpp \
					contact.cpp \

OBJS			=	$(SRCS:.cpp=.o)

all				:	$(NAME)

$(NAME)			:	$(OBJS)
				$(CXX) $(CXXFLAGS) $(INC) $^ -o $(NAME)

%.o			: %.cpp
				$(CXX) $(CXXFLAGS) $(INC) -c $^

clean			:
				rm -rf $(OBJS) $(DEPS)

fclean			: clean
				rm -rf $(NAME)

re				:	fclean all
