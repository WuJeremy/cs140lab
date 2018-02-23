#include <pthread.h>
#include <stdio.h>


int
main(int argc, char *argv[])
{
    int policy = 0;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    if (pthread_attr_getschedpolicy(&attr, &policy) != 0) {
        fprintf(stderr, "Unable to get policy.\n");
    } else {
        printf("%d\n", policy);
        if (policy == SCHED_OTHER) {
            printf("SCHED_OTHER\n");
        } else if (policy == SCHED_RR) {
            printf("SCHED_RR\n");
        } else if (policy == SCHED_FIFO) {
            printf("SCHED_FIFO\n");
        }
    }

    return 0;
}
