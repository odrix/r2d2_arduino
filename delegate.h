typedef void (*ptrActionPin)(int);

struct futuraction
{
  unsigned long milis;
  long interval;
  ptrActionPin action;
} ;

typedef struct futuraction FuturAction;
