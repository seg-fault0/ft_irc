#include "irc.hpp"

static void handlePass(Server& server, Client& client)
{
	std::string	pass = client.getBuffer().substr(5);
	int			fd = client.getFd();

	if (client.isPassAccepted() == true)
		return ;
	else if(pass != server.getPassWord())
		ft_send(fd, "ERROR : wrong pass word\n");
	else
	{
		client.setPass(true);
		ft_send(fd, "pass word accepted\n");
	}
}

static void	handleNick(Server& server, Client& client)
{
	std::string	nick = client.getBuffer().substr(5);

	if (server.searchNickName(nick) == true)
		ft_send(client.getFd(), "ERROR : client already exists\n");
	else
		client.setNickName(nick);
}

void Client::signIn(Server& server)
{
	if (_buffer.compare(0, 4, "PASS") == 0)
		handlePass(server,*this);
	else if (_buffer.compare(0, 4, "NICK") == 0)
		handleNick(server, *this);
	else
		ft_send(_fd, "wrong command\n");

	if (_isPassAccepted == true
		&& !_nickName.empty())
	{
		_isRegistered = true;
		ft_send(_fd, "Regestration completed\n");	
	}
}