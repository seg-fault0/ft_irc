#include "irc.hpp"

bool	Channel::isAdmin(const Client& client) const
{
	if (!isClient(client))
		return (false);
	
	std::string	client_nickName = client.getNickName();

	for (size_t i = 0; i < _admins.size(); i++)
	{
		if (_admins[i] == client_nickName)
			return (true);
	}
	return (false);
}

void	Channel::adminAdd(const Client& client)
{
	if (isAdmin(client))
		return ;
	
	std::string	client_nickName = client.getNickName();
	_admins.push_back(client_nickName);
}
