// CH : 26 : Devide & Conquer: 
// Q. MERGE SORT : 
/*
#include <iostream>
#include <vector>
using namespace std; 
void merge(int arr[], int si, int mid,int ei){ // parameter follow from call function 
	 vector<int> temp; 
	 int i = si;
  	 int j = mid+1; 
  	 
  	 while(i <= mid && j <= ei){
  	 	if(arr[i] <= arr[j]){
  	 		temp.push_back(arr[i++]);
	   }else{
	 	 	 temp.push_back(arr[j++]);
	   }
  }
  
  while(i<=mid){
  	temp.push_back(arr[i++]);
  }
  while(j <= ei){
  	temp.push_back(arr[j++]); 
  }
  
  // vector --> original arr
  for(int idx=si, x=0;	idx<=ei; idx++){
  	arr[idx] = temp[x++];
  }
	
}
void mergeSort(int arr[], int si, int ei){ // O(n logn) 
	if(si >= ei){
		return ; 
	}
	
	int mid = si + (ei - si)/2; 
	
	mergeSort(arr, si, mid); 
	mergeSort(arr, mid+1, ei); 
	
	merge(arr, si, mid, ei); // conquer
	
 // conquer : do choti problem ke sol a gaye 
// Ab badi problem ka solution solve karna hai 
	
}

void printArr(int arr[], int n){ 
	for(int i=0; i<n; i++){
		cout << arr[i] << " "; 
	}
	cout << endl; 
}
int main(){
	int arr[6] = {6, 3, 7, 5, 2, 4};
	int n = 6; 
	
	mergeSort(arr, 0, n-1); 
	printArr(arr, n); 
	return 0; 
}
*/ 

/*Q.2: Quick Sort:  three main steps 
	   - 1 : Select pivot(most cases select last index
	   - 2 : Devide Left - QS & Right - Qs:  
	   - 3 : Partition : (arr, si, ei) : pivot = arr[ei] : i = si-1:
*//*
#include <iostream >
using namespace std; 


int partition(int arr[], int si, int ei){
	int i = si-1; 
	int pivot = arr[ei]; 
	
	for (int j=si; j<ei; j++){ 
		if(arr[j] <= pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	
	i++; 
	swap(arr[i], arr[ei]); 
	
	//pivotIdx = i
	return i; 
}
void quickSort(int arr[], int si, int ei){ // O(n * logn) average TC : 
	if (si >= ei){
		return; 
	}
	int pivotIdx = partition(arr, si, ei);
	
	quickSort(arr, si, pivotIdx-1); // left half
	quickSort(arr, pivotIdx+1, ei); // right half
} 
void printArr(int arr[], int n){
	for(int i =0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl; 
}
int main (){
	int arr[6] = {6, 3, 7, 5, 2, 4}; 
	int n = 6; 
	
	quickSort(arr, 0, n-1); 
	printArr(arr, n); 
	return 0; 
}
Quick Sort: Worst Case TC how Become : O(N^2)
*This omplexity occurs when repeatedly the smallest or
 The largest element of the array becomes the pivot. 
*/ 
/* Q. 3: Search in Roatated Sorted : 
input roatated, sorted array with distinct nums ascending order 

- find index of target = 0: 
*//*

#include <iostream>
using namespace std; 
int search(int arr[], int si, int ei, int tar){
	if(si > ei){
		return -1; 
	}
	int mid = si + (ei - si)/2; 
	if(arr[mid] == tar){
		return mid; 
	}
	if(arr[si] <= arr[mid]){ //L1 
       if(arr[si]<= tar && tar <= arr[mid]){
       	//left half
       	return search(arr, si, mid-1, tar); 
	   }else{
	   	//right half
	   	return search(arr, mid+1, ei, tar); 
	   }
	}else{
		//L2
		if(arr[mid]<= tar && tar <= arr[ei]){
			//right half
			return search(arr, mid+1, ei, tar); 
		}else{
			//left half
			return search(arr, si, mid-1, tar); 
		}
	}
}
int main (){ 
	int arr[7] = {4, 5, 6, 7, 0, 1, 2}; 
	int n = 7; 
	
	cout << "idx: " << search(arr, 0, n-1, 0) << endl; // O/p : 4
	return 0; 
}
*/ 


// Assignment Questions :
/*Q. 1: Apply Merge sort to sort an array of Strings.(Assume that
	all the characters in	all	the	Strings	are	in lowercase).(EASY)
*//*
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Merge function : 
void merge(vector<string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Merge Sort function
void mergeSort(vector<string>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    vector<string> arr = {"sun", "earth", "mars", "mercury"};

    mergeSort(arr, 0, arr.size() - 1);

    for (const auto& str : arr)
        cout << str << " ";
    cout << endl;

    return 0;
}

*/
/*Q2. : Given An array nums of size n, return the majority element. 
   - The majority elements is the element that appears more than Ln / 2L times. 
   	 YOu may assume that the majority element exists in the array 
*/ /*
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> counts;
    int majority_count = nums.size() / 2;
    
    for (int num : nums) {
        counts[num]++;
        if (counts[num] > majority_count) {
            return num;
        }
    }
    return -1; // 
}*/
//Boyer-Moore Voting Algorithm
/* 
int majoElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

int main() {
    vector<int> nums = {3, 2, 3};
      vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << majorityElement(nums2) << endl;
    cout << "Majority Element:Boyer-Moore " << majoElement(nums) << endl;
    return 0;
}
*/ 
/*
Q.3 : inversion count basically yw batata hai ki array sorted hone se kitna 
dur hai. agar array already sorted hai, to inversion count 0 hoga.
array reverse sorted hai matlab maximum inversions hai to count sabse jyada
hoga. 
do elements a[i] aur a[j] inversion banate hai agar: 
1. a[i] > a[j] 
2. i < j 
*/ 

#include <iostream> 
#include <vector>
using namespace std; 
// function to merge two halves and count inversions 

int mergeAndcount(vector<int>& arr, int left, int mid, int right){
	int n1 = mid - left + 1; 
	int n2 = right - mid; 
	vector<int> leftArr(n1); 
	vector<int> rightArr(n2); 
	
	for(int i = 0; i < n1; i++)
	    leftArr[i] = arr[left + i]; 
    for(int j = 0; j < n2; j++)
  		rightArr[j] = arr[mid + 1 + j]; 
	
	int i = 0, j = 0, k = left; 
	int invCount = 0; 
	
	while (i < n1 && j < n2){
		if (leftArr[i] <= rightArr[j]){
			arr[k++] = leftArr[i++]; 
		}else{
			arr[k++] + rightArr[j++];
			invCount += (n1 - i); // count inversions
		}
	}
	
	while(i< n1){ 
 	   arr[k++] = leftArr[i++]; 
	}
	
	while(j<n2){
		arr[k++] = rightArr[j++];
	}
	return invCount; 
}

// Function to implement merge sort and count inversions 
int mergeSortAndCount(vector<int>& arr, int left, int right){
	int invCount = 0; 
	if (left < right){
		int mid = left + (right - left)/2; 
		
		invCount += mergeSortAndCount(arr, left, mid);
		invCount += mergeSortAndCount(arr, mid + 1, right); 
		invCount += mergeAndcount(arr, left, mid, right);
	}
	return invCount; 
}
int main (){
	vector<int> arr = {2, 4, 1, 3, 5}; 
	int n = arr.size(); 
	
	int invCount = mergeSortAndCount(arr, 0, n - 1); 
	cout << "number of inversions are: "<< invCount << endl; 
	
	return 0; 
}
