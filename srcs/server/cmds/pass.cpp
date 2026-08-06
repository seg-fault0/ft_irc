#include "irc.hpp"

void Server::handlePassCmd(Client& client)
{
	std::string	pass = client.request.getParam(0);
	int			fd = client.getFd();

	if (client.isPassAccepted() == true)
		return ;
	else if(pass != _passWord)
		sendMsgToClient(client, RSP_BADPASSWORD(client.getNickName()));
	else
		client.setPass(true);
}
