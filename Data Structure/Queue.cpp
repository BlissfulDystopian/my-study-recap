#include <iostream>


//	Queue (Last in First out)
struct Node {
	int val;
	Node *next, *prev;		
};
Node *create(int value) {
	Node *newNode = new Node;
	newNode->val = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;	
	return newNode;	
}
void push(Node **head, Node **tail, int value) {
	if((*head) == nullptr) {
		(*head) = create(value);
		(*tail)	= (*head);
	} else {
		Node *newNode = create(value);
		newNode->next = (*head);
		(*head)->prev = newNode;
		newNode->prev = nullptr;
		(*head) = newNode;
	}
}
void pop(Node **head, Node **tail) {
	if((*head == nullptr)) std::cout << "Nothing to pop!\n";
	else if((*head) == (*tail)) {
		delete (*head);
		(*head) = (*tail) = nullptr;
	} else {
		Node *del = (*tail);
		(*tail) = (*tail)->prev;
		delete del;
		(*tail)->next = nullptr;
	}
}
void display(Node **head){
	Node *cur = (*head);
	while(cur != nullptr) {
		std::cout << cur->val << " ";
		cur = cur->next;
	}
	std::cout << "\n";
}
void back(Node **tail){
	Node *cur = (*tail);
	while(cur != nullptr) {
		std::cout << cur->val << " ";
		cur = cur->prev;
	}
	std::cout << "\n";
}


int main() {
	Node *head = nullptr, *tail = nullptr;
	
	
	
	pop(&head, &tail);
	
	display(&head);
	back(&tail);
	return 0;
}
