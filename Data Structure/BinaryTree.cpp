#include <iostream>


/*
	Binary tree (tree that has max two children on each parents)
	
	Types :
	
		1. Full binary tree
			each parents have 2 childs or haven't child
			
		2. Complete Binary Tree
			All must have left children except latest generation
		
		3. Perfect Binary Tree
			Every node has exactly 2 nodes and all leaf node are at the same level 
		
		4. Skewed Binary Tree
			Dominated by left or right
		
		5. Balanced Binary Tree
			left child and right child are the same height

	Traversal
		- Inorder traversal (Left, root, right) A
		- Preorder traversal (root, left, right) L
		- Postorder traversal	(left, right, root) _I
*/
struct Node {
	char val;
	Node *left, *right;
};
Node *create(char value) {
	Node *newNode = new Node;
	newNode->val = value;
	newNode->left = newNode->right = nullptr;
	
	return newNode;
}
void printInorder(Node* node) {
	if(node == nullptr) return;
	
	printInorder(node->left);
	
	std::cout << node->val << " ";
	
	printInorder(node->right);
} 

void printPreorder(Node* node) {
	if(node == nullptr) return;
	
	std::cout << node->val << " ";
	
	printPreorder(node->left);
	
	printPreorder(node->right);
} 

void printPostorder(Node* node) {
	if(node == nullptr) return;
	
	printPostorder(node->left);
	
	printPostorder(node->right);
	
	std::cout << node->val << " ";
} 

void height(Node *node, int* count) {
	*count++;
	height(node->left, count);
	std::cout << "height = " << *count << std::endl;
}
int main() {
	int count = 0;
	Node *root = create('G');
	root->left = create('D');
	root->right = create('H');
	root->left->left = create('E');
	root->left->right = create('F');
	root->right->left = create('A');
	
	printInorder(root);
	
	std::cout << "\n";
	
	printPreorder(root);
	
	std::cout << "\n";
	
	printPostorder(root);
	
	std::cout << "\n";
	
	height(root, &count);
	
	std::cout << "\nroot : "<< root->val << " \n" << "root->left : "<< root->left->val << " \n" << std::endl;
	std::cout << "root->right : "<< root->right->val << " \n" << "root->left->left : "<< root->left->left->val << " \n" << std::endl;
	return 0;
}
