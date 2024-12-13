// 30: Link_List(LL) :   
/*1: Linked List Kya Hai?
Linked List ek aisa data structure hai jo ek sequence mein 
items ko store karta hai. Har item ko ek "node" bola jata hai, 
aur har node ke paas do cheezein hoti hain: ek data aur doosra 
next node ka address. */ 

//1: Structure of Link List :
/*#include <iostream>
using namespace std; 
	class Node{
		int data; 
		Node* next; 
	public: 
	    Node(int val){
	    	data = val; 
	    	next = NULL; 
		}
	};
	
	// LInk List : 
	class List{
		 Node* head; 
		 Node* tail; 
	public: 
		List(){
			head = NULL; 
			tail = NULL; 
		}	
	};
	
	int main (){
		List ll(); 
    	return 0;
	
}
*/
//2: Eaxample of LL : using functions 1: push_back, push_front
// Not Run :
/* 
#include <iostream>
using namespace std; 

class Node {
public: 
    int data; 
    Node* next; 

    Node(int val) {
        data = val; 
        next = NULL; 
    }
    
    ~Node(){
    	cout << "~Node " << data <<  endl; 
    	if(next != NULL){
    		delete next; 
    		next = NULL; 
		} // delete from tail to head 
	}
};

//Linked List: 
class List {

	    Node* head; 
	    Node* tail; 
	    
    public:
	    List() {
	        head = NULL; 
	        tail = NULL; 
	    }
	    
	    ~List(){
	    	cout << "~List\n "; 
	    	if(head != NULL){
				delete head; 
				head = NULL; 
			}
	}

	// 1: 
    void push_front(int val) {
        Node* newNode = new Node(val); // dynamic allocation here we allocate 
        // Dynamic allocation: to prevent newNode from being deleted when it goes out of scope
        
        if(head == NULL) { // corrected from `=` to `==`
            head = tail = newNode; 
        } else {
            newNode->next= head;
            head = newNode; 
        }    
    }
	//2:
    void push_back(int val) {
        Node* newNode = new Node(val); 
        
        if(head == NULL) {
            head = tail = newNode; 
        } else {
            tail->next = newNode;  // points towards next Node
            tail = newNode; 
        }    
    }
	//3: 
    void printList() {
        Node* temp = head; 
        
        while(temp != NULL) {
            cout << temp->data << "-> "; 
            temp = temp->next; 
        }
        cout << "null" << endl; // add "null" at the end to match the expected output
    } 
	
	//4:Insert In LL Middle : insert node at a given position in the LL 
	// LL.insert(val,pos)
	 
	void insert(int val, int pos){
		Node* newNode = new Node(val);
		
		Node* temp = head; 
		for(int i=0; i<pos-1; i++){
			if(temp == NULL){
				cout << "position is Invalid\n"; 
				return; 
			}
			temp = temp->next; 
		}
		
		//temp is now at pos-1 i.e. prev/left
		newNode->next=temp -> next; 
		temp->next = newNode; 
	}  
	
	//5:Pop_front : delete first Node: 
	void pop_front(){
		
		if(head == NULL){
			cout << "LL empty\n"; 
			return; 
		}
		Node* temp = head; 
		head = head->next; 
		
		temp->next = NULL; // delete first node 
		delete temp; 
	}
	
	//	6:Pop Back: ll.pop_back()
	void pop_back(){
		Node* temp = head; 
		
		while(temp->next->next != NULL){ 
  		     temp = temp -> next; 
		}
		
		temp->next = NULL; // temp = tail's prev 
		delete tail; 
		tail = temp; 
	}
	 // 7: Iterative Search : key=2 ; 
	 int searchItr(int key){
	 	Node* temp = head; 
	 	int idx = 0; 
	 	
	 	while(temp != NULL){
	 		if( temp->data == key){ 
	 		   return idx;
			 }
			 temp = temp->next; 
			 idx++; 
		 }
		 return -1; 
	 }
	 
	 //8: Find key using Recursive : 
    int helper(Node* h, int key){
    	if(h == NULL){
    		return -1; 
		}
    	
    	
    	if(h->data == key){
    		return 0; 
		}
		
		int idx = helper(h->next, key); 
		if(idx == -1){
			return -1; 
		}
		
		return idx + 1; 
	}
	int searchRec(int key){
    	return helper(head, key); 
	}
	
	// 9: Reverse Linked List: 
	
	void reverse(){
		Node* curr = head; 
		Node* prev = NULL; 
		tail = head; 
		while(curr != NULL){
			Node* next = curr->next;
			curr->next = prev; 
			
			//Updation for next itr
			
			prev = curr; 
			curr = next; 
		}
		head = prev;
	}
	
	//10: FInd and remove nth node From End: 
	int getSize(){
		int sz = 0; 
		Node* temp = head; 
		
		while(temp != NULL){
			temp = temp->next; 
			sz++; 
		}
		return sz; 
	}
	void removeNth(int n){ // n position which have remove
		int size = getSize(); 
		
		Node* prev = head; 
	   for(int i=1; i<(size-n); i++){ // i = size-n => prev => deletion node prev 
	   	prev = prev->next;
	   }
	   Node* toDel = prev->next; 
	   cout << "going to delete: "<< toDel->data << endl;
	   
	   prev->next = prev->next->next; 
	}  
};

int main () {
    List li; // corrected from `List li();`
    
	li.push_front(5); 
	li.push_front(4); 
    li.push_front(3); 
    li.push_front(2);
    li.push_front(1);
    li.printList();
    
//    cout << li.searchItr(2) << endl; 
//	  cout << li.searchRec(4) << endl; 
//	  li.reverse(); 
//	  li.printList(); 

	  li.removeNth(2); 
	  li.printList(); 

    
    
//    li.pop_front(); 
//    li.pop_back(); 
//	 li.printList(); // 
    
//    li.push_back(4); 
//    li.push_back(5);
//     //1-> 2-> 3-> 4-> 5-> null
//    
//    li.insert(100, 2);// (100, pos 25) invwlid 25 position not exist
//    li.printList(); //1-> 2-> 100-> 3-> 4-> 5-> null
    return 0;
} 
li.printList();
*/ /***************************************
**Detect a cycle/loop in LL :  *************************************************/
/*Explaination : Ye kaise hota hai?
Ek famous algorithm hai jo hum use karte hain, jise "Floyd’s 
Cycle-Finding Algorithm" ya "Tortoise and Hare Algorithm" kehte 
hain. Isme hum do pointers use karte hain:

1: Slow Pointer (Tortoise): Ye ek step aage badhta hai har turn pe.
2: Fast Pointer (Hare): Ye do step aage badhta hai har turn pe.
   Algorithm kaise chalta hai?
1: Pehle, slow aur fast dono ko head pe rakho.
2: Fir slow ko ek step aage badhao aur fast ko do step aage badhao.
3: Agar kabhi fast aur slow ek hi node pe aa jaate hain, iska matlab list me cycle hai.
4: Agar fast pointer null ya uske next null milta hai, toh cycle 
   nahi hai (list khatam ho gayi bina cycle ke). 
  
Code: *//* 
#include <iostream>
#include <string>
using namespace std; 

class Node { 
    public: 
	  int data; 
	  Node* next; 
	Node(int data){
		this->data = data; 
		next = NULL; 
	}  	  
};

class List {
	public: 
	    Node* head; 
	    Node* tail; 
    List(){
    	head = NULL; 
    	tail = NULL; 
	}
	
	void push_front(int val){
		Node* newNode = new Node(val);
		if(tail == NULL){
		    head = tail = newNode; 
		}else{
			newNode->next = head; 
			head = newNode; 
		}
	}
	void pop_front(){
		if(head==NULL){
			return; 
		}
		Node* temp = head;
		head = head->next; 
		
		temp->next = NULL;
		delete temp; 
	}
		
};
void printList(Node* head){
    Node* temp = head; 
    while(temp != NULL){
        cout << temp->data << "->"; 
        temp = temp->next; 
    }
    cout << "NULL\n"; 
}
// 10: Detect a cycle /Loop in Link List
bool isCycle(Node* head){
	Node* slow = head; 
	Node* fast = head; 
	
	while (fast != NULL && fast->next != NULL ){
		slow = slow->next; //update slow +1
		fast = fast->next->next; //+2
		
		if(slow == fast){
			cout << "cycle exists \n"; 
			return true; 
		}
	}
	cout << "cycle doesn't exist\n "; 
	return false ;
}
//Removing Cycle in Link List: 
void removeCycle(Node* head){
	//detect cycle
	Node* slow = head; 
	Node* fast = head; 
	
	while(fast != NULL && fast->next != NULL){
		slow = slow->next; 
		fast = fast->next->next; 
		bool isCycle = false; 
		
		
		if(slow == fast){ 
		    cout << "cycle exist\n"; 
		    isCycle = true; 
		    break; 
		} 
	}
	if(!isCycle){
		cout << "cycle doesn't exist \n"; 
		return; 
	}
	
	slow = head; 
	if(slow == fast){ // Special case : tail -> head
		while(fast->next != slow){
			fast = fast->next; 
		}
		fast->next = NULL; // remove Cycle
	}else {
		Node* prev = fast; 
		while(slow != fast){
		   slow = slow->next; 
		   prev = fast; 
		   fast = fast->next; 	
		}
		prev->next = NULL; // remove cycle
	}
}

int main () {
	List li; 
	
	li.push_front(5); 
	li.push_front(4); 
	li.push_front(3);
	li.push_front(2);
	li.push_front(1);
	
 
	li.tail->next = li.head;  
//	isCycle(li.head); 
	removeCycle(li.head);
	printList(li.head); 
	return 0; 
}
*/
//2: List in STL : 
/* Iterator : Iterator in c++ are Object that allow you to 
   traverse through the element of a container (like arrays, 
   vectors, lists, etc) in a sequential manner 
   */ 
 /*  
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;
    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        temp->next = NULL;
        delete temp;
    }
};

Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
    }

    return slow; // slow is the head of the right half
}
*/
// 3:NB:114: merge Sort
/*To ye "->" bas ek tarika hai jisse tu us node ke data aur next ko access kar sakta hai, jo pointer i aur j dekh rahe hain. Samjha?
Chal, aise samajh. i aur j do bande hain, theek hai? Aur ye 
dono bande ek linked list ke alag-alag nodes ko point kar rahe hain. Jab tu i->data likhta hai, to tu i bande se bol raha hai, "Oye i, jis node ko tu dekh raha hai, uska data mujhe de de." Aur jab tu i->next likhta hai, to tu i se keh raha hai, "Bhai, agla node kaun sa hai, mujhe bata."*/ 
/*
Node* merge(Node* left, Node* right) {
    List ans;
    Node* i = left;
    Node* j = right;

    while (i != NULL && j != NULL) {
        if (i->data <= j->data) {
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;
        }
    }
    while (i != NULL) {
        ans.push_back(i->data); // corrected to use i
        i = i->next; // move i to next
    }
    while (j != NULL) { // corrected to use j
        ans.push_back(j->data);
        j = j->next; // move j to next
    }
    return ans.head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* rightHead = splitAtMid(head);

    Node* left = mergeSort(head); // left head
    Node* right = mergeSort(rightHead); // right head

    return merge(left, right); // both are sorted LL
}

Node* reverse(Node* head) { 
    Node* prev = NULL; 
    Node* curr = head; 
    Node* next = NULL; 
     
    while (curr != NULL) {
        next = curr->next; 
        curr->next = prev; 
        
        prev = curr; 
        curr = next; 
    }
    return prev; // prev is head of reversed LL 
}
// 5:NB:116
Node* zigZagLL(Node* head){
	 
	Node* rightHead = splitAtMid(head); 
	Node* rightHeadRev = reverse(rightHead);
	
//	Alternate Merging : 1st head = head 2nd head = rightHeadRev 
 	Node* left = head; 
 	Node* right = rightHeadRev; 
 	Node* tail = right;

 	
 	while(left != NULL && right != NULL){
 		Node* nextLeft = left->next; 
 		Node* nextRight = right->next; 
 		
 		left->next = right; 
 		right->next = nextLeft; 
 		
 		tail = right ;
 		
 		left = nextLeft; 
 		right = nextRight; 
	 }
     
     if(right != NULL){
     
		tail->next = right; 
	 }
	 return head; 
}

int main() {
    List ll;

    ll.push_front(1);
    ll.push_front(2); // 2->1
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    //1->2->3->4->5->NULL 
    printList(ll.head); 
    
   ll.head = zigZagLL(ll.head);  
   printList(ll.head);
*/
/*    cout << "Original list: ";
    printList(ll.head);

    ll.head = mergeSort(ll.head);

    cout << "Sorted list: ";
    printList(ll.head);
*/
/*	
	ll.push_back(3); // 1->2->3-> 
	ll.push_back(4); // 1->2->3-> 	
	
	printList(ll); 
	// List in (STL) Standard tepmplate library
	cout << "head = " <<ll.front() << "\n"; 
	cout << "tail = " <<ll.back() << "\n";  
	
    ll.pop_front(); 
 	ll.pop_back();   
    printList(ll); 
    
    list<int>:: iterator it = ll.begin(); 
    
    advance(it, 2); 
    ll.insert(it, 2); 
    ll.insert(it, 99); 
    
    printList(ll); 
    
	return 0; 
}

*/ 
/*
#include <iostream>
using namespace std; 

class Node{
	public: 
	int data; 
	Node* next; 
	Node* prev; 
	
	Node(int val){
		data = val; 
		prev = next = NULL; 	
	}
};

class DoublyList{
	public: 
	Node* head; 
	Node* tail; 
	
	DoublyList(){
		head = tail = NULL; 
	}
	
	void push_front(int val){
		Node* newNode = new Node(val); 
		
		if(head == NULL){
			head = tail = newNode; 
		}else{
			newNode->next = head; 
			head->prev = newNode; 
			head = newNode; 
	
		}
	}
	
	void pop_front(){
		Node* temp = head; 
		head = head->next; 
		
		if(head != NULL){
			head->prev = NULL; 
		}
		
		temp->next = NULL; 
		delete temp; 
	}
	
	void printList(){
		Node* temp = head; 
		while(temp != NULL){
			cout << temp->data<< " <=> ";
			temp = temp ->next; 
		}
		cout << "NULL\n"; 
	}
};

int main(){
	DoublyList dbl; 
	
	dbl.push_front(4);
	dbl.push_front(3);
	dbl.push_front(2);
	dbl.push_front(1);
	
	dbl.printList(); 
	
	dbl.pop_front();
	dbl.printList(); 
	return 0; 
}
*/  
/*AssingnMents: Linked List: 
Q:1 Itersection of Two Linked Lists 
  In a System there are two linked list. By some programming error, 
  the end node of one of the linked lists got linked to the second 
  list, forming an inverted Y-shaped list Write a program to get the 
  point where two linked liss merge
  
  *Note we ahve to find the intersection part in this system.*/  
 
 /*i: Singly Linked list :                         
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = NULL;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int getCount(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getIntersectionNode(Node* head1, Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d = abs(c1 - c2);
 	       	  		   	 	 	// count here 4 = 4, 5, 6, 7
                              //5 = 1, 2, 3, 6, 7
		  	 	   	   	     // antar  = c1 - c2 = 4 - 5 = 1 : head2 firstNode will drop 
						    // make it equal: 2, 3, 6, 7:  2, 3, 6, 7 
	
	    if (c1 > c2) {
	        for (int i = 0; i < d; i++) {
	            head1 = head1->next;
	        }
	    } else {
	        for (int i = 0; i < d; i++) {
	            head2 = head2->next;
        }
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    SinglyLinkedList list1, list2;

    list1.append(1);
    list1.append(4);
    list1.append(5);
    Node* intersectingNode = new Node(6);
    list1.head->next->next->next = intersectingNode;
    list1.head->next->next->next->next = new Node(7);

    list2.append(2);
    list2.append(3);
    list2.head->next->next = intersectingNode;

    cout << "List 1: ";
    list1.printList();
    cout << "List 2: ";
    list2.printList();

    Node* intersection = getIntersectionNode(list1.head, list2.head);

    if (intersection != NULL) {
        cout << "The intersection point is: " << intersection->data << endl;
    } else {
        cout << "There is no intersection point." << endl;
    }

    return 0;
}
*/

