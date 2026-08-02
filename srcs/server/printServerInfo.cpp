#include "irc.hpp"

void	Server::printServerInfo(void) const
{
	std::cout << "*******  WELCOM TO IRC SERVER ***********\n";
	std::cout << "Port = " << _port << std::endl;
	std::cout << "Pass Word = " << _passWord << std::endl;
}
