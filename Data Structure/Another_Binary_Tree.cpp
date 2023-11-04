#include <iostream>

//	Binary tree
struct Node {
	int val;
	struct Node *left, *right, *parent;
};
//	Buat binary tree baru
Node *create(int value) {
	Node *newNode = new Node();
	newNode->val = value;
	newNode->left = newNode->right = newNode->parent = nullptr;
	return newNode;
}
void createTree(Node **root, int value) {
	if((*root) != nullptr) std::cout << "Tree Sudah dibuat!\n";
	else {
		(*root) = create(value);
		std::cout << "Binary Tree berhasil dibuat!\n";
	}
}
//	Inserting
void insertLeft(Node **root, int value) {
	if((*root) == nullptr) createTree(&(*root), value);	
	else {
		
		if ((*root)->left != nullptr) std::cout << "Sudah ada anak kiri!\n";
		else {
			Node *newNode = create(value);
			newNode->parent = (*root);
			(*root)->left = newNode;
		}
	}
}
void insertRight(Node **root, int value) {
	if((*root) == nullptr) createTree(&(*root), value);	
	else {
		if((*root)->right != nullptr) std::cout << "Sudah ada anak kanan!\n";
		else {
			Node *newNode = create(value);
			newNode->parent = (*root);
			(*root)->right = newNode;
		}
	}
}

//	untuk  mengosongkan binary tree
void clear();

//	mengecek apakah kosong atau tidak
void empty();

//	mencari root, parent, left childm atau right child (tree != null)
void find();

//	untuk mengubah isi node yang ditunjuk oleh pointer curr (tree != null)
void update();

//	mengetahui isi node
void retrieve();

//	menghapus subtree
void deleteSub();

//	mengetahui karakteristik tree
void characteristic();

//	mengunjungi seluruh node pada tree
void transverse();

int main() {
	struct Node *root = nullptr;
	insertRight(&root, 10);
	insertLeft(&root, 5);
	insertRight(&root, 4);
	insertLeft(&root, 6);
	insertRight(&root, 3);
	std::cout << root->val << " "<< root->left->val << " " << root->right->val<< std::endl;
	
	return 0;
}
