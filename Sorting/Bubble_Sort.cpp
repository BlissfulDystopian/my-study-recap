#include <iostream>

//	Bubble sort

void sort(int *arr, int size) {
	for(int i = 0; i < size; i++) {
	 	for(int j = 0; j < size; j++) {
			if(i == j) continue;
			if(arr[i] < arr[j]) {
				arr[j] += arr[i];
	 		    arr[i] = arr[j] - arr[i];
				arr[j] -= arr[i];	
			}	 
		}
	}
}
void print(int *arr, int size) {
	for(int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	} 
	std::cout << "\n";  
}
int main() {
	int size = 10, arr[size] = {10, 16, 3, 4, 2, 60, -2, 33, 21, -5};
	
	print(arr, size);
	sort(arr, size);
	print(arr, size);
	
	return 0;	
}
// a = 2     1. a = a + b   (6)
// b = 4     2. b = a - b   (2)
//			 3. a = a - b