#pragma once

#include "irc.hpp"

class  Request
{
	private:
		std::string					_cmd;
		std::vector<std::string>	_params;

	public:
		void		clear(void);
		void		parse(const std::string& buffer);
		
		std::string					getCmd(void) const;
		std::string					getParam(int) const;
		std::vector<std::string>	getAllParams(void) const ;
};