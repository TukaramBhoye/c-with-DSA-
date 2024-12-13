/* Dynamic Memory Allocation :


#include <iostream>
using namespace std; 
int main (){
//	int arr[100] = {1, 2, 3, 4, 5}; 
	int size; 
	cin >> size; 
//		delete but Not delete in stac we have to delete : Memory leak problem 
//		 |		|
	int *arr = new int[size];// new : uae to allocate new memory 
	int x = 1;  
	for(int i = 0; i < size; i++){
		arr[i] = x;
		cout << arr[i] << " "; 
		x++; 
	}
	cout << endl; 
	return 0; 
}
//- in this demo how allocate memory, access it , or print it

#include <iostream>
using namespace std; 
void func(){ 
// Static Memory Allocation : which is fixed constant 
	 int arr[100] = {1, 2, 3, 4, 5};
	 for(int i=0; i<5; i++){
	 	cout << arr[i] << " "; 
	 }
}
int main (){
	func(); 
	return 0; 
}
*/
 /*
#include <iostream>
using namespace std; 
void func(){ // DyNamic Memory Allocation 
	 int *ptr = new int; 
	 *ptr = 5; 
	 cout << *ptr << endl; 
	 
	 delete ptr;// if we use NEW here so important to delete memory address 
}
void funInt(){
	int size ; 
	cin >> size ; 
	int *ptr = new int[size]; 
	
	int x = 1; 
	for(int i=0; i<size; i++){
		ptr[i] = x; 
		cout << ptr[i] << " "; 
		x++;  
	}
	cout << endl; 
	delete [] ptr; 
}
int main (){
	func(); 
	funInt(); 
	return 0; 
}
**2D Dynamic Array */ /*

#include <iostream>
using namespace std; 
int main (){
	int rows, cols ; 
	cout << "enter rows : "<< endl ; 
	cin >> rows ; 
	cout << "Enter cols: "<< endl ; 
	cin >> cols; 
	// integer ptrs ko point karta hua array 
	int **matrix = new int*[rows]; 
	for(int i = 0; i<rows; i++){
		//ptr : point new int of cols 
		//har row ke liye individual cols ke barabar ham memory allocate kar rahe hai 
		matrix[i] = new int[cols];
		 
	}
	int x = 1; 
	for (int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++ ){
			matrix[i][j] = x++; 
			cout << matrix[i][j] << " "; 
		}
		cout << endl; 
	}
	cout << matrix[2][2] << endl; // both are same 
	cout << *(*(matrix + 2)+2) << endl; 
}
*//*
#include <iostream>
using namespace std; 
int main (){
	int x = 5; 
	int *ptr = &x;
	cout << ptr << " "<< endl; 
	cout<< *ptr << endl; 
return 0; 
}
*/
/* vector -------------------
#include <iostream> 
#include <vector> 
using namespace std; 
int main (){
	vector <int> vec1 = {1,2,3,4}; 
	cout << vec1.size() << "\n"; 
	
	vector <int> vec2(10, -1); 
	
	for (int i = 0; i<vec2.size(); i++){
		cout << vec2[i] << " ";
//		in array internal conversion like  vec1[i] ----> *(vec1+1)
	}
	return 0;  
}*/ /*

#include <iostream> 
#include <vector> 
using namespace std; 
int main (){
	vector <int> vec = {1,2,3,4}; 
	cout << "size: " << vec.size() << endl; 
	cout << "Capacity: "<< vec.capacity() << endl; 
	
	vec.push_back(4);// add new element in vec
	cout << "size: "<< vec.size() << endl; 
	cout << "capacity: " << vec.capacity() << endl; 
	
	vec.pop_back(); // use to delete 
	return 0;  
}

*//*
**Pair Sum : 
#include <iostream>
#include <vector>
using namespace std; 
vector<int> pairSum(vector<int>arr, int target){
	int st= 0, end = arr.size()-1; 
	int currSum = 0; 
	vector<int> ans; 
	
	while(st < end) {
		currSum = arr[st] + arr[end]; // currSum calculate
		if(currSum == target){  // comparison 
			ans.push_back(st);
			ans.push_back(end); 
			return ans;  // if answer get return 
		}
		else if(currSum > target){
			end--; // if not get answer then 
		}else { 
			  st++; // not if get answer then  
		}	
	}
	return ans; 
}
int main (){
	vector<int> vec = {2, 7, 11, 15}; 
	int target = 17; 
	
	vector<int> ans = pairSum(vec, target);
	
	cout << ans[0] <<" "<< ans[1]<< endl; 
	return 0; 
}

*//* 2D vecotrs : Syntx : vector<vector<int>> matrix ; 

 
#include <iostream>
#include <vector> 
using namespace std; 
int main () {
//	vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
//	Dynamic Size : 
//	not valid in Array 
	vector<vector<int>> matrix = {{1,2,3}, {4,5}, {7}};
	
	
	for (int i=0; i<matrix.size(); i++){
		for (int j=0; j<matrix[i].size(); j++){
			cout << matrix [i][j] << " "; 
		}
		cout << endl; 
	}
	return 0; 
}

meory allocation int the Vecotr =*//*

#include <iostream>
#include <vector> 
using namespace std; 
int main () {
	vector<int> v; 
	for(int i = 0; i<5; i++){
		v.push_back(i); 
	}
	cout << v.size() << endl; 
	cout << v.capacity() << endl; 
	return 0; 
}*/

