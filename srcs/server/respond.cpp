#include "irc.hpp"

void Server::respond(Client& client, const std::string& msg)
{
	log(RESPOND, client, msg);
}