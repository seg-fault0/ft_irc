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
		srcs/server/client.cpp			\
		srcs/server/channel.cpp			\
										\
		srcs/server/cmds/manager.cpp	\
		srcs/server/cmds/signIn.cpp		\
		srcs/server/cmds/nick.cpp		\
		srcs/server/cmds/pass.cpp		\
		srcs/server/cmds/user.cpp		\
		srcs/server/cmds/quit.cpp		\
		srcs/server/cmds/join.cpp		\
		srcs/server/cmds/part.cpp		\
		srcs/server/cmds/privmsg.cpp	\
										\
		srcs/client/client.cpp			\
		srcs/client/readBuffer.cpp		\
		srcs/client/channel.cpp			\
		srcs/client/request.cpp			\
										\
		srcs/channel/client.cpp			\
		srcs/channel/admin.cpp			\
		srcs/channel/geters.cpp			\
		srcs/channel/seters.cpp			\
		srcs/channel/orthodox.cpp		\

HEADER =	includes/irc.hpp			\
			includes/exception.hpp		\
			includes/server.hpp			\
			includes/client.hpp			\
			includes/channel.hpp		\
			includes/respondBuilder.hpp	\
			includes/request.hpp		\

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