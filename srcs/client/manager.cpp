#include "irc.hpp"

void	Client::manager(Server& server)
{
	readBuffer();

	if (_buffer.empty())
		server.deleteClient(*this);
	else if (!_isRegistered)
		signIn(server);
	else
		server.log.add(*this, _buffer[0]);
}