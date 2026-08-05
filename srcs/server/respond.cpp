#include "irc.hpp"

void Server::respond(const Client& client, const std::string& msg)
{
	send(client.getFd(), msg.c_str(), msg.length(), 0);
	log(RESPOND, client, msg);
}