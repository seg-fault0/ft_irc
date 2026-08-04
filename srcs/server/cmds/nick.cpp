#include "irc.hpp"

void	Server::handleNickCmd(Client& client)
{
	std::string	nick = client.getCmd(1);

	if (searchNickName(nick) == true)
		respond(client, "nick name already taken");
	else
	{
		respond(client, "good nick name");
		client.setNickName(nick);
	}
}
