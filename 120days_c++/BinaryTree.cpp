//36:NB2:39: Binary tree Part 1: 

/* tree traversal 4 ways : 
   i: preorder: 
   ii: inorder: 
   iii: postorder: 
   
1: Build a tree from preorder: 
*/ /*
#include <iostream> 
#include <vector> 
#include <queue>
using namespace std; 

class Node{
	public: 
	int data; 
	Node* left; 
	Node* right; 
	
	Node(int data){
		this->data = data; 
		left = right = NULL; 
	}	
};

static int idx = -1; 
Node* buildTree(vector<int>nodes){
	  idx++;
	  if(nodes[idx] == -1){
	  	return NULL; 
	  }
	  Node* currNode = new Node(nodes[idx]);
	  currNode->left =	buildTree(nodes); 
	  currNode->right= buildTree(nodes);   
	  
	  return currNode; 
}

//i.preorder Traversal 

void preorder(Node* root){ 
	 if(root == NULL){
	 	return; 
	 }
	cout << root->data << " " ;
	preorder(root->left); 
	preorder(root->right); 
	  
}

//ii. inorder Tree traversal: 
void inorder(Node* root){
	 if(root == NULL){
	 	return; 
	 }
    inorder(root->left); 
	cout << root->data << " "; 
	inorder(root->right); 
}
// iii. postOrder TreeTraversal 
void postorder(Node* root){

	 if(root == NULL){
	 	return; 
	 }
    inorder(root->left); 
	inorder(root->right); 
	cout << root->data << " "; 
}

// iv: Level Order Tree Traversal : 

void levelOrder(Node* root){
	if(root == NULL){
		return; 
	}
	
	queue<Node*>q;
	q.push(root);
	
	while(!q.empty()){
		Node* curr = q.front(); 
		q.pop(); 
		
		cout << curr->data<< " "; 
		if(curr->left != NULL){
			q.push(curr->left); 
		}
		
		if(curr->right != NULL){
			q.push(curr->right);
		}
	}
	cout << endl; 
}
void levelOrder_Null(Node* root){
	if(root == NULL){
		return; 
	}
	
	queue<Node*>q;
	q.push(root);
	q.push(NULL); 
	while(!q.empty()){
		Node* curr = q.front(); 
		q.pop(); 
		if(curr == NULL){
			cout << endl; 
			if(q.empty()){
				break; 
			}
			q.push(NULL); // to track next line 
		}else{
			cout << curr->data<< " "; 
			if(curr->left != NULL){
				q.push(curr->left); 
			}
			
			if(curr->right != NULL){
				q.push(curr->right);
			}
		}	
	}
}
int height(Node* root2) {
	if(root2 == 0){
		return 0; 
	} 
	
	int leftHT = height(root2->left); 
	int rightHT = height(root2->right); 
	
	int currHT = max(leftHT, rightHT)+1; 
	
	return currHT; 
}// TC: O(n) 

int count(Node* root){
	if(root == NULL){
		return 0; 
	}
	
	int leftCount = count(root->left); 
	int rightCount = count(root->right); 
	
	return leftCount + rightCount + 1; 
} 
	

int main(){
//	vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
//	Node* root = buildTree(nodes); 

	vector<int> nodes1 = {1, 2, 4, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};
	Node* root2 = buildTree(nodes1); 
	cout << "Height of tree: " << height(root2) << endl; 
	cout << "Counted Nodes: " << count(root2) << endl; 

//	cout << "root = " << root->data << endl; 
	
//	preorder(root); 
//	cout << endl; 

//	inorder(root);
 
//	postorder(root); 
  
//    levelOrder(root); 
//    levelOrder_Null(root); // with NULL and get next line tree structure :  
	// height of tree 
	return 0; 
}
*/ 
/* subtree of another tree: return true if there is a subtree of root
with the same structure and node values of subroot: 

also some are questions : 1: height 2: sum of node values 
	 	  	  			  3: longest diameter of a tree : 
							 */ 

