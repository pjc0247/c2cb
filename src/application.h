#pragma once

class Server;
class Client;

class Application{
public:
	Application();
	virtual ~Application();

	bool run(int port);
	
private:
	bool initialize();
	void cleanup();

protected:
	Server *server;
	Client *target;
};