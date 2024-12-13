/*How to Building Tries DS
i: insert ii. search  concepts */

/*
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Node{
    public:
    unordered_map<char, Node*> children;

    bool endOfword;
    Node(){
        endOfword = false; // false until explicitely not done true
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(string key){
        Node* temp = root;

        for(int i=0; i<key.size(); i++ ){

            if(temp->children.count(key[i]) == 0){ // if key not exist
                temp->children[key[i]] = new Node();
            }

            temp = temp->children[key[i]];
        }
        temp->endOfword = true;
    }

    bool search (string key){
        Node* temp = root;

        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];
            }else{
                return false;
            }

        }
        return temp->endOfword;
    }
};

// Q. 2: Word Break Problem
bool helper(Trie &trie, string key){
    if(key.size() == 0){
        return true;
    }

    for(int i=0; i<key.size(); i++){
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);

        if(trie.search(first) && helper(trie, second)){
            return true;
        }
    }

    return false;
}

bool wordBreak(vector<string>dict, string key){
    Trie trie;

    for(int i=0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }

    return helper(trie, key);
}
int main(){
    vector<string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};
    cout << wordBreak(dict, "like") << endl ;
*/
// for search
/*  vector<string> words = {"the", "a", "there", "their", "any", "thee"};

    Trie trie;
    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }

    cout << trie.search("any") << endl; // 1

    return 0;
}
*/

/*Q.*3:  Find shortest unique prefix for each word(no word prefix of another)
 */
/*

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Node{
    public:
    unordered_map<char, Node*> children;
    bool endOfword;
    int freq;

    Node(){
        endOfword = false; // false until explicitely not done true
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
        root->freq = -1;
    }

    void insert(string key){
        Node* temp = root;

        for(int i=0; i<key.size(); i++ ){

            if(temp->children.count(key[i]) == 0){ // if key not exist
                temp->children[key[i]] = new Node();
                temp->children[key[i]]->freq = 1;
            }else{
                temp->children[key[i]]->freq++;
            }

            temp = temp->children[key[i]];
        }
        temp->endOfword = true;
    }

    bool search (string key){
        Node* temp = root;

        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];
            }else{
                return false;
            }

        }
        return temp->endOfword;
    }

    string getPrefix(string key){ // O(L)
        Node* temp = root;
        string prefix = "";

        for(int i=0; i<key.size(); i++){
            prefix += key[i];
            if(temp->children[key[i]]->freq == 1){
                return prefix;
            }

            temp = temp->children[key[i]];
        }
        return prefix;
    }


// Q. 4: complete this for a trie: bool startsWith (string prefix)
    bool startsWith(string prefix){
        Node* temp = root;

        for(int i=0; i<prefix.size(); i++){
            if(temp->children[prefix[i]]){ // if exist
                temp = temp->children[prefix[i]];
            }else{
                return false;
            }
        }
        return true;
    }
};

void prefixProblem(vector<string>dict){
    Trie trie;
    for(int i=0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }

    for(int i=0; i<dict.size(); i++){
        cout << trie.getPrefix(dict[i])<< " ";
    }
}
//-----------


int main (){
    // Q. 4:
    vector<string> words = {"apple", "app", "mango", "man", "women"};

    Trie trie;
    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }

    cout << trie.startsWith("wom") << endl;


    // Q. 3: find shortest unique prefix for each word. No word prefix of another)
    // vector<string> dict = {"zebra", "dog", "duck", "dove"};
    // prefixProblem(dict);
     return 0;
}
*/

// Q.10: Longest String with all prefixes :
// from mam code : the code is wrong :
/*
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfword;

    Node() {
        endOfword = false; // false until explicitly set to true
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string key) {
        Node* temp = root;

        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) { // if key not exist
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfword = true;
    }

    string longestHelper(Node* root, string &ans, string temp){
        for(pair<char, Node*> child : root->children) {
         if(child.second->endOfword){


            temp += child.first;

            if((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())){
                ans = temp;
            }

            longestHelper(child.second, ans, temp);
            temp = temp.substr(0, temp.size()-1);
        }
      }
    }
    string longestStringEOW(){ // also helper of this
        string ans = "";
        longestHelper(root, ans, "");
        return ans;
    }
};
 string longestString(vector<string>dict){
    Trie trie;

    for(int i=0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }

    return trie.longestStringEOW(); // root is private member tr we can not pass form here for that we make a helper Function
 }


int main() {
    vector<string> dict = {"a", "banana", "appl", "ap", "apply", "apple"};

    cout << longestString(dict) << endl;
    return 0;
}
*/

//-Assingments: -----------------------------------------------------
/*//*Question 1: Medium : Group anagrams :
*Given an array of strings strs, group the anagrams together.
 You can return the answer in any order.
 An Anagrams is a word or phrase formed by rearranging the letters of
 a different word or phrase, typically using all the original letters exactly
 once.
 Sample Input 1: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 Sample Output 1: [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]] */

/*
  #include <iostream>
  #include <vector>
  #include <unordered_map>
  #include <algorithm>

  using namespace std;

  vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<string, vector<string>> anagramGroups;

    for(string str : strs){
        string sortedStr = str;

        sort(sortedStr.begin(), sortedStr.end());

        anagramGroups[sortedStr].push_back(str);
    }

    vector<vector<string>> result;
    for(auto &group : anagramGroups){
        result.push_back(group.second);
    }

    return result;
  }


  int main (){
    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groupAnag = groupAnagrams(str);

    for(const auto &group: groupAnag ){
        cout << "[";

        for(const auto& word : group){
            cout << word << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
*/

//*Question 2: MEDIUM : Longest Word in Dictionary :
/*Given an array of strings words represnting an English Dictionary, return
 the longest word in words that can be built one character at a time by other
 words in words.

 If there is more than one possible answer, return the longest word with
 the smallest lexicographical order. If there is no answer, return the empty string

 Note that the word should be built from left to right with each additional
 character being added to the end of a previous word.

 Sample Input 1 words = ["w", "wo", "wor", "worl", "world"]
 Sample Output 1 : "world" */

/*
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

string longestWord(vector<string> &words){
        unordered_set<string> wordSet(words.begin(), words.end());    
        string longest = "";

        for(const string &word : words) {
        bool canBuild = true;

        for (int i = 1; i < word.size(); ++i){
            if (wordSet.find(word.substr(0, i)) == wordSet.end()) {
                canBuild = false;
                break;
            }
        }

        if(canBuild && (word.size() > longest.size() || 
        (word.size() == longest.size() && word < longest))){

            longest = word; 
        }
    }

    return longest ; 
}

int main (){
    vector<string> words = {"w", "wo", "wor", "worl", "world"};
    cout << "Longest word: "<< longestWord(words) << endl ;

    return 0; 
}
*/ 