/*
#include <iostream> 
#include <vector> 
using namespace std; 

class Node {
	public: 
	int data; 
	Node* left; 
	Node* right; 
	
	Node(int data) {
		this->data = data; 
		left = right = NULL; 
	}	
};

static int idx = -1; 
Node* buildTree(vector<int>& nodes) {
	idx++;
	if(nodes[idx] == -1) {
		return NULL; 
	}
	Node* currNode = new Node(nodes[idx]);
	currNode->left = buildTree(nodes); 
	currNode->right = buildTree(nodes);   
	
	return currNode; 
}

int height(Node* root) {
	if(root == NULL) {
		return 0; 
	} 
	
	int leftHT = height(root->left); 
	int rightHT = height(root->right); 
	
	int currHT = max(leftHT, rightHT) + 1; 
	
	return currHT; 
}

int sum(Node* root ){
	if(root == NULL){
		return 0; 
	}
	
	int leftSum = sum(root->left); 
	int rightSum = sum(root->right); 
	
	int currSum = leftSum + rightSum + root->data;
	cout << "sum = "<< currSum << endl; 
//	sum = 4,sum = 7,sum = 13,sum = 18,sum = 24,sum = 3,sum = 28  <-o/p 
	return currSum; 
}
int diam1(Node* root){
	if(root == NULL){
		return 0; 
	}
	int currDiam = height(root->left)+ height(root->right)+1; 
	int leftDiam = diam1(root->left); 
	int rightDiam = diam1(root->right);
	
	return max(currDiam, max(leftDiam, rightDiam)); 
}
// Longest : 
pair<int, int>diam2(Node* root){
	if(root == NULL && subRoot == NULL){
		return true; 
	}else if(root == NULL || subRoot == NULL){
		  return false;
		
	}

    if(root == NULL){
    	return make_pair(0, 0); 
	}
//        (diam, height)
	pair<int, int>leftInfo = diam2(root->left); // ld, lh
	pair<int, int> rightInfo = diam2(root->right); // RD, RH 
	
	int currDiam = leftInfo.second + rightInfo.second + 1; 
	int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first)); 
	int finalHT = max(leftInfo.second, rightInfo.second)+ 1; 
	
	return make_pair(finalDiam, finalHT); 

}
// Subtree of another tree: 

bool isIdentical(Node* root1, Node* root2){
	if(root1 == NULL && root2 == NULL) {
		return true; 
	}else if(root1 == NULL|| root2 == NULL){
		return false; 
	}
	
	if(root1->data != root2->data){
		return false; 
	}
	
	return isIdentical(root->left, root2->left)
	&& isIdentical(root1->right, root2->right); 
}
// SubTree of another tree: 
bool isSubtree(Node* root, Node* subRoot){
	if(root == NULL && subRoot == NULL) {
		return true; 
	}else if(root == NULL || subRoot == NULL){
		return false; 
	}
	
	if(root->data == subRoot->data){
		if(isIdentical(root, subRoot)){
			return true; 
		}
	}
	int isLeftSubtree = isSubtree(root->left, subRoot); 
	if(!isLeftSubtree){
		return isSubtree(root->right, subRoot); 
	}
	return true; 
}

int main() {
//	vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};
	vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
	Node* root = buildTree(nodes);
//	Node* root2 = buildTree(nodes1);
	 
//	cout << "Height of tree: " << height(root) << endl; 
//	cout << "sum of Nodes: "<< sum(root) << endl;
	
//	cout << "Diameter : " << diam1(root) << endl;  
	cout << "Diameter : " << diam2(root).first<< endl;  

	Node* subRoot = new Node(2); 
	subRoot->left = new Node(4); 
	subRoor->right = new Node(5); 
	
	cout << isSubroot(root, subRoot); 


	return 0; 
}
*/ 
//-------------------------------------------------
//12:NB2:46: Map in C++ : STL Container: 
/*
exmple : student name(repeat val) and roll(unique key) number: 
map<int, int> m; // creating a map 
m[key] = val; // insert in a map 
cout << m[key]; // access val using key 
m.count(key); // 1 if key present, 0 if key not present

// loop on map 
for(auto iterator: m){
	cout << m.first << m.second; 
}
*/ 
/*
#include <iostream> 
#include <map>
#include <string>
using namespace std; 

int main (){
	map<int, string> m; 
	m[101] = "rahul"; 
	m[102] = "neha" ; 
	m[131] = "rahul"; 
	
	m[101] = "rajat"; // Override:the val 101 id rahul will delete
	cout << m.count(101) << endl; //1
	cout << m.count(120) << endl; //0
	
	cout << m[101] << endl ;
	for(auto it: m){
		cout << "key = " << it.first << ","<< "value = "<< it.second<< endl; 
	}
	
	return 0;  
	
	
}
*/ 

