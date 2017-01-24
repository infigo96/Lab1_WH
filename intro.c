#include <stdio.h>
#include "wrapper.h"
void HelloMoon(int* a) {

	int i = 0;
	while (i == i)
	{
		while (i < 10 && *a == 1)
		{
			Sleep(200);
			printf("Hello Moon\n");
			i++;
			if (i == 10)
			{
				i = 0;
				*a = 0;
			}
		}
	}
		
}
void HelloWorld(int* a)
{
	int i = 0;
	while (i == i)
	{
		while (i < 10 && *a == 0)
		{
			Sleep(200);
			printf("Hello World\n");
			i++;
			if (i == 10)
			{
				i = 0;
				*a = 1;
			}
			
		}
	}
}
main()
{
	int a = 0;
	DWORD numbar = threadCreate(HelloWorld, &a);
	DWORD numbar2 = threadCreate(HelloMoon, &a);
	int b = 2;
	getchar();
}