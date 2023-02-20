#define GENSM_NULL_SMPFUNC (0)

typedef void (*GensmPFunc_t)(void* args);

typedef struct
{
    GensmPFunc_t entry;
    GensmPFunc_t step;
    GensmPFunc_t exit;
} GensmStateFunc_t;

typedef struct
{
    int id;
    char* name;
    GensmStateFunc_t* function;
} GensmState_t;

typedef struct
{
    GensmState_t* stateTable;
    void* stateData;
    unsigned char nStates;
    unsigned char currentState;
} GensmStateContext_t;

int Gensm_Tick(GensmStateContext_t* smContextData);
int Gensm_StateTransition(GensmStateContext_t* smContextData,
                          int state);