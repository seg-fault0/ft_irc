#include "irc.hpp"

static void handlePass(Server& server, Client& client)
{
	std::string	pass = client.getCmd(1);
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
	std::string	nick = client.getCmd(1);

	if (server.searchNickName(nick) == true)
		server.log.add(client, "nick name already taken");
	else
		client.setNickName(nick);
}

static void handleUser(Server& server, Client& client)
{
	if (client.getAllCmd().size() < 5 || client.getCmd(4)[0] != ':')
		server.log.add(client, "bad args");
	else
	{
		client.setUserName(client.getCmd(1));
		std::string tmp;
		for(int i = 4; i < client.getAllCmd().size(); i++)
		{
			tmp += client.getCmd(i);
			if (i + 1 < client.getAllCmd().size())
				tmp += " ";
		}
		client.setRealName(tmp);
	}
}

void Client::signIn(Server& server)
{
	if (_cmds[0] == "PASS")
		handlePass(server,*this);
	else if (_cmds[0] == "NICK")
		handleNick(server, *this);
	else if (_cmds[0] == "USER")
		handleUser(server, *this);
	else
		server.log	.add(*this, "wrong command");

	if (_isPassAccepted == true && !_nickName.empty()
		&& !_userName.empty() && !_realName.empty())
	{
		_isRegistered = true;
		server.log.add(server, "new user registered");
	}
}