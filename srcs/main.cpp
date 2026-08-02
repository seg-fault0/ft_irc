#include "irc.hpp"

int main(int ac, char** av)
{
	(void) ac;
	(void) av;

	try
	{
		throw(Exception(WARNING, "Test exception"));
	}
	catch(const Exception& e)
	{
		std::cerr << e << '\n';
		return (1);
	}
	return (0);
}