NAME		=	Form
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Wall -std=c++98 $(INFLAGS)
INFLAGS		=	-I$(INCDIR)
INCDIR		=	./includes/
SRCDIR		=	./srcs/

SRCS	=	main.cpp \
			$(addprefix $(SRCDIR), \
			Bureaucrat.cpp \
			Form.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp)
			
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
