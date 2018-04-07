#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int data;
	struct node *next;
}node;

void push(node **stack,int add);
int pop(node **stack);
void display(node *stack);
node* initNode(int x);




int main(){
	node *stack = initNode(0);
	display(stack);
	printf("\n");
	printf("popped %d\n",pop(&stack));
	display(stack);
	return 0;
}

node* initNode(int x){

	node *new = (node *)malloc(sizeof(node));
	new->data = x;
	new->next = NULL;
	return new;


}

void push(node **stack, int add){
	node *new = initNode(add);
	if(stack == NULL){
		*stack = new;
		return;
	} 
	
	new->next = *stack;
	*stack = new;
	return;
}

int pop(node **stack){
	int data;
	if(*stack == NULL){
		printf("stack is empty\n");
		return -1;
		
	}
	node *del = *stack;
	*stack = (*stack)->next;
	data = del->data;
	free(del);
	return data;
}



void display(node *stack){

	if(stack == NULL){
		printf("stack is empty\n");
		return;
	}
	if(stack->next == NULL){
		printf("%d ",stack->data);
		return;
	}
	display(stack->next);
	printf("%d ",stack->data);
	return;
}


















