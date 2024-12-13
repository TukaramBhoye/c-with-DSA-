//1: RECURSION : When a function repeatedly calls itself 
/* 
- It is a method of solving computational problems where the solution 
  depencs on solution to smaller instance of the same problem.

- three things have 
  1: base class / smallest problem 
  2: kaam ? in each func call 
  3: how we call inner function
  
- use to big problems divide into small functions 

#include <iostream> 
using namespace std; 
void func(){
	cout << "function Call "<< endl; 
	func(); 
}
int main (){
	
	// here is not base case where we can end the program 
	return 0;	
}

2: Understanding using Math: i.  5! = f(n) = n * f(n-1)    
 							  ii. f(x) = x^2  : suppose f(f(x)) = (x^2)^2 	
- such type functions call recurrence recursion 
*/
/*
#include <iostream> 
#include <string>
using namespace std; 
int factorial(int n){
	if (n==0){
		return 1; 
	}
	return n * factorial(n-1); 
}

int main(){
	int ans = factorial(5); 
	cout << ans << endl; 
	return 0; 
}
*/ 
/*3: Print Numbers in decreasing order : from n to 1 
assume => print(n-1) : kaam => cout << n : Base Case => n=0 : */
/*
#include <iostream> 
#include <string>
using namespace std; 
void print(int n){
	if (n == 0){
		return; 
	}
	cout << n << " "; 
//	cout << 5 << " "; O/p : 5 5 5 5 5
	print(n-1); 
}

int main(){
	print(5); 
	return 0; 
}
*/ 
/*Stack Overflow : run infinite time/until not stack become 
				   full and it stop 
 causes : - declare multiple local variable in function 
		  - missing base case 
		  
*/
// 4. : Print the sum of N natural Numbers using recursion  : 
//create formula : sum(n) = n + sum(n-1) 
/*
#include <iostream> 
using namespace std; 
int Sum(int n){
	if (n == 1){
		return 1; 
	}
	return n + Sum(n-1);
}
int main (){
	cout << Sum(5) << endl; 
	return 0; 
}
*/ 
//5: WAP for nth fibonacci number : fib(n) = fib(n-1) + fib(n-2) recrusion tree 
/*
#include <iostream> 
using namespace std;
int fibonacci(int n ) { 
	if (n == 0 || n == 1) {
		return n; 
	}
	return fibonacci(n-1) + fibonacci(n-2); 
}
 
int main (){
	cout << fibonacci(5)<< endl; 
	return 0; 
}*//*

#include <iostream> 
using namespace std; 
bool isSorted(int arr[], int n, int i){
	if(i == n-1){ 
		 return true;
	}
	
	if(arr[i] >= arr[i+1]){
		return false; 
	}
	
	return isSorted(arr, n, i+1); 
}
int main (){
	int arr[5]={1, 2, 3, 4, 5};
	int arr1[5]={1, 2, 4, 3, 5}; 
	
	cout << isSorted(arr, 5, 0)<< " " ;
	cout << isSorted(arr1, 5, 0)<< " " ; 
	
	return 0; 
}*/ 

/*6:  First Occurance:  WAF to find first occurrence of an element in a vector
*//* 
#include <iostream> 
#include <vector>
using namespace std; // bcz of vector<int> we did not pass n
int firstOccur(vector<int> arr, int i, int target){
	if(i == arr.size()){
		return -1; 
	}
	if(arr[i] == target) { 
        return i; 
	}
	return firstOccur(arr, i+1, target); 
}
int lastOccur(vector<int> arr,int target,int i){
	if(i == arr.size()){
		return -1; //last index 
	}
	 		   	   		  		  // reverse i + 1
	int idxFound = lastOccur(arr, target, i+1);
		if(idxFound == -1 && arr[i] == target) {
			return i; 
		}
		return idxFound;  // OP: 4
}
int main (){ 
	vector<int> arr = {1, 2, 3, 3, 3, 4}; 
	
	cout << firstOccur(arr, 0, 3)<< endl;
	cout << lastOccur(arr, 3, 0)<< endl; 
}
*/ /* 
#include <iostream> 
using namespace std; 

int pow(int x, int n) {
	if(n==0) {
		return 1; 
	}
	// 		divide pow in half 
	int halfPow = pow(x, n/2); 
	int halfPowSquare = halfPow * halfPow; 
// if odd vlaue then 
	if(n % 2 != 0) {
		return x * halfPowSquare; 
	}
	return halfPowSquare; 
}
int main(){
	cout << pow(3, 3) << endl;
	return 0; 
}*/ 

