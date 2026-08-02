#include "irc.hpp"

static void setupBind(int fd, int port)
{
	struct sockaddr_in addr;

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);

	if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
		throw (Exception(ERROR, "bind : failed"));
}

static int setupSocket()
{
	int fd;

	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0)
		throw (Exception(ERROR, " socket : failed"));
	return (fd);
}

void setupListen(int fd)
{
	if (listen(fd, SOMAXCONN) < 0)
		throw (Exception(ERROR, "listen : failed"));
}

void	Server::init(Irc& irc, int ac, char** av)
{
	if (ac != 3)
		throw (Exception(ERROR, "usage : ./ircserver <port> <passWord>"));

	_port = ft_atoi(av[1]);
	if(_port <= 0)
		throw (Exception(ERROR, "port : bad port"));

	_passWord = av[2];
	_passWord += "\n";

	_fd = setupSocket();
	setupBind(_fd, _port);
	setupListen(_fd);

	irc.pfds.push_back(createPFD(_fd));
}
