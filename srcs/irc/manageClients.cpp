#include "irc.hpp"

void Irc::manageClients(int i)
{
	Client&	client = clients[pfds[i].fd];

	client.readBuffer();

	if (client.getBuffer().empty())
		deleteClient(i);
	else
		std::cout << "client " << i << ": " << client.getBuffer();
}