
#ifndef _STACKPRIVATE_H_
#define _STACKPRIVATE_H_

#ifndef NULL
#define Null (void*)(0)
#endif

typedef struct stackNode
{
    /* data */
    void* nodeData;
    char nodeBytesCount;
    struct stackNode* nextNode;
}StackNode;



typedef struct stackDataStructure
{

    StackNode* stackHead;
    int        stackSize;


    

}StackDataStructure;




#define Stack       StackDataStructure


#endif