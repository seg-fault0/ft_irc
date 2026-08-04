#include "irc.hpp"

void Server::handleUserCmd(Client& client)
{
	if (client.getAllCmd().size() < 5 || client.getCmd(4)[0] != ':')
		respond(client, "bad args");
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
		respond(client, "good user/real name");
	}
}