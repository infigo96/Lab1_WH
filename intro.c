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
	char*  name = "\\\\.\\mailslot\\mailbox";
	HANDLE hSlot = mailslotCreate(name);
	if (hSlot == INVALID_HANDLE_VALUE)
	{
		printf("Create Mailslot failed error code: %d\n", GetLastError());
	}
	else printf("Mailslot created successfully.\n");

	
	//mailslotClose(hSlot);
	//öppnar den existernade mailsloten
	HANDLE hSlot2 = mailslotConnect(name);
	if (hSlot2 == INVALID_HANDLE_VALUE)
	{
		printf("Connect Mailslot failed with error code: %d\n", GetLastError());
	}
	else printf("Mailslot open successfully.\n");

	char* medelande = "Fuck you I hate your silly little fucking ass of massdestruction and cocks";
	int fuuuu = mailslotWrite(hSlot2, medelande, strlen(medelande));
	printf("%d\n", fuuuu);


	medelande = "now go and die you fucked up WIN32 c";
	GetMailslotInfo(hSlot, 0, &fuuuu, 0, 0);
	printf("%d\n", fuuuu);

	char* kakaor = malloc(fuuuu);
	fuuuu = strlen(kakaor);
	fuuuu = mailslotRead(hSlot, kakaor, fuuuu);
	printf("kukarnas %d\n", fuuuu);
	kakaor[fuuuu] = '\0';
	printf("%s\n", kakaor);
	//closes the mailslot
	mailslotClose(hSlot);
	
	getchar();

	
}