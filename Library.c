
#include <stdio.h>
#include <stdlib.h>
#include "StackIncludes/StackPrivate.h"
#include "StackIncludes/StackInterface.h"
#include "ApplicationIncludes/Req2.h"
#include "QueueIncludes/Queue.h"
#include "LinkedListIncludes/linkedList.h"
#include "ApplicationIncludes/Req4.h"


#define databaseNumber  10


typedef struct database
{
    int databaseId;
    List databaseElements;
}Database;


void showMainMenu(void);

int main(void)
{
    Database* systemDatabases[10];//= (Database*)malloc(databaseNumber*sizeof(Database));
    int choice;
    int i = 0;
    int insertionElement;
    int dN;
    int flag;
    // for(int i =0;i<databaseNumber;i++)
    // {
    //     linkedListInitialize(&(systemDatabases[i].databaseElements));
    // }


    showMainMenu();
    printf("Enter your choice :");
    scanf("%d",&choice);

    while(choice!=5)
    {


        switch(choice)
        {


            case 1 :
            
            systemDatabases[i] = (Database*)malloc(sizeof(Database));
            
            if(!systemDatabases[i])
            {
                printf("Creation has not been proceeded \n");
                break;
            }
            systemDatabases[i]->databaseId = i;
            printf("Database has been created successfully ! \n");
            printf("Its number is %d\n",(systemDatabases[i]->databaseId));
            linkedListInitialize(&(systemDatabases[i]->databaseElements));
            i++;
            break;

            case 2:
            printf("plz enter the number of database : ");
            scanf("%d",&dN);
            printf("plz enter the element you want to be inserted : ");
            scanf("%d",&insertionElement);
            flag = listInsertion((&(systemDatabases[dN]->databaseElements)),&insertionElement);
            if(flag)
            {

                printf("Your element has been inserted succesfully inside the database ! \n");

            }
            else
            {
                printf("Error at the insertion of the element inside the database ! \n");
                printf("Plz try again later !");

            }
            break;
            
            case 3:
            printf("plz enter the number of database : ");
            scanf("%d",&dN);
            traverseAllElementsFromList(&(systemDatabases[dN]->databaseElements));
            break;

            case 4:
            printf("plz enter the number of database : ");
            scanf("%d",&dN);
            printf("plz enter the position of the element you want to be deleted : ");
            scanf("%d",&insertionElement);
            flag = returnSpecificElement(&(systemDatabases[dN]->databaseElements),&insertionElement);
            if(flag)
            {

                printf("the element deleted successfully and it was %d\n",flag);
            }
            else
            {
                printf("Error has been occured during the deletion \n");
                printf("Try again later !");

            }
            break;
            
            case 5:
            printf("plz enter the number of database : ");
            scanf("%d",&dN);
            printf("plz enter the element you want to be searched inside the DB : ");
            scanf("%d",&insertionElement);
            flag = searchLinkedList(&(systemDatabases[dN]->databaseElements),insertionElement);

            if(flag!=-1)
            {
                printf("Your entered element has been found at the %d position inside the database !\n",flag);

            }
            else
            {
                printf("Sry your entered element can't be found at the specified database !\n");
            }
            break;

            case 6:
            printf("plz enter the number of database to be sorted : ");
            scanf("%d",&dN);
            sortLinkedList(&(systemDatabases[dN]->databaseElements));
            traverseAllElementsFromList(&(systemDatabases[dN]->databaseElements));
            break;

            case 7:
            printf("plz enter the number of database to be reversed  : ");
            scanf("%d",&dN);
            reverseLinkedList(&(systemDatabases[dN]->databaseElements));
            traverseAllElementsFromList(&(systemDatabases[dN]->databaseElements));
            break;

            case 8:
            printf("plz enter the number of database you want to destroy : ");
            scanf("%d",&dN);
            deleteList(&(systemDatabases[dN]->databaseElements));
            printf("All of the elements inside the specified database have been deleted successfully ! \n");

            break;





            





            






        }



        printf("*********************************************\n");


    showMainMenu();
    printf("Enter your choice :");
    scanf("%d",&choice);
      
    }













}


void showMainMenu(void)
{
    printf("******************************************************************\n");
    printf("******************************************************************\n");
    printf("1-Create Database\n");
    printf("2-Insert into specific Database\n");
    printf("3-Show all of the elements inside the database\n");
    printf("4-Delete specific element inside a specified database\n");
    printf("5-Search for specific element inside a specific database \n");
    printf("6-Sort the elements of the specified database \n");
    printf("7-Reverse the elements of the specified database");
    printf("8-Destroy the elements of the specified database\n");
    printf("******************************************************************\n");
    printf("******************************************************************\n");
}