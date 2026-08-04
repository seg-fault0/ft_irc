SRCS =	srcs/main.cpp					\
										\
		srcs/exception/exception.cpp	\
										\
		srcs/other/ft_atoi.cpp			\
		srcs/other/network.cpp			\
		srcs/other/ft_split.cpp			\
		srcs/other/paintStr.cpp			\
										\
		srcs/server/init.cpp			\
		srcs/server/luncher.cpp			\
		srcs/server/server.cpp			\
		srcs/server/log.cpp				\
		srcs/server/respond.cpp			\
										\
		srcs/server/clients/create.cpp	\
		srcs/server/clients/delete.cpp	\
		srcs/server/clients/search.cpp	\
		srcs/server/clients/manager.cpp	\
		srcs/server/clients/signIn.cpp	\
										\
		srcs/server/cmds/nick.cpp		\
		srcs/server/cmds/pass.cpp		\
		srcs/server/cmds/user.cpp		\
										\
		srcs/client/client.cpp			\
		srcs/client/readBuffer.cpp		\

HEADER =	includes/irc.hpp		\
			includes/exception.hpp	\
			includes/server.hpp		\
			includes/client.hpp		\

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