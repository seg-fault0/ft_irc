#include "irc.hpp"

bool	Channel::isClient(const Client& client) const
{
	std::string client_nick = client.getNickName();

	for (size_t i = 0; i < _clients.size(); i++)
	{
		if (_clients[i] == client_nick)
			return (true);
	}
	return (false);
}

bool	Channel::isClientInvited(const Client& client) const
{
	std::string client_nick = client.getNickName();

	for (size_t i = 0; i < _clients.size(); i++)
	{
		if (_invitedClients[i] == client_nick)
			return (true);
	}
	return (false);
}

void	Channel::addToInvitedClient(std::string& user_nick)
{
	for (size_t i = 0; i < _invitedClients.size(); i++)
	{
		if (_invitedClients[i] == user_nick)
			return ;
	}
	_invitedClients.push_back(user_nick);
}

bool	Channel::clientAdd(const Client& client)
{
	std::string client_nick = client.getNickName();

	if (_userLimit >= _clients.size())
		return (false);

	_clients.push_back(client_nick);
	return (true);
}

void	Channel::clientKick(const Client& client)
{
	if (!isClient(client))
		return ;
	
	std::string client_nick = client.getNickName();

	for(size_t i = 0; i < _clients.size(); i++)
	{
		if (_clients[i] == client_nick)
			_clients.erase(_clients.begin() + i);
	}

	for(size_t i = 0; i < _admins.size(); i++)
	{
		if (_admins[i] == client_nick)
			_admins.erase(_admins.begin() + i);
	}
}

bool	Channel::isChannelInviteOnly(void)
{
	if (!_inviteOnly)
		return (false);
	return (true);
}