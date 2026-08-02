# include "irc.hpp"

Client::Client() : _fd(-1) {}

Client::~Client() 
{
	if (_fd >= 0)
		close(_fd);
}
