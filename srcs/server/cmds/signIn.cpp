#include "irc.hpp"

void Server::signIn(Client& client)
{
	if (client.request.getCmd() == "PASS")
		handlePassCmd(client);
	else if (client.request.getCmd() == "NICK")
		handleNickCmd(client);
	else if (client.request.getCmd() == "USER")
		handleUserCmd(client);
	else if (client.request.getCmd() == "CAP");
	else
		sendMsgToClient(client, UNKNOWNCMD(client.getNickName()));

	if (client.isPassAccepted() 
		&& !client.getNickName().empty() && client.getNickName() != "*"
		&& !client.getUserName().empty() 
		&& !client.getUserName().empty())
	{
		client.setRegistered(true);
		sendMsgToClient(client, WELCOME(client.getNickName(), client.getUserName()));
		sendMsgToClient(client, HOST(client.getNickName()));
		sendMsgToClient(client, CREATED(client.getNickName(), _date));
		sendMsgToClient(client, INFO(client.getNickName()));
	}
}