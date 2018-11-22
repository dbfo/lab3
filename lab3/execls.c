#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("Execiting execl.\n");

	execl("/bin/ls","ls","-l",(char*)0);
	perror("execl failed to run ls");
	exit(1);
}

