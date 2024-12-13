//32:NB2-13:  Stack
 
//: using vector
/*
#include <iostream>
#include <vector> 
using namespace std; 

// create Stack using vector
class Stack {
	vector<int> vec; 
	public: 
    void push(int val){
  	    vec.push_back(val);
    } 
	void pop(){
		if(isEmpty()){
			cout << "statck is empty\n"; 
			return;
		}
		vec.pop_back(); 
	}
	
	int top(){
		if(isEmpty()){
			cout << "Stack is empty.\n"; 
			return -1;
		}
		int lastIdx = vec.size()-1; 
		return vec[lastIdx];
	}
	
	bool isEmpty(){
		 return	vec.size() == 0;
	}
};
int main(){
	Stack s;
	s.push(3);
	s.push(2);
	s.push(1);
	
	while(!s.isEmpty()){
		cout << s.top()<< " "; 
		s.pop(); 
	}
	return 0; 
}*/

//2: Stack Implementation: using vector with class template: 

/* 
#include <iostream>
#include <vector> 
using namespace std; 

// create Stack using vector
template<class T> 
class Stack {
	vector<T> vec; 
	public: 
    void push(int val){
  	    vec.push_back(val);
    } 
	void pop(){
	
		if(isEmpty()){
			cout << "statck is empty\n"; 
			return;
		}
		vec.pop_back(); 
	}
	
	T top(){
//		if(isEmpty()){
//			cout << "Stack is empty.\n"; 
//			return -1;
//		}
		int lastIdx = vec.size()-1; 
		return vec[lastIdx];
	}
	
	bool isEmpty(){
		 return	vec.size() == 0;
	}
};
int main(){
	Stack<char> s; 
	
	s.push('c');
	s.push('d'); 
	s.push('e'); 
	
	while(!s.isEmpty()){
		cout << s.top()<< " "; 
		s.pop(); 
	}
	return 0;
}*/ 

// 3: Stack Using LinkList:#include <list> with header file
/*
#include <iostream>
#include <list> 
#include <vector> 
using namespace std; 

//create Stack using linked list: 
template<class T> 
class Stack {
	list<T> ll; 
	
	public: 
	   void push(T val){
	   	ll.push_front(val); 
	   }
	   
	   void pop(){
	   	ll.pop_front(); 
	   }
	   
	   T top(){
	   	return ll.front(); 
	   }
	   
	   bool isEmpty() {
	   	return ll.size() == 0; 
	   }
};

int main (){
	Stack<int> s; 
	
	s.push(3); 
	s.push(2); 
	s.push(1); 
	
	while(!s.isEmpty()){
		cout <<s.top() << " " ;
		s.pop(); 
	}
	cout << endl; 
	return 0; 	
}*/ /* 
// Stack LinkList without Header File:  
#include <iostream> 
#include <string> 
#include <vector> 
#include <stack> // can directly use
using namespace std; 

template<class T> 
class Node{
	public: 
	T data; 
	Node* next; 
	
	Node(T val){
		data = val;
		next = NULL; 
	}
};
template<class T>
class Stack {
	Node<T>* head; 
	
	public: 
		Stack(){
			head = NULL; 
		}
		
	   void push(T val){
	   	Node<T>* newNode = new Node<T>(val);
	   	
	   	if(head == NULL){
	   		head = newNode;
		   }else{
		   	newNode->next = head; 
		   	head = newNode; 
		   }
	   }
	   
	   //pop_front
	   void pop(){
	   	if(head == NULL){
	   		return; 
		   }
		   
 	   Node<T>* temp = head; 
	   	head = head->next; 
	   	temp->next = NULL; 
	   	delete temp; 
	   }
	   
	   T top(){
	   	return head->data; 
	   }
	   
	   bool isEmpty() {
	   	return head == NULL; 
	   }
};

int main (){
	Stack<int> s; 
	
	s.push(3); 
	s.push(2); 
	s.push(1); 
	
	while(!s.isEmpty()){
		cout<<s.top() << " ";
		s.pop(); 
	}
	cout << endl;
	return 0; 	
}*/ 
/* using #inlcude<stack> From STL(Standard Template library 
int main (){
	stack<int> s; //we write here S	in small case
	
	s.push(3); 
	s.push(2); 
	s.push(1); 
	
	while(!s.empty()){ // isEmpty convert into empty 
		cout<<s.top() << " ";
		s.pop(); 
	}
	cout << endl;
	return 0; 	
}*/

