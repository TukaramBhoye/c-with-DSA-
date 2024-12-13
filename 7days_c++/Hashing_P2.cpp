//1: NB: 79:  Hashingg Part 2: 

// Q. 1: Majority Elements : find elements that appear more than n/3 times: 
/*
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

void majorityElements(vector<int> nums)
{
    unordered_map<int, int> m; // <element, freq>

    for (int i = 0; i < nums.size(); i++){

        if (m.count(nums[i])){
            m[nums[i]]++;
        }else{
            m[nums[i]] = 1; // if not exists initialize with freq 1
        }
    }

    for (pair<int, int> p : m) {
        if (p.second > nums.size() / 3){
            cout << p.first << " ";
        }
    }

    cout << endl;
}
int main()
{
    vector<int> nums = {1, 3, 2, 5, 1, 3, 1, 5, 1}; // op: 1
    vector<int> nums2 = {1, 2};

    majorityElements(nums2); // 2, 1
    return 0;
}
*/ 

// Q:2. Search a String is Anagram or Not
//     anagram ex : string = "race"   anagram -> care : all string match 

/*
#include <iostream> 
#include <vector> 
#include <unordered_map>
#include <string> 
#include <unordered_set> 

using namespace std; 
bool validAnagram(string s, string t){

    if(s.size() != t.size()){
        return false; 
    }
    // s <char, freq> 
    unordered_map<char, int> freq; 

    for(int i = 0; i<s.size(); i++ ){
        if(freq.count(s[i])){
            freq[s[i]]++; 
        }else{
            freq[s[i]] = 1; 
        }
    }

    // 2nd to look for t's chars in freq
    for(int i=0; i<t.size(); i++){
        if(freq.count(t[i])){
            freq[t[i]]--; 
            if(freq[t[i]] == 0){
                freq.erase(t[i]);
            }
        }else{
              return false;   
        }
    }
    return freq.size() == 0; // frequency match all then zero return ->true op:1
}
int main(){
    string s = "tulip"; 
    string t = "lipid"; 

     cout << validAnagram(s, t) << endl; 
    return 0; 
}
*/ 
/*
// Q. count Distinct Element : 
#include <iostream> 
#include <vector> 
#include <unordered_map>
#include <string> 
#include <unordered_set> 
using namespace std; 

int countDistinct(vector<int> arr){
   unordered_set<int> s; 

   for(int i = 0; i < arr.size(); i++){
        s.insert(arr[i]); 
   } 

   for(int el: s){
    cout << el << " "; 
   }

    return s.size(); 

}

int main (){
    vector<int> arr = {4, 3, 2, 5, 6, 7, 3, 4, 2, 1};

    cout << "\ncount = " << countDistinct(arr) << endl; 

    return 0; 
}
*/ 

// Q. 3: print Union And Intersection 
/*
#include <iostream> 
#include <vector> 
#include <set> 
#include <unordered_set>
#include <string> 

using namespace std; 

void printUnion(vector<int> arr1, vector<int>arr2){
    set<int> s; 
    // unordered_set<int> s; 

    for(int el : arr1){
        s.insert(el); //  
    }

    for(int el: arr2){
        s.insert(el); 
    }

    for(int el: s){
        cout << el << " "; 
    }
    cout << endl; 
}

void printInterSection(vector<int> arr1, vector<int> arr2){
    unordered_set<int>s; 

    for(int el: arr1){
        s.insert(el); 
    }

    for(int el: arr2){
        if(s.find(el) != s.end()){
            cout << el << " "; 
            s.erase(el); 
        }

    }
    cout << endl ;

}
int main(){
    vector<int>arr1 = {7, 3, 9}; 
    vector<int>arr2 = {6, 3, 9, 2, 9, 4}; 

    cout << "Union: " ; 
    printUnion(arr1, arr2); 

    cout << "Intersection: "<< endl; 
    printInterSection(arr1, arr2);

    return 0; 
}
*/ 

// Q.4: Itinerary from tickets : 
/*

#include <iostream> 
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string> 

using namespace std; 

void printItenerary(unordered_map<string, string> tickets){
    // Starting Point
    unordered_set<string>to; 

    for(pair<string, string>ticket: tickets){
        to.insert(ticket.second); 
    }

    string start = ""; 

    for(pair<string, string>ticket: tickets){
        if(to.find(ticket.first) == to.end()){
            start = ticket.first; 
        }
    }

    cout << start << " -> "; 
    while(tickets.count(start)){
        cout << tickets[start] << " -> "; 
        start = tickets[start]; 
    }

    cout << "destination \n"; 
    // 
}
int main() {
    unordered_map<string, string> tickets; 
    tickets["Chennai"] = "Benguluru"; 
    tickets["Mumbai"] = "Delhi"; 
    tickets["Goa"] = "Chennai"; 
    tickets["Delhi"] = "Goa"; 

    printItenerary(tickets); 
    return 0; 
}
*/ 

