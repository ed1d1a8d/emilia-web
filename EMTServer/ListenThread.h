/*
Responsible for maintaining a socket open for listening on a specified port, as well as spawning sockets for every new connection, and calling functions to deal with messages once they are passed in.
*/

#pragma once

#include "../RainLibrary3/RainLibraries.h"
#include "MessageProc.h"
#include "ListenThreadParam.h"
#include "MessageProcParam.h"

#include <iomanip>
#include <fstream>
#include <map>
#include <mutex>
#include <queue>
#include <string>
#include <vector>
#include <Windows.h>

#define WM_LISTENWNDINIT	WM_RAINAVAILABLE
#define WM_LISTENWNDEND		WM_RAINAVAILABLE + 1

namespace Mono3 {
	//called from Start to create a thread
	DWORD WINAPI listenThread(LPVOID lpParameter);

	//message handlers for the listenThread message queue/window
	LRESULT onListenWndEnd(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT onListenWndInit(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	//onCall functions called by RainWSA2 library
	void OnClientRecvEnd(void *param);
}