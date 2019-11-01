#include "../LinkedListIncludes/linkedList.h"
#include<stdlib.h>
#include<stdio.h>


/*

that function for intializing the linked list it must
be called before calling anyother function from th list 
implemented functions.

*/
void linkedListInitialize(List*ls){

	ls->head = NULL;


	ls->current = NULL;


	ls->size = 0;
}

/*

this function is for inserting a specific element inside the list
this function is used only if you want to insert the element at the end of the specified
list otherwise use the other implementation that contains the position as paramater in it .
*/

int listInsertion(List*ls,linkedListType* data){

	Node* ptn = (Node*)malloc(sizeof(Node));
	ptn->data = *data;
	ptn->Next = NULL;
	int currentPosition = 1;
	if(ptn){

		if(ls->size==0){

			ls->head = ptn;
			ls->current = ls->head;
			ls->currentPosition = currentPosition;

		}else{
			Node* temp = ls->head;
			while(temp->Next){
				temp = temp->Next;
				currentPosition++;
			}
			ls->current = temp;
			temp->Next = ptn;

			//printf("the data is %d\n",temp->data);
		}
		ls->size++;
	}
	else{

		return -1;
	}

	return 1;

}



int returnLinkedListSize(List*ls){

	return ls->size;
}


/*

this function is for returning a specific element from the list which you will supply 
the position that you want its element 
that element won't be deleted from the linked list
it will be like you will take only a sneak peak at it.
*/

linkedListType returnSpecificElement(List*ls,int*elementNumber){


	Node* temp = ls->head;
	//printf("%d\n",temp->data);
	if((*elementNumber)-1==0){
		//printf("%d",temp->data);
		return temp->data;

	}
	else{

		for(int i =1;i<*elementNumber;i++){

			temp=temp->Next;


		}

	}

	return temp->data;

}

/*

this function is for taking a sneak peak of an specified element without deleteing it.
*/

linkedListType traverseSpecificElement(List*ls,int*elementNumber){

	Node* tmp = ls->head;
	Node* delete;
	linkedListType deletedElement;

	if(*elementNumber == 1){
		delete = tmp;
		deletedElement = tmp->data;
		ls->head = tmp->Next;


		free(delete);

	}else{

		for(int i =1;i<*elementNumber-1;i++){

			tmp = tmp->Next;
		}
		deletedElement = tmp->Next->data;
		delete = tmp->Next;
		tmp->Next = tmp->Next->Next;
		free(delete);

	}

	ls->size--;
	return deletedElement;


}

/*
this function is for printing all the elements inside the specified list
*/


void traverseAllElementsFromList(List*ls){

	Node*tmp = ls->head;

	int i =0;
	while(tmp!=NULL){

		printf("the %d element is : %d\n",i,tmp->data);
		tmp = tmp->Next;
		i++;
	}
	printf("***********************************************************\n");
}


/*
this function is for deleting all the elements inside the specified list
*/
void deleteList(List*ls){

	Node*tmp1=ls->head ;
	Node*tmp2;
	while(ls->head !=NULL){


		tmp2 = tmp1;
		tmp1 = tmp1->Next;
		free(tmp2);
		ls->head = tmp1;


	}
}

/*
this function for the user to implement a specific functionality at the main
and pass the list and a pointer to that functionality and 
the passed functionality will be applied to each element 
inside the linked list .
the passed pointer to function must return void 
and takes only one paramater as input.
*/
void applyFunctionalityOnList(List*ls,void(*ptf)(linkedListType* number)){

	Node*tmp1 = ls->head;
	Node*tmp2;

	while(tmp1){

		(ptf)(&(tmp1->data));
		tmp1 = tmp1->Next;
	}
}


/*

this function is used to insert a specifiec element at the position that will 
be provided by the user at the runtime.

*/

int insertValueAtSpecificPlace(List*ls,int insertionNumber,linkedListType*data){
	Node*tmp = ls->head;


	Node*newNode = (Node*)malloc(sizeof(Node));


	if(newNode){
		newNode->data = *data;
		if(insertionNumber == 1){
			newNode->Next = tmp;
			ls->head = newNode;
		}
		else{

			for(int i =1;i<insertionNumber-1;i++){

				tmp = tmp->Next;

			}

			newNode->Next = tmp->Next;

			tmp->Next = newNode;

		}

		ls->size++;
	}else{
		return -1;
	}

	return 1;
}



/*
this function is for inserting an element inside the linked list at a specific position 
that the user will provide .


i know it sounds confusing but if you as a user will provide aposition that would be 
bigger than half of the number of the elements use this one it is faster.
cause i am using the current pointer not to loop on the whole elements 
you can know the posisiton of the current pointer by using the function 
of  retCurrentPosition implemented before
*/

