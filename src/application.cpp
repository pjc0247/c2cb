#include "stdafx.h"

#include "application.h"

#include "server.h"
#include "client.h"

#include <thread>

using namespace std;

Application::Application() :
	server(nullptr), target(nullptr){
}
Application::~Application(){
}

void Application::initialize(){
	server = new Server();
}
void Application::cleanup(){
	SAFE_DELETE( server );
	SAFE_DELETE( target );
}

void Application::run(int port){
	initialize();

	try{
		server->run( port );
	}
	catch(const char *msg){
		printf("[%s]\n", msg);

		return;
	}

	while( true ){
		Client *client = server->accept();

		thread( [client](){
			while( true ){
				char inbuf[INBUF_SIZE];
				int received;

				received = client->recv( inbuf, INBUF_SIZE );

				/* connection이 끊어졌을 때 */
				if( received == -1 ){
					break;
				}

				//target->
			}
		}).detach();
	}
}