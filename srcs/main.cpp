#include "irc.hpp"

int main(int ac, char** av)
{
	Server	server;

	try
	{
		server.init(ac, av);
		server.lunch();
	}
	catch(const Exception& e)
	{
		std::cerr << e << '\n';
		return (1);
	}
	return (0);
}