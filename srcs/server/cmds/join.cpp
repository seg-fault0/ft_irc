#include "irc.hpp"

void	Server::handleJoinCmd(Client& client)
{
	std::string	channel_name = client.getCmd(1);

	if (!hasChannel(channel_name))
		createChannel(client, client.getCmd(1));
	else
		addClientToChannel(client, channel_name);
	client.channelAdd(channel_name);

	std::string names = getChannel(channel_name)->getClientsStr();

	sendMsgToChannel(channel_name, RSP_JOIN(client.getNickName(), client.getUserName(), channel_name));
	sendMsgToClient(client, RSP_NOTOPIC(client.getNickName(), channel_name));
	sendMsgToClient(client, RSP_NAMREPLY(client.getNickName(), channel_name, names));
	sendMsgToClient(client, RSP_ENDOFNAMES(client.getNickName(), channel_name));
}