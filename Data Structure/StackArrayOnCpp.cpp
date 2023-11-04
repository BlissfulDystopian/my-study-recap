#include <iostream>

void push(char val, char *stack, int *top, int stackSize) {
	if((*top) == -1) {
		stack[stackSize - 1] = val;
		*top = stackSize - 1;
	} else if ((*top) == 0) {
		std::cout << "Stack is Full!\n";
	} else {
		stack[(*top) - 1] = val;
		(*top)--;
	}
}
void pop(char *stack, int *top, int stackSize) {
	if(*top == -1) {
		std::cout << "Stack is Empty!\n";
	} else {
		std::cout << "Element Popped : " << stack[*top] << "\n";
		if(*top == stackSize - 1) {
			stack[stackSize - 1] = '\0';
			*top = -1;
		} else {
			stack[*top] = '\0';
			(*top)++;
		}
	}	
}
void display(char *stack, int *top) {
	int cur = (*top);
	std::cout << "Stack Element : \n";
	while(stack[cur] != '\0') {
		std::cout << stack[cur] << "\n";
		cur++;	
	}
}
int main() {
	int stackSize = 4;
	char stack[stackSize] = {'\0'};
	int top = -1;
	
	push('a', stack, &top, stackSize);
  	push('b',stack, &top, stackSize);
  	push('c',stack, &top, stackSize);
  	push('d',stack, &top, stackSize);
	push('e',stack, &top, stackSize);
	
	display(stack, &top);	
	
	pop(stack, &top, stackSize);
	pop(stack, &top, stackSize);     
	pop(stack, &top, stackSize);          
  	
	display(stack, &top);	
	
	pop(stack, &top, stackSize);     
  	pop(stack, &top, stackSize);     	  
	pop(stack, &top, stackSize);     	  
 	display(stack, &top);	
  
	return 0;
}
