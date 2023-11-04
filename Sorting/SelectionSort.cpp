#include <iostream>
#include <time.h>

// Tugas Sorting
void insertRand(int *arr, int size) {
	for(int i = 0; i < size; i++) {
		arr[i] = rand() % 100 - 1;
	}
}
void insert(int *arr, int size) {
	for(int i = 0; i < size; i++) {
		std::cout << "index " << i << " = "; std::cin >> arr[i];
	}
}
void print(int *arr, int size) {
	for(int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
void swap(int *a, int *b) {
	*b += *a;
	*a = *b - *a;
	*b -= *a;
}
void selection(int *arr, int size) {
	for(int i = 0; i < size - 1; i++) {
		int min = i;
		for(int j = i + 1; j < size; j++) {
			if(arr[j] < arr[min]) {
				min = j;
			}
		}
		if(min != i) swap(&arr[min], &arr[i]);	// Digunakan ketika terjadi redundansi antara min dan index i
	}
	std::cout << "Selection Sorted!\n";
}
void insertion(int *arr, int size) {
	for(int i = 0; i < size - 1; i++) {
		for(int j = i + 1; j < size; j++) {
			if(arr[j] < arr[i]) swap(&arr[j], &arr[i]);
		}
	}
	std::cout << "Insertion Sorted!\n";
}
int main() {
	srand(time(0));
	int size, x = 1, input, opt;
	while(x != 0) {
		std::cout << "Input array size : "; std::cin >> size;
		int arr[size];
		
		std::cout << "Choose your input mode!\n1. Manual\n2. Random\n";
		std::cin >> input;
		if(input == 1) insert(arr, size);
		else if(input == 2) insertRand(arr, size);
		else {
			std::cout << "Invalid input!\ngain?\n0. No\n1. Yes"; std::cin >> x;
			continue;
		}
		std::cout << "Your data = "; print(arr, size);
		std::cout << "Select sort!\n1. Selection sort\n2. Insertion sort\n"; std::cin >> opt;
		if(opt == 1) {
			selection(arr, size);
			std::cout << "Ur new data = "; print(arr, size);
		} else if(opt == 2) {
			insertion(arr, size);
			std::cout << "Ur new data = "; print(arr, size);
		} else std::cout << "Invalid input!\n";
			
		std::cout << "Again?\n0. No\n1. Yes\n"; std::cin >> x;	
	}
	return 0;
}
