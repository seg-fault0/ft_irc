#include "irc.hpp"

void	Server::handleNickCmd(Client& client)
{
	std::string	nick = client.getCmd(1);

	if (searchNickName(nick) == true)
		respond(client, RSP_NICKALREADYUSED(client.getNickName()));
	else if (nick == "*")
		respond(client, RSP_NICKNOTALLOWED(client.getNickName()));
	else
		client.setNickName(nick);
}
