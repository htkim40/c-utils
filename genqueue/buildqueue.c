#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>
#include "genqueue.c"

#define poolSize 5
Genqueue_QueueType_t queueType; 
Genqueue_StaticQueue_t queue;



int main()
{	
	int choice;
	bool terminate = 0;
	unsigned int nDequeues;
	uint32_t queuePool[poolSize];
	uint32_t userInput[3u];
	

	printf("%llu\n", sizeof(queuePool));
	printf("%llu\n", sizeof(uint32_t));
	

	if(poolSize != (sizeof(queuePool)/sizeof(uint32_t))){
		queueType = eGENQUEUE_INVALID_TYPE;
	
	}

	else{
		Genqueue_SQueueInit(&queue, queuePool, sizeof(queuePool)/sizeof(uint32_t), 
							sizeof(uint32_t), poolSize);

		printf("Initialized queue\n");
		queueType = eGENQUEUE_LINEAR_TYPE;
	}

	
	do{	
		printf("\nSelect desired operation:");
		printf("\n1.Insert");
		printf("\n2.Delete");
		printf("\n3.Display\n");

		choice = getche();
		switch(choice){
			case '1':
				Genqueue_SQueueEnqueue(&queue, userInput, sizeof(userInput)/sizeof(uint32_t));
				break;
			case '2':
				printf("How many elements would to dequeue:");
				scanf("%u", &nDequeues);
				Genqueue_SQueueDequeue(&queue, queue.pool, nDequeues);
				break;
			case '3':
				displayQueue(&queue, poolSize);
				break;
			default:
				Genqueue_SQueueDeinit(&queue);
				printf("\nInvalid choice, terminating program");
				terminate = 1;
		}
	} while (terminate != 1);
	
	// int x[5] = {5,3,4};
	// // int x = 2;
	// queue.pool = &x;
	// printf ("%d\n",x[3]);
	// printf("%d\n",*((int*)(queue.pool)+1));
	
	return 0;
}
