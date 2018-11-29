#pragma once

#include "rain-aeternum/rain-libraries.h"

#include <map>
#include <set>

namespace Emilia {
	namespace UpdateClient {
		typedef int(*RequestMethodHandler)(Rain::ClientSocketManager::ClientSocketManagerDelegateHandlerParam &);

		struct ConnectionHandlerParam {
			//global config
			std::map<std::string, std::string> *config;

			//accumulated request
			std::string request;

			//length of the request
			std::size_t requestLength;

			//parsed first section of the request
			std::string requestMethod;

			//a variable, manually set by the CSM thread, which will trigger an event when it reaches 0
			//decreases by 1 every time a response is complete, or by a trigger specific to each method
			int waitingRequests;

			//event triggered by waitingRequests
			HANDLE doneWaitingEvent;

			//the success of the last request, as a code
			//nonzero for error
			int lastSuccess;
		};
	}
}