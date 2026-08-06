#include "irc.hpp"

void	Server::handleJoinCmd(Client& client)
{
	if (client.request.getAllParams().size() == 0)
		return (sendMsgToClient(client, RSP_NEEDMOREPARAMS(client.getNickName())));

	std::string	channel_name = client.request.getParam(0);

	if (!hasChannel(channel_name))
		_channels.push_back(Channel(channel_name, client));

	client.channelAdd(channel_name);

	sendMsgToChannel("", channel_name, RSP_JOIN(client.getNickName(), client.getUserName(), channel_name));
	sendMsgToClient(client, RSP_NOTOPIC(client.getNickName(), channel_name));
	sendMsgToClient(client, RSP_NAMREPLY(client.getNickName(), channel_name, getChannel(channel_name)->getClientsStr()));
	sendMsgToClient(client,RSP_ENDOFNAMES(client.getNickName(), channel_name));
}