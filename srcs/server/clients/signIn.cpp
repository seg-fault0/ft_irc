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
	else
		log(RESPOND, client, "bad command");

	if (client.isPassAccepted() 
		&& !client.getNickName().empty()
		&& !client.getUserName().empty() 
		&& !client.getUserName().empty())
	{
		client.setRegistered(true);
		log(RESPOND, client, "new user registered");
	}
}