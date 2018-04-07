#include<stdio.h>
#include<stdlib.h>

typedef struct node{

	int data;
	struct node *next;

}node;

typedef struct queue{
	struct node *head;
	struct node *tail;
}queue;

node* initNode(int x);
queue* initQueue();
void enqueue(queue *q, int data);
int dequeue(queue *q);
void display(queue q);

int main(){
	queue *q = initQueue();
	enqueue(q,0);
	display(*q);
	printf("%d\n",dequeue(q));
	enqueue(q,0);
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	display(*q);	
	printf("%d\n",dequeue(q));
	display(*q);
	printf("%d\n",dequeue(q));
	display(*q);
	return 0;

}


queue* initQueue(){

	queue *new = (queue *)malloc(sizeof(queue));
	new->tail = NULL;
	new->head = NULL;
	return new;

}

node* initNode(int x){

	node *new = (node *)malloc(sizeof(node));
	new->data = x;
	new->next = NULL;
	return new;


}

void enqueue(queue *q, int data){
	node *new = initNode(data);
	if(q->head == NULL){
		q->head = new;
		q->tail = new;
		return;
	}
	q->tail->next = new;
	q->tail = new;
	return;

}

int dequeue(queue *q){
	int data;
	if(q->head == NULL){
		printf("queue is empty\n");
		return -1;
	}
	
		node *del = q->head;
		data = del->data;
		q->head = q->head->next;
		if(q->head == NULL)
			q->tail = NULL;
		free(del);
		return data;
}


void display(queue q){
	if(q.head == NULL){
		printf("queue is empty\n");
		return;
	}
	node *first = q.head;
	while(first){
		printf("%d ",first->data);
		first = first->next;
	}
	printf("\n");
	return;
}





























