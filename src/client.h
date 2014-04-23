#pragma once

#include "NetworkInterface.h"

class Client : public NetworkInterface{
public:
	Client();
	Client(SOCKET sock);
	virtual ~Client();

	virtual size_t send(void *data, size_t len);
	virtual size_t recv(void *data, size_t len);

	virtual void close();
};