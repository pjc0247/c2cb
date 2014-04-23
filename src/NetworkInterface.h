#pragma once

#include <WinSock2.h>
#include <windows.h>

class NetworkInterface{
public:
	NetworkInterface() :
		sock(0){
	};
	NetworkInterface(SOCKET _sock) :
		sock(_sock){
	};

	virtual size_t send(void *data, size_t len) = 0;
	virtual size_t recv(void *data, size_t len) = 0;

	virtual void close() = 0;

protected:
	SOCKET sock;
};