// 4:NB2:16:push At Bottom Of Stack: pushAtBottom(&stack, value) 
/*
#include <iostream>
#include <stack>
#include <string> 
using namespace std; 
//1:Push At Bottom 
void pushAtBottom(stack<int>&s, int val){
	if(s.empty()){
		s.push(val); //push at top = push at bottom 
		return; 
	}

	int temp = s.top(); // store before delete stack 
	s.pop();
	pushAtBottom(s, val); 
	s.push(temp); 	
}

int main(){
	stack<int>s; 
 
	s.push(3); 
	s.push(2); 
	s.push(1); 
	
	pushAtBottom(s, 4); 
	while(!s.empty()){
		cout << s.top()<<" "; 
		s.pop(); 
	}
	cout << endl; 
	return 0; 
}
*/
/*5: reverseString using stack: 
#include <iostream>
#include <stack>
#include <string> 
using namespace std; 

string reverseString(string str){ //TC:O(N) : SC: O(N)
	   string ans; 
	   stack<char> s; 
	   
	   for(int i=0; i<str.size(); i++){
	   		   s.push(str[i]); 
	   }
	   
	   while(!s.empty()){
		   	char top = s.top(); 
		   	ans += top; 
		   	s.pop(); 
	   }
	   return ans; 
}
int main(){
	string str = "abcd"; 
	cout << "reverse = " << reverseString(str) << endl;
	
	return 0; 
}*/
/*
//Q.6:	Reverse stack
#include <iostream>
#include <string> 
#include <vector>
#include <stack>
using namespace std; 
void pushAtBottom(stack<int>&s, int val){
	if(s.empty()){
		s.push(val); //push at top = push at bottom 
		return; 
	}

	int temp = s.top(); // store before delete stack 
	s.pop();
	pushAtBottom(s, val); 
	s.push(temp); 	
}
void reverse(stack<int>&s){
	if(s.empty()){
		return; 
	}
	
	int temp = 	s.top(); 
	s.pop(); 
	reverse(s); 
	pushAtBottom(s,	temp);
}

void printStack(stack<int>s){
	while(!s.empty()){
	  cout << s.top() << " "; 
	  s.pop(); 
	}
	
	cout << "\n ";
}
int main () {
	stack<int> s; 
	
	s.push(3);
	s.push(2);
	s.push(1);
	printStack(s); 
	
	reverse(s); 
	printStack(s); 
	return 0 ;
}*/ 
//Q.7-i:NB2:19 stock span problem : 
// span = max of consicutive days (including current
/*
#include <iostream>
#include<vector>
#include<stack>
#include <string>
using namespace std; 
void stackSpanProblem(vector<int>stock, vector<int>span){
	stack<int>s; 
	s.push(0); 
	span[0] = 1;
	
	for(int i=1; i<stock.size(); i++){
		int currPrice = stock[i];  
		while(!s.empty() && currPrice >= stock[s.top()]){
			s.pop();        
		}
	
		if(s.empty()){
			span[i] = i+1;   
		}else{
			int prevHigh = s.top();  
			span[i] = i-prevHigh; 
		}     
	}
	for(int i=0; i<span.size(); i++){
		cout << span[i]<< " "  ;
	}                
     
    cout << endl; 
}
int main(){
	vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
	vector<int> span = {0, 0, 0, 0, 0, 0, 0};
	
	stackSpanProblem(stock, span); 
	return 0; 
}
*/ 
/*Q.7-ii : Next Greater Element : 
next greater first greater element that is to the right: 
*/ /* 
#include <iostream> 
#include <vector> 
#include <stack> 
using namespace std; 
void	nextGreater(vector<int>arr, vector<int>ans){
	stack<int>s; 
	int idx = arr.size()-1; 
	ans[idx] = -1; 
	s.push(arr[idx]); 
	
	for(idx = idx-1; idx>=0; idx--){
		int curr = arr[idx]; 
		while(!s.empty() && curr >= s.top()){
			s.pop(); 
		}
		
		if(s.empty()){
			ans[idx] = -1; 
		}else{
			ans[idx] = s.top();
		}
		
		s.push(curr); 
	}
	
	
	for(int i = 0; i<ans.size(); i++ ){
	    cout << ans[i] << " " ; 
	}
	cout << endl ; 
}
int main(){
	vector<int>arr	= {6, 8, 0, 1, 3};//  arr {6, 8, 0, 1, 3} hai, to arr.size() - 1 index 1 ko refer karta hai.
	vector<int>ans = {0,0,0,0,0}; 
	
	nextGreater(arr, ans); 
}
*/ /*Q.8:NB2: Valid Parenthesis : Given a string containing just a character 
'(', ')', '{', '}', '[', ']' determine if the input string is valid. 
- string is valid when : - brackets must be clode by same
  - must be close in correct order
  - ever bracket has corresponding open brackets of the same type;
 */ /* 
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std; 
bool isValid(string str){
	stack<char>s; 
	for(int i=0; i<str.size(); i++ ){
		char ch = str[i]; 
		if(ch == '(' || ch == '['|| ch == '{'){
			s.push(ch);  
		}else{
			if(s.empty()){
				return false; 
			}
			//match; 
			int top = s.top(); 
			if ((top == '(' && ch == ')' ) || 
       		   (top == '[' && ch == ']' ) || 
       		   (top == '{' && ch == '}' )){
       		   	 s.pop(); 
            }else{
            	return false; 
			}
		}
	}
	return s.empty(); 
}
int main (){
    string str1 ="(}{()]";
	string str2 = "([{}])";
	
	
	 cout << isValid(str1) << endl; // 0
	 cout << isValid(str2) << endl; // 1
	 
	 return 0 ; 
	
} */

