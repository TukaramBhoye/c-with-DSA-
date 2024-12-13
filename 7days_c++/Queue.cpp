    // 34:NB2:23: Queue: FIFO 
/* 
#include <iostream>

using namespace std; 

class Node{
	public: 
	int data; 
	Node* next; 
	
	Node(int data){
		this->data =  data; 
		this->next = NULL; 
	}
};

class Queue{
	Node* head; 
	Node* tail; 
	
	public: 
	Queue(){
		head = tail = NULL;
	}
	
	void push(int data){
		Node* newNode = new Node(data);
		if(head == NULL){
			head = tail = newNode; 
		}else{
			tail->next = newNode; 
			tail = newNode; 
		}
	}
	
	void pop(){
		if(empty()){
			cout << "queue is empty\n"; 
			return; 
		}
		Node* temp = head; 
		head = head->next; 
		delete temp; 
	}
	int front(){
		if(empty()){
			cout<< "queue is empty\n"; 
			return -1; 
		}
		return head->data; 
	}
	
	bool empty(){
		return head == NULL; 
	}	
};

int main (){
	Queue q; 
	
	q.push(1); 
	q.push(2); 
	q.push(3);
	
	while (!q.empty()){
		q.pop(); 
		cout << q.front() << endl; 
	} 
	
	return 0; 
}
*/ 

// Q. 2: Circular queue IMplementation: Using arrays 
/* 
#include <iostream> 
using namespace std; 

class Queue{
	int *arr; 
	
	int capacity;   // n 
	int currSize;  // 4  
	
	int f, r; 
	
public: 
		Queue(int capacity){
			this->capacity = capacity; 
			arr = new int[capacity]; //allocate memory as size  
			currSize = 0; 
			
			f = 0; // in front() he trying to accessing -1  
		    r = -1; // so that case prevent here right f = 0 & r = -1
		}
		
//		 - All functions are in O(1) TC 
		void push(int data){
			if(currSize == capacity ){
				cout << "queue is full \n"<< endl; 
				return;  
			}
			
			r = (r + 1) % capacity; 
			arr[r] = data; // r ko store into data 
			currSize++; 
		}
		
		void pop(){
			if(empty()){
				cout << "Quote is Empty \n"; 
				return; 
			}
			f = (f + 1) % capacity; 
			currSize--; 
		}
		
		int front(){
			if(empty()){
				cout << "Queue is empty \n ";
				return -1;  
			}
			
			return arr[f]; // return front
		}
		
		bool empty(){
			return currSize == 0; 
		}
		
       void printRear(){
	   		cout << arr[r] << endl;	
       }
};


int main(){
	Queue q(4); // maximum capacity of size 4 

	q.push(1); 
	q.push(2); 
	q.push(3); 
	q.push(4);
	q.push(5); 
	
	cout << q.front() << endl ; 
	q.pop();
	
	cout << q.front() << endl; 
	q.push(5); 
	cout << q.front() << endl; 
	q.printRear();
	return 0; 
}
*/ 

//Q. 3: Queue in STL : #include <queue>
/*
#include <iostream>
#include <queue>
using namespace std; 

int main (){
	queue<int> q; 
	
	q.push(1); 
	q.push(2); 
	q.push(3); 
	q.push(4); 	
	while(!q.empty()){
		cout << q.front()<< endl;
		q.pop(); 
	}
	return 0; 
}
*/ 

//Q.4: Queue Using 2 Stack : use queue 1 and 2 stack for values get top by( revers)
// Homework is same Q. use : for push do O(1) TC Or Pop O(n) TC 
/*
#include <iostream>
#include <stack>
using namespace std; 
class Queue{ 
	  stack<int> s1; 
	  stack<int> s2; 
    public: 
 		 
        void push(int data){ // O(n) 
 			 // s1 -> s2 
			  while(!s1.empty()){
			    s2.push(s1.top()); 
			  	s1.pop(); 
			  }
			 s1.push(data);   
			
			//s2 -> s1	
			while(!s2.empty()){
				s1.push(s2.top());
				s2.pop();
			}
        }
        
        void pop() {
        	s1.pop(); 
		}
		
		int front(){
			return s1.top(); 
		}
		
		bool empty(){
			return s1.empty(); 
		}
};
int main (){
	Queue q;
 	q.push(1); 
 	q.push(2); 
 	q.push(3); 
 	
 	while(!q.empty()) {
 		cout << q.front() << endl; 
 		q.pop(); 
	 }
    
    return 0; 
}
*/ 

