#include "irc.hpp"

void Server::handlePrivmsgCmd(Client& client)
{
	if (client.request.getAllParams().size() == 0)
		return (sendMsgToClient(client, ERR_NORECIPIENT));

	if (client.request.getAllParams().size() == 1)
		return (sendMsgToClient(client, ERR_NOTEXTTOSEND));

	std::string target = client.request.getParam(0);
	std::string message = client.request.getParam(1);

	if (target[0] == '#')
	{
		if (!hasChannel(target))
			return (sendMsgToClient(client, ERR_NOSUCHCHANNEL(client.getNickName(), target)));

		if (!client.isChannelMember(target))
			return (sendMsgToClient(client, ERR_CANNOTSENDTOCHAN(client.getNickName(), target)));

		sendMsgToChannel(client.getNickName(), target, PRIVMSG(client.getNickName(), client.getUserName(), target, message));
	}
	else
	{
		Client *receiver = getClientByNickName(target);
		if (!receiver)
			return (sendMsgToClient(client, ERR_NOSUCHNICK(client.getNickName(), target)));
		sendMsgToClient(*receiver, PRIVMSG(client.getNickName(), client.getUserName(), target, message));
	}
}