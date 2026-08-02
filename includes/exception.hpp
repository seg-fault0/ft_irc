#pragma once

# include "irc.hpp"

/**************************************/
/************     MACROS    ***********/
/**************************************/

# define WARNING 1
# define ERROR 2

/**************************************/
/************     CLASS     ***********/
/**************************************/

class Exception
{
	private:
		int			_type;
		std::string	_msg;

	public:
	//orthodox
		Exception(int type, const std::string& msg);

	//geters
		int	getType(void) const ;
		std::string	getMsg(void) const ;
};

//overload cerr
std::ostream&	operator<<(std::ostream& os, const Exception& e);