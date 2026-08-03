#pragma once

#include "irc.hpp"

class Server;
class Client;

class Log
{
	public:
		void add(const Server& server, const std::string& msg);
		void add(const Client& client, const std::string& msg);
};