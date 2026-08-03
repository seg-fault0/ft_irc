#include "client.hpp"

void	Client::readBuffer(void)
{
	_buffer.clear();
	
	char 	buffer[1024];
	int bytes = recv(_fd, buffer, sizeof(buffer) - 1, 0);

	if (bytes <= 0)
		return ;

	buffer[bytes] = '\0';
	
	_buffer = ft_split(buffer, ' ');
}
