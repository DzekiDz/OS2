gc#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
    printf("The process ID is %d\n", (int) getpid());
    printf("The parent process ID is %d\n", (int) getppid());
    return 0;
}
