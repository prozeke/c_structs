#include<stdio.h>
#include<stdlib.h>
//#define	 MAX_STACK_SIZE 65

typedef struct{
	char *element;
	int max_size;
	int top;

}stack;

int isEmpty(stack s){
	if (s.top == -1)
		return 1;
	else
		return 0;

}

void push(stack *s , char c){
	if(s->top != s->max_size - 1){
		s->top++;	
		s->element[s->top] = c;
	}
	else
		printf("max stack size reached\n");
	

}

char pop(stack *s){
	if(!isEmpty(*s)){
		char c = (*s).element[(*s).top];
		(*s).top--;
		return c;
	}
	else{
		printf("stack is empty!!\n");
		return -1;
	}

}

char top(stack s){
	if(s.top != -1)
		return s.element[s.top];
	else
		printf("stack is empty\n");

}


int main(){

	stack eChar;
	eChar.top = -1;
	eChar.max_size = 3;
	eChar.element = (char *)malloc(sizeof(char) * eChar.max_size );
	push (&eChar , 'a');
	push (&eChar , 'b');
	push (&eChar , 'c');
	printf("%c\n", top(eChar));
	while(eChar.top != -1){
		printf("%c\n" , pop(&eChar) );
	
	
	}
	printf("%d\n", eChar.max_size );




}
