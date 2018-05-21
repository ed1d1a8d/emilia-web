/*
Standard
*/

#pragma once

#include "RainWSA2Include.h"

#include "RainWSA2SendRecv.h"

#include <string>

namespace Rain {
	int initWinsock(WSADATA &wsaData);

	//client side functions
	int getClientAddr(std::string host, std::string port, struct addrinfo **result);
	int createClientSocket(struct addrinfo **ptr, SOCKET &ConnectSocket);
	int connToServ(struct addrinfo **ptr, SOCKET &ConnectSocket); //never frees ptr; we might need it again

	int quickClientInit(WSADATA &wsaData, std::string host, std::string port, struct addrinfo **paddr, SOCKET &connect);

	//server side functions
	int getServAddr(std::string port, struct addrinfo **result);
	int createServLSocket(struct addrinfo **ptr, SOCKET &ListenSocket);
	int bindServLSocket(struct addrinfo **ptr, SOCKET &ListenSocket); //frees ptr
	int listenServSocket(SOCKET &ListenSocket);
	int servAcceptClient(SOCKET &ClientSocket, SOCKET &ListenSocket);

	int quickServerInit(WSADATA &wsaData, std::string port, struct addrinfo **paddr, SOCKET &listener);

	//both sides
	int shutdownSocketSend(SOCKET &ConnectSocket);
	std::string getClientNumIP(SOCKET &clientsock);

	//send/recv
	int sendText(SOCKET &sock, std::string strText);
	int sendTextRef(SOCKET &sock, std::string &strText);

	//custom Rain formats of messages
	int sendBlockText(SOCKET &sock, std::string strText);
	int sendBlockTextRef(SOCKET &sock, std::string &strText);

	int sendHeader(SOCKET &sock, std::unordered_map<std::string, std::string> *headers);
}