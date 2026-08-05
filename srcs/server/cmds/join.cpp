#include "irc.hpp"

void	Server::handleJoinCmd(Client& client)
{
	std::string	channel_name = client.getCmd(1);

	if (!hasChannel(channel_name))
		createChannel(client, client.getCmd(1));
	else
		addClientToChannel(client, channel_name);
	client.channelAdd(channel_name);

	std::vector<file> clients_in_channel = getChannel(channel_name)->getClients();
	std::string names;
	for (size_t i = 0; i < clients_in_channel.size(); i++)
		names += getClientNickNameFromFd(clients_in_channel[i]) += " ";

	sendMsgToChannel(channel_name, RSP_JOIN(client.getNickName(), client.getUserName(), channel_name));
	respond(client, RSP_NOTOPIC(client.getNickName(), channel_name));
	respond(client, RSP_NAMREPLY(client.getNickName(), channel_name, names));
	respond(client, RSP_ENDOFNAMES(client.getNickName(), channel_name));
}