#include "irc.hpp"

void	Server::log(int type, const Client& client, const std::string& msg)
{
	std::stringstream str;

	if (type == REQUEST)
		str << "[REQUEST]";
	else if (type == RESPOND)
		str << "[RESPOND]";

	if (client.getNickName() == "*")
		str << "[id= " << client.getFd() << "]";
	else
		str << "[" << client.getNickName() << "]";

	if (type == REQUEST)
		std::cout << paintStr(color::cyan, str.str()) << " : ";
	else if (type == RESPOND)
		std::cout << paintStr(color::green, str.str()) << " : ";
		

	std::cout << msg;
	if(msg[msg.length() - 1] != '\n')
		std::cout << "\n";
}