#include<stdio.h>

#define MAX_SIZE 20

typedef struct{
	int element[MAX_SIZE];
	int front;
	int rear;
}queue; 

int isFull(queue q){
	if( (q.rear + 1) % MAX_SIZE == q.front )
		return 1;
	else
		return 0;

}


int isEmpty(queue q){
	if( q.rear == q.front)
		return 1;
	else
		return 0;	

}

int enqueue(queue *q, int i){
	if(isFull(*q)){
		printf("queue is full\n");
		return 0;
	}
	
	q->rear = (++ (q->rear) ) % MAX_SIZE;
	(q->element)[q->rear] = i;
	return 1;

}

int dequeue(queue *q){
	if(isEmpty(*q)){
		printf("queue is empty\n");
		return 0;
	}
	
	q->front = (++ (q->front) ) % MAX_SIZE;
	return 1;

}

int front(queue q){
	int f = (++ (q.front) ) % MAX_SIZE;
	return q.element[f];

}


int main(){
	
	queue q;
	q.front = 0;
	q.rear = 0;
	int i;
	for(i = 0; i < 20; i++){
		enqueue(&q, i);
		printf("!%d\n",q.rear);
		}
	printf("%d\n", front(q));
	dequeue(&q);
	printf("%d\n", front(q));
	for(i = 0; i<14; i++){
		dequeue(&q);
		printf("%d\n", front(q));
	}
	printf("%d\n", front(q));
	for(i = 0; i < 14; i++)
		enqueue(&q, i);
	printf("%d\n", front(q));
	for(i = 0; i<14; i++){
		dequeue(&q);
		printf("%d\n", front(q));
	}
	
	for(i = 0; i<14; i++){
		dequeue(&q);
		printf("%d\n", front(q));
	}
	
	return 0;
}

















