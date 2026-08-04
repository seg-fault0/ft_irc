#pragma once

# include "irc.hpp"

#define RSP_BADPASSWORD(nick)(":irc.server 464 " + (nick) + " :Incorrect password\r\n")