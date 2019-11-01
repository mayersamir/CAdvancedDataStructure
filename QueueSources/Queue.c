

#include "../QueueIncludes/Queue.h"
#include <stdlib.h>
#include <stdio.h>


/*

this function is for intitializing a freshly created queue datastructure
this function must be called at the first thing before anything.

*/
void createQueue(Queue*queue)
{

    queue->Front = NULL;
    queue->size = 0;
}


/*
this function is used to return the size of the queue

*/
int queueSize(Queue*queue)
{
    return queue->size;
} 


/*

this function is used to delete all of the queue elements
*/
void deleteQueue(Queue*queue)
{

    QueueNode* tmp ;


    while(queue->Front)
    {
        tmp = queue->Front;
        queue->Front = queue->Front->Next;
        free(tmp);


    }

    queue->size = 0;
   
}

/*
this function is used to enqueue data inside a specified queue
using the queue methodology 
*/
void enqueue(Queue*queue,QueueElement*element)
{

    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    
    node->Data = *element;

    node->Next = NULL;
    if(!queue->Front)
    {
        //queue->Front = queue->Rear = node;
        node->Next = queue->Front;
        queue->Front = node;
    }
    else
    {
        QueueNode* tmp = queue->Front;
        while(tmp->Next)
        tmp = tmp->Next;
        node->Next = tmp->Next;
        tmp->Next = node;

    }

    queue->size+=1;
    

}


/*
this function is used to the element that has the turn to be returned 
and deleting it from the given queue 
also it works the same as the methodolgy of the queue datastructure;

*/

void dequeue(Queue* queue,QueueElement*elmentToBeReturned)
{

    *elmentToBeReturned = queue->Front->Data;


    //printf("dequeue\n");
    QueueNode* tmp = queue->Front;
    queue->Front = queue->Front->Next;

    free(tmp);
    queue->size-=1;




}


