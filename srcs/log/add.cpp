#include "irc.hpp"

void Log::add(const Server& server, const std::string& msg)
{
	std::cout << paintStr(color::red, "[SERVER]") << " : " << msg;

	if (!msg.empty() && msg[msg.size() - 1] != '\n')
		std::cout << "\n";
}

void Log::add(const Client& client, const std::string& msg)
{
	std::string	nick;

	if (client.getNickName().empty())
		nick = "unknown";
	else
		nick = client.getNickName().substr(0, client.getNickName().size() - 1);
	
	std::stringstream	ss;
	ss << "[CLIENT " << client.getFd() << " : "
		<< "" << nick << "]";

	std::cout << paintStr(color::green, ss.str()) << " : " << msg;

	if (!msg.empty() && msg[msg.size() - 1] != '\n')
		std::cout << "\n";
}