#include "irc.hpp"

/************************************************/
/**************       METHODS   *****************/
/************************************************/

void		Request::clear(void)
{
	_cmd.clear();
	_params.clear();
}

void		Request::parse(const std::string& buffer) 
{
	clear();

	size_t i = 0;
	size_t len = buffer.length();

	// Skip leading spaces
	while (i < len && buffer[i] == ' ')
		i++;

	// Read command
	while (i < len && buffer[i] != ' ' && buffer[i] != '\r' && buffer[i] != '\n')
	{
		_cmd += buffer[i];
		i++;
	}

	// Read parameters
	while (i < len)
	{
		// Skip spaces
		while (i < len && buffer[i] == ' ')
			i++;

		if (i >= len || buffer[i] == '\r' || buffer[i] == '\n')
			break;

		// Trailing parameter (everything after ':')
		if (buffer[i] == ':')
		{
			_params.push_back(buffer.substr(i + 1));
			break;
		}

		// Normal parameter
		size_t start = i;

		while (i < len &&
			   buffer[i] != ' ' &&
			   buffer[i] != '\r' &&
			   buffer[i] != '\n')
			i++;

		_params.push_back(buffer.substr(start, i - start));
	}

	// Remove trailing CR/LF from the last parameter if present
	if (!_params.empty())
	{
		std::string &last = _params.back();
		while (!last.empty() &&
			  (last[last.size() - 1] == '\r' ||
			   last[last.size() - 1] == '\n'))
			last.erase(last.size() - 1);
	}
}

/************************************************/
/**************       GETERS   ******************/
/************************************************/

std::string					Request::getCmd(void) const { return (_cmd); }

std::string					Request::getParam(int i) const
{
	if (i < _params.size())
		return (_params[i]);
	return (std::string());
}

std::vector<std::string>	Request::getAllParams(void) const { return (_params); }
