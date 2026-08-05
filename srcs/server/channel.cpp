#include "irc.hpp"

/**********************************************/
/********       CREATE && DELETE      *********/
/**********************************************/

void	Server::createChannel(const Client& client, const std::string& channel_name)
{
	_channels.push_back(Channel(channel_name, client));
}

/**********************************************/
/**************       GETERS      *************/
/**********************************************/

bool	Server::hasChannel(const std::string& channel_name)
{
	for (size_t i = 0; i < _channels.size(); i++)
	{
		if (channel_name == _channels[i].getName())
			return (true);
	}
	return (false);
}

Channel*	Server::getChannel(const std::string& channel_name)
{
	for (size_t i = 0; i < _channels.size(); i++)
	{
		if (channel_name == _channels[i].getName())
			return (&_channels[i]);
	}
	return (NULL);	
}


/********************************************************/
/*******    (ADD && REMOVE) CLIENT FROM CHANNEL   *******/
/********************************************************/


void	Server::addClientToChannel(Client& client, const std::string& channel_name)
{
	Channel* channel = getChannel(channel_name);

	if (!channel)
		throw (WARNING, "channel not found");

	channel->clientAdd(client);
	client.channelAdd(channel_name);
}

/********************************************************/
/*******      SEND MSG TO ALL CHANNEL CLIENTS     *******/
/********************************************************/

void		Server::sendMsgToChannel(const std::string& channel_name, const std::string& msg)
{
	Channel* channel = getChannel(channel_name);

	if (!channel)
		throw (WARNING, "channel nout found");
	
	std::vector<std::string>	clientsNickNames = channel->getClients();

	for (size_t i = 0; i < clientsNickNames.size(); i++)
	{
		Client* client = getClientByNickName(clientsNickNames[i]);
		if (client)
			sendMsgToClient(*client, msg);
	}
}

