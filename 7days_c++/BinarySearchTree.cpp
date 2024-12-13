/*39:NB2:52:  BST : search key = 3 ----> worst case TC: O(n) in BT 
   	   root - > data == key --> 
   	   root < key --> rightsubTree
   	   root > key --->  left subTree 
  - BST TC: O(height)---> 2 type tree: 
  			1: balanced Tree : log n  
  			2: skewed Tree: worst case tc : O(n) 
  						   
*/ 

//Q. 1 Build a BST Array : 
/*
#include <iostream> 
#include <vector> 
using namespace std; 

class Node{
	public: 
	int data; 
	Node* left; 
	Node* right; 
	
	Node(int data){
		this->data = data; 
		this->left = NULL; 
		this->right = NULL;
	}	
}; 	 
Node* insert(Node* root, int val){
	if(root == NULL){
		root = new Node(val); 
		return root; 
	}
	if(val < root->data) { // left subtree
		root->left = insert(root->left, val); 
	}else{  //right Subtree 
		root->right = insert(root->right, val); 
	}
	
	return root; 
}
Node* buildBST(int arr[], int n){
	Node* root = NULL; 
	
	for(int i=0; i<n; i++){
		root = insert(root, arr[i]); 	
	}
	return root; 
}  	
void inorder(Node* root){
	if(root == NULL){
		return; 
	}
	
	inorder(root->left); 
	cout << root->data << " "; 
	inorder(root->right);
} 	

int main (){
//	int arr[6] = {5, 1, 3, 4, 2, 7}; 
	int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
	
	Node* root = buildBST(arr, 9); 
	
	inorder(root); 
	cout << endl; 
	return 0;
}*/ 
//Q2: Search in Bst Array 
/*
#include <iostream>
#include <vector> 
using namespace std; 
class Node{
	public: 
	int data; 
	Node* left; 
	Node* right; 
	
	Node(int data){
		this->data = data; 
		this->left = NULL; 
		this->right = NULL;
	}	
}; 	 
Node* insert(Node* root, int val){
	if(root == NULL){
		root = new Node(val); 
		return root; 
	}
	if(val < root->data) { // left subtree
		root->left = insert(root->left, val); 
	}else{  //right Subtree 
		root->right = insert(root->right, val); 
	}
	
	return root; 
}
Node* buildBST(int arr[], int n){
	Node* root = NULL; 
	
	for(int i=0; i<n; i++){
		root = insert(root, arr[i]); 	
	}
	return root; 
}  
bool search(Node* root, int key){//O(Height); => avg O(log n)
	if(root == NULL){
		return false; 
	}
	
	if(root->data == key){
		return true; 
	}
	
	if(root->data > key){
		return search (root->left, key); 
	}else{
		return search(root->right, key);
	}		
}

int main(){
      int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
	  
	  Node* root = buildBST(arr2, 9); 
	  
	  cout << search(root, 9)<< endl;   
	  return 0; 
}
*/ 

/*Q:3: Inorder Successor(IS) : In BST it is lef-most node in right->SubTree of a node
   (This is alwaus has  0 OR 1 left child) */ 
  
/* 
#include <iostream> 
#include <vector> 
using namespace std; 

class Node{
	public: 
	int data; 
	Node* right; 
	Node* left; 
	
	Node(int data){
		this->data = data; 
		this->left = NULL; 
		this->right = NULL;
	}
};

Node* insert(Node* root, int val){
	if(root == NULL){
		root = new Node(val); 
		return root; 
	}
	if(val < root->data) { // left subtree
		root->left = insert(root->left, val); 
	}else{  //right Subtree 
		root->right = insert(root->right, val); 
	}
	
	return root; 
}

Node* buildBST(int arr[], int n){
	Node* root = NULL; 
	
	for(int i=0; i<n; i++){
		root = insert(root, arr[i]); 	
	}
	return root; 
} 

Node* getInOrderSuccessor(Node* root){
	while(root->left != NULL){
		root = root->left; 
	}
	
	return root; //IS
}

Node* delNode(Node* root, int val){
	if(root == NULL){
		return NULL; 
	}
	
	if(val < root->data) { //left subtree
		   root->left = delNode(root->left, val);
	}else if(val > root->data){ // right subtree
		  root->right = delNode(root->right, val); 	
	}else{
		//root == val 
		// case1: 0 children 
		if(root->left == NULL && root->right == NULL){
			delete root; 
			return NULL;
		}
		
		// case2 : 1 child: 
		if(root->left == NULL || root->right == NULL){
			return root->left == NULL ? root->right : root->left; 
		}
		
		// case3: 2 children :
		Node* IS = getInOrderSuccessor(root->right); 
		root->data = IS->data; 
		root->right = delNode(root->right, IS->data); // case1, case2	
	}	
	return root; 
}

void inorder(Node* root){
	if(root == NULL){
		return; 
	}
	
	inorder(root->left);
	cout << root->data << " "; 
	inorder(root->right); 
}

int main(){
	int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14}; 
	Node* root = buildBST(arr2, 9); 
	
	inorder(root); 
	cout << endl; 
	
	delNode(root, 11); 
	
	inorder(root); 
	cout << endl; 
	
	return 0; 
}
*/

