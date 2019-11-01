




#include "../StackIncludes/StackPrivate.h"
#include "../StackIncludes/StackInterface.h"
#include "../QueueIncludes/Queue.h"
#include "../ApplicationIncludes/Req4.h"


#include <stdio.h>
static int stringCharsCount(char*string)
{

    int len = 0;

    while(*string) {
        /* Count only lower-case letters a-z. */
        if (*string) ++len;
        ++string;
    }

    return len;
}

Stack stripParentheses(char*string)
{

    int numberOfChars = stringCharsCount(string);
    char elementSize = sizeof(char);
    Stack s;
    stackInitialize(&s);


    for(int i = 0;i<numberOfChars;i++)
    {

        switch(*string)
        {
            case '(':
            break;
            case ')':
            break;
            default:
                stackPush(&s,string,elementSize);
            break;



        }
        string++;
    }


    return s;

}


long evaluateExpression(Queue*expression)
{



    long value = 0;
    void* elmentToBePoped ;
    char dataSize = sizeof(char);
    Stack operators ;
    stackInitialize(&operators);


    Stack operands;
    stackInitialize(&operands);

    int numberOfChars = queueSize(expression);
    int queueFlag = 0;
    int stackFlag = 0;
    char element ;
    



    //printf("%d",numberOfChars);

    
        
        //printf("%c",*((char*)elmentToBePoped));
    for(int i =0;i<numberOfChars;i++)
    {
        dequeue(expression,&element);
        
        switch(element)
        {
            case '+':
                queueFlag =1;
                break;
            case '-':
                queueFlag = 1;
                break;
            case '*':
                queueFlag = 1;
                break;
            case '/':
                queueFlag = 1;
                break;
            default:
                stackFlag = 1;

        }

        if(stackFlag == 1)
        {
            stackPush(&operands,&element,dataSize);
            stackFlag = 0;

        }
        else if(queueFlag == 1)
        {
            stackPush(&operators,&element,dataSize);
            queueFlag = 0;
        }
        else
        {
            /* code */
        }
        


    }


    Queue reversed,reversed2 ;
    createQueue(&reversed);
    createQueue(&reversed2);

    void* returnedData;
    int size = stackSize(&operands);
    int size2 = stackSize(&operators);



    for(int i = 0;i<size;i++)
    {

        stackPop(&operands,&returnedData,&dataSize);
        enqueue(&reversed,((char*)returnedData));
        //printf("%c\n",*((char*)returnedData));
    }
    for(int i = 0;i<size2;i++)
    {

        stackPop(&operators,&returnedData,&dataSize);
        enqueue(&reversed2,((char*)returnedData));
        //printf("%c\n",*((char*)returnedData));
    }




    char elmentToBeReturned;


    dequeue(&reversed,&elmentToBeReturned);

    value += (elmentToBeReturned-'0');
    //printf("%d\n",value);

    for(int i = 0;i<size-1;i++)
    {
        char operation ;
        char operand;
        dequeue(&reversed2,&operation);
        dequeue(&reversed,&operand);
        switch(operation)
        {

            case '+':
           
            value+=(operand -'0');
            printf("%c\n",operation);
            break;
            case '*':
            value*=(operand-'0');
            printf("%c\n",operation);
            break;
            case '/':
            value/=(operand-'0');
            break;
            case '-':
            value-=(operand-'0');
            break;


        }

    }

    return value;


    


}