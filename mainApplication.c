
#include <stdio.h>

#include "StackIncludes/StackPrivate.h"
#include "StackIncludes/StackInterface.h"
#include "ApplicationIncludes/Req2.h"
#include "QueueIncludes/Queue.h"
#include "LinkedListIncludes/linkedList.h"
#include "ApplicationIncludes/Req4.h"



int main2(void)
{

    Stack stack;

    stackInitialize(&stack);

    int size;
    int parenthesesFlag;
    char variableHolder;
    char dataSize = sizeof(char);

    // printf("plz enter the number of parentheses you want to enter : ");
    // scanf("%d",&size);
    char arr[8] = {'(','(',')',')','{','}','{','}'};

    //printf("%c",arr[0]);


    for(int i = 0;i<8;i++)
    {
        

        stackPush(&stack,&arr[i],dataSize);
        //printf("%c",arr[i]);


    }

   // void *ptData;

    // for(int i = 0;i<4;i++)
    // {

    //     stackPop(&stack,&ptData,&dataSize);
    //     //printf("%c\n",*((char*)ptData));




    // }



    

    parenthesesFlag = checkParenthesesTruth(&stack);
    if(parenthesesFlag)
    {
        printf("you got the perfect parentheses structure ! \n");

    }
    else
    {
        printf("you have a severe problem with your entered parentheses ! \n");
    }
    


    return 0;

}


/*


    this main function for testing the functionality of the queue implementation 
    you can remove the number beside the main an put the number beside every other main
    to be able to run each functionality that file do !

*/

int main22()
{


    Queue q ;
    createQueue(&q);
    char element = 'm';
    enqueue(&q,&element);
    element = 'a';
    enqueue(&q,&element);
    element = 'y';
    enqueue(&q,&element);


    dequeue(&q,&element);
    printf("%c\n",element);
    dequeue(&q,&element);
    printf("%c\n",element);
        


    return 0;








}


/*

this main function is for testing requirement 4 that has been implemented separately
if you want to use it just remove the number beside the main 
and then put a number beside every other main


*/

int main4(void)
{



    char*str = "((3+3)*(5*6))";

    Stack s = stripParentheses(str);

    char dataSize = sizeof(char);
    int size = stackSize(&s);
    void* characterToBeReturned;

    long value ;
    Queue expression ;
    for(int i = 0;i<size;i++)
    {
        stackPop(&s,&characterToBeReturned,&dataSize);
        enqueue(&expression,((char*)characterToBeReturned));

    }
    value = evaluateExpression(&expression);

    printf("%d",value);




}

/*

this main function is for testing the functionality of the linked list 
and testing the linked list it self

for that one to run you got remove the number beside the main name
and put a number beside any other function 

*/

int main(void)
{


    List l ;
    linkedListInitialize(&l);

    linkedListType element = 5 ;
    listInsertion(&l,&element);


    element = 8;

    listInsertion(&l,&element);
    element = 3;

    listInsertion(&l,&element);

    element = 4;
    listInsertion(&l,&element);

    element = 10;
    listInsertion(&l,&element);


    traverseAllElementsFromList(&l);

    sortLinkedList(&l);

    traverseAllElementsFromList(&l);

    reverseLinkedList(&l);

    traverseAllElementsFromList(&l);



}