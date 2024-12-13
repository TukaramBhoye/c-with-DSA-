/*graph_4:NB2:136: Longest common Substring:
- Longest Common Substring : substring is contigious sequence of charater with strint */
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int LCSubstring(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    int ans = 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++) {
            if (str1[i - 1] == str2[j - 1]){
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                    ans = max(ans, dp[i][j]); 
            }else{
                dp[i][j] = 0; 
            }
        }
    }
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++) {
            cout << dp[i][j] << " "; 
        }
        cout << endl; 
    }
    return ans; 
}
int main(){
    string str1 = "abcde";
    string str2 = "abgce";

    cout << LCSubstring(str1, str2) << endl; 
    return 0;
}
*/

// Q:2:(LIS) Longest common increasing sequence: 

/*
#include <iostream> 
#include <vector> 
#include <string> 
#include <unordered_set> 
#include <algorithm> 
using namespace std; 

int LIS(vector<int> arr){
    unordered_set<int> s(arr.begin(), arr.end());  // unique - O(n)

    vector<int> arr2(s.begin(), s.end()); 
    sort(arr2.begin(), arr2.end()); // ascending sorted order - O(n log n)
   
    //LCS => LIS 
    int n = arr.size(); 
    int m = arr2.size(); 

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); 

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(arr[i-1] == arr2[j-1]){
                dp[i][j] = 1 + dp[i - 1][j - 1]; 
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }
    }
    return dp[n][m]; 
}

int main(){
    vector<int> arr = {50, 3, 10, 7, 40, 80}; 

    cout << LIS(arr)<< endl;

    return 0; 
}
*/ 

/* Q.3: Edit Distance : for 2 strings, return min no. of operations to 
convert str1 to str2. 
    str1 = "abc"; str2 = "ac"; ops = 1; // delete 'b' 
    str1 = "horse"; str2 = "ros" ops = 3; // replace 'h' with 'r' & delete 'r' & 'e'
*/ 
/*Explanation:
*Initialization:
 - The first row and column of the dp table are initialized to represent 
   the cost of converting an empty string to the other string.

*Filling the DP Table:
-  The table is filled in a bottom-up manner. If the characters match, we 
   take the diagonal value. Otherwise, we take the minimum value from insertion, 
   deletion, or replacement and add 1.
*Return Value:
  - The final value at dp[n][m] represents the minimum edit distance between word1 
    and word2.
*//*
#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


    int minDistance(string word1, string word2) { 
        int n = word1.size(); 
        int m = word2.size(); 
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); 

        // Initialize the first row and column
        for(int j = 0; j < m + 1; j++){
            dp[0][j] = j; 
        }
        for(int i = 0; i < n + 1; i++){
            dp[i][0] = i; 
        }

        // Bottom-up fill
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1]; 
                } else {
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                }
            }  
        }
        return dp[n][m];
    }

int main() {
    
    string str1 = "horse";
    string str2 = "ros";

    
    cout << minDistance(str1, str2) << endl; 

    return 0;
}

*/ 

