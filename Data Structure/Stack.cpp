#include <iostream>

//	PERBAIKI INDENTASINYA

struct Node {
	int val;
	Node *next, *prev;
};
struct Stack {
	int value;
	Stack *link;
};
Stack *create(int val) {
	Stack *newStack = new Stack;
	newStack->value = val;
	newStack->link = nullptr; 
	return newStack;
}
void push(Stack **top, int val) {
	if((*top) == nullptr) {
		(*top) = create(val);
		std::cout << "Stack Added Capt!" << std::endl;
	} else {
		Stack *newStack = create(val);
		newStack->link = (*top);
		(*top) = newStack;
		std::cout << "Top Added Capt!" << std::endl;
	}
}
void pop(Stack **top) {
	if((*top) == nullptr) std::cout << "Nothing to delete here Capt!" << std::endl;
	else {
		if((*top)->link == nullptr) {
			delete (*top);
			(*top) = nullptr;
			std::cout << "Stack cleared Capt!" << std::endl;
		} else {
			Stack *del = (*top);
			(*top) = (*top)->link;
			del->link = nullptr;
			delete del;
			std::cout << "Done Capt!" << std::endl;
		}
	}
}
void init(Stack **top) {
	if((*top == nullptr)) {
		std::cout << "Nothing to init btw :/" << std::endl;
	}else if((*top)->link == nullptr){
		delete(*top); (*top) = nullptr;
	} else {
		Stack *del, *cur = (*top);
		do {
			// Config
			del = cur;
			cur = cur->link;
			
			// Untied
			del->link = nullptr;
			
			//	Trashed
			delete del;		
		} while(cur != nullptr); 
		(*top) = nullptr;
	}
	std::cout << "Initialized Capt!" << std::endl;
}
void printStack(Stack **top) {
	if((*top) == nullptr){
		std::cout << "No Stack Found!" << std::endl;	
	} else {
		Stack *cur = (*top);
		while(cur != nullptr) {
			std::cout << cur->value << std::endl;
			cur = cur->link;
		}	
	}
}
void sort(int **top) {
	
	Stack *topTemp = nullptr;
	int temp = (*top)->val;
	
	while((*top) != nullptr) {
		if(cur->val > temp) {
			
			// Popped out first element
			int temp = (*top)->val;
			pop((*top));
		}
		while(topTemp != nullptr && topTemp->value > temp) {
			
			// pop from temporary stack and push
            // it to the input stack
            push((*top), topTemp->value);
            pop(topTemp);
		}  
        push(topTemp, temp);
	}
}
int main() {
	Stack *top = nullptr;

	printStack(&top);
	push(&top, 10);
	push(&top, 9);
	push(&top, 8);
	push(&top, 7);
	push(&top, 6);
	printStack(&top);
	
	pop(&top);
	pop(&top);
	pop(&top);
	printStack(&top);	
	init(&top);
	printStack(&top);
	
	return 0;
}
