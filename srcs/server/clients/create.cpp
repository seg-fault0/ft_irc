#include "irc.hpp"

void Server::createNewClient(void)
{
	int	client_fd = accept(_fd, NULL, NULL);
	if (client_fd < 0)
		throw (Exception(WARNING, "client : failed to accecpt client"));

		
	_clients.push_back(Client());
	_clients[_clients.size() - 1].setFd(client_fd); // i added this line cuz the line before calls the destructore wich will close the fd
	_pfds.push_back(createPFD(client_fd));
	

	log(RESPOND, _clients[_clients.size() - 1], "new client connected");
}