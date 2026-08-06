#include "client.hpp"

void	Client::readBuffer(Server& server)
{
	_buffer.clear();
	
	char 	buffer[1024];
	int bytes = recv(_fd, buffer, sizeof(buffer) - 1, 0);

	if (bytes <= 0)
		return ;

	buffer[bytes] = '\0';
	
	_buffer = buffer;

	while (!_buffer.empty()
			&& (_buffer[_buffer.size() - 1] == '\r' 
				|| _buffer[_buffer.size() - 1] == '\n'))
	{
		_buffer.erase(_buffer.size() - 1);
	}
	
	request.parse(_buffer);
}
