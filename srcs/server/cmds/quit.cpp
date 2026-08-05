#include "irc.hpp"

void	Server::handleQuitCmd(Client& client)
{
	if (client.getAllCmd().size() <= 1)
		return (sendMsgToClient(client, RSP_NEEDMOREPARAMS(client.getNickName())));
	
	for(size_t i = 0; i < client.getChannels().size(); i++)
	{
		Channel* channel = getChannel(client.getChannels()[i]);
		if (channel)
		{
			channel->clientKick(client);
			sendMsgToChannel(channel->getName(),
							RSP_QUIT(client.getNickName(), client.getUserName(), client.getCmd(1)));
		}
	}
	deleteClientFromServer(client);
}