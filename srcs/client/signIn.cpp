#include "irc.hpp"

static void handlePass(Server& server, Client& client)
{
	std::string	pass = client.getBuffer()[1];
	int			fd = client.getFd();

	if (client.isPassAccepted() == true)
		return ;
	else if(pass != server.getPassWord())
		server.log.add(client, "wrong pass word");
	else
	{
		client.setPass(true);
		server.log.add(client, "entered right pass word");
	}
}

static void	handleNick(Server& server, Client& client)
{
	std::string	nick = client.getBuffer()[1];

	if (server.searchNickName(nick) == true)
		server.log.add(client, "nick name already taken");
	else
		client.setNickName(nick);
}

static void handleUser(Server& server, Client& client)
{
	if (client.getBuffer().size() < 5 || client.getBuffer(4)[0] != ':')
		server.log.add(client, "bad args");
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
		server.log.add(*this, "wrong command");

	if (_isPassAccepted == true && !_nickName.empty()
		&& !_userName.empty() && !_realName.empty())
	{
		_isRegistered = true;
		server.log.add(server, "new user registered");
	}
}