//7: count total ways to tile a floor(2*n)with tiles : google questions
/* in recursion three stratagy : Kaam, recursion, Base Case(Small_Value); 
#include <iostream>
using namespace std; 
int tilingProblem(int n){ // n*2
 	// Base Case 
	 if(n==0 || n==1){
 		return 1; 
	 }
	 // Vertical 
	 int ans = tilingProblem(n-1);
	 
	 // horizontal  fit 2 tiles that minus from n 
	 
	 int ans1 = tilingProblem(n-2);
	  
//	return tilingProblem(n-2) + tilingProblem(n-1); both are right
	 return ans + ans1; 
}
int main() {
	int n = 3; 
	cout << tilingProblem(4)<< endl; 
}
*/ 
//8:  Remove Duplicates From string : using Recursion 
/*
#include <iostream>
#include <string>
using namespace std; 
void removeDuplicates(string str, string ans, int i, int map[26]){
	if(i == str.size()){
		cout << "ans : " << ans << endl; 
		return; 
	}
	
	int mapIdx = (int)(str[i] - 'a');
	
	if(map[mapIdx]){ // duplicate 
		removeDuplicates(str, ans, i+1, map); 
	}else { // not duplicate 
		  map[mapIdx] = true; 
		  removeDuplicates(str, ans+str[i], i+1, map); 
	}
}
//2nd Approach
void removeDuplicate(string str, string ans, int map[26]){
	if(str.size()== 0){
		cout << "ans : " << ans << endl; 
		return; 
	}
	
	int n = str.size(); 
	char ch = str[n-1]; 
	int mapIdx = (int)(str[n-1] - 'a');
	str = str.substr(0, n-1); 
	
	if(map[mapIdx]){ // duplicate 
		removeDuplicate(str, ans, map); 
	}else { // not duplicate 
		  map[mapIdx] = true; 
		  removeDuplicate(str, ch+ans,  map); 
	}
}
int main (){ 
	string str = "appnacollage"; 
	string ans = ""; 
	int map[26] = {false}; 
	
//	removeDuplicates(str, ans, 0, map); //	 apncolge
	
	removeDuplicate(str, ans, map); // : pncolage : reverse Index
	

	return 0; 
}

*/
/*Q. 9:  find total way of inWhich n friend can be paired up. 
 each friend can be only be once paired: 
#include <iostream> 
#include <string>
using namespace std; 

int friendPairing(int n){
	if (n == 1 || n == 2){
		return n; 
	}
	
	return friendPairing(n-1) + (n-1) * friendPairing(n-2); 
}
// pairs --> a b c : ab c : ac b: bc a: = 4
int main () {
	cout << friendPairing(5) << endl; 
	return 0; 
}
*/ 
/*10>: Print all Binary Strings of size N without any consecutive(Lagatar) 1s. 
   Ex: n=2 : "00" , "10" , "01"
   	    n= : "00" , "10" , "01" *//*
   	    
#include <iostream> 
using namespace std; 
void binString(int n, int lastPlace, string ans){
	if(n==0){
		cout << ans << endl; 
		return; 
	}
	if(lastPlace !=1){
		binString(n-1, 0, ans + '0'); // 0 is lastPlace
		binString(n-1, 1, ans + '1'); 
	}else{
		binString(n-1, 0, ans + '0'); 
	}
}

 // without Last Index
void binStringg(int n, string ans){
	if(n==0){
		cout << ans << endl; 
		return; 
	}
	if(ans[ans.size()-1]!='1'){ // don't do: ==
		binStringg(n-1, ans + '0'); // 0 is lastPlace
		binStringg(n-1, ans + '1'); 
	}else{
		binStringg(n-1, ans + '0'); 
	}
}	    
int main (){ 
	string ans = ""; 
	binString(3, 0, ans); 
	binStringg(4, ans); 
	return 0;				 
}*/
//*Assignments:
//Q. 1 : To find all occurrences (indices) of a given element
/*
#include <iostream> 
#include <vector> 
using namespace std;

void dhundOccurances (int arr[], int key, int size, int index){
	// Base case : 
	if (index >= size){
		return; 
	}
	// if element match with curr index
	if(arr[index] == key){ 
         cout << index << " "; 
	}
	// to check next element 
	dhundOccurances(arr, key, size, index + 1); 
}

int main (){
	//sample input
	int arr[] = {3, 2, 4, 5, 6, 2, 7, 2, 2}; 
	int key = 2; 
	int size = sizeof(arr) / sizeof(arr[0]); 
	
	// function call karke key ke occurances ke indices print karo 
	cout << " bhai " << key  << "ka Index dhund Raha hoon: "; 
	dhundOccurances(arr, key, size, 0), 
	cout << endl; 
	return 0; 
} //O/P: 1 5 7 8

Q.2 : implement a recursive binary search function to find the index of a key in a sorted array.
*//* 
#include <iostream>
using namespace std; 
int findIndex(int arr[], int start, int end, int key){
	if(start > end){
		return -1; // key not found
	}
	int mid = start + (end - start) / 2; 
	
	if (arr[mid] == key) {
		return mid; 			// if found mid index
	}
	else if(arr[mid]<key){ 		// if arr[mid] less than key, search int the right half
		 return findIndex(arr, mid + 1, end, key); 				 	
	}
	else{						// if greter than key, search left half
		return findIndex(arr, start, mid - 1, key); 
	}

}

int main (){
	int arr[] = {1, 2, 3, 4, 5, 6, 7 };
	int n = 7; 
	int key = 5;
	
	int index = findIndex(arr, 0, n - 1, key);
    cout << "index of " << key << " is " << index << endl;
	return 0; 
}
*/ 

