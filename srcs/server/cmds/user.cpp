#include "irc.hpp"

void	Server::handleUserCmd(Client& client)
{
	if (client.request.getAllParams().size() < 4)
		sendMsgToClient(client, NEEDMOREPARAMS(client.getNickName()));
	else
	{
		client.setUserName(client.request.getParam(0));
		client.setRealName(client.request.getParam(3));
	}
}