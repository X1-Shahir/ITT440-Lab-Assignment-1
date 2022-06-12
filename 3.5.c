#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask()
{
	int n,i,m=0,flag=0;
        printf("Enter the number to check prime:");
        scanf("%d",&n);
        m=n/2;
}

void parentTask()
{
	int n,i,m=0,flag=0;

	for(i=2;i<=m;i++)
	{
	if(n%i==0)
	{
	  printf("Number is not prime \n");
	  flag=1;
	  break;
	}
	}

	if(flag==0)
	{
	  printf("Number is prime \n");
	}
}


int main (void)
{
	int pipefds[2], n;
	pid_t pid = fork();
	char buffer[5];

	pipe(pipefds);

	if(pid == 0)
	{
	  childTask();
	  close(pipefds[0]); // close read fd
	  write(pipefds[1], &n, 5);

	  exit(EXIT_SUCCESS);
	}

	else if(pid > 0)
	{
	  wait(NULL);
	  parentTask();
	}

	else
	{
	  printf("Unable to create child process.");
	}


return EXIT_SUCCESS;
}