// Q: 4: Largest SubArray with Sum 0; 
/*
#include <iostream>
#include <vector> 
#include <unordered_map> 
#include <unordered_set> 

using namespace std;
int largetsSubArrWith0ThSum(vector<int>arr){
    unordered_map<int, int> m; // sum, idx
    int sum = 0; 
    int ans = 0; 

    for(int j=0; j<arr.size(); j++){
        sum += arr[j]; 

        if(m.count(sum)){ // map ke andar count ki value for sum true hai
            int currLen = j-m[sum]; // j=idx 
            ans = max(ans, currLen); 
        }else{
            m[sum] = j;  // false hai to 
        }
    }

    return ans;  // O(n) for all loop 
}
int main(){
   vector<int> arr = {15, -2, 2, -8, 1, 7, 10}; 
   cout << "Largest subArray with sum 0 : " << largetsSubArrWith0ThSum(arr)<<endl; 

   return 0; 
}*/ 

// Q. 5: SubArray Sum Equals K 
/*
#include <iostream> 
#include <vector> 
#include <unordered_set> 
#include <unordered_map>

using namespace std; 

int subArrayCountWithK(vector<int> arr, int K){  // sum[i, j] = sum[j] - sum[i]
    unordered_map<int, int> m; 
    m[0] = 1; // zero with count of one 

    int sum = 0; 
    int ans = 0; 

    for(int i=0; i<arr.size(); i++){
        sum += arr[i]; 
        if(m.count(sum-K)){
            ans += m[sum-K]; 
        }

        if(m.count(sum)){
            m[sum]++; 
        }else{
            m[sum] = 1; 
        }
    }
        return ans; 
}
int main (){
    vector<int>  arr = {10, 2, -2, -20, 10}; 
    int K = -10; 

    cout << "SubArray count: "<< subArrayCountWithK(arr, K) << endl; 
    return 0; 
}
*/ 
//************************************************************************* */
//*Assignments : Questions: 
/*Question 1: 
Bottom View of a Binary Tree
- The top view of a binary tree is the set of nodes visible when the tree
is viewed from the top.
- given a binary tree, print the top view of it. The output nodes can be 
  printed in any order 
Sample input : 20 8 5 -1 -1 3 10 -1 -1 14 -1 -1 22 -1 25 -1 -1

Hint Use the concept of vertical Order*/

/*
#include <iostream> 
#include <queue> 
#include <map> 
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

void bottomView(Node* root){
    if(root == NULL){
        return ; 
    }

    map<int, int>hdNodeMap; // Map to store the horizontal distance and the corresponding bottom-most node
    queue<pair<Node*, int>> q; // queue to store nodes along with their horizontal distance

    q.push(make_pair(root, 0)); // Initialize the que with root node at horizontal distance 0

    while(!q.empty()){
        pair<Node*, int> temp = q.front(); 
        q.pop(); 

        Node* node = temp.first; 
        int hd = temp.second; 

        hdNodeMap[hd] = node->data;  // store/replace the node data for each horizontal distance in the map 

        if(node->left != NULL){ //Enque left child with horizontal distance -1
                q.push(make_pair(node->left, hd - 1)); 
        }

        if (node->right != NULL){
            q.push(make_pair(node->right, hd + 1)); 
        }

    }

    for(auto it : hdNodeMap){
        cout<< it.second << " "; 
    }

    cout << endl; 
}

int main (){
    // Sample input tree 
    Node* root = new Node(20); 
    root->left = new Node(8); 
    root->right = new Node(22); 
    root->left->left = new Node(5);
    root->left->right = new Node(3); 
    root->right->right = new Node(25);
    root->left->right->left = new Node(10); 
    root->left->right->right = new Node(14); 

    bottomView(root); 

    return 0; 
}
*/ 

// prev Question with Top View : 
/*
#include <iostream> 
#include <queue> 
#include <map> 
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

void topView(Node* root){
    if(root == NULL){
        return; 
    }

   map<int, int>hdNodeMap; // Map to store the horizontal distance and the corresponding top-most Node
   queue<pair<Node*, int>> q; // queue to store nodes along with their horizontal distance

   q.push(make_pair(root, 0)); // Initialize the queue root node at horizontal  distance 0 


   while(!q.empty()){
    pair<Node*, int> temp = q.front(); 
    q.pop(); 

    Node* node = temp.first; 
    int hd = temp.second; 

    if(hdNodeMap.find(hd) == hdNodeMap.end()){
        hdNodeMap[hd] = node-> data; 
    }

     if(node->left != NULL){
        q.push(make_pair(node->left, hd - 1)); 
     }

     if(node->right != NULL){
        q.push(make_pair(node->right, hd + 1)); 
     }
   }

   for(auto it : hdNodeMap){
        cout << it.second << " ";
   }
}


int main(){
    Node* root = new Node(20); 
    root->left = new Node(8); 
    root->right = new Node(22); 
    root->left->left = new Node(5);
    root->left->right = new Node(3); 
    root->right->right = new Node(25);
    root->left->right->left = new Node(10); 
    root->left->right->right = new Node(14); 

    topView(root); 
    return 0; 
}
*/ 