/*Q.3: WE Are given a string S, we need to find the count of all contigous 
	   substring starting and ending with the same character.
	Sample Input 1 : S = "abcab" ; 
	Sample Output : 7  */ 
/*
#include <iostream>
#include <string>
using namespace std;

int countCharacters(const string& S, int index) {
    // Base case: when index exceeds string length
    if (index >= S.length()) {
        return 0;
    }
    
    // Count current character and recur for the rest
    return 1 + countCharacters(S, index + 1);
}

int countSubstring(const string& S, int start, int end, char ch) {
    // Base case: start index 
    if (start > end) {
        return 0;
    }
    
    // Count if start and end characters are the same
    int count = (S[start] == ch && S[end] == ch) ? 1 : 0;
    
    // Recur for substrings with updated start and end indices
    return count + countSubstring(S, start + 1, end - 1, ch);
}

int main() {
    string S = "abcab";
    
    // Count individual characters
    int totalCount = countCharacters(S, 0);
    
    // Count contiguous substrings
    for (int i = 0; i < S.length(); i++) {
        totalCount += countSubstring(S, i, S.length() - 1, S[i]);
    }
    
    cout << "substrings start and end : " << totalCount << endl;

    return 0;
}

Q.4 Tower of Hanoi : 
   You Have 3 towers and N disks of different sizes which can 
   slice onto any tower. The puzzle starts with disks sorted in 
   ascending order of size from top to bottom (i.e., each disk sits 
   on top o an even larger one).
*/ /* 
#include <iostream>
#include <stack>
using namespace std;

// Recursive function to move disks
void moveDisks(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
        return;
    }
    moveDisks(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    moveDisks(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int N = 3; // Number of disks
    char rod1 = 'A', rod2 = 'B', rod3 = 'C'; // Rods
    
    moveDisks(N, rod1, rod3, rod2); // Calling the recursive function
    
    return 0;
}
*/ 
//Q.5 : 

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int countGoodDigitStrings(int n) {
    vector<long long> dp(n + 1);
    
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) { // Even index
            dp[i] += dp[i - 1];
            dp[i] %= MOD;
        }
    }

    return dp[n];
}

int main() {
    int n = 1; // Length of the digit string
    cout << "Total number of good digit strings of length " << n << ": " << countGoodDigitStrings(n) << endl;
    return 0;
}
