#include "pch.h"

HANDLE hProcess;
DWORD ProcessID;

DWORD WINAPI PayloadMain(LPVOID PARAMS) {

	std::cout << "Payload running.....\n";
	

	//find processID via window handle, this can also be done with batfitch's function.

	HWND windowHandle = NULL; 

	do {
		windowHandle = FindWindowA(0, "YourWindowNameHere"); //Target process to gain access too.
		Sleep(10);
	} while (windowHandle == NULL);




	GetWindowThreadProcessId(windowHandle, &ProcessID);
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, ProcessID); //ALL_ACCESS not recommended.



	// example read & write process memory

	DWORD baseAddr = 0x005DAC;
	DWORD offset = 0xFC;

	int targetValue;


	int newValue = 100;

	//lets read the value of our target.
	ReadProcessMemory(hProcess, (LPVOID)(baseAddr + offset), &targetValue, sizeof(targetValue), NULL);

	//lets write something different into our target value

	WriteProcessMemory(hProcess, (LPVOID)(baseAddr + offset), &newValue, sizeof(newValue), NULL);

	
	// We can spawn threads from here to keep running
	//CreateThread(0, 0, &RunPayloadThread, 0, 0, 0);

	return TRUE;

}
