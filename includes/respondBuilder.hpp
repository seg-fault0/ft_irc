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
#define RSP_WELCOME(nick, user)(":irc.server 001 " + (nick) + " :Welcome to the Internet Relay Network " + (nick) + "!" + (user) + "@localhost\r\n")
#define RSP_HOST(nick)(":irc.server 002 " + (nick) + " :Your host is irc.server, running version ft_irc-1.0\r\n")
#define RSP_CREATED(nick, date)(":irc.server 003 " + (nick) + " :This server was created " + date + "\r\n")
#define RSP_INFO(nick)(":irc.server 004 " + (nick) + " irc.server ft_irc-1.0 o o\r\n")