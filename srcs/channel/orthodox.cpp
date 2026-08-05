#include "irc.hpp"

Channel::Channel(const std::string& name, const Client& client)
{
	_name = name;
	_clients.push_back(client.getNickName());
	_admins.push_back(client.getNickName());
	_userLimit = -1;
	_inviteOnly = false;
	__topicRestricted = false;
}

Channel::~Channel() {}