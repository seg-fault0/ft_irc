#include "irc.hpp"

void Irc::deleteClient(int index)
{
	Client& client = clients[pfds[index].fd];
		
	clients.erase(client.getFd());
	pfds.erase(pfds.begin() + 1);
	
	std::cout << "client " << index << "left\n";
}