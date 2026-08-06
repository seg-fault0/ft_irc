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
# define RSP_NEEDMOREPARAMS(nick)(":irc.server 461 " + (nick) + ": Need more params\r\n")

//welcom
#define RSP_WELCOME(nick, user)(":irc.server 001 " + (nick) + " :Welcome to the Internet Relay Network " + (nick) + "!" + (user) + "@localhost\r\n")
#define RSP_HOST(nick)(":irc.server 002 " + (nick) + " :Your host is irc.server, running version ft_irc-1.0\r\n")
#define RSP_CREATED(nick, date)(":irc.server 003 " + (nick) + " :This server was created " + date + "\r\n")
#define RSP_INFO(nick)(":irc.server 004 " + (nick) + " irc.server ft_irc-1.0 o o\r\n")

//join
#define RSP_JOIN(nick, user, channel)(":" + (nick) + "!" + (user) + "@localhost JOIN " + (channel) + "\r\n")
#define RSP_NOTOPIC(nick, channel)(":irc.server 331 " + (nick) + " " + (channel) + " :No topic is set\r\n")
#define RSP_TOPIC(nick, channel, topic)(":irc.server 332 " + (nick) + " " + (channel) + " :" + (topic) + "\r\n")
#define RSP_NAMREPLY(nick, channel, names)(":irc.server 353 " + (nick) + " = " + (channel) + " :" + (names) + "\r\n")
#define RSP_ENDOFNAMES(nick, channel)(":irc.server 366 " + (nick) + " " + (channel) + " :End of /NAMES list\r\n")

//quit
#define RSP_QUIT(nick, user, reason)(":" + (nick) + "!" + (user) + "@localhost QUIT :" + (reason) + "\r\n")

//part
#define RSP_NOSUCHCHANNEL(nick, channel)(":irc.server 403 " + nick + " " + channel + " :No such channel\r\n")
#define RSP_NOTONCHANNEL(nick, channel)(":irc.server 442 " + nick + " " + channel + " :You're not on that channel\r\n")
#define RSP_PART(nick, user, channel, msg)(":" + nick + "!" + user + "@localhost PART " + channel + " :" + msg + "\r\n")