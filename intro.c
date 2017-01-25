#include <stdio.h>
#include <windows.h>
#include "wrapper.h"

CRITICAL_SECTION CS;
void HelloMoon()
{
	int i = 0;
	while (i == i)
	{
		Sleep(1);
		EnterCriticalSection(&CS);

		for (i = 0; i < 10; i++)
		{
			Sleep(200);
			printf("Hello Moon\n");
		}

		LeaveCriticalSection(&CS);
	}
}
void HelloWorld()
{
	int i = 0;
	while (i == i)
	{
		Sleep(1);
		EnterCriticalSection(&CS);

		for (i = 0; i < 10; i++)
		{
			Sleep(200);
			printf("Hello World\n");
		}

		LeaveCriticalSection(&CS);
	}
}
main()
{
	//InitializeCriticalSection(&CS);
	//DWORD numbar = threadCreate((LPTHREAD_START_ROUTINE)HelloWorld, 0);
	//DWORD numbar2 = threadCreate((LPTHREAD_START_ROUTINE)HelloMoon, 0);
	
	//Skapar mailslot
	HANDLE hSlot = mailslotCreate("\\\\.\\mailslot\\blort");
	if (hSlot == INVALID_HANDLE_VALUE)
	{
		printf("CreateMailslot failed with %d\n", GetLastError());
	}
	else printf("Mailslot created successfully.\n");

	//öppnar mailsloten
	hSlot = mailslotConnect("\\\\.\\mailslot\\blort");
	if (hSlot == INVALID_HANDLE_VALUE)
	{
		printf("CreateMailslot failed with %d\n", GetLastError());
	}
	else printf("Mailslot created successfully.\n");

	//closes the mailslot
	mailslotClose(hSlot);
	
	getchar();

	
}