// Q.13: Top view Of Tree: 

/* 
#include <iostream> 
#include <vector> 
#include <queue>
#include <map>
using namespace std; 

class Node {
	public: 
	int data; 
	Node* left; 
	Node* right; 
	
	Node(int data) {
		this->data = data; 
		left = right = NULL; 
	}	
};

static int idx = -1; 
Node* buildTree(vector<int>& nodes) {
	idx++;
	if(nodes[idx] == -1) {
		return NULL; 
	}
	Node* currNode = new Node(nodes[idx]);
	currNode->left = buildTree(nodes); 
	currNode->right = buildTree(nodes);   
	
	return currNode; 
}

void topView(Node* root){
	queue<pair<Node*, int>> Q; // node, HD: -> pair
	map<int, int>m; // HD, node->data
			 		// initially zro hd: 
	Q.push(make_pair(root, 0)); 
	while(!Q.empty()){
		pair<Node*, int>curr = Q.front(); 
		Q.pop(); 
		
		Node* currNode = curr.first; 
		int currHD = curr.second; 
   				   	 
		if(m.count(currHD)== 0){// HD_unique -> add in map 
	            m[currHD] = currNode->data;
		}
		//children 
	
		if(currNode->left != NULL){
			pair<Node*, int> left = make_pair(currNode->left, currHD-1);
			Q.push(left);  
		}
		
		if(currNode->right != NULL) {
			pair<Node*, int>right = make_pair(currNode->right, currHD+1); 
			Q.push(right); 
		}
	}
	
	for(auto it : m){
		cout << it.second << " "; 
	}
	cout << endl; 
}

int main (){
	vector<int>nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
	Node* root = buildTree(nodes); 
	
	topView(root); 
	
	return 0; 
}
*/ 

//****************************************************************
//38:NB:48:Binary part: Kth level of a tree: tree: 1, 2, 4, -1, -1, 5, -1, -1, 1, 3, -1, 6; 
/*

//Q.1 Find the Kth level of a Tree 
#include <iostream> 
#include <vector> 
#include <queue>
#include <map>
using namespace std; 

class Node {
	public: 
	int data; 
	Node* left; 
	Node* right; 
	
	Node(int data) {
		this->data = data; 
		left = right = NULL; 
	}	
};

static int idx = -1; 
Node* buildTree(vector<int>&nodes) {
	idx++;
	if(nodes[idx] == -1) {
		return NULL; 
	}
	Node* currNode = new Node(nodes[idx]);
	currNode->left = buildTree(nodes); 
	currNode->right = buildTree(nodes);   
	
	return currNode; 
}

void KthHelper(Node* root, int K, int currLevel){
	
	if(root == NULL){
		return; 
	}
	
	if(currLevel == K){
		cout << root->data << " "; 
		return; 
	}
	
	KthHelper(root->left, K, currLevel+1); //left
	KthHelper(root->right, K, currLevel+1); // right
}

void KthLevel(Node* root, int K){
		KthHelper(root, K, 1); 
  						// 1 is currlevel 
}
int main (){
	vector<int>nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
	Node* root = buildTree(nodes); 
	
	
	KthLevel(root, 2); 
	
	return 0; 
}*/ 

