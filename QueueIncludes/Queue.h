#ifndef _QUEUE_H_
#define _QUEUE_H_



#define QueueElement      char



typedef struct queueNode
{
    QueueElement Data;
    struct queueNode* Next;
    
}QueueNode;



typedef struct queue
{

    QueueNode* Front;
    
    int size;


}Queue;



void createQueue(Queue*queue);


void enqueue(Queue*queue,QueueElement*elelment);

void dequeue(Queue* queue,QueueElement*elmentToBeReturned);

void deleteQueue(Queue*queue);

int queueSize(Queue*queue);







#endif