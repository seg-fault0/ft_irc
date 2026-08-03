#include "irc.hpp"

static void handlePass(Server& server, Client& client)
{
	std::string	pass = client.getBuffer(1);
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
	std::string	nick = client.getBuffer(1);

	if (server.searchNickName(nick) == true)
		ft_send(client.getFd(), "ERROR : client already exists\n");
	else
		client.setNickName(nick);
}

void Client::signIn(Server& server)
{
	if (_buffer[0] == "PASS")
		handlePass(server,*this);
	else if (_buffer[0] == "NICK")
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