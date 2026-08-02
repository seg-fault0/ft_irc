#include "irc.hpp"

void Irc::manageClients(int i)
{
	int		client_fd = pfds[i].fd;
	char 	buffer[1024];

	int bytes = recv(client_fd, buffer, sizeof(buffer) - 1, 0);

	if (bytes <= 0)
	{
		std::cout << "client disconnected\n";
		pfds.erase(pfds.begin() + i);
		return ;
	}
	buffer[bytes] = '\0';
	std::cout << "client" << client_fd << " : "<< buffer;
}