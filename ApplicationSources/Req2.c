
#include "../StackIncludes/StackPrivate.h"
#include "../StackIncludes/StackInterface.h"
#include "../ApplicationIncludes/Req2.h"
#include <stdlib.h>
#include <stdio.h>


char arrOfParentheses[6] = {'{','}','(',')','[',']'};

static char checkTwoParentheses(char paren1,char paren2)
{
    int i ;
    int flag = 0;
     //printf("%c  %c\n",paren1,paren2);

    for(i =0 ;i<6;i++)
    {
        if(arrOfParentheses[i]==paren1)
        {
            if(arrOfParentheses[i+1]==paren2)
            {
                flag =1 ;
            }
            else if(arrOfParentheses[i-1]==paren2)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;

            }
            
        
        }
    }

    return flag;

}


static char checkEquilibrium(char*arr,Stack* s)
{

    void* returnedData;
    char dataSize = sizeof(char);
    int size = stackSize(s);
    char* arrS = (char*)malloc(sizeof(char)*size);
    int flag = 0;
    char previousElement = 0;
    int i,j ;


    for(i = 0;i<size;i++)
    {
        stackPop(s,&returnedData,&dataSize);
        arrS[i] = *((char*)returnedData);
        
        if((*((char*)returnedData)==arr[i])&&(*((char*)returnedData)!=previousElement))
        {
            flag = -1;
           // printf("%c\n",*((char*)returnedData));
            previousElement = *((char*)returnedData);
            //printf("hey\n");
        }
        else
        {
            flag = 0;
            free(returnedData);
            break;
        }

        free(returnedData);


        

       

        


    }


    

    for( j =i;(j>=0);j--)
    {
        stackPush(s,&arrS[j],dataSize);

    }


    //printf("%d",i);
    return i;


}


char checkParenthesesTruth(Stack *elements)
{


    int size = stackSize(elements);
    char* arrStack = (char*)malloc(sizeof(char)*size);
    Stack firstHalf;
    Stack secondHalf;
    stackInitialize(&firstHalf);
    stackInitialize(&secondHalf);
    void* returnedData;
    void* returnedData2;
    char dataSize = sizeof(char);
    int flag=1;




    int i;



    for(i =0;i<size;i++)
    {

        stackPop(elements,&returnedData,&dataSize);
        arrStack[i] = *((char*)returnedData);

        //stackPush(&firstHalf,returnedData,dataSize);
        //////printf("%c",*((char*)returnedData));
        free(returnedData);




       
    }


    for(i = size-1;i>=0;i--)
    {
        stackPush(elements,&arrStack[i],dataSize);
        //printf("%c\n",arrStack[i]);
        

    }
    //printf("********************");
    int returnedFlag = checkEquilibrium(arrStack,elements);
    if(returnedFlag==-1)
    {
        return flag;
    }
    else
    {
        
        for(i = returnedFlag-1;i<size;i++)
        {
           // printf("%c\n",arrStack[i]);
            stackPush(&firstHalf,&arrStack[i],dataSize);
        }
        for(int j = 0;j<returnedFlag-1;j++)
        {
            stackPop(elements,&returnedData2,&dataSize);
            //printf("")
        }
            
    }
    






    for(i = 0;i<size-(returnedFlag-1);i++)
    {

        stackPop(&firstHalf,&returnedData,&dataSize);
        stackPop(elements,&returnedData2,&dataSize);

        if(!checkTwoParentheses(*((char*)returnedData),*((char*)returnedData2)))
        {
            flag = 0;
            //printf("flag\n");
           // printf("%d",i);


        }
        free(returnedData);
        free(returnedData2);

   
        
    }

    //printf("%d",size);
   
    for(int j= 0;j<size;j++)
    {
        //printf("lol");
        ///printf("%c\n",arrStack[j]);
        stackPush(elements,&arrStack[j],dataSize);
        
        
    }


    free(arrStack);
    //printf("%c",*((char*)returnedData));



    // for(;i<size;i++)
    // {
    //     stackPop(elements,&returnedData,&dataSize);
    //     stackPush(&secondHalf,returnedData,dataSize);
    //     printf("%c",*((char*)returnedData));

    // }


    // for(int j = 0;j<size/2;j++)
    // {
        
    //     stackPop(&firstHalf,&returnedData,&dataSize);
    //     stackPop(&secondHalf,&returnedData,&dataSize);
    //     if(!checkTwoParentheses(*((char*)returnedData),*((char*)returnedData2)))
    //     {

    //         flag = 0;



    //     }
    //    stackPush(elements,returnedData,dataSize);
    //    stackPush(elements,returnedData2,dataSize);


        


    // }


    return flag;




}

