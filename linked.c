#include<stdio.h>
#include<stdlib.h>


typedef struct node{

	
	int value;
	struct node *next;

}node;

typedef struct linkedlist{
	struct node *head;
	struct node *tail;

}linkedlist;

int insert(linkedlist *list, int value);
int delete(linkedlist *list, int value);
void printlist(linkedlist l);


int main(){

	linkedlist l;
	l.head = NULL;
	l.tail = NULL;
	insert(&l,1);
	printf("l head: %d\n", (l.head)->value);
	insert(&l,0);
	insert(&l,2);
	insert(&l,5);
	insert(&l,4);
	printf("%d\n",delete(&l, 5));
	printf("l head: %d\n", ((l.head)->value));
	printf("l head next %d\n",l.head->next->value);
	printlist(l);
	printf("tail of the list: %d\n",l.tail->value);
	


	return 0;
}




int insert(linkedlist *list, int val){

	node *new = (node *)malloc(sizeof(node));
	new->next = NULL;
	new->value = val;
	if(list->head == NULL){
		list->head = new;
		list->tail = new;		
		return 0;
	}
	node *before = list->head;
	node *after = before ->next;
	if(val < before->value){
		new->next = before;
		list->head = new;
		return 0;
	}
	while (after != NULL){
		if(val < after->value){
			
			new->next = after;
			before->next = new;
			return 0;
		}
		else{
			after = after->next;
			before = before->next;
		}

		
	}
	before->next = new;
	list->tail = new;
	return 0;
}


int delete(linkedlist *l, int val){
	if(!l->head){
		printf("no element in list\n");
		return 0;
	}
	node *before = l->head;
	node *current = before->next;
	if(before->value == val){
		free(l->head);
		l->head = current;
		return 1;
	
	}
	for(;current;before = before->next, current = current->next){
		if(current->value == val){
			if(!current->next)
				l->tail = before;
			before->next = current->next;
			free(current);
			return 1;
		}
	
	}	




	return 0;
}

void printlist(linkedlist l){

	struct node *element = (node *)l.head;
	printf("my linked list is:");
	for(;element;element = element->next){
		printf(" %d",element->value);
	}
	printf("\n");




}












