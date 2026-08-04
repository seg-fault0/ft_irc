#pragma once

# include "irc.hpp"

class Channel
{
	private:
		std::string			_name;
		std::string			_topic;
		std::string			_passWord;
		int					_userLimit;
		std::vector<file>	_clients;
		std::vector<file>	_admins;
		std::vector<file>	_invitedClients;
		bool				_inviteOnly;
		bool				__topicRestricted;

	public:
		Channel(const std::string& name, file client);
		~Channel();

		bool	isClient(const Client&) const;
		bool	isClientInvited(const Client&) const;
		bool	clientAdd(const Client&);
		void	clientDel(const Client&);
		
		bool	isAdmin(const Client&) const;
		void	adminAdd(const Client&);
	
		std::string	getTopic(void) const ;
		std::string	getPassWord(void) const ;

		void	setInviteOnly(bool state);
		void	setTopicRestrict(bool state);
		void	setUserLimit(int limit);
};