/*Q.2:  Lowest Common Ancestor Approach 1: i:  O(n), sc : O(n)
   		  		 		   ii: O(n), sc: O(1)
 n1 = 4, n2 = 5; 				
 */ /*
#include <iostream> 
#include <vector> 
#include <queue>
#include <map>
using namespace std; 

class Node {
	public: 
	int data; 
	Node* left; 
	Node* right; 
	
	Node(int data) {
		this->data = data; 
		left = right = NULL; 
	}	
};

static int idx = -1; 
Node* buildTree(vector<int>&nodes) {
	idx++;
	if(nodes[idx] == -1) {
		return NULL; 
	}
	Node* currNode = new Node(nodes[idx]);
	currNode->left = buildTree(nodes); 
	currNode->right = buildTree(nodes);   
	
	return currNode; 
}
bool rootToNodePath(Node* root, int n, vector<int>&path){
	if(root == NULL){
		return false; 
	}
	path.push_back(root->data);
	if(root->data == n){
		return true; 
	}
	
	int isLeft = rootToNodePath(root->left, n, path);
	int isRight = rootToNodePath(root->right, n, path); 
	
	if(isLeft || isRight){
		return true; 
	}
	path.pop_back(); 
	return false; 
}
//Q.2:  Lowest Common Ancestor Approach 1:
int LCA(Node* root, int n1, int n2){
	vector<int>path1;
	vector<int>path2; 
	
	rootToNodePath(root, n1, path1);
	rootToNodePath(root, n2, path2); 
	
	int lca = -1;
	for(int i=0, j=0; i<path1.size() && j<path2.size(); i++, j++){
		if(path1[i] != path2[j]){
			return lca;
		}
		lca = path1[i]; 
	}
	return lca; 
}
//Q.3:  Lowest Common Ancestor Approach 2:
Node* LCA2(Node* root, int n1, int n2){
	if(root == NULL ){
		return NULL;
	}
	
	if(root->data == n1 || root->data == n2){
		return root; 
	}
	
	Node* leftLCA = LCA2(root->left, n1, n2); 
	Node* rightLCA = LCA2(root->right, n1, n2); 
	
	if(leftLCA != NULL && rightLCA != NULL){
		return root; 
	}
	
	return leftLCA == NULL ? rightLCA : leftLCA; 
}

// Q.4 Min Dist: between Nodes: 
int dist(Node* root, int n){
	if(root == NULL){
		return -1; 
	}
	
	if(root->data == n){
		return 0; 
	}
	
	int leftDist = dist(root->left, n); 
	if(leftDist != -1){
		return leftDist + 1; 
	}
	
	int rightDist = dist(root->right, n); 
	if(rightDist != -1){
		return rightDist + 1; 
	}
	
	return -1; 
}
int minDist(Node* root, int n1, int n2){
	Node* lca = LCA2(root, n1, n2); 	
	int dist1 = dist(lca, n1); 
	int dist2 = dist(lca, n2); 
	
	return dist1 + dist2; 
}

// Q.Kth ancestor Of Node  Node = 4; K = 2 
int KthAncestor(Node* root, int node, int K){
	if(root == NULL){
		return -1; 
	}
	
	if(root->data == node){
		return 0; 
	}
	
	int leftDist = KthAncestor(root->left, node, K); 
	int rightDist = KthAncestor(root->right, node, K); 	
	
	if(leftDist == -1 && rightDist == -1){
		return -1; 
	}		
	
	int validVal = leftDist == -1 ? rightDist : leftDist; 
	
	if(validVal + 1 == K ){
		cout << "Kth Ancestor : " << root->data << endl;
	}
		
	return validVal+1;	  		
}

int main (){
	vector<int>nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
	Node* root = buildTree(nodes); 
	
	
	int n1 = 4, n2 = 6;  // op = 2 
//	cout << "lca = " <<LCA2(root, n1, n2)->data << endl; 
	cout << "Min dist: "<< minDist(root, n1, n2)<< endl ; // O/p = 4  minimum dist
	
	int node = 4; int K = 1; 
	
	KthAncestor(root, node, K); 
	
	return 0; 
} 
*/ 

