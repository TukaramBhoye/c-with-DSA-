//40:NB2:57: BST part2:-------------------------------------
//Q. 1. Sorted Array to BAlanced BST : 
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

Node* buildBSTfromSorted(int arr[], int st, int end){
	if(st > end){
		return NULL; 
	}
	
	int mid = st + (end-st)/2; 
	Node* curr = new Node(arr[mid]); 
	
	curr->left = buildBSTfromSorted(arr, st, mid-1); 
	curr->right = buildBSTfromSorted(arr, mid+1, end); 
	
	return curr; 
}

void preorder(Node* root){
	if(root == NULL){
		return; 
	}
	
	cout << root->data << " " ;
	preorder(root->left); 
	preorder(root->right); 
}

int main(){
	int arr[7] = {3, 4, 5, 6, 7, 8, 9}; 
	
	Node* root = buildBSTfromSorted(arr, 0, 6);
	preorder(root); 
	cout << endl; 
}
*/ 
//Q. 2 convert BST to Balance BST : 

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

Node* BSTfromSortedVec(vector<int> arr, int st, int end){
	if(st > end){
		return NULL; 
	}
	
	int mid = st + (end-st)/2; 
	Node* curr = new Node(arr[mid]); 
	
	curr ->left = BSTfromSortedVec(arr, st, mid-1); 
	curr ->right = BSTfromSortedVec(arr, mid+1, end); 
	
	return curr; 
}

void getInorder(Node* root, vector<int>&nodes){
	
	if(root == NULL){
		return; 
	}
	
	getInorder(root->left, nodes); 
	nodes.push_back(root->data); 
	getInorder(root->right, nodes); 
		
}


Node* balanceBST(Node* root){
	// get inorder seq  
	
	vector<int> nodes; 
	getInorder(root, nodes); 
	
	return	BSTfromSortedVec(nodes, 0, nodes.size()-1); 
}
void preorder(Node* root){
	if(root == NULL){
		return; 
	}
	
	cout << root->data << " " ;
	preorder(root->left); 
	preorder(root->right); 
}


int main(){
	Node* root = new Node(6); 
	root->left = new Node(5); 
	root->left->left = new Node(4); 
	root->left->left->left = new Node(3);
	
	root->right = new Node(7); 
	root->right->right = new Node(8); 
	root->right->right->right = new Node(9); 
	
	
	root = balanceBST(root); 
    preorder(root); 
	
	cout << endl ; 
	return 0; 
}
*/ 

//Q:3.Size of Largest BST in BT: TC : O(n); 
/*
#include <iostream>
#include <climits> // For INT_MAX and INT_MIN
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Info class definition
class Info {
public:
    bool isBST;
    int min;
    int max;
    int sz;

    Info(bool isBST, int min, int max, int sz) {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->sz = sz;
    }
};

static int maxSize = 0;
static Node* largestRoot;
// Function to find the largest BST
Info* largestBST(Node* root) {
    if (root == NULL) {
        return new Info(true, INT_MAX, INT_MIN, 0);
    }
    

    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
    int currMax = max(root->data, max(leftInfo->max, rightInfo->max));

    int currSz = leftInfo->sz + rightInfo->sz + 1;

    if (leftInfo->isBST && rightInfo->isBST 
        && root->data > leftInfo->max
        && root->data < rightInfo->min) {
        maxSize = max(maxSize, currSz);
        return new Info(true, currMin, currMax, currSz);
    }

    return new Info(false, currMin, currMax, currSz);
}

int main() {
    Node* root = new Node(50); 
    root->left = new Node(30); 
    root->left->left = new Node(5);
    root->left->left->right	= new Node(20);

    root->right = new Node(60); 
    root->right->left = new Node(45); 
    root->right->right = new Node(70);
    root->right->right->left = new Node(65); 
    root->right->right->right = new Node(80); 

    largestBST(root);
    cout << "Max Size: " << maxSize << en l;
    return 0;
}*/ 
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

Node* BSTfromSortedVec(vector<int> arr, int st, int end){
	if(st > end){
		return NULL; 
	}
	
	int mid = st + (end-st)/2; 
	Node* curr = new Node(arr[mid]); 
	
	curr ->left = BSTfromSortedVec(arr, st, mid-1); 
	curr ->right = BSTfromSortedVec(arr, mid+1, end); 
	
	return curr; 
}

