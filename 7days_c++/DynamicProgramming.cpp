//51:DP:NB2:121: Dynamic Programming:
/* keys : 1: optimal substructure: 
        2: overlapping subproblems 

/*1: Fibonacci with optimize code Using DP*/
/*
#include <iostream> 
#include <vector> 
using namespace std; 
// Without DP
int fib(int n ){
    if(n == 1 || n == 0){
        return n; 
    }
    return fib(n-1) + fib(n-2); 
}

//With DP TC : O(n)
int fibDP(int n, vector<int>&f ) {
    if(n==0 || n == 1){
        return n; 
    }

    if(f[n] != -1){ // -1 = already exist at another place
        return f[n]; 
    }

    f[n] = fibDP(n-1, f) + fibDP(n-2, f); 
    return f[n]; 

}
int main(){
    int n = 6; 

    vector<int> f(n+1, -1); 
    cout << fib(n) << endl; 

    cout << fibDP(n, f); 
    return 0; 
} 
*/ 

//2: fibonacci with tabular form :
/*keys: i: define DS and meaning of cell(if metrix) & index(if 1D Array)
ii: initialize with smallest solution 
iii: solve small to large value.
*/ 
/*
#include <iostream>
#include <vector>  
using namespace std; 

int fibTab(int n){
    vector<int> fib(n+1, 0);

    fib[0] = 0; 
    fib[1] = 1; 

    for(int i=2; i<=n; i++){
        fib[i] = fib[i-1] + fib[i-2]; 
    }
    return fib[n]; 
}

int main(){
    int n = 6;
    cout << fibTab(n) << endl ;
    return 0 ;
}
*/ 

//Q.2: Climbing Stairs : 
/* Count Ways to reach the nth stair. A person can climb 1 or 2 stairs 
at a time. 
*/
/*
#include <iostream> 
#include <vector> 
using namespace std; 

int countWaysRec(int n ){
    if(n == 0 || n == 1){
        return 1; 
    }
   
    int result =  countWaysRec(n-1) + countWaysRec(n-2); 

    return result;
}

// Program Top Down apRoach Of Memoization : 
int countWayMemoization(int n, vector<int> &dp){
    if(n == 0 || n == 1 ){
        return 1; 
    }

    if(dp[n]!= -1){
        return dp[n]; 
    }

    dp[n] = countWayMemoization(n - 1, dp)  + countWayMemoization(n - 2, dp);  
}

int countWaysTab(int n){
    vector<int> dp(n+1, 0);
        dp[0] = 1; 
        dp[1] = 1; 

        for(int i = 2; i<=n; i++){
            dp[i] = dp[i - 1] + dp[i - 2]; 
        
        }

        return dp[n]; 
}

// Count ways to reach the nth stair. A person can climb 1, 2 or 3 stairs at a time. 
int countWaysTabStairs(int n){
    vector<int> dp(n+1, 0); 
    dp[0] = 1; 
    dp[1] = 1; 
    dp[2] = 2; 

    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]; 
    }

    return dp[n]; 
}
int main(){
   int n = 5; 
  
   cout << countWaysTabStairs(n) << endl; 
    return 0; 
}
*/ 




