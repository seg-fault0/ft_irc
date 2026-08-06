#include "irc.hpp"

void	Server::cmdManager(Client& client)
{
	const std::string& cmd = client.getCmd(0);

	if (cmd == "QUIT")
		handleQuitCmd(client);
	else if (cmd == "JOIN")
		handleJoinCmd(client);
	else if (cmd == "PART")
		handlePartCmd(client);
	else
		sendMsgToClient(client, RSP_UNKNOWNCMD(client.getNickName()));
}