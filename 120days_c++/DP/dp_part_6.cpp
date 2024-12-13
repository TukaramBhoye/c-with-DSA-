
//56:NB2:149: Dynamic Programming : 

/*MCM(matrices chain Multiplication) : with recursion */
/*
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
}*/

/*MCM with Memoization : both need in Mem i: overlapping subproblems ii: optimal substructure 
*/
/*
#include <iostream> 
#include <vector> 
#include <climits> 

using namespace std; 

int mcmMem(vector<int> arr, int i, int j, vector<vector<int>> & dp){
    if(i==j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j]; 
    }

    int ans = INT_MAX; 

    for(int k = i; k<j; k++){
        // (i, k) 
        int cost1 = mcmMem(arr, i, k, dp); 

        //k+1, j
        int cost2 = mcmMem(arr, k+1, j, dp); 

        // curr Partion cost 

        int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, currCost);  
    }

    return dp[i][j] = ans; 
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 3}; // n-> n-1 matrices (1 to n-1)
    int n = arr.size(); 

    vector<vector<int>> dp(n, vector<int> (n, -1));

    cout << mcmMem(arr, 1, n-1, dp) << endl ;
    return 0; 
}
*/ 

// tabulation : 
/*
#include <iostream> 
#include <vector> 
#include <climits> 
using namespace std; 

int mcmTab(vector<int> arr){
    int n = arr.size(); 
    vector<vector<int>> dp(n, vector<int> (n, 0)); 

    // initialization 
     for(int i=1; i<n; i++){
        dp[i][i] = 0; 
     }
   
   // bottom up fill 
   for(int len=2; len<n; len++){
    for(int i=1; i<=n-len; i++){
        int j = i+len-1; 
        dp[i][j] = INT_MAX; 

        for(int k=i; k<j; k++){
            int cost1 = dp[i][k]; 
            int cost2 = dp[k+1][j]; 

            int currCost = cost1 + cost2 + (arr[i-1]*arr[k]*arr[j]); 
            dp[i][j] = min(dp[i][j], currCost); 

        }
    }
   }
   for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dp[i][j] << " "; 
        } 
        cout << endl;   
    }
    return dp[1][n-1]; 
}
int main (){
    vector<int> arr = {1, 2, 3, 4, 3}; 
    int n = arr.size(); 

    vector<vector<int>> dp(n, vector<int> (n, -1)); 
    cout << mcmTab(arr) << endl; 

    return 0; 
}
*/ 
// Q.homework : egg Droping problem 


/*Q.4: Minimum Partitioning :  
   arr = {1, 6, 11, 5}  partitioning--> grp1: 1, 6   grp2 : 11, 5 : min dif : 9 
                                        grp1: 1, 5  grp2 : 6, 11 : 6 & 17 Min dif = 11
                                        grp1: 1, 5, 6--> 12 grp2: 11   : 12 & 11 min diff = 1


*/
// tabulation code : 
#include <iostream> 
#include <vector> 
using namespace std; 

int getMinDiff(vector<int> nums){
    int totSum = 0; 
    for(int el : nums){
        totSum += el; 
    }

    int n = nums.size(); 
    int w = totSum/2; 
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0)); 

    for(int i=1; i<n+1; i++){
        for(int j = 1; j<w+1; j++){
            if(nums[i-1] <=j) {
                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]); 
            }else{
                dp[i][j] = dp[i-1][j]; 
            }
        }
    }

    int grp1Sum = dp[n][w]; 
    int grp2Sum = totSum - grp1Sum; 
    return abs(grp1Sum - grp2Sum); 
}

int main(){
    vector<int> nums = {1, 6, 11, 5}; 

    cout << getMinDiff(nums) << endl;

    return 0; 
}