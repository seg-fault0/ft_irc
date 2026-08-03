#include "irc.hpp"

void	Client::manager(Server& server)
{
	readBuffer(server);

	if (_buffer.empty())
		server.deleteClient(*this);
	else if (!_isRegistered)
		signIn(server);
	else
		server.log(RESPOND, *this, "responding ...\n");
}