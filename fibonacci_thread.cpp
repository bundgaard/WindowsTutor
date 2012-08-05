#include <stdio.h>
#include <stdlib.h>
#include <process.h>

long fib(unsigned long c)
{

	unsigned long f0 = 0;
	unsigned long f1 = 1;
	unsigned long idx;
	for(idx = 0; idx < c; idx++)
	{
		unsigned long tmp;
		if(idx <= 1)
			tmp = idx;
		else
		{

		
		tmp = f0 + f1;
		f0 = f1;
		f1 = tmp;
		
		}
		printf("%u\n",tmp);
	}
	return 0l;
}
void RunThread(void *arguments)
{
	printf("Inside thread\n");
	fib(50);

}
void RunHelloWorldTenTimes(void *argument)
{

	int i;
	for(i = 0; i < 10; i++)
	{

		printf("Hello, World\n");
	}
}
int main(int argc, char **argv)
{
	uintptr_t threadid;
	threadid = _beginthread(RunThread,0,0);
	threadid = _beginthread(RunHelloWorldTenTimes,0,0);
	system("pause");
	return 0;
}