//2: doubly LInkList:
/*
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

        delete temp;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int getCount(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getIntersecNode(Node* head1, Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d = abs(c1 - c2);

    if (c1 > c2) {
        for (int i = 0; i < d; i++) {
            head1 = head1->next;
        }
    } else {
        for (int i = 0; i < d; i++) {
            head2 = head2->next;
        }
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    DoublyList list1, list2;

    list1.push_front(7);
    list1.push_front(6);
    list1.push_front(5);
    list1.push_front(4);

    list2.push_front(1);
    list2.push_front(2);
    list2.push_front(3);
   

    // Create intersection at node with value 6
    list2.head->next->next = list1.head->next->next->next;

    cout << "List 1: ";
    list1.printList();
    cout << "List 2: ";
    list2.printList();

    Node* intersection = getIntersecNode(list1.head, list2.head);

    if (intersection != NULL) {
        cout << "The intersection point is: " << intersection->data << endl;
    } else {
        cout << "There is no intersection point." << endl;
    }

    return 0;
}
*/

//Q. 2: 
/* Delete N Nodes After M Nodes of a Linked List
   WE have a linked list and two integers M and N. Traverse the linked 
   list such that you retain M nodes then delete N nodes, continue the 
   same till end of the linked list. Difficulty Level Rookie
   
   Sample Input 1 : M = 2 N = 2   LL: 1->2->3->5->6->7-> 
   Sample Output 1 : 1->2->5->6
   
   Sample Input2: M = 3 N = 2 LL : LL: 1->2->3->4->5->6->7->8->9->10
*/ /*
#include <iostream>
using namespace std;

// Definition of a Node in doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// Doubly linked list class
class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = tail = NULL;
    }

    // Function to add a new node with value val at the front of the list
    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to remove the node from the front of the list
    void pop_front() {
        if (head == NULL) return;

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

        delete temp;
    }

    // Function to delete N nodes after M nodes in a linked list
    void deleteNodes(int M, int N) {
        if (head == NULL) return;

        Node* current = head;
        Node* prev = NULL;

        while (current != NULL) {
            // Skip M nodes
            for (int i = 1; i <= M && current != NULL; i++) {
                prev = current;
                current = current->next;
            }

            // Delete N nodes
            for (int i = 1; i <= N && current != NULL; i++) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }

            // Link the previous node to the current node after deletion
            if (prev != NULL) {
                prev->next = current;
                if (current != NULL) {
                    current->prev = prev;
                }
            } else {
                head = current;
                if (head != NULL) {
                    head->prev = NULL;
                }
            }
        }
    }

    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;

            if (temp->next != NULL)
                cout << "->";

            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Create an object of DoublyList
    DoublyList list;

    // Sample Input
    list.push_front(7);
    list.push_front(6);
    list.push_front(5);
    list.push_front(4);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    cout << "Original Linked List: \n";
    list.printList();

    // Delete N nodes after M nodes
    int M = 2, N = 2;
    list.deleteNodes(M, N);

    cout << "Modified Linked List: \n";
    list.printList();

    // Free memory (not shown in this basic example)

    return 0;
}
*/



