#include<stdio.h>
#include<unistd.h>

int
main(void)
{
    pid_t pid;

    printf("(Parent) Process ID: %ld\n", (long)getpid());

    pid = fork();

    if (pid == 0) {
        printf("\n");
        printf("(Child) Parent Process ID: %ld\n", (long)getppid());
        printf("(Child) Child Process ID: %ld\n", (long)getpid());
    }

    return 0;
}