//Q.4: Print in Range : start = 5, end = 12;  
/*
#include <iostream> 
#include <vector>
using namespace std; 
class Node{
	public: 
	int data; 
	Node* right; 
	Node* left; 
	
	Node(int data){
		this->data = data; 
		this->left = NULL; 
		this->right = NULL;
	}
};
Node* insert(Node* root, int val){
	if(root == NULL){
		root = new Node(val); 
		return root; 
	}
	if(val < root->data) { // left subtree
		root->left = insert(root->left, val); 
	}else{  //right Subtree 
		root->right = insert(root->right, val); 
	}
	
	return root; 
}

Node* buildBST(int arr[], int n){
	Node* root = NULL; 
	
	for(int i=0; i<n; i++){
		root = insert(root, arr[i]); 	
	}
	return root; 
} 
 
 void printInRange(Node* root, int start, int end){
 	if(root == NULL){
 		return;
	 }
 	
	 if(start <= root->data && root->data <= end){ 
	 	printInRange(root->left, start, end); 
	 	cout << root->data << " "; // Inorder sequence : also we can print preorder or postorder
	 	printInRange(root->right, start, end); 
	 }else if(root->data < start){
	 	printInRange(root->right, start, end); 
	 }else{
	 	printInRange(root->left, start, end); 
	 }
 }
 
int main(){
	int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14}; 
	Node* root = buildBST(arr2, 9);
	
 printInRange(root, 5, 12);
	
	cout << endl; 
	return 0; 
}

*/  

//Q.5:NB2:55: Root to leaf Path : to travel All tree TC = O(n) 
/*
#include <iostream> 
#include <vector>
using namespace std; 
class Node{
	public: 
	int data; 
	Node* right; 
	Node* left; 
	
	Node(int data){
		this->data = data; 
		this->left = NULL; 
		this->right = NULL;
	}
};
Node* insert(Node* root, int val){
	if(root == NULL){
		root = new Node(val); 
		return root; 
	}
	if(val < root->data) { // left subtree
		root->left = insert(root->left, val); 
	}else{  //right Subtree 
		root->right = insert(root->right, val); 
	}
	
	return root; 
}

Node* buildBST(int arr[], int n){
	Node* root = NULL; 
	
	for(int i=0; i<n; i++){
		root = insert(root, arr[i]); 	
	}
	return root; 
}
void printPath(vector<int> path){
	for(int i=0; i<path.size(); i++){
		cout << path[i] << " "; 
	}
	cout << endl; 
}
void pathHelper(Node* root, vector<int>&path){
	if(root == NULL){
		return; 
	}
	path.push_back(root->data);
	
	if(root->left == NULL && root->right == NULL){
		printPath(path); 
		path.pop_back(); 
		return;
	}
	pathHelper(root->left, path); 
	pathHelper(root->right, path); 
	
	path.pop_back(); 		
}
void rootToLeafPath(Node* root){
	vector<int>path;
	pathHelper(root, path);  
}
/* Q.6: validate BST : from invalid subTree  ;
   How to check valid OR Not ? :
   1: if Node > maxValue in left subtree
   2: if Node < minValue in right Subtree
    
*/
/*
bool validateHelper(Node* root, Node* min, Node* max){
	if(root == NULL){
		return true; 
	}
	if(min != NULL && root->data < min->data){
		return false; 
	}
	
	if(max != NULL && root->data > max->data){
		return false; 
	}
	
	return validateHelper(root->left, min, root) &&
		   validateHelper(root->right, root, max); 
}

bool validateBST(Node* root){
	return validateHelper(root, NULL, NULL);
}
int main(){
	int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14}; 
	
	Node* root = buildBST(arr2, 9);
		
//	rootToLeafPath(root);  // Q.5
//	root->data = 15; 
	cout << validateBST(root) << endl; 

	return 0; 
}*/




