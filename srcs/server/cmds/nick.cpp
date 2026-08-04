#include "irc.hpp"

void	Server::handleNickCmd(Client& client)
{
	std::string	nick = client.getCmd(1);

	if (searchNickName(nick) == true)
		log(RESPOND, client, "nick name already taken");
	else
	{
		log(RESPOND, client, "good nick name");
		client.setNickName(nick);
	}
}

