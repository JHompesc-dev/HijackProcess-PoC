// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "PEBhide.h"
#include "Payload.h"

BOOL APIENTRY DllMain(HMODULE hMOD, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		
		UnlinkModuleFromPEB(hMOD); //Unlink the module from the Process Environment Header. We could archieve the same goal by using a manual map injector.

		//Let's allocate a console for debugging purposes. 
		AllocConsole(); 
		freopen("conin$", "r+t", stdin);
		freopen("conout$", "w+t", stdout);
		freopen("conout$", "w+t", stderr);
		
		//Create the main thread and run our payload.
		CreateThread(0, 0, &PayloadMain, 0, 0, 0);
	};
	}
	return TRUE;
}
