#include "irc.hpp"

void	Server::handleNickCmd(Client& client)
{
	std::string	nick = client.request.getParam(0);

	if (searchNickName(nick) == true) sendMsgToClient(client, RSP_NICKALREADYUSED(client.getNickName()));
	else if (nick == "*")
		sendMsgToClient(client, RSP_NICKNOTALLOWED(client.getNickName()));
	else
		client.setNickName(nick);
}
