

#ifndef _STACKINTERFACE_H_
#define _STACKINTERFACE_H_

#define StackElementType  char





void stackInitialize(Stack*stack);

void stackPush(Stack*stack,void*data,char dataBytesSize);

void stackPop(Stack*stack,void**dataToBeReturned,char* dataBytesSize);

void stackDelete(Stack*stack);

int stackSize(Stack*stack);

#endif
