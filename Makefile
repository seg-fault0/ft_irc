SRCS =	srcs/main.cpp					\
										\
		srcs/exception/exception.cpp	\
										\
		srcs/other/ft_atoi.cpp			\
		srcs/other/network.cpp			\
		srcs/other/ft_split.cpp			\
										\
		srcs/server/init.cpp			\
		srcs/server/luncher.cpp			\
		srcs/server/server.cpp			\
										\
		srcs/server/clients/create.cpp	\
		srcs/server/clients/delete.cpp	\
		srcs/server/clients/search.cpp	\
										\
		srcs/client/client.cpp			\
		srcs/client/readBuffer.cpp		\
		srcs/client/signIn.cpp			\
		srcs/client/manager.cpp

HEADER =	includes/irc.hpp		\
			includes/exception.hpp	\
			includes/server.hpp		\
			includes/client.hpp

NAME = ircserver

CC = c++
FLAGS = -I includes/ -std=c++98 #-Wall -Wextra -Werror

OBJDIR = obj
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all