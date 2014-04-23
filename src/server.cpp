#include "stdafx.h"

#include "server.h"
#include "client.h"

Server::Server() :
	port(0){
}
Server::~Server(){
}

bool Server::initialize(int port){
	WSAData wsa;
	SOCKADDR_IN addr;

	/* init winsock */
	WSAStartup( MAKEWORD(2,2), &wsa );

	/* create socket */
	sock = ::socket(PF_INET, SOCK_STREAM, 0);   
	if( socket == 0 ){
		printf("socket error");
		return false;
	}

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(port);

	/* bind */
	if( bind(sock, (SOCKADDR*)&addr, sizeof(addr)) == -1 ){
		printf("bind error");
		return false;
	}

	/* listen */
	if( listen(sock, BACKLOG_SIZE) == -1 ){
		printf("listen error");
		return false;
	}

	return true;
}
void Server::cleanup(){
	close();
}

bool Server::run(int port){

	if( initialize(port) == false )
		return false;

	return true;
}

Client *Server::accept(){
	SOCKET clientSock;
	SOCKADDR_IN clientAddr;
	int clientAddrSize = sizeof(clientAddr);

	clientSock = 
		::accept( sock, (SOCKADDR*)&clientAddr, &clientAddrSize );

	Client *client = new Client( clientSock );

	return client;
}

size_t Server::send(void *data, size_t len){
	return ::send( sock, (char*)data, len, 0 );
}
size_t Server::recv(void *data, size_t len){
	return ::recv( sock, (char*)data, len, 0 );
}

void Server::close(){
	closesocket( sock );
	sock = 0;
}