#include "irc.hpp"

void	Server::handlePartCmd(Client& client)
{
	if (client.getAllCmd().size() <= 1)
		sendMsgToClient(client, RSP_NEEDMOREPARAMS(client.getNickName()));
	else if (!hasChannel(client.getCmd(1)))
		sendMsgToClient(client, RSP_NOSUCHCHANNEL(client.getNickName(), client.getCmd(1)));
	else if (!client.isChannelMember(client.getCmd(1)))
		sendMsgToClient(client, RSP_NOTONCHANNEL(client.getNickName(), client.getCmd(1)));
	else
	{
		if (client.getAllCmd().size() >= 3)
			sendMsgToChannel(client.getCmd(1), RSP_PART(client.getNickName(), client.getUserName(), client.getCmd(1), client.getCmd(2)));
		else
			sendMsgToChannel(client.getCmd(1), RSP_PART(client.getNickName(), client.getUserName(), client.getCmd(1), ""));
		client.channelDel(client.getCmd(1));
		getChannel(client.getCmd(1))->clientKick(client);
	}
}
