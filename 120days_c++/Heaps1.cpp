// Heaps: 
// 2:NB:50: Priority Queue(PQ) in STL : 
//i: highest priority Queue: 
/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std; 
int main(){
	priority_queue<int>pq;
	
	pq.push(5); 
	pq.push(10);
	pq.push(9); 
	pq.push(7);
	pq.push(3); 
	
	while(!pq.empty()){
		cout << "top: "<< pq.top() << endl; 
		pq.pop(); 
	}
	return 0; 
}
*/ 

//ii: lowest priority Queue: 
// also we do operation for string data : 
/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std; 
int main(){
	priority_queue<int, vector<int>, greater<int>>pq;
	
	pq.push(5); 
	pq.push(10);
	pq.push(9); 
	pq.push(7);
	pq.push(3); 
	
	while(!pq.empty()){
		cout << "top: "<< pq.top() << endl; 
		pq.pop(); 
	}
	return 0; 
}

*/

//Q.2 Push In Heap:  
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std; 

class Heap{
	vector<int> vec; 
	
	public: 
	
	 void push(int val){
	 	//step1 
	 	vec.push_back(val); 
	 	
	 	//fix heap 
	 	int x = vec.size()-1; //childI
	 	int parI = (x-1)/2; 
	 	
	 	
	 	// for minHeap reverse conditions: 
	 	while(parI >= 0 && vec[x] > vec[parI]){
	 		swap(vec[x], vec[parI]); 
	 		x = parI; 
	 		parI = (x-1)/2; 
		 }
	 }
	 
	 void heapify(int i){
	 	
	 	if(i >= vec.size()){
	 		return; 
		 }
	 	
	 	int l = 2 * i + 1;
	 	int r = 2 * i + 2;  
	 	
	 	int maxI = i; 
	 	
	 	if(l < vec.size() && vec[l] > vec[maxI]){
	 		maxI = l; 
		 }
		 
		 if(r < vec.size() && vec[r] > vec[maxI]){
		 	maxI = r; 
		 }
		 swap(vec[i], vec[maxI]); 
		 if(maxI != i){ // swapping with child node
		     heapify(maxI); 
		 }
	 }
	 
	 void pop(){
	 	//step1
	 	swap(vec[0], vec[vec.size()-1]); 
	 	
	 	//step2
	 	vec.pop_back();
	 	
//	 	step3
		heapify(0); // O(log n)
	 }
	 
	 int top(){ // O(1) 
	 	 return vec[0]; //highest priority element
	 }
	 
	 bool empty(){
	 	return vec.size() == 0; 
	 }
};

int main(){
	Heap heap; 
	
	heap.push(9); 
	heap.push(4); 
	heap.push(8);
	heap.push(1); 
	heap.push(2); 
	heap.push(5);
	
	
	while(!heap.empty()){
		cout << "top : "<< heap.top() << endl; //Op:  
		heap.pop(); 
	}
	
	
	cout << "top = " << heap.top() << endl; //op:  50
	return 0; 
}
 */ 
 
 // PQ(priority Queue) for Ibjects : 
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

class Student { //"<" overload : 
    public: 
    string name; 
    int rank; 
    
    Student(string name, int rank){
        this->name = name; 
        this->rank = rank; 
    }
    	// Operator overloading for priority queue comparison
    bool operator < (const Student &obj) const {  // build a default max heap  
        return this->rank < obj.rank;
//		 return this ->rank > obj.rank; // for minHeap 
    }
};

int main(){
	priority_queue<Student> pq; 
	
	pq.push(Student("tukaram", 85));
	pq.push(Student("Akshay", 95)); 
	pq.push(Student("marathi", 84)); 
	
    while (!pq.empty()) {
        cout << "Top = " << pq.top().name << ", " << pq.top().rank << endl;
        pq.pop();
    }
	return 0; 
}
*/ 

// PQ Pairs for pairs: 

#include <iostream> 
#include <vector>
#include <queue>
using namespace std; 

struct Compare{
	bool operator() (pair<string, int> &p1, pair<string, int> &p2){
		return p1.second < p2.second;
	}
};

int main(){
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq; 
	
	pq.push(make_pair("aman", 500));
	pq.push(make_pair("tukaram", 1000)); 
	pq.push(make_pair("chetan", 2000)); 
	
	while(!pq.empty()){
		cout << "top = "<< pq.top().first << ", "<< pq.top().second << endl; 
		pq.pop(); 
	}
	
	return 0; 
}


