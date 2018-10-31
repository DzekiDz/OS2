#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static int idata = 111;

int main()
{
    int istack = 222;
    pid_t childPid;

    switch (childPid = fork()) {
        case -1:
            exit(-1);
        case 0:
            idata *= 3;
            istack *= 3;
            break;
        default:
            sleep(3);
            break;
    }

    // Both parent and child come here

    printf("PID=%ld %s idata=%d istack=%d\n", (long) getpid(), 
        (childPid == 0) ? "(child) " : "(parent) ", idata, istack);

    exit(EXIT_SUCCESS);
}
