#pragma once

# include "irc.hpp"

//pass word
# define RSP_BADPASSWORD(nick)(":irc.server 464 " + (nick) + " :Incorrect password\r\n")

//nickname
# define RSP_NICKALREADYUSED(nick)(":irc.server 433 " + (nick) + " : NickName already used\r\n")
# define RSP_NICKNOTALLOWED(nick)(":irc.server 432 " + (nick) + " : NickName already used\r\n")

//cmd
# define RSP_UNKNOWNCMD(nick)(":irc.server 421 " + (nick) + ": Uknown command\r\n")

//params
# define ERR_NEEDMOREPARAMS(nick)(":irc.server 461 " + (nic) + ": Need more params\r\n")

//welcom
# define RSP_WELCOM(nick)("irc.server 001 " + (nick) + ": WELCOM\r\t")
# define RSP_HOST(nick)("irc.server 002 " + (nick) + ": HOST\r\t")
# define RSP_CREATED(nick)("irc.server 003 " + (nick) + ": CRETED\r\t")
# define RSP_INFO(nick)("irc.server 004 " + (nick) + ": INFO\r\t")