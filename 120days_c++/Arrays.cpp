/* Array : Linear collection of same type of elements that are stored 
   		   together in contiguous memory spaces.
		 - Memory is statically allocated (at compile time)  



#include <iostream>
using namespace std;
int main (){
	int marks[] = {1,2,3,4,5};
	int n = sizeof(marks)/ sizeof(int);
	cout << sizeof(marks)/ sizeof(int)<< endl;// count the length-division use here
	
	return 0; 
}
 
#include <iostream>
using namespace std;
int main (){
	int arr[5]; 
	int n = sizeof(arr)/sizeof(int);
//	int arr[n]; in new version support like this input 
	for(int i=0; i<n; i++){// instead of i<=n-1 ;use i<n 
			cin>>arr[i];
	}
	for (int i=0; i<n; i++)
	{
		cout << arr[i] << ",";
	}
	cout<< endl; 
	
	int ar[] = {5,4,6,3,42,55}
	int max = ar[0];
	int  min = ar[0];
	for (int i=0; i<j; i++)
	{
		if(ar[i]>max){
			max = ar[i];			   
		}
	}
	cout << "largest  = "<< max << endl; 
	return 0; 
}

#include <iostream>
using namespace std; 
int main(){
	
	int arr[] = {5,4,6,3,42,55};
	int j = sizeof(arr)/ sizeof(int);
	int max = arr[0];
	int  min = arr[0];
	
	for (int i=0; i<j; i++)
	{
		if(arr[i]>max){
			max = arr[i];			   
		}
	}
	cout << "largest  = "<< max << endl; 
	return 0; 
}
***************************************
*- in c++ lang name of aar is consider as pointer and print address

- Array are passed by reference : 

syntax : void printArr(int arr[]){..}
	   	 void printArr(int *arr){..) both meaning are same bcz array is pointer


#include <iostream>
using namespace std; 
void func(int arr[])
{
	arr[0] = 1000;
}
void func2(int *ptr){ // fun & fun2 both meaning are same: 
 	 ptr[0] = 1000; 
}
int main(){
	int a = 5; 
	int *ptr = &a;
	
	cout<<ptr<<endl;
	
	int arr[] = {1, 2, 3, 4, 5,};
	int n = sizeof(arr) / sizeof(int);
	
	func(arr); //passing array name is equivalent to passing the pointer
	cout << arr[0] << endl; 
	return 0; 
 
}
- index value never become minus they always start with zero toward --positive
**1.:Linear Search : if array not found then return -1.
- TC(time complexity) : relation bet input size  & no. of operations 
Q. search for key = 10; 

   |
  x|	  linear time complexity 
   |   	  o(n): jis gravity se array ka size badhega usi ke sath no. of operation badhenge
   |	 y=x graph  --
   |___________
   			   y 

* reference call 
#include <iostream > 
using namespace std; 
int linearSearch (int *arr,int n, int key){
	for(int i=0; i<n; i++)
	{
		if(arr[i]==key){
			return i;
		}
	}
	return -1; 
}
int main (){
	int arr[] = {2,4,5,6,8,10,12,14,16};
	int n = sizeof(arr)/sizeof(int);
	
	cout<< linearSearch(arr, n, 10) << endl; 
	return 0; 
}output : 5 - the 10 is at the no. of 5

**2:reverse an  array: with extra space  & using without extra space 

- reverse Array with extra space: 
#include <iostream > 
using namespace std;
void printArr(int arr[], int n){
	for(int i=0; i<n; i++ ){
	    cout<< arr[i] << endl;
	}

} 
int main(){
	int arr[]= {5,4,3,9,2};
	int n = sizeof(arr)/sizeof(int); 
	
	int copyArr[n]; //extra space of int n get into copy
	for(int i=0; i<n; i++) 
	{
		int j = n-i-1;
		copyArr[i] = arr[j];
	}
	for(int i = 0 ; i<n; i++)
	{
		arr[i] = copyArr[i];
//		cout << arr[i]<<" ";
	}
	printArr(arr, n);
	return 0; 
}
- without Extra space using : 
- 2 pointer Spproach : pointer means here index


#include <iostream > 
using namespace std;
printArr(int *arr, int n){
	for(int i=0; i<n; i++)
	cout<< arr[i] << " ";
}
int main (){
	int arr[]= {5,4,3,9,2};
	int n = sizeof(arr)/sizeof(int);
	
	int start = 0, end = n-1; 
	while(start < end)
	{
		//swap 
//		swap(arr[start], arr[end]); also use like this 
		int temp = arr[start];
		arr[start]=arr[end];
		arr[end] = temp; 
		start++; 
		end--;
	}
	 printArr(arr, n);
	 return 0; 
}

** 3: Binary Search : prerequisite: sorted Array 


#include <iostream > 
using namespace std;
int biSearch(int *arr, int n, int key){

	int st = 0, end = n-1; 
	
	while (st<=end){
		int mid = (st + end)/2; 
		if(arr[mid] == key){
			return mid; 
		}
		else if(arr[mid]<key){//2nd half
			st = mid + 1; 
		}
	}
	return -1; 
}
int main (){
	int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
	int n = sizeof(arr)/ sizeof(int);
	
	cout << biSearch(arr, n, 12)<< endl; 
	return 0; 
}//output: 5  here 12 is mid 


Binary Search : the relation bet input size and  no. of operations(decide from no. iteration)  
- devide search space in 2 parts
- for sorted array use binary search(o(log n)) alwayas no linear search(O(n))  
- Time Complexity : 1st iter: arr size n = n/2^0 = also we can write n = n/2^1-1 
  				   	2nd iter : arr size n = n/2^1 = also we can write n = n/2^2-1 
  				   	3rd iter : arr size n = n/2^2 = also we can write n = n/2^3-1 
  				   	4th iter : arr size n = n/2^3 = also we can write n = n/2^4-1 
  				   	-		   	   -		-								-
					-			   -		-								-
	 	  			nth ite			   		n = n/2^x = 1						  n = n/2^x-1		 


**4:  Array pointer : ArrPointer acts like a constant pointer. 											log-base2 n = x-1 = x = log-base2 n(constants delete)  = n(log)
Ex: 

#include <iostream>
using namespace std; 
int main (){
	int x = 10;
	int *ptr = &x; 
	// change the address x to y
	int y = 25; 
	ptr  = &y; 
	 
 	 cout << *ptr << "\n"; //output : 25
	return ; 
}
// but in ARRay : 
#include <iostream>
using namespace std; 
int main (){
	arr[5]; // read only value : 
	cout << arr << "\n"; // memory address being pointer
	// arr name consider as constant value that cannot be change
	// arrays first value always  consider
	y = 25;
	arr = &y; // error
	
	return 0; 
}
**6: 1. : pointer Arithmatic: 
- 1. increment & Decrement Operators 
  	 ptr++ or ++ptr
  	 ptr-- or --ptr 
  	  
 
#include <iostream>
using namespace std; 
int main (){
	int a = 10; 
	int *ptr = &a; 
	
	cout<< ptr << endl; 
	ptr++; // in pointer  : 1 int++ = 4 byte increase hoil 
		   	 // if take char var: char size = 1 byte : increase 1 byte  
	cout << ptr << endl; 
	return 0; 
}
**2: Pointer Arithmetic: addition substraction of constants
	- ptr + 3 : means increase 3 int which is = 12 byte
	- ptr - 3 : decrease
    - ptr1 + ptr2 : invalid operation 
    - ptr1 - ptr2 : both should be same type 
   	 


#include <iostream>
using namespace std; 
void printArr(int *ptr, int n)
{
	for(int i=0; i<n; i++)
	{
//		cout << *(ptr + i) << endl;
		cout << *ptr << "\n";
		ptr = ptr + 1;
	}	
}
int main (){
	int arr[] = {1,2,3,4,5,6,}; 
	int n = sizeof(arr)/ sizeof(int); 
	printArr(arr, n);
	
	return 0; 
}

***************************************************
*: Print SubArrays : SubArray is continuous part of an array 
 example: arr[]: {1, 2, 3, 4, 5} ; 		start point:ending point 
subArray: 1, 12, 123, 1234 ,12345; 		1			1, 2, 3, 4, 5
 		  2, 23 ,234, 2345				2			2, 3, 4, 5
 		  3, 34, 345, 					3			3, 4, 5,
 		  4, 45 
 		  5
 		  n=5 5+4+3+2+1 = 15 = 5*6/2 = 15  
 		  n=4 4+3+2+1 = 10 = 5*4 = 10
 		  
 	sum of n natural numbers formula : n +(n-1)+ (n-2) + (n-3)+---1
 		   	 		 		 		   
		subarray formula:  n*(n+1)/2 example 5*6/2 = 15  
		

#include <iostream>
using namespace std;

void printSubArr(int *arr, int n) {  
    for (int start = 0; start < n; start++) {// run : n time
        for (int end = start; end < n; end++) { // run : n time
//            cout << "(S " << start<< ",E " << end << ")";
            for(int i  = start; i<end; i++ )
            {
            	cout<< arr[i];
            } 
			 cout<< " "; 			 
        }
        cout << endl; 
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    printSubArr(arr, n);
    return 0;
}
*/
/*10/05/2024**************************
**1: Brute-Force method: 
* Use 3 Approaches there are further: 1. brute force method 2.optimize 3. kadane's 
*Max SubArray Sum : Brute Force Approach:
- eXample Array : a[]= {2,-3, 6, -5, 4, 2}; 
sum of possible subarray :       2 -1 5 0 4 6
	   					 		 -3 3 -2 2 4
                                6 1 5 7 : 7 is max here all over
					            -5 -1 1
					   			4, 6 
					   			2 
					   			

#include <iostream>
using namespace std; 
void maxSubAr(int *arr, int n){
	int maxSum = INT_MIN; // for minimum value print: INT_MAX : -infinite(symbol) &for maximum value use:  INT_MIN:+infinite(symbol plus) = both are predefine macros 
	 for(int start=0; start<n;  start++){
	 	for(int end=start; end<n; end++){
	 		int currSum = 0; 
	 		for(int i = start; i<=end; i++){
	 		 	currSum = currSum + arr[i]; 
		    }
		    cout << currSum << ","; 
		    maxSum = max(maxSum, currSum); 
		    // just for max of three number max(a, max(b, c));
		 }
		 cout<<endl;
		  
	 }
	 cout << "maximum subArray sum =  "<< maxSum << endl;
}
int main(){
	int arr[6] = {2, -3, 6, -5, 4, 2};
	int n = sizeof(arr)/ sizeof(int); 
	
	maxSubAr(arr, n); 
	return 0;
	
	// time coplexity : 3 loop : O(n^3): worst time complexity for better time complexity use : next example
}// output : upar hai : form output get max 

 
// optimization: arr[]=int arr[6] = {2, -3, 6, -5, 4, 2};
 *NOTE:   here assume a value which is 2 index : and start some of eacch
*/   				 		
/*2 ;
 #include <iostream>
using namespace std; 
void maxSubAr(int *arr, int n){
	int maxSum = INT_MIN; 
	// for minimum value print: INT_MAX : -infinite(symbol) &for maximum value use:  INT_MIN:+infinite(symbol plus) = both are predefine macros 
	 for(int start=0; start<n;  start++){
	 	int currSum = 0;	
	 	for(int end=start; end<n; end++){
//		    cout << currSum << ","; 
			currSum += arr[end]; 
		    maxSum = max(maxSum, currSum); 	  
	  }	 
	     
    }
 	cout << "maximum subArray sum =  "<< maxSum << endl;
} 
int main(){
	int arr[6] = {2, -3, 6, -5, 4, 2};
	int n = sizeof(arr)/ sizeof(int); 
	
	maxSubAr(arr, n); 
	return 0;
}

**3: Kadane's Algorithm (DP) : use single loop : 
- Kaddane's algorithm (dynamic Programming(is big chapter) )
  arr[6] = {2, -3, 6, -5, 4, 2};
  
  Here: suppose 2 numbers have: then : positive + positive = positive
  				  		  			   negative + big-val-positive = positive
  				  		  			   big-val-neg + positive = negative
{2, -3, 6, -5, 4, 2}:  2 + -3 = -1 next val kam karega so then re-initialize currSum with 0    
 calculation currSum:INT_MAX: sums 2=-1=0(reinitialize)=6=1=5=7 
 			 maxSum: INT_MIN: sums = 2,6,7 : ignore negative values
 Example: 


#include <iostream>
using namespace std; 
void sumSubArr(int *arr, int n){
	int maxSum = INT_MIN; 
	int currArr = 0; 
	for(int i=0; i<n; i++){
		currArr += arr[i];
		maxSum = max(currArr, maxSum);
		if(currArr<0){
			currArr = 0; 
		}
	}
	cout << "maxSum Array: " << maxSum << endl; 
}
int main 
sell price - buy price = profit 

best sell: 7 1 5 3 6 4
	 	   INT_MIN 
profit : -oo(infinite) 7 - +oo= -oo, 1-7=-6, 5-1=4, 3-1=1, 6-1 = 1 , 4-1=3.
	   	 
 
#include <iostream>
#include <climits> // Include this header for INT_MIN
using namespace std;

void maxProfit(int *prices, int n) {
    int bestBuy[1000];
    bestBuy[0] = prices[0]; // Initialize to the first price
    for (int i = 1; i < n; i++) {
        bestBuy[i] = min(bestBuy[i - 1], prices[i - 1]);
    }
	cout << "best BUY : "<< *bestBuy << endl; 
    int maxProfit = 0;
    for (int i = 0; i < n; i++) {
        int currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currProfit);
    }
    cout << "max Profit = " << maxProfit << endl;
}

int main() {
    int prices[6] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(int);

    maxProfit(prices, n);
    return 0;
}

#include <iostream>
using namespace std;
int trap(int *heights, int n){
	int leftMax[20000], rightMax[20000];
	leftMax[0] = heights[0]; // not use bcz : INT_MIN instead OF use heights 0  bcz: neg = neg become positive
	rightMax[n-1] = heights[n-1];
	
	for(int i=1; i<n; i++){
		leftMax[i] =  max(leftMax[i-1], heights[i-1]);
		
	}//output:  -21474836(-oo), 4,4,4,6,6,6
	
	for(int i=n-2; i>0; i--){
		rightMax[i] = max(rightMax[i+1], heights[i+1]);	
			
	}//output: 5,5,5,6,6,6, -21474836(-oo):actually this 6,6,6,5,5,5 -21474836(-oo)
	// both of min : -oo, 4,4,4,5,5,-oo
	// minus from height: -oo, 2,4,-2,2,3,-oo
	// 	- values become 0: 0,2,4,0,2,3,	0: sum = 11
	
	int waterTrapped = 0; 
	for(int i=0; i<n; i++){
		int currWater = min(leftMax[i], rightMax[i]) - heights[i];
		if(currWater > 0){
			waterTrapped += currWater; 
		}
	}
	cout << "water trapped = " << waterTrapped << endl; 
	return waterTrapped;	
} 
int main (){
		 		// bar chart			
	int heights[7] = {4, 2, 0, 6, 3, 2, 5};
	int n = sizeof(heights)/ sizeof(int); 
	
	trap(heights, n);
	return 0; 
}
Q.1 Given an integer array nums,return true if any value appears
atleast twice in the array, and return false if every element is 
distinct. 

#include <iostream>
#include <algorithm>
using namespace std;

bool containsDuplicate(int *num, int n) {
    sort(num, num + n); 
    
    for(int i = 1; i < n; i++) {
        if(num[i] == num[i - 1]) {
            return true; 
        }
    }
    return false; 
}

int main() {
    int num1[10] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}; 
    int n1 = sizeof(num1) / sizeof(int); 
    cout << boolalpha << containsDuplicate(num1, n1) << endl; 
    
    int num2[4] = {1, 2, 3, 1}; 
    int n2 = sizeof(num2) / sizeof(int); 
    cout << boolalpha << containsDuplicate(num2, n2) << endl;
    
    int num3[4] = {1, 2, 3, 4}; 
    int n3 = sizeof(num3) / sizeof(int); 
    cout << boolalpha << containsDuplicate(num3, n3) << endl;
    
    return 0; 
}
Q. : Given the array nums after the possible rotation and an 
integer target, return the index of target if it is in nums, 
or -1 if it is not in nums: 
*//* 
#include <iostream>
#include <vector>
using namespace std; 

int indexNums(vector<int>& nums, int target) { // Corrected function signature and passed vector by reference
    int low = 0, high = nums.size() - 1; 
    
    while (low <= high) {
        int mid = (low + high) / 2; 
        
        if (nums[mid] == target) {
            return mid; 
        }
        
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) { // Corrected syntax error
                high = mid - 1;
            } else { 
                low = mid + 1; 
            }
        } else {
            if (nums[mid] < target && target <= nums[high]) { // Corrected syntax error
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
    }
    return -1; 
}

int main () {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target; // Added a target value for testing
    cin >> target;
    int result = indexNums(nums, target); // Called the function with correct parameters
    
    cout << "Index of target (" << target << "): " << result << endl; 
    return 0; // Added return statement
} //output : target choose from array : 5 is at index 1 : 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
class Solution { 
public:
  int maxProduct(vector<int>& nums){
	int n = nums.size();
	if(n == 0) return 0;
	 
	int maxProd = nums[0]; 
	int minProd = nums[0]; 
	int result = nums[0]; 
	
	for(int i = 0; i<n; i++){
		if(nums[i]<0)
		swap(maxProd, minProd);
		
		maxProd = max(nums[i], maxProd * nums[i]);
		minProd = min(nums[i], minProd * nums[i]);
		
		result = max(result, maxProd);
	}
	return result; 
}
};
int main (){
	Solution sol; 
	vector<int>nums1 = {2,3,-2,4};
	cout << sol.maxProduct(nums1) << endl; 
	
	vector<int> nums2 = {-2, 0, -1};
	cout << sol.maxProduct(nums2)<< endl; 
	return 0;
}
