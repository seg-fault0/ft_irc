#include "irc.hpp"

void	Server::handleJoinCmd(Client& client)
{
	std::string	channel_name = client.getCmd(1);

	if (!hasChannel(channel_name))
		createChannel(client, channel_name);
	else
		addClientToChannel(client, channel_name);

	sendMsgToChannel(channel_name, RSP_JOIN(client.getNickName(), client.getUserName(), channel_name));
	sendMsgToClient(client, RSP_NOTOPIC(client.getNickName(), channel_name));
	sendMsgToClient(client, RSP_NAMREPLY(client.getNickName(), channel_name, getChannel(channel_name)->getClientsStr()));
	sendMsgToClient(client, RSP_ENDOFNAMES(client.getNickName(), channel_name));
}