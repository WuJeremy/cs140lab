#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define NUM_THREADS 500

int A = 1000;
int B = 1000;

pthread_mutex_t mx_A;
pthread_mutex_t mx_B;


void *TransferAtoB()
{
    pthread_mutex_lock(&mx_A);
    pthread_mutex_lock(&mx_B);

    A = A - 10;
    B = B + 10;

    pthread_mutex_unlock(&mx_A);  
    pthread_mutex_unlock(&mx_B);  

    pthread_exit(NULL);
}

void *TransferBtoA()
{
    pthread_mutex_lock(&mx_B);
    pthread_mutex_lock(&mx_A);

    B = B - 10;
    A = A + 10;

    pthread_mutex_unlock(&mx_B);  
    pthread_mutex_unlock(&mx_A);  

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

        if (i%2) ret = pthread_create(&threads[i], NULL, TransferAtoB, NULL);
        else ret = pthread_create(&threads[i], NULL, TransferBtoA, NULL);

        if (ret) {
            printf("ERROR: Unable to create thread!\n");
            exit(1);
        }
    }

    for (i=0; i<NUM_THREADS; i++) {
        ret = pthread_join(threads[i], &status);
    }

    printf("%d\n%d\n", A, B);

    pthread_exit(NULL);
}