//Q. Transform to Sum Tree : Each Node - sum of left & right subtrees
/* 
#include <iostream> 
#include <vector> 
#include <queue>
#include <map>
using namespace std; 

class Node {
	public: 
	int data; 
	Node* left; 
	Node* right; 
	
	Node(int data) {
		this->data = data; 
		left = right = NULL; 
	}	
};

static int idx = -1; 
Node* buildTree(vector<int>&nodes) {
	idx++;
	if(nodes[idx] == -1) {
		return NULL; 
	}
	Node* currNode = new Node(nodes[idx]);
	currNode->left = buildTree(nodes); 
	currNode->right = buildTree(nodes);   
	
	return currNode; 
}
void levelOrder(Node* root){
	if(root == NULL){
		return; 
	}
	
	queue<Node*>q;
	q.push(root);
	
	while(!q.empty()){
		Node* curr = q.front(); 
		q.pop(); 
		
		cout << curr->data<< " "; 
		if(curr->left != NULL){
			q.push(curr->left); 
		}
		
		if(curr->right != NULL){
			q.push(curr->right);
		}
	}
	cout << endl; 
}
void levelOrder_Null(Node* root){
	if(root == NULL){
		return; 
	}
	
	queue<Node*>q;
	q.push(root);
	q.push(NULL); 
	while(!q.empty()){
		Node* curr = q.front(); 
		q.pop(); 
		if(curr == NULL){
			cout << endl; 
			if(q.empty()){
				break; 
			}
			q.push(NULL); // to track next line 
		}else{
			cout << curr->data<< " "; 
			if(curr->left != NULL){
				q.push(curr->left); 
			}
			
			if(curr->right != NULL){
				q.push(curr->right);
			}
		}	
	}
}

//Transform to Sum Tree
int transform(Node* root){
		if(root == NULL){
			return 0; 
		}
		int leftOld = transform(root->left); 
		int rightOld = transform(root->right); 
		int currOld = root->data; 
		
		root->data = leftOld + rightOld; 
		
	    if(root->left != NULL){
	    	root->data += root->left->data; 
		}
		
		if(root->right != NULL){
			root->data += root->right->data; 
		}
		
		 
		return currOld; 
		
}
int main (){
	vector<int>nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
	Node* root = buildTree(nodes); 
	
	transform(root);
	
	levelOrder(root);
	return 0; 
} */ 

//-Assignment: -------------------------------------------------------------
/*Q.1:A binary tree is univalued if every node in tree has the same value.
		Given the root of a binary tree, return true if the given tree is uni-valued, 
		or false otherwise. 
*/ /* 
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
		left = right = NULL; 
		
	}
};

static int idx = -1; 

Node* buildTree(vector<int>nodes){
	idx++; 
	if(nodes[idx] == -1){
		return NULL; 
	}
	
	Node* currNode = new Node(nodes[idx]); 
	currNode->left = buildTree(nodes); 
	currNode->right = buildTree(nodes); 
	
	return currNode; 
}

bool isUnivalued(Node* root, int val){
	
	if(root == NULL){
		return true; 
	}
	
	if(root->data != val){
		return false; 
	}
	
	return isUnivalued(root->left, val) && isUnivalued(root->right, val);
}

bool isUnivaluedTree(Node* root){
	if(root == NULL){
		return true; 
	}
	
	return isUnivalued(root, root->data); 
}

int main (){
	vector<int>nodes = {1, 1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, -1};
	
	Node* root = buildTree(nodes); 
	
    cout << (isUnivaluedTree(root)? "true" : "false") << endl; 
	
	if(isUnivaluedTree(root)){
		cout << "The tree is Univalued."<< endl; 
	}else{
		cout << "The tree is not univalued. "<< endl; 
	}
	return 0; 
}
*/ 
/*Q.2: Given the root of a binary tree, invert the tree, and return its root.
 
 */
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
		left = NULL;
		right = NULL; 
	}
};
static int idx = -1; 
Node* buildTree(vector<int>& nodes){
	idx++; 
	
	if(nodes[idx] == -1){
		return NULL; 
	}
	
	Node* currNode = new Node(nodes[idx]); 
	currNode->left = buildTree(nodes); 
	currNode->right = buildTree(nodes); 
	
	return currNode;
}
Node* invertTree(Node* root){
	if(root == NULL){
		return NULL; 
	}
	
	Node* left = invertTree(root->left);
	Node* right = invertTree(root->right);
	
	root->left = right; 
	root->right = left; 
	
	return root; 
}

void printPreOrder(Node* root){
	if(root == NULL){
		cout << "-1 " ;
		return; 
	}
	
	cout << root->data << " ";
	printPreOrder(root->left); 
	printPreOrder(root->right);
}
int main(){
	vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
	Node* root = buildTree(nodes); 
	
	root = invertTree(root); 
	printPreOrder(root); 
	return 0; 	
}
*/

