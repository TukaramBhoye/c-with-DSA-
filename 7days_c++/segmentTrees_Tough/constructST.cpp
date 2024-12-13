// CH: 57:NB2:151:Segment Tree 

// Q.1 Creating A Segment Tree --> 
/*
#include <iostream> 
#include <vector> 
using namespace std; 

class SegmentTree{
    vector<int> tree; 
    int n; 

    public: 

    SegmentTree(vector<int> &arr){
        n = arr.size(); 
        tree.resize(4*n); 
        buildTree(arr, 0, n-1, 0); 
    }

    void buildTree(vector<int> &arr, int start, int end, int node){
        if(start == end){
            tree[node] = arr[start]; 
            return; 
        }

        int mid = start + (end-start)/2; 

        buildTree(arr, start, mid, 2*node+1); 
        buildTree(arr, mid+1, end, 2*node+2); 

        tree[node] = tree[2*node+1] + tree[2*node+2] ;
    }

    void printTree(){
        for(int i=0; i<tree.size(); i++){
            cout << tree[i] << " "; 
        }
        cout << endl; 
    }
};

int main(){
    vector<int> arr= {1, 2, 3, 4, 5, 6, 7, 8}; 

    SegmentTree st(arr); 

    st.printTree();
    return 0; 
}
*/
// Q.2: Queries On Segment Tree : 
/*
#include <iostream> 
#include <vector> 
using namespace std; 

class SegmentTree {
    vector<int> tree; 
    int n; 

    void buildTree(vector<int> &arr, int start, int end, int node) {  // Builds the segment tree for the given array 'arr'.
        if (start == end) {
            tree[node] = arr[start];  // Leaf node assignment
            return; 
        }

        int mid = start + (end - start) / 2; 

        // Recursively build the left and right subtrees
        buildTree(arr, start, mid, 2 * node + 1); 
        buildTree(arr, mid + 1, end, 2 * node + 2); 

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int rangeSum(int qi, int qj, int si, int sj, int node) {
        
        if (qj < si || qi > sj) { // No overlap
            return 0; 
        }

        if (si >= qi && sj <= qj) {  // Complete overlap
            return tree[node]; 
        }

        // Partial overlap, need to check both sides
        int mid = si + (sj - si) / 2; 
        return rangeSum(qi, qj, si, mid, 2 * node + 1) + 
               rangeSum(qi, qj, mid + 1, sj, 2 * node + 2); 
    }

    void updateUtil(int idx, int newVal, int start, int end, int node){ // O(log n)
        if(start == end){
            tree[node] = newVal; 
            return;
        }

        int mid = start + (end - start)/2;

        if(idx >= start && idx <= mid) { // left
            updateUtil(idx, newVal, start, mid, 2 * node + 1); 

        } else{
            updateUtil(idx, newVal, mid+1, end, 2 * node + 2) ;
        }

        tree[node] = tree[2*node+1] + tree[2*node+2]; 
    }
public:
    
    SegmentTree(vector<int> &arr) {  // Constructor to initialize the segment tree
        n = arr.size(); 
        tree.resize(4 * n, 0); // Initialize tree with 0s
        buildTree(arr, 0, n - 1, 0);  // Build the segment tree
    }

   
    int rangeQuery(int qi, int qj) {  // Function to query the sum in the range [qi, qj]
        return rangeSum(qi, qj, 0, n - 1, 0); 
    }

    //Q.3 -- Update on Segment Tree 
   void updateQuery(int idx, int newVal){
        updateUtil(idx, newVal, 0, n-1, 0); 
    }
    
    void printTree() {
        for (int i = 0; i < tree.size(); i++) {
            cout << tree[i] << " "; 
        }
        cout << endl; 
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8}; 

    SegmentTree st(arr); 

    cout << st.rangeQuery(2, 5) << endl;  // Sum of elements from index 2 to 5
    cout << st.rangeQuery(0, 3) << endl;  
    cout << st.rangeQuery(6, 7) << endl;  

    st.updateQuery(1, 3); 
    cout << st.rangeQuery(0, 3) << endl; // 
    return 0; 
}

*/ 

#include <iostream> 
#include <vector> 
#include <climits>
using namespace std; 

class SegmentTree{
    vector<int> tree; 
    int n; 

    void buildTree(vector<int> &nums, int start, int end, int node){ // O(n)

        if(start == end){
            tree[node] = nums[start]; 
            return ; 
        }

        int mid = start + (end-start)/2;

        buildTree(nums, start, mid, 2 * node + 1); 
        buildTree(nums, mid+1, end, 2 * node + 2); 

        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]); 

    }

    int maxQuery(int qi, int qj, int si, int sj,int node){
        
        if(qi > sj || qj < si){
            return INT_MIN; 
        }

        if(si >= qi && sj <= qj) { // complete
            return tree[node]; 
        }

        // partial 
        int mid = si + (sj-si)/2; 

        int leftMax = maxQuery(qi, qj, si, mid, 2*node+1); 
        int rightMax = maxQuery(qi, qj, mid+1, sj, 2 * node + 2); 

        return max(leftMax, rightMax); 
    }

    void updateUtility(int idx, int newVal, int start, int end, int node){ // O(log n)

        if(start == end){
            tree[node] = newVal; 
            return; 
        }
        int mid = start + (end-start)/2; 

        if(idx >= start && idx <= mid){
            updateUtility(idx, newVal, start, mid,  2*node + 1); 
        }
        else{
            updateUtility(idx, newVal, mid+1, end, 2*node+2); 
        }

        tree[node] = max(tree[2*node+1], tree[2*node+2]); 
    }

    public: 

    SegmentTree(vector<int> &nums){
        n = nums.size(); 
        tree.resize(4 * n); 
        buildTree(nums, 0, n-1, 0); 
    }

    void printTree(){
        for(int el : tree){
            cout << el << " "; 
        }
        cout << endl; 
    }

    // Question 5: Range of Max Segment tree 
    int rangeQuery(int qi, int qj){
        return maxQuery(qi, qj, 0, n-1, 0 ); 
    }

    // Question 6: Update Segment Tree->& return Max Value 

    void updateQuery(int idx, int newVal){
        return updateUtility(idx, newVal, 0, n-1, 0);
    }
};

int main(){
    // Range Max Queries 
    vector<int> nums = {6, 8, -1, 17, 1, 3, 2, 4}; 

    SegmentTree st(nums); 
    st.printTree(); 

    cout << st.rangeQuery(2, 5) << endl; // 17
    cout << st.rangeQuery(5, 8) << endl; // 17

    st.updateQuery(3, 5); // index 4 varti update val 5
    cout << st.rangeQuery(0, 8) <<endl; 
    return 0; 
}