/* Q. 9>: Duplicate Parenthesis 
 - given a balanced expression that can contain and closing parenthesis, check if it
   contains any duplicate parenthesis or not. 
   
   Input : 1. ((x + y))+z -op->true : 2. (x+y)-->false 3: ((x+y ) + ((z)))-->true 
   OutPut: true : 
   Explanation: Duplicate() found in suexpression ((x+y))
 */ /* 
#include <iostream>
#include <vector>
#include <stack>
#include <string> 
using namespace std; 
 
 bool isDuplicate(string str){
 	stack<char> s; 
 	
 	for(int i=0; i<str.size(); i++){
 		char ch = str[i]; 
		// BC
		if(ch != ')') { //non closing
            s.push(ch); 
            
		}else{//in closing : we have to find opening
  		    if(s.top() == '('){
  		    	return true; //Duplicate
            }
			
			while(s.top() != '('){
				s.pop(); 
			}
			s.pop(); 	
		}
	 }
	 return false; 
 }
 int main (){
 	string str = "((x + y))+z";  // invalid: true
 	string str2 = "((a+b))+(c+d))"; // invalid 
 	string str3 = "(x+y)"; // valid: false 
 	
 	cout <<  isDuplicate(str) << endl; 
 	cout <<  isDuplicate(str2) << endl;
 	cout <<  isDuplicate(str3) << endl;
 	
 	
 	return 0; 
 }
 */ 
 /* Q. 10 : Histogram: Max Area of Histogram : 
  Return the area of Largest Rectangle in Histogram heights = [2, 1, 5, 6, 2, 3] 
  area * height = height[i]  
  *//*  
 #include <iostream> 
 #include <vector> 
 #include <stack> 
 using namespace std; 
 
 void printArr(vector<int> vec){
 	for(int i = 0; i<vec.size(); i++){
 		cout << vec[i] << " "; 
	 }
	 cout << endl; 
 }
 void maxAreaHistogram(vector<int>height){
 	int n = height.size(); 
 	vector<int>nsl(n); 
 	vector<int> nsr(n); 
 	stack<int>s; 
 	
 	//next smaller left
 	nsl[0] = -1; 
 	s.push(0); 
 	for(int i=1; i<height.size(); i++){
 		int curr = height[i]; 
 	
	 	while(!s.empty() && curr<= height[s.top()] ){
 			s.pop(); 
 		}
		 
		 if(s.empty()){
		 	nsl[i] = -1; 
		 }else{
		 	nsl[i] = s.top(); 
		 }
		 s.push(i); 
	 }
    printArr(nsl); 
	 while(!s.empty()){
	 	s.pop();
    }
   
	 //next smaller right
	 s.push(n-1); 
	 nsr[n-1]= n; 
	 
	 for(int i=n-2; i>=0; i--){
	 	int curr = height[i]; 
	 	
	 	while(!s.empty() && curr <= height[s.top()]){
	 		s.pop(); 
		 }
		 
		 if(s.empty()){
		 	nsr[i] = n; // -1 : width sahi se calculate ho isiliye n dala hai
		 }else{
		 nsr[i] = s.top(); 
		 }
		 s.push(i); 
	 }
	 int maxArea = 0; 
	 for(int i=0; i<n; i++){
	 	int ht = height[i]; 
	 	int width = nsr[i] - nsl[i] - 1;
	 	int  area = ht * width; 
	 	
	 	maxArea = max(area, maxArea); 
	 }
	 cout << "max area of histogram: " << maxArea << endl; 
}
  
int main (){
	 vector<int>height = {2, 1, 5, 6, 2, 3};
	 maxAreaHistogram(height); 
	 return 0; 
}*/ 

