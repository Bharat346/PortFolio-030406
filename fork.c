#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void InsertAtFirst(struct Node* *head,int element){
	struct Node* elem = (struct Node*)malloc(sizeof(struct Node));
	elem->data = element;
	elem->next = *head;
	*head = elem;
}

void InserAtIndex(struct Node* *head,int index,int element){
	struct Node* elem = (struct Node*)malloc(sizeof(struct Node));
	int i = 0;
	struct Node* ptr = *head;
	while (i != index-1)
	{
       ptr = ptr->next;
	   i++;
	}
	elem->data = element;
	elem->next = ptr->next;
	ptr->next = elem;
}

void InsertAtEnd(struct Node* *head,int element){
	struct Node* elem = (struct Node*)malloc(sizeof(struct Node));
	int i = 0;
	struct Node *ptr = *head;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	elem->data = element;
	elem->next = NULL; 
    ptr->next = elem;
}

void deleteFirst(struct Node* *head){
	struct Node* ptr = *head;
	*head = (*head)->next;
	free(ptr);
}

void deleteAtIndex(struct Node** head,int index){
	struct Node* ptr = *head;
	struct Node* q = (*head)->next;
	for (int i = 0; i < index - 1; i++)
	{
		ptr = ptr->next;
		q = q->next;
	}
	ptr->next = q->next;
	free(q);
}

void deleteLastNode(struct Node** head){
	struct Node* ptr = *head;
	struct Node* q = (*head)->next;
	while (q->next != NULL)
	{
		ptr = ptr->next;
		q = q->next;
	}
	ptr->next = NULL;
	free(q);
	
}

void deleteByValue(struct Node** head , int value){
	struct Node* ptr = *head;
	struct Node* q = (*head)->next;
	while (q->data != value && q->next != NULL)
	{
		ptr = ptr->next;
		q = q->next;
	}

	if (q->data == value)
	{
		ptr->next = q->next;
		free(q);
	}
}

int main()
{
	struct Node *head;
	struct Node *Second;
	struct Node *Third;
	struct Node *Fourth;
	struct Node *Fifth;

	head = (struct Node*)malloc(sizeof(struct Node));
	Second = (struct Node*)malloc(sizeof(struct Node));
	Third = (struct Node*)malloc(sizeof(struct Node));
	Fourth = (struct Node*)malloc(sizeof(struct Node));
	Fifth = (struct Node*)malloc(sizeof(struct Node));
	head->data = 7; head->next = Second;
	Second->data = 10; Second->next= Third;
	Third->data = 4; Third->next = Fourth;
	Fourth->data = 13 ; Fourth->next = Fifth;
	Fifth->data = 21 ; Fifth->next = NULL;

    //InsertAtFirst(&head,99);
	//InserAtIndex(&head,2,99);
	//InsertAtEnd(&head,99);

	//deleteFirst(&head);
	//deleteAtIndex(&head,2);
	//deleteLastNode(&head);
	deleteByValue(&head,13);

	struct Node* current = head;
	while (current != NULL)
	{
		printf("%d\t%ld\n",current->data,&(current->data));
		current = current->next;
	}
	
	
	return 0;
}
