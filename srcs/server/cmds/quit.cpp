#include "irc.hpp"

void	Server::handleQuitCmd(Client& client)
{
	deleteClient(client);
}