#pragma once

# include "irc.hpp"

//pass word
# define BADPASSWORD(nick)(":irc.server 464 " + (nick) + " :Incorrect password\r\n")

//nickname
# define NICKALREADYUSED(client, nick) (":irc.server 433 " + (client) + " " + (nick) + " :Nickname is already in use\r\n")
# define ERRONEUSNICKNAME(client, nick) (":irc.server 432 " + (client) + " " + (nick) + " :Erroneous nickname\r\n")
# define NICK_BROADCAST(old_nick, user, host, new_nick) (":" + (old_nick) + "!" + (user) + "@" + (host) + " NICK :" + (new_nick) + "\r\n")
# define NONICKNAMEGIVEN(client) (":irc.server 431 " + (client) + " :No nickname given\r\n")
# define ERRONEUSNICKNAME(client, nick) (":irc.server 432 " + (client) + " " + (nick) + " :Erroneous nickname\r\n")




//cmd
# define UNKNOWNCMD(nick)(":irc.server 421 " + (nick) + ": Uknown command\r\n")

//params
# define NEEDMOREPARAMS(nick)(":irc.server 461 " + (nick) + ": Need more params\r\n")

//welcom
#define WELCOME(nick, user)(":irc.server 001 " + (nick) + " :Welcome to the Internet Relay Network " + (nick) + "!" + (user) + "@localhost\r\n")
#define HOST(nick)(":irc.server 002 " + (nick) + " :Your host is irc.server, running version ft_irc-1.0\r\n")
#define CREATED(nick, date)(":irc.server 003 " + (nick) + " :This server was created " + date + "\r\n")
#define INFO(nick)(":irc.server 004 " + (nick) + " irc.server ft_irc-1.0 o o\r\n")

//join
#define JOIN(nick, user, channel)(":" + (nick) + "!" + (user) + "@localhost JOIN " + (channel) + "\r\n")
#define NOTOPIC(nick, channel)(":irc.server 331 " + (nick) + " " + (channel) + " :No topic is set\r\n")
#define TOPIC(nick, channel, topic)(":irc.server 332 " + (nick) + " " + (channel) + " :" + (topic) + "\r\n")
#define NAMREPLY(nick, channel, names)(":irc.server 353 " + (nick) + " = " + (channel) + " :" + (names) + "\r\n")
#define ENDOFNAMES(nick, channel)(":irc.server 366 " + (nick) + " " + (channel) + " :End of /NAMES list\r\n")

//quit
#define QUIT(nick, user, reason)(":" + (nick) + "!" + (user) + "@localhost QUIT :" + (reason) + "\r\n")

//part
#define NOSUCHCHANNEL(nick, channel)(":irc.server 403 " + nick + " " + channel + " :No such channel\r\n")
#define NOTONCHANNEL(nick, channel)(":irc.server 442 " + nick + " " + channel + " :You're not on that channel\r\n")
#define PART(nick, user, channel, msg)(":" + nick + "!" + user + "@localhost PART " + channel + " :" + msg + "\r\n")
#define INVITEONLYCHAN(nick, channel) (":irc.server 473 " + nick + " " + channel + " :Cannot join channel (+i)\r\n")
#define BADCHANNELKEY(nick, channel) (":irc.server 475 " + nick + " " + channel + " :Cannot join channel (+k)\r\n")
#define CHANNELISFULL(nick, channel) (":irc.server 471 " + nick + " " + channel + " :Cannot join channel (+l)\r\n")

// invite 
#define INVITING(nick, user, channel)(":irc.server 341 " + std::string(user) + " " + std::string(nick) + std::string(channel)+ "\r\n")
#define NOSUCHNICK(user, nick) (":irc.server 401 " + std::string(user) + " " + std::string(nick) + " :No such nickname\r\n")

//privmsg
#define ERR_NORECIPIENT (":irc.server 411 * :No recipient given (PRIVMSG)\r\n")
#define ERR_NOTEXTTOSEND ":irc.server 412 * :No text to send\r\n"
#define ERR_NOSUCHNICK(nick, target) (":irc.server 401 " + nick + " " + target + " :No such nick/channel\r\n")
#define ERR_NOSUCHCHANNEL(nick, channel) (":irc.server 403 " + nick + " " + channel + " :No such channel\r\n")
#define ERR_CANNOTSENDTOCHAN(nick, channel) (":irc.server 404 " + nick + " " + channel + " :Cannot send to channel\r\n")
#define PRIVMSG(nick, user, target, msg)(":" + nick + "!" + user + "@localhost PRIVMSG " + target + " :" + msg + "\r\n")