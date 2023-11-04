#include <iostream>

// Singly Linked List	
struct Node{
	int value;
	Node *next;
}*head = nullptr, *tail = nullptr;

int boundCheck() {
	int count = 0;
	Node *cur = head;
	while(cur != nullptr) {
		cur = cur->next;
		count++;
	}
	return count;
}
void pushHead(int val) {
	/*
		1. gaada linked list
		2. ada linked list
	*/
	if(head == nullptr) {
		Node *newNode = new Node;
		newNode->value = val;
		newNode->next = nullptr;
		head = tail = newNode;
	}else {
		Node *newNode = new Node;
		newNode->value = val;
		newNode->next = head;
		head = newNode;
	}
}
void pushTail(int val) {
	/*
		1. gaada linked list
		2. ada linked list
	*/
	if(head == nullptr) {
		pushHead(val);
	}else{
		Node *newNode = new Node;
		newNode->value = val;
		newNode->next = nullptr;
		tail->next = newNode;
		tail = tail->next;
	}
	
}
void pushMid(int val, int index = 1){
	if(head == nullptr) {
		pushHead(val);
		std::cout << "Linked list created!\n";
	}else if(index == 1) {
		pushHead(val);
	}else if(boundCheck() + 1 == index) {
		pushTail(val);
	}
	else if(index > 1 && index <= boundCheck()) {
		//	Traversing
		int count = 1;
		Node *cur = head;
		
		while(count < index - 1){
			cur = cur->next;
			count++;
		}
		Node *newNode = new Node;
		newNode->value = val;
		newNode->next = cur->next;
		cur->next = newNode;
		std::cout << "Added at index " << index << std::endl;	
	} else std::cout << "No Shit Found!" << std::endl;	
	
}
void print() {
	Node *cur = head;
	
	//	Traversing
	while(cur != nullptr){
		std::cout << cur->value << std::endl;
		cur = cur->next;
	}
}
int main() {
	pushHead(1);
	pushHead(2);
	pushTail(5);
	pushMid(4);
	print();
	
	std::cout << "jumlah linked list = " <<boundCheck() << std::endl;
	return 0;
}
