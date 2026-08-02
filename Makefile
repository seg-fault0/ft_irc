SRCS =	srcs/main.cpp					\
		srcs/exception/exception.cpp	\

HEADER = 	includes/irc.hpp		\
			includes/exception.hpp	\

NAME = ircserver

CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -I includes/
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $@

%.o : %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all