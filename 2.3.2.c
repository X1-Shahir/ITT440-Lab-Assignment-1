#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask()
{
	char name[10];
	printf("Enter name: ");
	scanf("%s" , name);
        printf("Name: %s", name);
}

void parentTask()
{
  printf("Job is done \n");
}

int main (void)
{
	for(int i = 0; i < 4; i++)
	{
	  char name[10];
	  pid_t pid = fork();

	  if (pid == 0)
	  {
	    childTask();
	    printf ("\n");
	    exit(EXIT_SUCCESS);
	  }

	  else (pid > 0);
	  {
	    wait(NULL);
 	    parentTask();
	  }
	}

return EXIT_SUCCESS;
}
