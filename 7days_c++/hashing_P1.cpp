// 43:NB:71:hasing Part 1->

// Q.3 :  Building Hashing table :
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        this->next = NULL;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

class HashTable {
    int totSize;
    int currSize;
    Node** table;

    int hashFunction(string key) {
        int idx = 0;
        for (int i = 0; i < key.size(); i++) {
            idx = idx + (key[i] * key[i]) % totSize;
        }
        return idx % totSize; // Hash index should be modulo table size
    }

    void rehash() {
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = 2 * totSize; // Increase table size
        currSize = 0;
        table = new Node*[totSize];

        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }


        // Copy old values to new table
        for (int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];
            while (temp != NULL) {
                insert(temp->key, temp->val);
                temp = temp->next;
            }
            if (oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int size = 5) {
        totSize = size;
        currSize = 0;
        table = new Node*[totSize];

        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) {
        int idx = hashFunction(key);
        Node* newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx] = newNode;
        currSize++;

        double lambda = currSize / (double)totSize;
        if (lambda > 1) {
            rehash();  // Rehash if load factor > 1
        }
    }

    bool exist(string key) {
        int idx = hashFunction(key);
        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) { // Key found
                return true;
            }
            temp = temp->next;
        }
        return false; // Key not found
    }

    int search(string key) {
        int idx = hashFunction(key);
        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                return temp->val; // Return value if key found
            }
            temp = temp->next;
        }
        return -1; // Return -1 if key not found
    }

    void remove(string key){
            int idx = hashFunction(key);

            Node* temp = table[idx];
            Node* prev = temp;
            while(temp != NULL){  // O(lambda  // all nodes tak jayega)
                if(temp->key == key){
                    if(prev == temp){
                        table[idx] = temp->next;
                    }else{
                        prev->next = temp->next;
                    }
                    break;
                }

                prev = temp;
                temp = temp->next;
            }
    }

    void print(){
        for(int i=0; i<totSize; i++){
            cout << " idx "<< i << "->";
            Node* temp = table[i];
            while (temp != NULL){
                cout << "(" << temp->key << ","<< temp->val << ") -> ";
                temp = temp -> next;
            }
      cout << endl ;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("Us ", 50);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);

    if (ht.exist("Canada")) {
        cout << "India population: " << ht.search("India") << endl;
    }


    ht.remove("China");
    ht.print();

    cout << "--------------\n";
    ht.remove("UK");
    ht.print();
    return 0;
}
*/

// 5:NB2:75: STL Containers : i : Unordered Maps : ii: maps
// iii: Unordered Set  // iv : set
/*
#include <iostream>
#include <unordered_map>
#include <map> 
using namespace std;
//i : Unordered Map 
int main()
{
    unordered_map<string, int> map;
    map["China"] = 150;
    map["India"] = 150;
    map["US"] = 50;
    map["Nepal"] = 10;

    cout << map["India"] << endl ;

    for(pair<string, int> country : map){
         cout << country.first<< " , "<< country.second << endl;
    }

    if(map.count("Canada")){
        cout << "Canada exists\n"; 
    }else{
        cout << 'Nepal doesnt exist' << endl;
    }
} 
// ii: Ordered Map : 

int main()
{
    map<string, int> map;
    map["China"] = 150;
    map["India"] = 150;
    map["US"] = 50;
    map["Nepal"] = 10;
    map["UK"] = 20;

    cout << map["India"] << endl ;

    for(pair<string, int> country : map){
         cout << country.first<< " , "<< country.second << endl;
    }

    if(map.count("Canada")){
        cout << "Canada exists\n"; 
    }else{
        cout << 'Nepal doesnt exist' << endl;
    }
}
*/
// iii: Unordered Set 
/*
#include <iostream> 
#include <unordered_set> 
#include <set> 
#include <unordered_map>

using namespace std; 
int main(){
    unordered_set<int> s; 

    s.insert(1); 
    s.insert(2);
    s.insert(4); 
    s.insert(5);
    s.insert(6); 
    // once we store value after cannot add new value 
    // to see magic before run prev val and after save further vals 
    s.insert(7);
    s.insert(8); 
   
   cout << s.size()<< endl; 

   if(s.find(10) != s.end()){
    cout << "exists\n"; 
   }else{
    cout << "10 doesn't exist" << endl; 
   }

   for(auto el: s){
        cout << el << " "; 
   }

   return 0; 
}
*/ 

// iv: Set: 
/*
#include <iostream> 
#include <unordered_set> 
#include <set> 
#include <unordered_map>

using namespace std; 
int main(){
    set<int> s; 

// print unique values
    s.insert(1); 
    s.insert(2);
    s.insert(4); 
    s.insert(1);
    s.insert(6);  
    s.insert(3);
    s.insert(1); 
   
  
  cout << s.size() << endl;  // OP: 5
   for(auto el: s){
        cout << el << " "; // 1 2 3 4 6
   }

   return 0; 

}
*/

// Q. PairSum : 
//[1, 2, 7, 11, 15, 5, 9]       target = 9; 
/*
#include <iostream> 
#include <unordered_map> 
using namespace std; 

int main(){
    int arr[] = {1, 2, 7, 11, 15, 5, 9}; 

    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9; 

    unordered_map<int, int>m; 

    for(int i=0; i<n; i++){
        int comp = target - arr[i]; 

        if(m.count(comp)){
            cout << "Ans = "<< m[comp] << " , "<< i << endl; 
          break; 
        }

        m[arr[i]] = i; 
    }

    return 0; 

}*/ 

