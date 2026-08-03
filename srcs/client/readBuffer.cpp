#include "client.hpp"

void	Client::readBuffer(Server& server)
{
	_buffer.clear();
	_cmds.clear();
	
	char 	buffer[1024];
	int bytes = recv(_fd, buffer, sizeof(buffer) - 1, 0);

	if (bytes <= 0)
		return ;

	buffer[bytes] = '\0';
	
	_buffer = buffer;
	_cmds = ft_split(_buffer, ' ');

	server.log(REQUEST, *this, _buffer);
}
