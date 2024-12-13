//55:NB2:139:DP Part_5: 

/*
Q.4: Given an input string (s) and a pattern (p), implement wildcard pattern matching 
with support for '?' and '*' where:

- '?' Matches any single character.
- '*' Matches any sequence of characters (including the empty sequence).
 The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
*/
/*
#include <iostream> 
#include <vector> 
#include <string> 
using namespace std; 

int isMatch(string t, string p){
    int n = t.size(); 
    int m = p.size(); 

    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false)); 
    dp[0][0] = true; 

    for(int j=1; j<m+1; j++){
        if(p[j-1] == '*'){
            dp[0][j] = dp[0][j-1]; 
        }else{
            dp[0][j] = false; 
        }
    }

    // Fill up in a bottom-up manner
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(t[i-1] == p[j-1] || p[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1]; 
            }else if(p[j-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }else{
                dp[i][j] = false;
            }
        }
    }

    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl; 
    }
    return dp[n][m]; 
}

int main(){
    string t = "abc"; 
    string p = "ab?"; 

    cout << isMatch(t, p) << endl; 
}
*/ 

/*Q.5 : Catalans Number C0 = 1 , C1 = 1, c2 = 2, c3 = 5, c4 = 14, c5 = 42 
 example for 2 : c0 * c2 + c1 * c1 + c2 * c0 
 
*/
/*
#include <iostream> 
#include <vector> 
using namespace std; 

int catalans(int n){
    if(n==0 || n == 1){
        return 1; 
    }

    int ans = 0; 
    for(int i=0; i<n; i++){
        ans += catalans(i) * catalans(n-i-1); 
    }

    return ans; 
}

int main (){
    for(int i=0; i<=6; i++){
        cout << catalans(i)<< " "; 
    }
    cout << endl; 
    return 0; 
}
*/ 

// Q.6 :  catalans using dp->memoization
/*
#include <iostream>
#include <vector>
using namespace std;

int catalansMem(int n, vector<int> &dp){
    if (n == 0 || n == 1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int ans = 0; 
    for(int i=0; i<n; i++){
        ans += catalansMem(i, dp) * catalansMem(n-i-1, dp);
    }

    return dp[n] = ans; 
}

int catalansTab(int n){
    vector<int> dp(n+1, 0); 
    dp[0] = dp[1] = 1; 

    for(int i=2; i<=n; i++){
        for(int j = 0; j<i; j++) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n]; 
}
int main(){
    int n = 4;
    // vector<int> dp(n + 1, -1);

    for (int i = 0; i <= n; i++){
        cout << catalansTab(i)<< " "; 
    }
    cout << endl; 
    return 0; 

}*/ 


/*Q.7 : Count BSTs : 
Find count of all possible structurally unique BSTs that ca nbe formed 
with n nodes. */
/* 
#include <iostream> 
#include <vector>
using namespace std;

int countBst(int n){
     vector<int> dp(n+1, 0); 
        dp[0] = dp[1] = 1; 

        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++){
                dp[i] += dp[j] * dp[i-j-1]; 
            }
        }
        return dp[n];
}
int main (){
    int n = 3; 

     cout << countBst(n) << endl;
    
    return 0; 
}
*/ 


/*Q.8: Mountain Ranges :Using up & strokes create mountains. Find total */
/*
#include <iostream> 
#include <vector>
using namespace std;

int mountainRanges(int n){
    vector<int> dp(n+1, 0); 
    dp[0] = dp[1] = 1; 

    for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
            dp[i] += dp[j] * dp[i-j-1]; 
        }
    }

    return dp[n]; 
}

int main(){
    int pairs = 3; //5

    cout << mountainRanges(pairs) << endl; 
    return 0; 
}
*/ 

#include <iostream> 
#include <vector> 
#include <climits>
using namespace std; 

int mcmRec(vector<int> arr, int i, int j){ //return minCost 
     if(i == j){
        return 0; 
     }

     int ans = INT_MAX; 

     for(int k=i; k<j; k++){
        // i, k

        int cost1 = mcmRec(arr, i, k); 

        // k+1, j
        int cost2 = mcmRec(arr, k+1, j);

        // curr Partition cost
        int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]); 
        ans = min(ans, currCost); 
     }

     return ans; 
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 3};  // n -> n-1 matrices (1 to n-1)
    int n = arr.size(); 

    cout << mcmRec(arr, 1, n-1); 
    return 0; 
}