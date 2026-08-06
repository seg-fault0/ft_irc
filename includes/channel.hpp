#pragma once

# include "irc.hpp"

class Client;

class Channel
{
	private:
		std::string					_name;
		std::string					_topic;
		std::string					_passWord;
		int							_userLimit;
		std::vector<std::string>	_clients;
		std::vector<std::string>	_admins;
		std::vector<std::string>	_invitedClients;
		bool						_inviteOnly;
		bool						__topicRestricted;

	public:
		Channel(const std::string& name, const Client& client);
		~Channel();

		bool	isClient(const Client&) const;
		bool	isClientInvited(const Client&) const;
		bool	clientAdd(const Client&);
		void	clientKick(const Client&);
		void	addToInvitedClient(std::string& user_nick);
		bool	isChannelInviteOnly(void);
		
		bool	isAdmin(const Client&) const;
		void	adminAdd(const Client&);

	
		std::string					getTopic(void) const ;
		std::string					getPassWord(void) const ;
		std::string					getName(void) const ;
		std::vector<std::string>	getClients(void) const;
		std::string					getClientsStr(void) const ;

		void	setInviteOnly(bool state);
		void	setTopicRestrict(bool state);
		void	setUserLimit(int limit);
};
