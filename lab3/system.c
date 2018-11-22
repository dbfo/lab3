#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	execl("/bin/ls","ls","-al",(char *)0);
	perror("execl failed to run ls");
	exit(1);
}
