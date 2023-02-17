/**
 * @file genqueue.h
 * @brief Contains API for generic static or linear queue.
 * @author Hong Kim
 */

typedef enum
{
    eGENQUEUE_INVALID_TYPE,
    eGENQUEUE_CIRCULAR_TYPE,
    eGENQUEUE_LINEAR_TYPE
} Genqueue_QueueType_t;

typedef struct
{
    void* pool;
    void* front;
    void* back;
    unsigned int poolSize;
    unsigned int elementSize;
    unsigned int maxNElements;
} Genqueue_StaticQueue_t;

/**
 * @brief Initializes a generic static queue given a queue pool.
 * @param[in] squeue: Pointer to a static queue object to initialize.
 * @param[in] pool: Pointer to a queue pool to associate with a static queue.
 * @param[in] poolSize: Size of pool in bytes.
 * @param[in] elementSize: Size of elements of queue in bytes.
 * @return -1 if queue failed to initialize, otherwise returns max number of elements.
 */
int Genqueue_SQueueInit(Genqueue_StaticQueue_t* sQueue,
                        void* pool,
                        unsigned int poolSize,
                        unsigned int elementSize);

int Genqueue_SQueueEnqueue(Genqueue_StaticQueue_t* sQueue,
                           void* elements,
                           int nElements);

int Genqueue_SQueueDequeue(Genqueue_StaticQueue_t* sQueue,
                           void* elements,
                           int nElements);

int Genqueue_SQueueFront(Genqueue_StaticQueue_t* sQueue,
                         void* element);

int Genqueue_SQueueBack(Genqueue_StaticQueue_t* sQueue,
                        void* element);

int Genqueue_SQueueDeinit(Genqueue_StaticQueue_t* sQueue);