/*//*Question 2: Two Sum : 

Given an array of integers arr[] and an integer target, return indices of 
the two numbers such that they add up to target. 
YOu may asume that each input would have exactly one solution , and you may 
not use the same element twice YOu can return the answer in any order. 
SAmple imput 1  arr = [2, 7, 11, 15], target = 9
*/ 
/*

#include <iostream> 
#include <vector> 
#include <unordered_map> 
using namespace std; 

vector<int> twoSum(vector<int> & nums, int target){
        
        unordered_map<int, int> num_map; // To store the value and its index

        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i]; 
           
            if(num_map.find(complement) != num_map.end()){     
                return {num_map[complement], i}; // Found the solution 
            }
            num_map[nums[i]] = i; 
        }

        return {}; // In case no solution is found, though the problem states there will always be a solution. 
}

int main(){
    vector<int> arr = {2, 7, 11, 15}; 

    int target = 17;

    vector<int> result = twoSum(arr, target); 

    if(!result.empty()){
        cout << "Indices: " << result[0] << ", " << result[1] << endl; 
    }else{
        cout << "No solution found" << endl; 
    }

    return 0; 
}*/ 


/*Question : 3: Sort By frequency : 
    Given a string s, sort it in decreasing order based on the frequency 
    of the characters. The frequency of a character is the number of times of
    it appears in the string. 
  - Return the sorted string. If there are multiple answers, return any of them. 
  Sample Input 1: s = "cccaaa"; 
*/
/*
#include <iostream> 
#include <string> 
#include <unordered_map>
#include <vector> 
#include <algorithm>

using namespace std; 

bool compare(pair<char, int>&a, pair<char, int>&b){// Comparator function to sort pairs by frequency
       return a.second > b.second; // sort in decreasing order of frequency  
}

string sortByFrequency(const string& s){
   unordered_map<char, int> freqMap; 

   for(char c : s){ // calculate frequency of each character
        freqMap[c]++; 
   } 

    vector<pair<char, int>>freqVector(freqMap.begin(), freqMap.end()); // create a vector of pairs from the frequency map 

    sort(freqVector.begin(), freqVector.end(), compare); // sort the vector base frequency

    string result; 

    for(const auto& p : freqVector){
        result.append(p.second, p.first); // append character p.first p.second times
    }

    return result; 
}

int main () {
     string s = "cccaaa"; 
     string sortedString = sortByFrequency(s); 

    cout << "Sorted String: " << sortedString << endl; 
    return 0; 
}*/ 


/*Question 4: Bulls & Cows : 
 - You are playing a game with your friend. You wirte down a secret number 
 and ask your friend to guess what the number is. When your friend makes a 
 guess, you provide  a hint with the following info. 
 
 - The number of "bulls", which are digits in the guess that are in the correct position.
 - The number of 'cows', which are digits in the guess that are in your secret number but 
   are located in the wrong position Specifically, the non-bull digits in the guess that could
   be rearrange such that they becomes bull.
 - Given the secret number secret and your friends guess, return the hind for your friend's
   guess. 
   
- The hint should be formatted as "xAyB" Where s is the number of bulls and y is the number 
   of cowns Note that both secret and guess may contain duplicate digits.
   
   Sample Input1 :secret="1807", guess="7810"
   Sample Output1:"1A3B"
    */

   #include <iostream> 
   #include <vector> 
   #include <unordered_map> 
   #include <string> 

   using namespace std; 

   string getHint(string secret, string guess){
        int bulls = 0; 
        int cows = 0; 

        unordered_map<char, int> secretMap; 
        unordered_map<char, int> guessMap; 

        for(int i=0; i<secret.size(); i++){ // first count bulls
            if(secret[i] == guess[i]){
                bulls++; 
            }else{
                secretMap[secret[i]]++; 
                guessMap[guess[i]]++; 
            }
        }

        for(auto &pair: guessMap){

            int ch = pair.first; 
            if(secretMap.find(ch) != secretMap.end()){
                cows += min(pair.second, secretMap[ch]); 
            }
        }

        return to_string(bulls) + "A" + to_string(cows)+ "B"; 
   }

   int main(){
    string secret = "1807"; 
    string guess = "7810"; 

    cout <<"Hint: "<< getHint(secret, guess) << endl ;

    return 0; 
   }