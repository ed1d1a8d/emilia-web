#pragma once
#pragma comment(lib, "user32.lib")

#include "rain-aeternum/rain-libraries.h"

#include "build-helper.h"

#include <algorithm>
#include <map>
#include <set>

namespace Emilia {
	namespace HTTPServer {
		struct ConnectionCallerParam {
			//global config options
			std::map<std::string, std::string> *config;

			//used to log socket communications from main
			Rain::LogStream *logger;

			//total number of connected clients
			int connectedClients;
		};

		struct ConnectionDelegateParam {
			//LL node for all threads which are handling requests for this connection
			struct ThreadNode {
				ThreadNode *prev, *next;
				std::thread th;
			};

			//accumulated request from messages
			std::string request;

			//GET/POST/etc, request method name; "" if don't know yet
			std::string requestMethod;

			//index of the first character of the end of the block of headers (two newlines), or -1
			std::size_t headerBlockLength;

			//content length header content for POST requests; -1 if don't know yet
			//also identifies the length of the body block
			std::size_t contentLength;

			//LL and mutex to manage threads associated with this connection
			ThreadNode thLLBegin, thLLEnd;
			std::mutex thLLMutex;
		};

		//handlers for RecvThread
		int onConnect(void *funcParam);
		int onMessage(void *funcParam);
		int onDisconnect(void *funcParam);

		//called by RecvThread handlers when a full message comes in
		//header keys are all lowercase
		//returns non-zero to close connection
		int processRequest(SOCKET *cSocketPtr,
			std::map<std::string, std::string> *configPtr,
			const std::string &requestMethod,
			const std::string &requestURI,
			const std::string &httpVersion,
			const std::map<std::string, std::string> &headers,
			const std::string &bodyBlock);

		//helper function to parse a header block in a SS
		void parseHeaders(std::stringstream &headerStream, std::map<std::string, std::string> &headers);
	}  // namespace HTTPServer
}  // namespace Emilia