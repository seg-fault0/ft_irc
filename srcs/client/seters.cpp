#include "irc.hpp"

void Client::setFd(int fd) { _fd = fd; }

void Client::setPass(bool state) { _isPassAccepted = state; }

void	Client::setNickName(const std::string& nickName) { _nickName = nickName; }