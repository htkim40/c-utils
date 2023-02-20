#include "genqueue.h"

Genqueue_QueueType_t queueType;



int Genqueue_SQueueInit(Genqueue_StaticQueue_t* sQueue,
                        void* pool,
                        unsigned int poolSize,
                        unsigned int elementSize,
                        unsigned int maxNElements)
{
    sQueue->front = sQueue->back = pool;
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
    void* const lastWritableAddr = sQueue->pool + (sQueue->maxNElements - 1) * sQueue->elementSize;
    
    // (sQueue->back - (sQueue->pool + (sQueue->maxNElements-1) * sQueue->elementSize))/sQueue->elementSize
    (void) memcpy(sQueue->back, elements, nElements * sQueue->elementSize);
    sQueue->back = sQueue->back + nElements * sQueue->elementSize;


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
    memset(sQueue, 0, sizeof(Genqueue_StaticQueue_t));
    return 0;
}

int displayQueue(Genqueue_StaticQueue_t* sQueue, unsigned int maxNElements)
{   Genqueue_StaticQueue_t* tempQueue = sQueue;
    printf("\nQueue:");
    for(int x = 0; x < sQueue->maxNElements; x++){
        printf("%d ", *(uint16_t*)sQueue->pool);
        tempQueue->pool++;
    }
    return 0;
}