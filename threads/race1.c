#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define NUM_THREADS 500

int x  = 0;

void *AddOne()
{
    unsigned int i, j = 0;
    int tmp;

    tmp = x;
    for (i=0; i<rand()*100; i++) {
        j++;
    }

    x = tmp + 1;

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int ret;
    long i;
    void *status;

    srand(time(NULL));
    
    for (i=0; i<NUM_THREADS; i++) {
        ret = pthread_create(&threads[i], NULL, AddOne, NULL);
        if (ret) {
            printf("ERROR: Unable to create thread!\n");
            exit(1);
        }
    }

    for (i=0; i<NUM_THREADS; i++) {
        ret = pthread_join(threads[i], &status);
    }

    printf("%d", x);
    pthread_exit(NULL);
}
