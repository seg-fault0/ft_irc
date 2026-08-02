#include "irc.hpp"

bool	Manager::manage(int id)
{
	char 	buffer[1024];
	int		clien_fd = id;

	int bytes = recv(clien_fd, buffer, sizeof(buffer) - 1, 0);

	if (bytes <= 0)
	{
		std::cout << "client disconnected\n";
		return (false);
	}
	buffer[bytes] = '\0';
	std::cout << "client" << id << " : "<< buffer;
	return (true);
}