/*Q. 3 : Swapping Nodes in Linked List;
We have a linked list and two keys in it, swap nodes for two given 
keys Nodes should be swapped by changing links. swapping data of 
nodes may be expensive in many situations when data contains many 
fields. It may be assumed that all keys in the linked list are distinct
	 Sample Input 1: 1->2->3->4,  x = 2, y = 4	
	 Sample Output 1: 1->4->3->2
*//*  

#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode* prev;

    // Constructor with member initialization list
    ListNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Doubly linked list class
class doublyList {
public:
    ListNode* head;
    ListNode* tail;

    // Constructor to initialize an empty list
    doublyList() : head(nullptr), tail(nullptr) {}

    // Function to add a new node at the beginning of the linked list
    void push_front(int val) {
        ListNode* newNode = new ListNode(val);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    int getSize(ListNode* head) {
        int size = 0;
        while (head != nullptr) {
            size++;
            head = head->next;
        }
        return size;
    }

    ListNode* KthFromEnd(ListNode* head, int k) {
        ListNode* temp = head;
        int size = getSize(head);
        for (int i = 0; i < size - k; i++) {
            temp = temp->next;
        }
        return temp;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left = head;
        for (int i = 0; i < k - 1; i++) {
            left = left->next;
        }

        ListNode* right = KthFromEnd(head, k);

        int temp = left->data;
        left->data = right->data;
        right->data = temp;

        return head;
    }

    // Function to print the linked list
    void printList() {
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    doublyList dll;

    // Sample input: 1 -> 2 -> 3 -> 4
    dll.push_front(4);
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);

    cout << "Original Linked List: ";
    dll.printList();

    int k = 2;
    dll.head = dll.swapNodes(dll.head, k);

    cout << "After Swapping " << k << "th node from the start and end: ";
    dll.printList();

    return 0;
}

*/
 /* Q.4 : Odd Even Number Linked List: 
We have a linked List of integers, write a function to 
modify the linked list such that all even numbers appear 
before all the odd numbers in the modifies linked list. 
Also, keep the order of even and odd numbers same.

Sample Input 1: 8->12->10->5->4->1->6->NULL
Sample Output 1: 8->12->10->4->6->5->1->NULL
*//*
#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int val) : data(val), next(nullptr) {}
};

class List {
private:
    ListNode* head;
    ListNode* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    ~List() {
        cout << "~List" << endl;
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void push_front(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }

        ListNode* evenStart = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;

        while (odd->next && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenStart;
        return head;
    }

    void printList() {
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << "->null" << endl;
    }

    void modifyList() {
        head = oddEvenList(head);
    }
};

int main() {
    List list;

    list.push_back(8);
    list.push_back(12);
    list.push_back(10);
    list.push_back(5);
    list.push_back(4);
    list.push_back(1);
    list.push_back(6);

    cout << "Original Linked List: ";
    list.printList();

    list.modifyList();

    cout << "Modified Linked List: ";
    list.printList();

    return 0;
}
*/

