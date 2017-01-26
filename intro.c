#include <stdio.h>
#include <windows.h>
#include "wrapper.h"

CRITICAL_SECTION CS;
void buff(char* msg)
{
	char dummy;
	//while ((dummy = getchar()) != '\n' && dummy != EOF)
	fgets(msg, 1024, stdin);
	
	if (*(msg + (strlen(msg) - 1)) == '\n')		//if the last char is \n. Changes it to \0
	{
		*(msg + (strlen(msg) - 1)) = '\0';
	}
	else		//if the last char is not \n
	{
		do
		{   // loop until the new-line is read to remove keyboard buffer
			dummy = getchar();
		} while (dummy != '\n');

	}
}
void input()
{
	char*  name = "\\\\.\\mailslot\\mailbox";
	HANDLE hSlot = INVALID_HANDLE_VALUE;
	while (TRUE)
	{
		
		
		if (hSlot == INVALID_HANDLE_VALUE)
		{
			Sleep(50);
			hSlot = mailslotConnect(name);
			if (hSlot == INVALID_HANDLE_VALUE)
			{
				printf("Connect Mailslot failed with error code: %d\n", GetLastError());
			}
		}
		else
		{
			char* message = malloc(1024);
			buff(message);
			EnterCriticalSection(&CS);
			int written = mailslotWrite(hSlot, message, strlen(message)+1);
			LeaveCriticalSection(&CS);
			printf("written: %d\n", written);
			free(message);
		}
	}
}
void output()
{
	char*  name = "\\\\.\\mailslot\\mailbox";
	HANDLE hSlot = mailslotCreate(name);
	if (hSlot == INVALID_HANDLE_VALUE)
	{
		printf("Create Mailslot failed error code: %d\n", GetLastError());
	}
	else printf("Mailslot created successfully.\n");

	int msgSize = 0;

	while(TRUE)
	{
		
				
		//medelande = "now go and die you fucked up WIN32 c";
		GetMailslotInfo(hSlot, 0, &msgSize, 0, 0);
		//printf("%d\n", msgSize);

		if (msgSize != -1)
		{
			char* message = malloc(msgSize + 1);
			//fuuuu = strlen(kakaor);

			EnterCriticalSection(&CS);
			int charRead = mailslotRead(hSlot, message, msgSize);
			char* upp = message;
			//message[charRead] = '\0';
			LeaveCriticalSection(&CS);

			//printf("kukarnas %d\n", charRead);
			//printf("%s\n", message);
			printf("grej");
			free(message);
		}
	}
	mailslotClose(hSlot);
}
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
	InitializeCriticalSection(&CS);
	DWORD numbar = threadCreate((LPTHREAD_START_ROUTINE)input, 0);
	DWORD numbar2 = threadCreate((LPTHREAD_START_ROUTINE)output, 0);
	
	//Skapar mailslot
	
	
	//mailslotClose(hSlot);
	//öppnar den existernade mailsloten
	
	//eoifwoeijfowiejfowi



	
	
	getchar();

	
}