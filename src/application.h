#pragma once

class Server;
class Client;

class Application{
public:
	Application();
	virtual ~Application();

	void run(int port);
	
private:
	void initialize();
	void cleanup();

protected:
	Server *server;
	Client *target;
};