#include "irc.hpp"

bool	Client::isChannelMember(const std::string& channel_name)
{
	for(size_t i = 0; i < _channels.size(); i++)
	{
		if (channel_name == _channels[i])
			return (true);
	}
	return (false);
}

void	Client::channelAdd(const std::string& channel_name)
{
	_channels.push_back(channel_name);
}

void	Client::channelDel(const std::string& channel_name)
{
	if (!isChannelMember(channel_name))
		return ;
	
	for(size_t i = 0; i < _channels.size(); i++)
	{
		if (_channels[i] == channel_name)
		{
			_channels.erase(_channels.begin() + i);
			break ;
		}
	}
}