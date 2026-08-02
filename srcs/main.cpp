#include "irc.hpp"

int main(int ac, char** av)
{
	Irc	irc;

	try
	{
		irc.server.init(irc, ac, av);
		irc.server.run(irc);
	}
	catch(const Exception& e)
	{
		std::cerr << e << '\n';
		return (1);
	}
	return (0);
}