int insertValueAtSpecificPlace2(List*ls,int insertionNumber,linkedListType*data){
	Node*tmp = ls->head;


	Node*newNode = (Node*)malloc(sizeof(Node));
	int currentPosition = 1;
	if(newNode){


		if(insertionNumber == 1){
			newNode->Next = tmp;
			ls->head = newNode;
			ls->current = ls->head;
			//ls->currentPosition = 1;
		}
		else if(ls->currentPosition>insertionNumber){




					for(int i =ls->currentPosition;i<insertionNumber-1;i++){

						tmp = tmp->Next;
						currentPosition++;
					}

					newNode->Next = tmp->Next;
					ls->current = newNode;

					tmp->Next = newNode;




				ls->currentPosition = currentPosition;

		}
		else{

			ls->currentPosition = currentPosition=0;

			for(int i =1;i<insertionNumber-1;i++){

						tmp = tmp->Next;
						currentPosition++;
			}

					newNode->Next = tmp->Next;
					ls->current = newNode;

					tmp->Next = newNode;


		}

		ls->currentPosition = currentPosition;




	}


	return 1;

}




/*

this function is for knowing the current position that the new element will be inserted 
into if the user hasn't specified the position himself .
*/

int retCurrentPosition(List*ls){

	return ls->currentPosition;

}




/*
the first one for sorting linked list !

i did the hard way i didn't want to swap the values of the nodes , i wanted to swap 
the nodes themselves !

first i divided the problem into two different problems 
the first was to swap two elements 
the second was to do the sorting itself 
so i don't need to handle all the corner cases all at once 


*/
//bounus tasks !

static void swapTwoNodes(List*ls,Node*tmp1,Node*tmp2)
{

	


	Node* tmp3,*tmp4,*placeHolder;

	tmp4 = tmp2->Next;

	if(tmp1->Next!=tmp2)
	{
		tmp3 = tmp1->Next;
		//tmp3->Next = tmp1;
		tmp2->Next = tmp1->Next;
		tmp3->Next = tmp1;
		tmp1->Next = tmp4;
		
		

	}
	else
	{
		/* code */
		placeHolder = ls->head;
		if(placeHolder!=tmp1)
		{
			while(placeHolder->Next!=tmp1)
			placeHolder = placeHolder->Next;

		}
		
		tmp3 = placeHolder;
		tmp3->Next = tmp2;
		tmp2->Next = tmp1;
		tmp1->Next = tmp4;
	}
	
	


	

	
	//tmp1->Next = tmp4;
	if(tmp1 == ls->head)
	{
		ls->head = tmp2;
	}




}
/*
this function is used for sorting the linked list in ascending order only !

*/

void sortLinkedList(List*ls)
{


	Node* tmp,*tmp2,*tmp3,*tmp4 ;
	int size = returnLinkedListSize(ls);
	tmp = ls->head;
	tmp2 = tmp->Next;



	 for(int i =0;i<size-1;i++)
	 {
	 	//tmp = tmp->Next;
		for(int j =0;j<size-1-i;j++)
		{

			
			if((tmp->data)>(tmp2->data))
			{
				
				swapTwoNodes(ls,tmp,tmp2);
				tmp2 = tmp->Next;
				//printf("%d %d\n",j,tmp->data);
				 //break;
				

			}
			else
			{
				tmp2 = tmp2->Next;
			}
			
			
		
		
			
		

		 }
		 tmp=ls->head;
		 for(int k = 0;k<=i;k++)
		 {
			 tmp = tmp->Next;

		 }
		 tmp2 = tmp->Next;
	}


	return ;
	




}


/*

this upcoming function is to reverse the nodes of the linked list
i also didn't reverse the elemnts inside the list but what i did 
is to reverse the nodes themsleves

but once i implemented the the swap two nodes for linked list it became a 
peace of cake !


*/



void reverseLinkedList(List*ls)
{
	//printf("llllll\n")
	Node* tmp,*tmp2;
	int size = returnLinkedListSize(ls);
	tmp = ls->head;
	tmp2 = tmp->Next;
	//printf("%d\n%d\n",tmp->data,tmp2->data);


	for(int i = 0;i<size-1;i++)
	{

		for(int j=0;j<size-1-i;j++)
		{
			//printf("kkk]n");
			swapTwoNodes(ls,tmp,tmp2);
			tmp2 = tmp->Next;
			//break;
			
		}
		//traverseAllElementsFromList(ls);
		//break;
		tmp = ls->head;
		tmp2 = tmp->Next;
	}


}


/*


this function is to search for an elment inside the linked list and
returning the position of it inside the linked list
it returns -1 if it can't find that element inside the 
linked list .

*/

int searchLinkedList(List*ls,int element)
{


	Node* tmp = ls->head;
	int position = -1;


	int size = returnLinkedListSize(ls);

	for(int i = 0;i<size;i++)
	{
		if(tmp->data==element)
		{
			position = i;
		}
		tmp = tmp->Next;
	}

	return position;



}