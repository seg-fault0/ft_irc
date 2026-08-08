#include "irc.hpp"

void	Server::cmdManager(Client& client)
{
	if (client.request.getCmd() == "QUIT")
		handleQuitCmd(client);
	else if (client.request.getCmd() == "JOIN")
		handleJoinCmd(client);
	else if (client.request.getCmd() == "PART")
		handlePartCmd(client);
	else if (client.request.getCmd() == "PRIVMSG")
		handlePrivmsgCmd(client);
	else if (client.request.getCmd() == "INVITE")
		handleInviteCmd(client);
	else if (client.request.getCmd() == "NICK")
		handleNickCmd(client);
	else
		sendMsgToClient(client, UNKNOWNCMD(client.getNickName()));
}