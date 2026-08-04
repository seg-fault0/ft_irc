#include "irc.hpp"

void Server::handlePassCmd(Client& client)
{
	std::string	pass = client.getCmd(1);
	int			fd = client.getFd();

	if (client.isPassAccepted() == true)
		return ;
	else if(pass != _passWord)
		log(RESPOND, client, "bad pass word");
	else
	{
		client.setPass(true);
		log(RESPOND, client, "good pass word");
	}
}
