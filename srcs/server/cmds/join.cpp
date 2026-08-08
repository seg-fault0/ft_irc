#include "irc.hpp"

void	Server::handleJoinCmd(Client& client)
{
	if (client.request.getAllParams().size() == 0)
		return (sendMsgToClient(client, RSP_NEEDMOREPARAMS(client.getNickName())));

	std::string	channel_name = client.request.getParam(0);

	std::vector<std::string> channels = ft_split(channel_name, ',');
	std::vector<std::string> keys = ft_split(client.request.getParam(1), ',');

	for (size_t i = 0; i < channels.size(); i++)
	{
		const std::string& chan_name = channels[i];
		if (chan_name.empty() || (chan_name[0] != '#' && chan_name[0] != '&'))
			return (sendMsgToClient(client, RSP_NOSUCHCHANNEL(client.getNickName(), chan_name)));
		Channel *chan = getChannel(chan_name);
		if (chan != NULL)
		{
			if (chan->isClient(client))
				continue;
			if (chan->isChannelInviteOnly() && !chan->isClientInvited(client))
            {
                sendMsgToClient(client, RSP_INVITEONLYCHAN(client.getNickName(), chan_name));
                continue;
            }
			if(!chan->getPassWord().empty())
			{
				if (i < keys.size() && keys[i] != chan->getPassWord())
					return (sendMsgToClient(client, RSP_BADCHANNELKEY(client.getNickName(), chan_name)));
			}
			if (!chan->clientAdd(client))
				return (sendMsgToClient(client, RSP_CHANNELISFULL(client.getNickName(), chan_name)));
		}
		else
			_channels.push_back(Channel(chan_name, client));
		client.channelAdd(chan_name);
	}
	sendMsgToChannel("", channel_name, RSP_JOIN(client.getNickName(), client.getUserName(), channel_name));
	sendMsgToClient(client, RSP_NOTOPIC(client.getNickName(), channel_name));
	sendMsgToClient(client, RSP_NAMREPLY(client.getNickName(), channel_name, getChannel(channel_name)->getClientsStr()));
	sendMsgToClient(client,RSP_ENDOFNAMES(client.getNickName(), channel_name));
}