#include "irc.hpp"

void Server::handlePassCmd(Client& client)
{
	std::string	pass = client.getCmd(1);
	int			fd = client.getFd();

	if (client.isPassAccepted() == true)
		return ;
	else if(pass != _passWord)
		respond(client, RSP_BADPASSWORD(client.getNickName()));
	else
		client.setPass(true);
}
