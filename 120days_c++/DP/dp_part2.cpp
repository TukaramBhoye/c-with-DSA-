//52:NB2:125: Dynamic Programming_part_2: 

//Question 1 : 0/1 Knapsack problem :
/*
#include<iostream> 
#include <vector> 
using namespace std; 

int knapsackRec(vector<int> val, vector<int>wt, int w, int n ){
    if(n == 0 || w == 0){
        return 0;
    }
    int itemWt = wt[n - 1]; 
    int itemVal = val[n - 1];

    if(itemWt <= w){
       //*include 
        int ans1 = knapsackRec(val, wt, w-itemWt, n-1) + itemVal; 
        //*exclude
        int ans2 = knapsackRec(val, wt, w, n-1); 
        return max(ans1, ans2); 
    }else{
        //*exclude
        return knapsackRec(val, wt, w, n-1); 
    }
}

int main(){
    vector<int> val = {15, 14, 10, 45, 30}; 
    vector<int> wt = {2, 5, 1, 3, 4}; 
    int w = 7; 
    int n = 5; 

    cout << knapsackRec(val, wt, w, n) << endl; 
    return 0; 
}*/


//2: Process of "Memoization" with 0/1 Knapsack 
/*
#include <iostream> 
#include <vector> 
using namespace std;

int  knapsackMem(vector<int> val, vector<int> wt, int c, int n, vector<vector<int>>&dp  ){
    if( n == 0 || c == 0){
        return 0; 
    }

    if(dp[n][c] != -1){
        return dp[n][c]; 
    }

    int itemWt = wt[n-1]; 
    int itemVal = val[n-1]; 

    if(itemWt <= c){
        int ans1 = knapsackMem(val, wt, c-itemWt, n-1, dp) + itemVal; 

        // exclude 
        int ans2 = knapsackMem(val, wt, c, n-1, dp); 

        dp[n][c] = max(ans1, ans2); 
    }else{
        dp[n][c] = knapsackMem(val, wt, c, n-1, dp); 
    }
    return dp[n][c]; 
}

int knapsackWithTab(vector<int> val, vector<int> wt, int c, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < c + 1; j++) {
            int itemWt = wt[i - 1];
            int itemVal = val[i - 1];

            if (itemWt <= j) {
                dp[i][j] = max(itemVal + dp[i - 1][j - itemWt], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Optional: Debugging print for dp table
    
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < c + 1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    

    return dp[n][c];
}

int main (){
    vector<int> val = {15, 14, 10, 45, 30}; 
    vector<int> wt = {2, 5, 1, 3, 4}; 

    int c = 7;  //capacity  c = w ; 
    int n = 5; 

    cout << knapsackWithTab(val, wt, c, n); 
*/
/*
    vector<vector<int>> dp(n+1, vector<int>(c+1, -1));
    cout << knapsackMem(val, wt, c, n, dp) << endl;

    cout << "Mem matrix : "; 

    for(int i = 0; i<n+1; i++){
        for(int j = 0; j < c + 1; j++){
            cout << dp[i][j] << "   ";
        
        }
        cout << endl; 
    } 
    return 0; 
}*/ 

/* Question 2: TargetSum Subset : find there is a subset number which give the 
sum equal to target--> target = 7 : nums[] = {4, 2, 7, 1, 3}  subsets: i: 4, 2, 1 
                                     ii: 7        iii : 4, 3 --> here sum = 7
                                      */
  /*                             
#include <iostream> 
#include <vector> 
using namespace std; 

bool targetSum(vector<int> nums, int target){
    int n = nums.size(); 

    // Initializing a 2D DP Array 
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0)); 

    // loop over each item in the array 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){

            // checking if the current item can be included in the subset

            if(nums[i-1] <= j){
                dp[i][j] = max(nums[i-1]+ dp[i-1][j-nums[i-1]], dp[i-1][j]); 
            }else{
                dp[i][j] = dp[i-1][j]; 
            }
        }
    }
     for(int i=0; i<=nums.size(); i++){
        for(int j=0; j<=target; j++){
             cout << dp[i][j] << " "; 
        }
        cout << endl; 
     }

    //Return true if we can form the exact target sum 
    return dp[n][target] == target; 
}

int main (){
    vector<int> nums = {4, 2, 7, 1, 3}; 
    int target = 10; 
    
    cout <<"Ans : " <<  targetSum(nums, target) << endl;
    
    return 0; 
}
*/ 

/*Unbounded KnapSack 
val[] = {15, 14, 10, 45, 30}
wt[] = {2, 5, 1, 3, 4} W = 7

*/
#include <iostream> 
#include <vector> 
using namespace std; 
int unBoundedKnapsack(vector<int> val, vector<int> wt, int w, int n){
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0)); 

    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            int itemVal = val[i-1]; 
            int itemWt = wt[i-1];

            if(itemWt <= j){
                dp[i][j] = max(itemVal + dp[i][j-itemWt], dp[i-1][j]); 
            } else{
                dp[i][j] = dp[i-1][j]; 
            }
        }
    }
    return dp[n][w]; 
}
int main(){
    vector<int> val = {15, 14, 10, 45, 30 };
    vector<int> wt = {2, 5, 1, 3, 4}; 
    int w = 7; 
    int n = 5; 

    cout << unBoundedKnapsack(val, wt, w, n)<< endl; 

   return 0; 
}

