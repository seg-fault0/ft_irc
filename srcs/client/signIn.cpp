#include "irc.hpp"

static void handlePass(Irc& irc, Client& client)
{
	std::string	buffer = client.getBuffer();
	int			fd = client.getFd();

	if (client.isPassAccepted() == true)
		return ;
	else if(buffer.compare(5, buffer.length() - 5, irc.server.getPassWord()) != 0)
		ft_send(fd, "wrong pass word\n");
	else
	{
		client.setPass(true);
		ft_send(fd, "pass word accepted\n");
	}
}

void Client::signIn(Irc& irc)
{
	if (_buffer.compare(0, 4, "PASS") == 0)
		handlePass(irc, *this);
	else
		ft_send(_fd, "wrong command\n");

	if (_isPassAccepted == true)
		_isRegistered = true;
}