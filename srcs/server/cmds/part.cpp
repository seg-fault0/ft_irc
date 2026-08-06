#include "irc.hpp"

void	Server::handlePartCmd(Client& client)
{
	if (client.request.getAllParams().size() < 1)
		sendMsgToClient(client, RSP_NEEDMOREPARAMS(client.getNickName()));
	else if (!hasChannel(client.request.getParam(0)))
		sendMsgToClient(client, RSP_NOSUCHCHANNEL(client.getNickName(), client.request.getParam(0)));
	else if (!client.isChannelMember(client.request.getParam(0)))
		sendMsgToClient(client, RSP_NOTONCHANNEL(client.getNickName(), client.request.getParam(0)));
	else
	{
		if (client.request.getAllParams().size() >= 2)
			sendMsgToChannel(client.request.getParam(0), RSP_PART(client.getNickName(), client.getUserName(), client.request.getParam(0), client.request.getParam(1)));
		else
			sendMsgToChannel(client.request.getParam(0), RSP_PART(client.getNickName(), client.getUserName(), client.request.getParam(0), ""));

		client.channelDel(client.request.getParam(0));
		getChannel(client.request.getParam(0))->clientKick(client);
	}
}