/*Q.3: Given a binary tree root and an integer target, delete all the lead nodes
	with value target. 
	NOte that oncee you delete a leaf node with value target, if its parent
	node becomes a leaf node and has the value target, it should also be deleted 
	(you need to continue doing that until you cannot.
/*
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int>& nodes) {
    idx++;

    if (idx >= nodes.size() || nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

Node* deleteNode(Node* root, int target) {
    if (root == NULL) {
        return NULL;
    }

    root->left = deleteNode(root->left, target);
    root->right = deleteNode(root->right, target);

    // Check if root is a leaf and has the target value
    if (root->left == NULL && root->right == NULL && root->data == target) {
        delete root;
        return NULL; 
    }

    return root;
}

// Function to print the tree in pre-order traversal for verification
void printTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Example vector representing the tree structure
    vector<int> nodes = {1, 2, 2, -1, -1, -1, 3, 2, -1, -1, 4, -1, -1};
    int target = ;

    // Build the tree from the vector
    Node* root = buildTree(nodes);

    // Print the original tree in pre-order for verification
    cout << "Original tree in pre-order traversal:" << endl;
    printTree(root);
    cout << endl;

    // Delete leaf nodes with the target value
    root = deleteNode(root, target);

    // Print the modified tree in pre-order for verification
    cout << "Modified tree in pre-order traversal after deleting nodes with target value " << target << ":" << endl;
    printTree(root);
    cout << endl;

    return 0;
}

*/
/*Q.4: Given the root of a binary tree, return all duplicate subtrees. 
    For each kind of duplicate subtree, you only need to return the root
    node of any one of them. Two trees are duplicate if they have the same 
    Structure with the same node values. 
	input: 1 2 4 -1 -1 -1 3 2 4 -1 -1 -1 4 -1 -1 
	Op : [[2, 4], [4]]
	First duplicate subtree with nodes[2, 4]
	Second duplicate subtree with node[4]
		
	*/ 
/*	
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int>& nodes) {
    idx++;
    if (idx >= nodes.size() || nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

string duplicate(Node* root, unordered_map<string, int>& mp, vector<Node*>& v) {
    if (root == NULL) return "";

    string a = duplicate(root->left, mp, v);
    string b = duplicate(root->right, mp, v);
    string temp = to_string(root->data) + "," + a + "," + b;
    mp[temp]++;

    if (mp[temp] == 2) v.push_back(root);
    return temp;
}

vector<Node*> findDuplicateSubtrees(Node* root) {
    unordered_map<string, int> mp;
    vector<Node*> v;
    duplicate(root, mp, v);
    return v;
}

void printTree(Node* root) {
    if (!root) {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, -1, 3, 2, 4, -1, -1, -1, 4, -1, -1};
    Node* root = buildTree(nodes);

    vector<Node*> duplicates = findDuplicateSubtrees(root);
    for (Node* duplicate : duplicates) {
        printTree(duplicate);
        cout << endl;
    }

    return 0;
}*/
	
/*Q.5: A Path in a binary tree is a sequence of nodes where each pair of
		adjacent nodes in the sequence has an edge connecting them. A node can only
		appear in the sequence at most once. Note that the path does not need to pass
		through the root. 
		The path sum of a path is the sum of the node's values in the path. 
		Given the root of a binary tree, return the maximum path sum of any 
		non-empty path. 
		
		input: 4 2 -1 -1 7 -1 -1 outPut : 13
		
		input: -10 9 -1 -1 20 15 -1 -1 7 -1 -1  outPut : 42
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int>& nodes) {
    idx++;
    if (idx >= nodes.size() || nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

int maxPath(Node* root, int &max_sum) {
    if (root == NULL) {
        return 0;
    }

    int left = max(0, maxPath(root->left, max_sum));
    int right = max(0, maxPath(root->right, max_sum));

    int current_sum = root->data + left + right;
    max_sum = max(max_sum, current_sum);

    return root->data + max(left, right);
}

int maxPathSum(Node* root) {
    int max_sum = INT_MIN;
    maxPath(root, max_sum);
    return max_sum;
}

int main() {
    vector<int> nodes1 = {4, 2, -1, -1, 7, -1, -1};
    Node* root1 = buildTree(nodes1);
    cout << "Output for first tree: " << maxPathSum(root1) << endl;

    idx = -1; // Reset index for the next tree
    vector<int> nodes2 = {-10, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
    Node* root2 = buildTree(nodes2);
    cout << "Output for second tree: " << maxPathSum(root2) << endl;

    return 0;
}