//Q.5:NB2:27: Stack using 2 Queues
/*
#include <iostream> 
#include <queue> 

using namespace std; 

class Stack{
	queue<int> q1; 
	queue<int> q2; 
	
	public: 
           void push(int data){
      	       while(!q1.empty()){
     		       q2.push(q1.front()); 
     		       q1.pop(); 
               }
                q1.push(data); 
                
                while(!q2.empty()){
                	q1.push(q2.front()); 
                	q2.pop(); 
				}	
            }
           void pop(){
		   	  q1.pop(); 
		   }
		   
		   int top(){
		   	  return q1.front(); 
		   }
		   
		   bool empty(){
		   	  return q1.empty(); 
		   }		   		  
};

int main(){
	Stack s; 
	
	s.push(1); 
	s.push(2); 
	s.push(3); 
	
	while(!s.empty()){
		cout << s.top()<< endl; 
		s.pop(); 
	}
	return 0; 
}
*/ 
//Q.6:NB2:28: Non-Repeating Letter: 
//- Find First Non-repeating letter in a Stream of characters 
/*
#include <iostream>
#include <queue>
#include <string>
using namespace std; 

void FirstNonRepeat(string str){
	queue<char>Q; 
	int freq[26] = {0}; 
	
	for(int i=0; i<str.size(); i++){
		char ch = str[i];
		Q.push(ch); 
		freq[ch-'a']++; 
		
		while(!Q.empty() && freq[Q.front()-'a'] > 1){ // -'a' Q.front ka index nikalne ke liye  
			Q.pop(); 
		}
		
		if(Q.empty()){
			cout << "-1\n"; 
		}else{
			cout << Q.front() << "\n"; 
		}
	}
}
int main (){
	string str = "aabccxb";
	
	FirstNonRepeat(str); 
	return 0; 
} */ 

/*Q. 7 Interleave 2 Queues: 
Interleave 2 halves of a queue of even size: 
Ognl-Q: 1 2 3 4 5 6 7 8 9 10 : to queue just forward travelled possible No backward: 
ans:     1 6 2 7 3 8 4 9 5 10 : 
*/ 
/*
#include <iostream>
#include <queue>// containers:stack, queue, vector passes pass by value
using namespace std;

void interleave(queue<int>&org){
	int n = org.size(); 
	queue<int>first; 
	
	for(int i=1; i<=n/2; i++){
		first.push(org.front()); 
		org.pop(); 
	}
	
	while(!first.empty()){
		org.push(first.front()); 
		first.pop(); 
		
		org.push(org.front()); 
		org.pop(); 
	}
}
int main(){
	queue<int> org; 
	for(int i=1; i<=10; i++){
		org.push(i);
	}
	
	interleave(org); 
	
	for(int i=1; i<=10; i++){
		cout << org.front() << " "; 
		org.pop(); 
	}
	cout << endl; 
	return 0; 
}*/ 

//Q.8: Queue Reversal : Reverse a Queue 
/*
#include <iostream> 
#include <stack> 
#include <queue>
using namespace std;

void reverse(queue<int> &q){
	stack<int> s;
	
	while(!q.empty()){
		s.push(q.front()); // front() queue library. 
		q.pop(); 
	}
	
	while(!s.empty()){
		q.push(s.top()); // top() stack library 
		s.pop(); 
	}
}
int main (){
	queue<int> q; 
	for(int i=1; i<=5; i++){
		q.push(i); 
	}
	
	reverse(q);
	
	for(int i=1; i<=5; i++){
		cout << q.front() << " "; 
		q.pop();
	}
	cout << endl; 
	return 0; 
}
*/ 
//Q.9:NB2:30:  New Datatructure : Deque: 
/*
#include <iostream> 
#include <deque> 
using namespace std; 

int main(){
	deque<int> deq; 
	
	deq.push_front(2); 
	deq.push_front(1); 
	
	deq.push_back(3); 
	deq.push_back(4); 
	
	// 1 2 3 4 
	
	deq.pop_front();
	deq.pop_back();
	
	cout << deq.front()<< "  ";
	cout << deq.back(); 
	return 0; 
}
*/
//Q. 10: Queue using Deque: 
/*
#include <iostream>
#include <deque>

using namespace std; 

class Queue{
	deque<int> deq; 
	public: 
	void push(int data){
		deq.push_back(data); 
		 
	}
	
	void pop(){
		deq.pop_front(); 
	}
	
	int front(){
		return deq.front(); 
	}
	
	bool empty(){
		return deq.empty(); 
	}
};

int main (){
	Queue q; 
	for(int i=1; i<=5; i++){
		q.push(i); 
	}
	
	for(int i=1; i<=5; i++){
		cout << q.front() << endl; 
		q.pop(); 
	}
	return 0; 
}
*/

