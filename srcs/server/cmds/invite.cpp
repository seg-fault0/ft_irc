#include "irc.hpp"

void	Server::handleInviteCmd(Client& client)
{
	if (client.request.getAllParams().size() < 2)
	{
		sendMsgToClient(client, NEEDMOREPARAMS(client.getNickName()));
		return ;
	}
	std::string nick_name = client.request.getParam(0);
	std::string channel_name = client.request.getParam(1);
	
	if (!hasChannel(channel_name))
	{
		sendMsgToClient(client, NOSUCHCHANNEL(client.getNickName(), channel_name));
		return ;
	}
	Channel* channel = getChannel(channel_name);
	if (!channel->isClient(client))
	{
		sendMsgToClient(client, NOTONCHANNEL(client.getNickName(), channel_name));
		return ;
	}
	if (!searchForClient(nick_name))
	{
		sendMsgToClient(client, NOSUCHNICK(client.getNickName(),nick_name));
		return ;
	}
	channel->addToInvitedClient(nick_name);
	std::string msg = ":" + client.getNickName() + " INVITE " + nick_name + " :" + channel_name;
	Client *target = getClientByNickName(nick_name);
	sendMsgToClient(*target, msg);
	sendMsgToClient(client, INVITING(nick_name, client.getNickName(), channel_name));
}
