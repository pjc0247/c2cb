#include "stdafx.h"

#include "client.h"

Client::Client(){
}
Client::Client(SOCKET sock) :
	NetworkInterface(sock){
}
Client::~Client(){
}

size_t Client::send(void *data, size_t len){
	return ::send( sock, (char*)data, len, 0 );
}
size_t Client::recv(void *data, size_t len){
	return ::recv( sock, (char*)data, len, 0 );
}

void Client::close(){
	closesocket( sock );
	sock = 0;
}