void getInorder(Node* root, vector<int>&nodes){
	
	if(root == NULL){
		return; 
	}
	
	getInorder(root->left, nodes); 
	nodes.push_back(root->data); 
	getInorder(root->right, nodes); 	
}

void preorder(Node* root){
	if(root == NULL){
		return; 
	}
	
	cout << root->data << " "; 
	preorder(root->left); 
	preorder(root->right); 
}
Node* mergeBSTs(Node* root1, Node* root2){
	vector<int>nodes1;
	vector<int>nodes2; 
	vector<int>merged; 
	
	getInorder(root1, nodes1); 
	getInorder(root2, nodes2); 
	
	int i = 0; int j = 0; 
	
	while(i<nodes1.size() && j<nodes2.size()){
		if(nodes1[i] < nodes2[j]){
			merged.push_back(nodes1[i++]); 
		}else{
			merged.push_back(nodes2[j++]); 
		}
	}
	
	while(i<nodes1.size()){
		merged.push_back(nodes1[i++]); 
	}
	
	while(j<nodes2.size()){
		merged.push_back(nodes2[j++]);
	}
	
	return BSTfromSortedVec(merged, 0, merged.size()-1); 
}
int main(){
	Node* root1 = new Node(2);
	root1->left = new Node(1); 
	root1->right = new Node(4); 
	
	Node* root2 = new Node(9); 
	root2->left = new Node(3); 
	root2->right = new Node(12); 
	
	Node* root = mergeBSTs(root1, root2); 
	preorder(root); 
	cout << endl; 
	return 0; 
}
*/

//-Assignment: Binary Search Trees---------------------------------------------------------- 
/*Q.1 : Given the root node of a binary search tree and two integers low and
	  	high, return the sum of values of all noted with a value in the inclusive
	  	range [low, high]. 
*/ 
/*
#include <iostream>
#include <vector>
using namespace std; 

class Node{
	public: 
	int val; 
	Node* left; 
	Node* right; 
	
	Node(int val){
		this->val = val;
		this->left = NULL; 
		this->right = NULL;
	}
};

Node* BSTfromSortedVec(vector<int>arr, int st, int end){
	if(st > end){
		return NULL; 
	}
	
	int mid = st + (end - st)/2;
	
	Node* curr = new Node(arr[mid]);
	
	curr->left = BSTfromSortedVec(arr, st, mid-1);
	curr->right = BSTfromSortedVec(arr, mid+1, end); 
	
	return curr; 
}

int rangeSumBST(Node* root, int low, int high){
	
	if(root == NULL){
		return 0;
	}
	
	if(root->val >= low && root->val <= high){
		return root->val + rangeSumBST(root->left, low, high) 
		+ rangeSumBST(root->right, low, high);	
	}
	
	if(root->val < low) {
		return rangeSumBST(root->right, low, high);
	}
	
	return rangeSumBST(root->left, low, high); 
}

int main(){
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7}; 
	Node* root = BSTfromSortedVec(arr, 0, arr.size()-1);
	
	int low = 3, high = 6; 
	int sum = rangeSumBST(root, low, high); 
	
	cout << "low to high number of nodesSum : "<< sum << endl; 
	
	return 0; 
}

  */ 
  
/* Q. 2: we have a binary search tree and a target node K. The task is find the 
   node with minimum absolute difference with given target value K. 
  
   IS : 3 5 6 8 11 12  input K = 5 
   Output1 : ans = 5(abs diff = 0); 
  */
 /*
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* BSTfromSortedVec(vector<int> arr, int st, int end) {
    if (st > end) {
        return NULL;
    }

    int mid = st + (end - st) / 2;

    Node* curr = new Node(arr[mid]);

    curr->left = BSTfromSortedVec(arr, st, mid - 1);
    curr->right = BSTfromSortedVec(arr, mid + 1, end);

    return curr;
}

void minAbsoluteDiff(Node* root, int k, int& min_diff, int& min_diff_key) {
    if (root == NULL) {
        return;
    }

    if (root->val == k) {
        min_diff = 0;
        min_diff_key = root->val;
        return;
    }

    if (min_diff > abs(root->val - k)) {
       
	    min_diff = abs(root->val - k);
        min_diff_key = root->val;
    }

    if (k < root->val) {
        minAbsoluteDiff(root->left, k, min_diff, min_diff_key);
    } else {
        minAbsoluteDiff(root->right, k, min_diff, min_diff_key);
    }
}

int findClosestValue(Node* root, int k) {
    int min_diff = INT_MAX;
    int min_diff_key = -1;
    minAbsoluteDiff(root, k, min_diff, min_diff_key);
    return min_diff_key;
}

int main() {
    vector<int> nodes = {3, 5, 6, 8, 11, 12};
    Node* root = BSTfromSortedVec(nodes, 0, nodes.size() - 1);
    int k = 5;

    int closest_value = findClosestValue(root, k);
    cout << "Closest value to " << k << " is: " << closest_value << endl;

    return 0;
}
*/ 

