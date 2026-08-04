#include "irc.hpp"

Channel::Channel(const std::string& name, file client)
{
	_name = name;
	_clients.push_back(client);
	_userLimit = -1;
	_inviteOnly = false;
	__topicRestricted = false;
}

Channel::~Channel() {}