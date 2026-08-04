#include "irc.hpp"

void	Server::manageClient(Client& client)
{
	client.readBuffer(*this);
	log(REQUEST, client, client.getBuffer());

	if (client.getBuffer().empty())
		deleteClient(client);
	else if (!client.isRegistered())
		signIn(client);
	else
		cmdManager(client);
}