#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void *threadFunc() {
   printf("Thread created\n");
   printf("Thread Id: %ld\n", (long)pthread_self());
}

int main (int argc, char *argv[])
{
	pthread_t thread;
	printf("Creating thread.\n");
	pthread_create(&thread, NULL, &threadFunc, NULL);
	printf("Thread will be deleted\n");
        pthread_exit(NULL);
	printf("Thread deleted\n");
	return 0;
}
