#include "irc.hpp"

bool	isValidNickName(const std::string& nickname)
{
	if (nickname.empty())
		return (false);
	char	first = nickname[0];
	if (first == '#' || first == ':' || first == '$' || std::isdigit(static_cast<unsigned char>(first)))
		return (false);
	for (size_t i = 0; i < nickname.length(); ++i)
	{
        char c = nickname[i];
		if (c == ' ' || c == ',' || c == '*' || c == '?' || c == '!' || c == '@' || c == '.')
			return (false);
		if (std::iscntrl(static_cast<unsigned char>(c)))
			return (false);
	}
	return (true);
}

void	Server::handleNickCmd(Client& client)
{
	if (client.request.getAllParams().empty())
	{
		sendMsgToClient(client, NONICKNAMEGIVEN(client.getNickName()));
		return ;
	}
	std::string	nick = client.request.getParam(0);
	if (!isValidNickName(nick))
	{
		sendMsgToClient(client, ERRONEUSNICKNAME(client.getNickName(), nick));
		return;
	}
	if (nick.size() > 30)
		nick = nick.substr(0, 30);
	if (searchNickName(nick) == true) 
	{
		sendMsgToClient(client, NICKALREADYUSED(client.getNickName(), nick));
		return ;
	}
	if (client.getNickName() == nick)
		return ;
	if (client.getNickName() == "*")
		client.setNickName(nick);
	else
	{
		std::string oldNick = client.getNickName();
		client.setNickName(nick);
		sendMsgToClient(client, NICK_BROADCAST(oldNick, client.getUserName(), "localhost", nick));
		for (size_t i = 0 ; i < client.getChannels().size(); i++)
		{
			Channel *channel = getChannel(client.getChannels()[i]);
			sendMsgToChannel(oldNick, channel->getName(), NICK_BROADCAST(oldNick, client.getUserName(), "localhost", nick));
		}
	}
}
