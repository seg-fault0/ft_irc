#include "irc.hpp"

void	Server::cmdManager(Client& client)
{
	const std::string& cmd = client.getCmd(0);

	if (cmd == "QUIT")
		handleQuitCmd(client);
	else
		respond(client, RSP_UNKNOWNCMD(client.getNickName()));
}