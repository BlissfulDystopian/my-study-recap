#include <stdio.h>
/*
	Bagaimana ini bekerja?
	-	By default top bervalue -1 (artinya stack masih kosong)
	-	Push() bekerja memasukkan value dari index terakhir ke index pertama
	-	Pop() bekerja sebaliknya
	-	display() bekerja dari index top hingga menemukan nilai NULL ('\0') 
*/	
void push(char element, char *stack, int *top, int stackSize) {
	if(*top == -1) {
		stack[stackSize - 1] = element;  		
		*top = stackSize - 1;
	} else if(*top == 0) {
		//	When top == 0 (Stack is Full)	
  		printf("The stack is already full. \n");
 	} else {
		stack[(*top) - 1] = element;
  		(*top)--; // Top decremented
 	}
}
void pop(char *stack, int *top, int stackSize) {
	if(*top == -1) {
   		printf("The stack is empty. \n");
 	} else {
		// informing where the element was poped!
  		printf("Element popped: %c \n", stack[(*top)]);
  		// If the element popped was the last element in the stack
  		// then set top to -1 to show that the stack is empty
		if((*top) == stackSize - 1) {	
			stack[stackSize - 1] = '\0';
    		(*top) = -1; //	Where in the fuuckin world
  		} else {	
			stack[(*top)] = '\0';
    		(*top)++;
  		}
 	}
}
void display(char *stack, int *top) {
	int cur = (*top);
	printf("Stack Element : \n");
	while(stack[cur] != '\0') {
		printf("%c %d\n", stack[cur], cur);
		cur++;
		
	}
}
int main()
{
  	int stackSize = 4;
  	char stack[stackSize] = {NULL};
  	
	  // A negative index shows that the stack is empty
  	int top = -1;
  
  	push('a', stack, &top, stackSize);
  	push('b',stack, &top, stackSize);
	pop(stack, &top, stackSize);
	
  	push('d',stack, &top, stackSize);
  	push('c',stack, &top, stackSize);
 
	pop(stack, &top, stackSize);     
	pop(stack, &top, stackSize);          
  	pop(stack, &top, stackSize);     
  	pop(stack, &top, stackSize);     	  
  
 	display(stack, &top);	
	return 0;
}