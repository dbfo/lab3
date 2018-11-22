#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>

int getargs(char *cmd, char **argv);

int main()
{
	char buf[256];
	char *argv[50];
	int narg;
	pid_t pid;

	while(1)
	{
		printf("shell> ");
		scanf("%s",buf);
		narg = getargs(buf, argv);

		pid = fork();
		if(pid == 0)
			execvp(argv[0], argv);
		else if(pid > 0)
			wait((int*)0);
		else 
			perror("fork failed");
	}
}
int getargs(char *cmd, char **argv)
{
	int narg = 0;

	while(*cmd){
		if(strcmp(cmd,"exit")==0)
				exit(1);
		if(*cmd ==' '||*cmd == '\t')
			*cmd++ = '\0';
		else{
			argv[narg++] = cmd++;
			while(*cmd != '\0' && *cmd != ' ' && *cmd!='\t')
				cmd++;
		}
	
	}
	argv[narg] = NULL;
	return narg;
}