// Assgnments: Stacks 
/*Given the head of a singly linked list, return true if it is a 
  palindrome or false Otherwise. 
  *//* 
#include <iostream>
#include <stack> // For using stack data structure

using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    // Constructor to initialize data and next pointer
    ListNode(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(NULL) {}

    // Function to add a new node at the end of the list
    void push_back(int val) { // Changed parameter name to 'val'
        ListNode* new_node = new ListNode(val); // Corrected variable name to 'val'
        if (head == NULL) {
            head = new_node;
            return;
        }
        ListNode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    // Function to check if the linked list is a palindrome
    bool isPalindrome() {
        stack<int> s;
        ListNode* current = head;

        // Push all elements of the linked list onto the stack
        while (current != NULL) {
            s.push(current->data);
            current = current->next;
        }

        // Reset current to the head of the linked list
        current = head;

        // Compare elements from the linked list with elements popped from the stack
        while (current != NULL) {
            int top = s.top();
            s.pop();
            if (current->data != top) {
                return false;
            }
            current = current->next;
        }

        return true;
    }

    // Function to print the linked list
    void printList() {
        ListNode* current = head;
        while (current != NULL) {
            cout << current->data;
            if (current->next != NULL) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    // Example usage
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(2);
    list.push_back(1);

    // Print the linked list
    cout << "Linked List: ";
    list.printList();

    // Check if the linked list is a palindrome
    if (list.isPalindrome()) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}

*/ 

