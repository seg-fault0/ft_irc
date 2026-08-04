#include "irc.hpp"

void	Channel::setInviteOnly(bool state) { _inviteOnly = state; }

void	Channel::setTopicRestrict(bool state) { __topicRestricted = state; }

void	Channel::setUserLimit(int limit) { _userLimit = limit; }
