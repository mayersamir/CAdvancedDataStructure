#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


#define linkedListType     int
	
	typedef struct node{
		linkedListType data;
		struct node*Next;


	}Node;


	typedef struct Linkedlist{

		Node*head;
		Node*current;
		int size;
		int currentPosition;
	}List;

	void linkedListInitialize(List*ls);

	int listInsertion(List*ls,linkedListType* data);

	linkedListType returnSpecificElement(List*ls,int*elementNumber);

	linkedListType traverseSpecificElement(List*ls,int*elementNumber);

	void traverseAllElementsFromList(List*ls);

	int returnLinkedListSize(List*ls);

	void deleteList(List*ls);

	void applyFunctionalityOnList(List*ls,void(*ptf)(linkedListType* number));


	int insertValueAtSpecificPlace(List*ls,int insertionNumber,linkedListType*data);

	int insertValueAtSpecificPlace2(List*ls,int insertionNumber,linkedListType*data);


	int retCurrentPosition(List*ls);



	void sortLinkedList(List*ls);

	void reverseLinkedList(List*ls);
	
	int searchLinkedList(List*ls,int element);


#endif
