#include "irc.hpp"

void Server::deleteClient(Client& client)
{
	for(size_t i = 1; i < _clients.size(); i++)
	{
		if (_clients[i].getFd() == client.getFd())
		{
			_clients.erase(_clients.begin() + i);
			_pfds.erase(_pfds.begin() + i);
			std::cout << "client " << _clients[i].getFd() << "left\n";
			return ;
		}
	}
}