/* Q.5: Questions 5: merge k Sorted Lists 
   		We have K sorted linked lists of size N each, 
        merge them and print the sorted output. 
        
        Sample Input : k = 2, n = 2
        l1 = 1->3->NULL
		l2 = 6->8->NULL
		l3 = 9->10->NULL
		
		Sample Output 1: 1>3->6->8->9->10->NULL
*/ 
#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int val) : data(val), next(nullptr) {}
};

class List {
public:
    ListNode* head;
    ListNode* tail;

    List() : head(nullptr), tail(nullptr) {}

    ~List() {
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode* mptr = &dummy;
        ListNode* left = list1;
        ListNode* right = list2;

        while (left != nullptr && right != nullptr) {
            if (left->data <= right->data) {
                mptr->next = left;
                mptr = mptr->next;
                left = left->next;
            } else {
                mptr->next = right;
                mptr = mptr->next;
                right = right->next;
            }
        }
        if (left != nullptr) {
            mptr->next = left;
        }
        if (right != nullptr) {
            mptr->next = right;
        }

        return dummy.next;
    }

    ListNode* mergeLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        ListNode* head = lists[0];
        for (size_t i = 1; i < lists.size(); i++) {
            head = merge(head, lists[i]);
        }
        return head;
    }

    void printList() {
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << "->null" << endl;
    }
};

int main() {
    List list;

    list.push_back(8);
    list.push_back(12);
    list.push_back(10);
    list.push_back(5);
    list.push_back(4);
    list.push_back(1);
    list.push_back(6);

    cout << "Original Linked List: ";
    list.printList();

    // Assuming we have multiple lists to merge
    vector<ListNode*> lists = {list.head, list.head, list.head}; // Example with same list

    ListNode* mergedHead = list.mergeLists(lists);
    list.printList(); // Will print the original list again

    return 0;
}

