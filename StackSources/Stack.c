#include "../StackIncludes/StackPrivate.h"
#include "../StackIncludes/StackInterface.h"

#include <stdlib.h>
#include <stdio.h>


/*

this function is used to intitizlize the stack
it must be called first thing before doing anyother 
operation on the stack 
or 
everything will be wrong.
*/
void stackInitialize(Stack*stack)
{

    stack->stackSize = 0;
    stack->stackHead = NULL;

}


/*
this function is used to push ana element inside the stack
i explained to U sir that i used the a pointer to void for the data element
to be able not to specify the datatype of the element that will be stored at the 
stack 
as all i care about is how many bytes that should i write at the memory
that is why i am passing a void pointer to the data 
and i am also passing the size of the data that will be pushed inside the stack

*/
void stackPush(Stack*stack,void*data,char dataBytesSize)
{

    StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));

    void* nodeData = malloc(dataBytesSize);
   for(int i =0;i<dataBytesSize;i++)
   {
    //    *(((char*)(nodeData))+i) = *(((char*)(data))+i);
    ((char*)nodeData)[i] = ((char*)data)[i];



   }
  

    stackNode->nodeBytesCount = dataBytesSize;
    stackNode->nodeData = nodeData;
     //printf("%d",*((int*)(stackNode->nodeData)));
    stackNode->nextNode = NULL;
    

     StackNode* tmp = stack->stackHead;

     stack->stackHead = stackNode;
     stackNode->nextNode = tmp;
     stack->stackSize += 1;

    // if(!stack->stackHead)
    // {
    //     stack->stackHead = stackNode;
    // }
    // else
    // {
       
    //     while(tmp->nextNode)
    //     tmp = tmp->nextNode;
    //     tmp->nextNode = stackNode;
    // }
    
    return;
}



/*

the user will supply the address of a void pointer from the main 
and i am taking a pointer to that pointer as i want to change 
what that void pointer will point at that why i used **
then after this function is finished the user can cas his pointer 
to anytype that he knew to be previously inserted to that stack
and i also returning to the user the number of the bytes that have been 
written for that element that has been poped from the stack and from the memory
the dataBytesSize represents the number of bytes that element has taken to be 
stored

*/
void stackPop(Stack*stack,void**dataToBeReturned,char* dataBytesSize)
{
    (*dataToBeReturned) = malloc((*dataBytesSize));

   // dataToBeReturned = stack->stackHead->nodeData;

    *dataBytesSize = stack->stackHead->nodeBytesCount;

    char* ptr = (char*)(*dataToBeReturned);
   
   for(int i =0;i<(*dataBytesSize);i++)
   {
    //    *(((char*)(nodeData))+i) = *(((char*)(data))+i);
    ptr[i] = ((char*)stack->stackHead->nodeData)[i];



   }
   //printf("%d",*((int//*)(*dataToBeReturned)));

    StackNode* tmp = stack->stackHead;

    stack->stackHead = stack->stackHead->nextNode;

    stack->stackSize -= 1;

    free(tmp->nodeData);
    free(tmp);

     //printf("%d",*((int*)(dataToBeReturned)));

    return;


}


void stackDelete(Stack*stack)
{

    StackNode* tmp ;

    for(int i = 0;i<stack->stackSize;i++)
    {
        tmp = stack->stackHead;
        stack->stackHead = stack->stackHead->nextNode;
        free(tmp);
    }
    stack->stackSize = 0;

    return;

}


int stackSize(Stack*stack)
{
    return stack->stackSize;
}