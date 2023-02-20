#include "genqueue.h"

Genqueue_QueueType_t queueType;



int Genqueue_SQueueInit(Genqueue_StaticQueue_t* sQueue,
                        void* pool,
                        unsigned int poolSize,
                        unsigned int elementSize,
                        unsigned int maxNElements)
{
    sQueue->front = sQueue->back;
    sQueue->poolSize = poolSize;
    sQueue->elementSize = elementSize;
    sQueue->pool = pool;
    sQueue->maxNElements = maxNElements;

    return 0;
}

int Genqueue_SQueueEnqueue(Genqueue_StaticQueue_t* sQueue,
                           void* elements,
                           unsigned int nElements)
{

    return 0;
}
int Genqueue_SQueueDequeue(Genqueue_StaticQueue_t* sQueue,
                           void* elements,
                           unsigned int nElements)
{
    return 0;
}

int Genqueue_SQueueFront(Genqueue_StaticQueue_t* sQueue,
                         void* element)
{
    return 0;
}

int Genqueue_SQueueBack(Genqueue_StaticQueue_t* sQueue,
                        void* element)
{
    return 0;
}

int Genqueue_SQueueDeinit(Genqueue_StaticQueue_t* sQueue)
{
    sQueue->pool = 0;
    sQueue->front = sQueue->back = 0;
    sQueue->poolSize = 0;
    sQueue->elementSize = 0;
    sQueue->maxNElements = 0;
    return 0;
}

int displayQueue(Genqueue_StaticQueue_t* sQueue, unsigned int maxNElements)
{
    printf("\nQueue:");
    for(int x = 0; x < sQueue->maxNElements; x++){
        printf("%d ", *(uint16_t*)sQueue->pool);
        sQueue->pool++;
    }
    return 0;
}