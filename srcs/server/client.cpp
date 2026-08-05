#include "irc.hpp"

/**********************************************/
/********       CREATE && DELETE      *********/
/**********************************************/

void Server::createNewClient(void)
{
	int	client_fd = accept(_fd, NULL, NULL);
	if (client_fd < 0)
		throw (Exception(WARNING, "client : failed to accecpt client"));

		
	_clients.push_back(Client());
	_clients[_clients.size() - 1].setFd(client_fd); // i added this line cuz the line before calls the destructore wich will close the fd
	_pfds.push_back(createPFD(client_fd));
	
	log(RESPOND, _clients[_clients.size() - 1], "new client connected");
}

void Server::deleteClient(Client& client)
{
	for(size_t i = 1; i < _clients.size(); i++)
	{
		if (_clients[i].getFd() == client.getFd())
		{
			_clients[i].closeFd();
			_clients.erase(_clients.begin() + i);
			_pfds.erase(_pfds.begin() + i);
			return ;
		}
	}
}

/**********************************************/
/**************      SEND MSG     *************/
/**********************************************/

void Server::sendMsgToClient(const Client& client, const std::string& msg)
{
	send(client.getFd(), msg.c_str(), msg.length(), 0);
	log(RESPOND, client, msg);
}

/**********************************************/
/**************       SEARCH      *************/
/**********************************************/

bool Server::searchNickName(const std::string& nickName)
{
	for(size_t i = 1; i < _clients.size(); i++)
	{
		if (_clients[i].getNickName() == nickName)
			return (true);
	}
	return (false);
}

/**********************************************/
/**************       MANAGER     *************/
/**********************************************/

void	Server::manageClient(Client& client)
{
	client.readBuffer(*this);
	log(REQUEST, client, client.getBuffer());

	if (client.getBuffer().empty())
		deleteClient(client);
	else if (!client.isRegistered())
		signIn(client);
	else
		cmdManager(client);
}

/**********************************************/
/**************       GETERS      *************/
/**********************************************/

std::string	Server::getClientNickNameFromFd(file fd)
{
	for (size_t i = 0; i < _clients.size(); i++)
	{
		if (fd = _clients[i].getFd())
			return (_clients[i].getNickName());
	}
	return (std::string());
}

Client*		Server::getClientByNickName(const std::string& nick_name)
{
	for (size_t i = 0; i < _clients.size(); i++)
	{
		if (nick_name == _clients[i].getNickName())
			return (&_clients[i]);
	}
	return (NULL);
}