/* Bubble sort: 
large elements come to end by swapping with adjacents.

time complexcity 
*/
#include <iostream>
#include <algorithm >
using namespace std; 
void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " "; 
    }
    cout << endl; 
}


 
void bubbSort(int *arr, int n){
	for (int i=0; i<n; i++){
	//	bool isSwap = false;  if array {1,2,3,4,5};
	// cout << "swap" << endl;  // runs one time 
		for(int j = 0; j<n-i-1; j++){
		// cout << "is bool" << endl; runs after swap until the end 
				if (arr[j] > arr[j+1]){
					swap(arr[j], arr[j+1]);
				//	isSwap = true; 
				}		
		}
	}
	print(arr, n);
}
// O(n*log n) is better than O(n^2) 
void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    print(arr, n);
}

void insertionSort(int arr[], int n){
	for (int i=1; i<n; i++){
		int curr = arr[i]; 
		int prev = i-1;
		while(prev >= 0 && arr[prev] > curr){
			swap(arr[prev], arr[prev + 1]); 
			prev--;
		}
		arr[prev + 1] = curr;
	}
	print (arr, n); 
}

void countSort(int  arr[], int n){
	int freq[1000] = {0}; // range
	int minVal = INT_MAX, maxVal = INT_MIN; 
	for(int i=0; i<n; i++){
		minVal = min(minVal, arr[i]);
		maxVal = max(maxVal, arr[i]); 
	}
	cout << maxVal << " " << minVal << endl; 
	// 1st step - O(n)
	for (int i = 0; i<n; i++){
		freq[arr[i]]++; 
	}
	
	// 2nd step - O(range) - max-min
	for(int i = minVal, j=0; i<=maxVal; i++){
		while(freq[i] > 0){
		arr[j++] = i; 	
		freq[i]--; 
		}
	}
	print(arr, n);
}
int main (){
//	int arr[5] = {5,4,1,3,2};
	int arr[8] = {1,4,1,3,2,4,3,7};
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10} ;// 0 (1, 1) 
//	bubbSort(arr, 5); 
//	selectionSort(arr, 5); 
//	insertionSort(arr, 5); 
	countSort(arr, 8);
	return 0; 
}


