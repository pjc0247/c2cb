#pragma once

#include "NetworkInterface.h"

class Client;

class Server : public NetworkInterface{
public:
	Server();
	virtual ~Server();

	void run(int port);

	Client *accept();

	virtual size_t send(void *data, size_t len);
	virtual size_t recv(void *data, size_t len);

	virtual void close();

private:
	void initialize(int port);
	void cleanup();

protected:
	int port;
};