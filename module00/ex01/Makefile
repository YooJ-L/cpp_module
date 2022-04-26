.PHONY			:	all re clean fclean

NAME			=	phonebook
CXX				=	clang++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98
INC				=	-I ./includes

SRCS			=	main.cpp \
					phonebook.cpp \
					contact.cpp \

OBJS			=	$(SRCS:.cpp=.o)

DEPS			=	$(OBJS:.o=.d)

all				:	$(NAME)

$(NAME)			:	$(OBJS)
				$(CXX) $(CXXFLAGS) $(INC) $^ -o $(NAME)

%.o			: %.cpp
				$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ -MD

clean			:
				rm -rf $(OBJS) $(DEPS)

fclean			: clean
				rm -rf $(NAME)

re				:	fclean all



-include $(DEPS)