//Assignment : 
/* QA:1: There are n people in a line queing to buy tickets, 
  where the 0th person is at the front of the line and the 
  (n-1)th person is at the back of the line.
  
  You are given a o-indexed integer array tickets of length 
  n where the number of tickts that the  ith  person would like 
  to buy is ticket[i]. 
  
Input tickets = [2, 3, 2] k = 2
output: 6
*/ 
/* 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to calculate the time required to buy tickets
int timeRequireToBuy(vector<int> &tickets, int k) {
    queue<pair<int, int>> q;
    int n = tickets.size();
    
    // Initialize the queue with ticket counts and their original indices
    for (int i = 0; i < n; i++) {
        q.push({tickets[i], i});
    }
    
    int time = 0;
    while (!q.empty()) {
        pair<int, int> frontPair = q.front();  // Explicitly declare frontPair
        int num_tickets = frontPair.first;     // Extract number of tickets
        int og_i = frontPair.second;           // Extract original index
        q.pop();
        num_tickets--;
        time++;
        
        // Check if the required ticket is bought and no tickets left
        if (og_i == k && num_tickets == 0) {
            return time;
        }
        
        // If there are remaining tickets, push back to the queue
        if (num_tickets > 0) {
            q.push({num_tickets, og_i});
        }
    }
    return time;
}

int main() {
    // Example usage:
    vector<int> tickets = {2, 3, 2};
    int k = 2; // Index of the ticket we want to buy
    
    int timeTaken = timeRequireToBuy(tickets, k);
    
    cout << "Time required to buy ticket at index " << k << " is: " << timeTaken << " minutes." << endl;
    
    return 0;
}
*/ 

/* Q.2: There are n gas station along a circular route, where the amount of 
gas at the ith station is gas[i]. 

*/ 
// use Deque to solve question 
/* 
#include <iostream>
#include <stack> 
#include <queue> 
using namespace std; 

int canCompleteCircuit(vector<int>&gas, vector<int>&cost){
	int totalgas = 0; 
	int currgas = 0; 
	int startIndex = 0; 
	
	for(int i = 0; i<gas.size(); i++){
//	(gas-cost) add in total and currgas. 

        currgas = currgas + gas[i] - cost[i]; 
	
	// if current is -ve then reintialize startindex.
		if(currgas<0){
			startIndex = i+1;
			currgas = 0; 
		}
	
	}
	return totalgas >= 0 ? startIndex : -1; 
}
int main (){
	vector<int> gas = {1, 2, 3, 4, 5};
	vector<int> cost = {3, 4, 5, 1, 2};
	
	int start = canCompleteCircuit(gas, cost); 
	
	if(start != -1){
		cout << "Starting at station index: " << start << endl; 
	}else{
		cout << "Cannot complete the circuit. "<< endl; 
	}
	return 0; 
}
 */ 
 
/* Q.3: Given an integer K and a queue of integers, we need to 
  reverse the order of the first K elements of the queue, leaving
  the other elements in the same relative order. 
  */ 
/*
#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    struct Node {
        int key, value;
        Node* next;
        Node* prev;
        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

    unordered_map<int, Node*> map;
    int capacity;
    Node* head;
    Node* tail;

    void pushToHead(Node* node) {
        remove(node);
        add(node);
    }

    void add(Node* node) {
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        Node* node = map[key];

        pushToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            node->value = value;
            pushToHead(node);
        } else {
            if (map.size() >= capacity) {
                Node* lru = tail->prev;
                map.erase(lru->key);
                remove(lru);
                delete lru;
            }

            Node* node = new Node(key, value);
            map[key] = node;
            add(node);
        }
    }
};

int main() {
    LRUCache cache(2); // Create a cache with capacity 2

    // Test put and get operations
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // Output should be 1

    cache.put(3, 3); // Evicts key 2
    cout << cache.get(2) << endl; // Output should be -1, because key 2 is evicted

    cache.put(4, 4); // Evicts key 1
    cout << cache.get(1) << endl; // Output should be -1, because key 1 is evicted
    cout << cache.get(3) << endl; // Output should be 3
    cout << cache.get(4) << endl; // Output should be 4

    return 0;
}
*/

//Q3 :  

#include <iostream> 
#include <queue> 
#include <stack> 
using namespace std; 

void reverseFirstElement(queue<int> &q, int k){
	if(q. empty() || k > q.size()|| k <= 0)return; 
	stack<int> s; 
	
	// push first k element into the stack
  
  	for(int i = 0; i<k; ++i){
  		s.push(q.front()); 
		q.pop();  
    }
    
    // enqueu back the stack elements to the queue
    
    while(!s.empty()){
    	q.push(s.top()); 
    	s.pop(); 
	}
	
	// move the remaining elements from the front to the near to maintain order
	
	int remainingElements = q.size() - k; 
	
	for(int i = 0; i<remainingElements; ++i){
		q.push(q.front()); 
		q.pop(); 
	}
}

void printQueue(queue<int>& q){
	queue<int> temp = q; 
	while(!temp.empty()){
		cout << temp.front() << " ";
		temp.pop(); 
	}
	cout << endl; 
}

int main(){
	queue<int> q; 
	q.push(1); 
	q.push(2); 
	q.push(3); 
	q.push(4); 
	q.push(5); 
	
	int k = 3; 
	cout << "Original queue: "; 
	printQueue(q); // op : 1 2 3 4 5 
	
	reverseFirstElement(q, k); 
	
	cout << "Queue after reversing first "<< k << " elements"<< endl; 
	printQueue(q);  //op:  3 2 1 4 5
	return 0; 
}
