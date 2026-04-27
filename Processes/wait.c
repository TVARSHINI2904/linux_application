#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int status, i;

         pid_t pid1, pid2;

    // First child
    pid1 = fork();
    if (pid1 == 0)
    {
        for (int i = 0; i < 5; i++)
            sleep(1);

        printf("From first child\n");
        exit(1);
    }

    // Second child
    pid2 = fork();
    if (pid2 == 0)
    {
        for (int i = 0; i < 10; i++)
            sleep(1);

        printf("From second child\n");
        exit(2);
    }

    // Parent process
    printf("Parent waiting for second child only...\n");

    // Wait for ONLY second child
    waitpid(pid2, &status, 0);

    if (WIFEXITED(status))
    {
        printf("Second child exited with code = %d\n",
               WEXITSTATUS(status));
    }

    return 0;
}
