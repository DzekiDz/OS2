#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid;

    pid = fork();
    if (pid > 0) {
        printf("parent: child=%d\n", pid);
        pid = wait(0);
        printf("child %d is done\n", pid);
    } else if (pid == 0) {
        printf("child: exiting\n");
        exit(0);
    } else {
        printf("fork error\n");
    }

    return 0;
}
