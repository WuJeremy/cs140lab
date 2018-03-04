#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long n;
long thread_count;
long factorial_result = 1;
pthread_mutex_t mx;

long 
get_range_start(long tid)
{
	long load = n / thread_count;
	long mod = n % thread_count;
	long start;

	if ((long)tid <= mod) { load++; }
	
	start = ((long)tid - 1) * (n / thread_count) + 1;
	if ((long)tid > mod) { start += mod; }
	else { start += ((long)tid - 1); }

	return start;
}

long
get_range_end(long tid, long start)
{
	long load = n / thread_count;
	long mod = n % thread_count;
	if ((long)tid <= mod) { load++; }
	
	return (start + (load - 1));
} 

void *factorial(void *tid)
{
	long i;
	long product = 1;
	long start, end;
	
	start = get_range_start((long)tid);
	end = get_range_end((long)tid, start);

	for (i = start; i <= end; i++) {
		product *= i;
	}

	pthread_mutex_lock(&mx);

	factorial_result *= product;

	pthread_mutex_unlock(&mx);

	printf("Thread %ld: [%ld, %ld] [%ld]\n", (long)tid, start, end, product);
	
	pthread_exit(NULL);
}

int 
main (int argc, char *argv[])
{
	long i = 0;
	pthread_t threads[thread_count];
	void *status;

	if (argc < 3) {
		printf("Usage: %s <n> <no-of-threads>\n", argv[0]);
		return 1;
	}

	n = (long)atoi(argv[1]);
	thread_count = (long)atoi(argv[2]);

	for (i = 0; i < thread_count; i++) {
		pthread_create(&threads[i], NULL, factorial, (void *)(i+1));
	}

	for (i = 0; i<thread_count; i++) {
		pthread_join(threads[i], &status);
	}

	//Print result
	printf("Factorial of %ld is %ld\n", n, factorial_result);

	pthread_exit(NULL);
}