/*Q.3 : given the root of a binary search tree, and an integer k, return the
   kth smallest value (1-indexed) of all the values of the nodes in tree. */
   
/*
#include <iostream>
#include <vector>
#include <algorithm> // For sorting the input array

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* BSTfromSortedVec(vector<int> arr, int st, int end) {
    if (st > end) {
        return NULL;
    }

    int mid = st + (end - st) / 2;

    Node* curr = new Node(arr[mid]);

    curr->left = BSTfromSortedVec(arr, st, mid - 1);
    curr->right = BSTfromSortedVec(arr, mid + 1, end);

    return curr;
}

int search(Node* root, int &K) {
    if (root == NULL) {
        return -1; 
    }

    int leftVal = search(root->left, K); 
    if (leftVal != -1) {
        return leftVal; 
    }

    K--; 
    if (K == 0) {
        return root->val; 
    }

    return search(root->right, K); 
}

int kthSmallest(Node* root, int k) {
    return search(root, k);
}

vector<int> elements;

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    elements.push_back(root->val);
    inorderTraversal(root->right);
}

int main() { 
    vector<int> nodes = {3, 1, 4, NULL,	2};
    sort(nodes.begin(), nodes.end()); // Sorting the array

    Node* root = BSTfromSortedVec(nodes, 0, nodes.size() - 1);

    int K = 1; 
    cout << "The " << K << "th smallest element is " << kthSmallest(root, K) << endl; 

    return 0; 
}
*/
/*
Q.4: Given two binary search trees, return True if and only is a node in
the first tree and a node in the second tree whose values sum up to a given 
integer target. 
*/
/* Q.5 : Given a binary tree root, return the maximum sum of all keys if any 
   	   sub-tree which is also a Binary Search TRee(BST).
   	   
   	   Assume a BST is defined as follows: 
   	   - the left subtree if a node contains only nodes with keys less than
   	   	 node's key. 
       - The right subtree of a node contains only nodes with keys greater
         than the node's key 
       - both the left and right subtree must also be binary search trees. 
       
*/ 

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
        this->left = NULL;
        this->right = NULL;
    }
};

class NodeValue {
public:
    int min;
    int max;
    int sum;

    NodeValue(int min, int max, int sum) {
        this->min = min;
        this->max = max;
        this->sum = sum;
    }
};

class Solution {
public:
    int ans = 0;

    int maxSumBST(Node* root) {
        helper(root);
        return ans;
    }

    NodeValue helper(Node* root) {
        if (root == NULL) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        NodeValue l = helper(root->left);
        NodeValue r = helper(root->right);

        if (root->data > l.max && root->data < r.min) {
            int sum = root->data + l.sum + r.sum;
            ans = max(ans, sum);
            return NodeValue(min(root->data, l.min), max(root->data, r.max), sum);
        }

        return NodeValue(INT_MIN, INT_MAX, max(l.sum, r.sum));
    }
};

Node* BSTfromSortedVec(vector<int>& arr, int st, int end) {
    if (st > end) {
        return NULL;
    }

    int mid = st + (end - st) / 2;
    Node* curr = new Node(arr[mid]);
    curr->left = BSTfromSortedVec(arr, st, mid - 1);
    curr->right = BSTfromSortedVec(arr, mid + 1, end);

    return curr;
}

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node* root = BSTfromSortedVec(arr, 0, arr.size() - 1);
    cout << "Maximum sum of BST in tree: " << solution.maxSumBST(root) << endl;
    return 0;
}


