#include "irc.hpp"

void Irc::manageClients(int i)
{
	Client&	client = clients[pfds[i].fd];

	client.readBuffer();
	if (client.getBuffer().empty())
	{
		std::cout << "client " << i << "left\n";
		clients.erase(client.getFd());
		pfds.erase(pfds.begin() + 1);
	}
	else
		std::cout << "client " << i << ": " << client.getBuffer() << "\n";
}