/*Q.2: Bhai, samjho, tune ek encoded string diya hai, hume usko 
decoded string mein convert karna hai. Encoding rule hai ki agar
koi string [encoded_string] ke andar square brackets mein hai aur 
uske aage ek number k hai, toh encoded_string ko k baar repeat karna hai.
Examples dekho:
Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Iska matlab hai ki "a" ko 3 baar aur "bc" ko 2 baar repeat karna hai.*/ 
/*
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decodeString(string s) {
    stack<int> numStack;
    stack<string> strStack;
    string currentStr;
    int currentNum = 0;

    for (char c : s) { // char c ko string s ke har character se initialize kiya jata hai
        if (isdigit(c)) {
            currentNum = currentNum * 10 + (c - '0');
        } else if (c == '[') {
            numStack.push(currentNum);
            strStack.push(currentStr);
            currentNum = 0;
            currentStr = "";
        } else if (c == ']') {
            int repeatTimes = numStack.top();
            numStack.pop();
            string temp = strStack.top();
            strStack.pop();
            for (int i = 0; i < repeatTimes; ++i) {
                temp += currentStr;
            }
            currentStr = temp;
        } else {
            currentStr += c;
        }
    }

    return currentStr;
}

int main() {
    string s1 = "3[a]2[bc]";
    string s2 = "2[abc]3[cd]ef";

    cout << "Input: " << s1 << "\nOutput: " << decodeString(s1) << endl;
    cout << "Input: " << s2 << "\nOutput: " << decodeString(s2) << endl;

    return 0;
}
*/ 

/* Q. 3: We have an absolute path for a file(Unix-style), simplyfy it Note that 
      absolute path always begins with'/' (rootdirectory), a dot in path 
	  represents current directory and double dot represents parent directory. 
	 
Example: input: path = "home//foo/" 
Output: "/home/foo"
explanation: Multiple consecutive slashes are replaced by a single one*/ 

//without Linklist
/*
#include <iostream> 
#include <stack> 
#include <string> 

using namespace std; 

string simplyfyPath(string path){
	stack<string>s; 
	int length = path.length(); 
	
	int i = 0; 
	
	while(i < length){
//		- skip the initial '/' 
		while(i< length && path[i] == '/'){
			i++; 
		}
		
//       - Extract the part between slashes 
		string part = ""; 
		while(i<length && path[i] != '/'){
			part = part + path[i]; 
			i++;
		}
		
		if(part == ""|| part == "."){
//		 - ignore empty parts and current director '.' 
			continue; 
		}else if(part == "..") {
//		 - Go up to the parent directory if possible 
			if(!s.empty()){
				s.pop();
		   }
		}else{
//		 - valid directori name, push to stack 
				s.push(part); 
			}
		}
//		 - Construct the simplified path from stack 
		if(s.empty()){
			return "/"; 
		}
		
		string simplifiedPath = ""; 
		
		while (!s.empty()){
			simplifiedPath = "/" + s.top() + simplifiedPath; 
			s.pop(); 
		}
		return simplifiedPath; 		
}
int main(){
	string path1 = "/home//foo/"; 
	string path2 = "/home/user/Documents/../Pictures";
	
	cout << "input: " << path1 << "\n Output: " << simplyfyPath(path1) << endl; 
	cout << "input: " << path2 << "\n Output: " << simplyfyPath(path2) << endl; 
	return 0; 
}

*/ 

/* Q.4 Given n non negative integers representing an elevation map where the 
     width of each bar is, compute how much water it can trap after raining. 
     
Examples: input height = {7, 0, 4, 2, 5, 0, 6, 4, 0, 5}
		  		trap water = [6, 2, 4, 1, 6, 1, 5]
		  		   
*/ 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
    if (height.empty()) return 0;

    int left = 0; // indexe 
    int right = height.size() - 1; // index
    int leftMax = 0; // traveler 
    int rightMax = 0; // traveler
    int waterTrapped = 0;  //total trapped of water

    while (left < right) { // 
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                waterTrapped += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                waterTrapped += rightMax - height[right];
            }
            right--;
        }
    }

    return waterTrapped;
}

int main() {
    vector<int> height = {7, 0, 4, 2, 5, 0, 6, 4, 0, 5};
    cout << "Water trapped: " << trap(height) << endl; // Output: 25
    return 0;
}


