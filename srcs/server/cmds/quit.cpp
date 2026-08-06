#include "irc.hpp"

void Server::handleQuitCmd(Client& client)
{
	std::string reason = "Client Quit";

	if (!client.request.getAllParams().empty())
		reason = client.request.getParam(0);

	for (size_t i = 0; i < client.getChannels().size(); ++i)
	{
		Channel *channel = getChannel(client.getChannels()[i]);
		if (!channel)
			continue;

		sendMsgToChannel("", channel->getName(), RSP_QUIT(client.getNickName(), client.getUserName(), reason));
	
		channel->clientKick(client);
	}

	deleteClientFromServer(client);
}