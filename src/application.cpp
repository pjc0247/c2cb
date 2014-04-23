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

bool Application::initialize(){
	server = new Server();

	return true;
}
void Application::cleanup(){
	SAFE_DELETE( server );
	SAFE_DELETE( target );
}

bool Application::run(int port){
	if( initialize() == false )
		return false;

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

	return true;
}