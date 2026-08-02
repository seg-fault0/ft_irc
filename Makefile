SRCS =	srcs/main.cpp					\
		srcs/exception/exception.cpp	\
		srcs/other/ft_atoi.cpp			\
		srcs/other/createPfd.cpp		\
		srcs/other/ft_send.cpp			\
		srcs/server/init.cpp			\
		srcs/server/run.cpp				\
		srcs/server/server.cpp			\
		srcs/server/printServerInfo.cpp	\
		srcs/irc/createClient.cpp		\
		srcs/irc/deleteClient.cpp		\
		srcs/irc/search.cpp				\
		srcs/irc/manageClients.cpp		\
		srcs/client/client.cpp			\
		srcs/client/readBuffer.cpp		\
		srcs/client/signIn.cpp			\

HEADER = 	includes/irc.hpp		\
			includes/exception.hpp	\
			includes/server.hpp		\
			includes/client.hpp		\

NAME = ircserver

CC = c++
FLAGS = -I includes/ -std=c++98 #-Wall -Wextra -Werror
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