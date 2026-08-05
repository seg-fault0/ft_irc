#include "irc.hpp"

void Server::signIn(Client& client)
{
	std::string cmd = client.getCmd(0);

	if (cmd == "PASS")
		handlePassCmd(client);
	else if (cmd == "NICK")
		handleNickCmd(client);
	else if (cmd == "USER")
		handleUserCmd(client);
	else if (cmd == "CAP");
	else
		sendMsgToClient(client, RSP_UNKNOWNCMD(client.getNickName()));

	if (client.isPassAccepted() 
		&& !client.getNickName().empty()
		&& !client.getUserName().empty() 
		&& !client.getUserName().empty())
	{
		client.setRegistered(true);
		sendMsgToClient(client, RSP_WELCOME(client.getNickName(), client.getUserName()));
		sendMsgToClient(client, RSP_HOST(client.getNickName()));
		sendMsgToClient(client, RSP_CREATED(client.getNickName(), _date));
		sendMsgToClient(client, RSP_INFO(client.getNickName()));
	}
}