#include "irc.hpp"

static void handlePass(Server& server, Client& client)
{
	std::string	pass = client.getBuffer()[1];
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
	std::string	nick = client.getBuffer()[1];

	if (server.searchNickName(nick) == true)
		ft_send(client.getFd(), "ERROR : client already exists\n");
	else
		client.setNickName(nick);
}

static void handleUser(Server& server, Client& client)
{
	if (client.getBuffer().size() < 5 || client.getBuffer(4)[0] != ':')
		ft_send(client.getFd(), "ERROR : BAD INPUT\n");
	else
	{
		client.setUserName(client.getBuffer()[1]);
		std::string tmp;
		for(int i = 4; i < client.getBuffer().size(); i++)
		{
			tmp += client.getBuffer(i);
			if (i + 1 < client.getBuffer().size())
				tmp += " ";
		}
		client.setRealName(tmp);
	}
}

void Client::signIn(Server& server)
{
	std::string& cmd = _buffer[0];

	if (cmd == "PASS")
		handlePass(server,*this);
	else if (cmd == "NICK")
		handleNick(server, *this);
	else if (cmd == "USER")
		handleUser(server, *this);
	else
		ft_send(_fd, "wrong command\n");

	if (_isPassAccepted == true && !_nickName.empty()
		&& !_userName.empty() && !_realName.empty())
	{
		_isRegistered = true;
		ft_send(_fd, "Regestration completed\n");	
	}
}