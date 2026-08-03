#include "irc.hpp"

static void handlePass(Server& server, Client& client)
{
	std::string	pass = client.getCmd(1);
	int			fd = client.getFd();

	if (client.isPassAccepted() == true)
		return ;
	else if(pass != server.getPassWord())
		server.log(RESPOND, client, "bad pass word");
	else
	{
		client.setPass(true);
		server.log(RESPOND, client, "good pass word");
	}
}

static void	handleNick(Server& server, Client& client)
{
	std::string	nick = client.getCmd(1);

	if (server.searchNickName(nick) == true)
		server.log(RESPOND, client, "nick name already taken");
	else
	{
		server.log(RESPOND, client, "good nick name");
		client.setNickName(nick);
	}
}

static void handleUser(Server& server, Client& client)
{
	if (client.getAllCmd().size() < 5 || client.getCmd(4)[0] != ':')
		server.log(RESPOND, client, "bad args");
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
		server.log(RESPOND, client, "good user/real name");
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
		server.log(RESPOND, *this, "wrong command");

	if (_isPassAccepted == true && !_nickName.empty()
		&& !_userName.empty() && !_realName.empty())
	{
		_isRegistered = true;
		server.log(RESPOND, *this, "new user registered");
	}
}