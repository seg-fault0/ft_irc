#include "irc.hpp"

/**************************************/
/************    ORTHODOX   ***********/
/**************************************/

Exception::Exception(int type, const std::string& msg) : _type(type), _msg(msg) {}

/**************************************/
/************     GETERS    ***********/
/**************************************/

int			Exception::getType(void) const { return (_type); }

std::string	Exception::getMsg(void) const { return (_msg); }

/**************************************/
/********     overload cerr    ********/
/**************************************/

std::ostream&	operator<<(std::ostream& os, const Exception& e)
{
	if (e.getType() == WARNING)
		os << "Warning : " << e.getMsg();
	else
		os << "ERROR : " << e.getMsg();
	return (os);
}