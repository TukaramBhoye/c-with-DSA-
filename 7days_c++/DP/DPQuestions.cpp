// DP -- Questions :
/*  Q.1: i: tabulation  Tribonacci Sequence : 
The Tribonacci sequence Tn is defined as follows: 
T0 = 0, T1 = T2 = 1, and Tn+3 = Tn + 3 = Tn + Tn+1 + Tn + 2 for n >= 0. 
Given n, return the value of Tn. 
*/
/*
#include <iostream> 
#include <vector> 
using namespace std; 
class solution {
    public : 
    int tribonacci(int n){
        // handle the base cases 
        if (n == 0) return 0; 
        if(n == 1 || n == 2) return 1; 

        // Initialize a DP array to store the Tribonacci numbers 

        vector<int> dp(n+1); 
        dp[0] = 0; 
        dp[1] = 1; 
        dp[2] = 1; 

        // fill the DP array using the recurrence relation 
        for (int i=3; i <= n;  i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3]; 
        }

        // return the nth Tribonacci number 
        return dp[n] ;
    }
};
int main(){
    solution sol; int n; 
    cout << "Enter the value of n: " ; 

    cin >> n ;

    int result = sol.tribonacci(n); 
    cout << "Tribonacci number T" << n << " is: " << result << endl; 

    return 0; 
}

*/ 

/*ii: tribonacci with memoization : */
/*
#include <iostream> 
#include <vector> 
using namespace std; 

class Solution{
    public: 
    int tribonacci(int n){
        // create a memoization array initialized with -1 to indicate uncomputed values 
        vector<int> memo(n+1, -1); 

        return triboHelper(n, memo); 
    }

    private: 
        int triboHelper(int n, vector<int>& memo){
            // Base cases 
            if(n == 0) return 0; 
            if(n == 1 || n == 2) return 1;

            // if the value has already been completed, return it
            if(memo[n] != -1) return memo[n];

            //recursively compute the value while storing the result in the memo array

            memo[n] = triboHelper(n-1, memo) + triboHelper(n-2, memo) + triboHelper(n-3, memo); 
            return memo[n]; 
        }
};

int main (){
    Solution sol; 
    int n = 6 ; 

    int result = sol.tribonacci(n); 

    cout << "Tribonacci number " << n << " = " << result << endl; 

    return 0; 
}*/ 


/*Question 2: Maximum Profit after buying and selling stocks with transaction fees :
You are given an array of prices where price[i] is the price of a given stock on the
ith day, and an integer fee reprsenting a tranjaction fee. 

- find the maximum profit you can achievve. You nay complete as many transactions as
you like, but you need to pay the transaction fee for each transaction.  */

 // ---Memoization Code : -------------
/*
class Solution {
public:
        int maxProfit(vector<int>&prices, int fee){
            // start with day 0, and not holding any stock 
            return dp(0, 0, prices, fee); 
        }
        unordered_map<int, unordered_map<int, int>> memo; 

        int dp(int i, int holding, vector<int> &prices, int fee){
            // Base case: when we've considered all days
            if( i == prices.size()){
                return 0; 
            }

            // if res already in mem 
            if(memo[i][holding]){
                return memo[i][holding]; 
            }

            int doNothing = dp(i + 1, holding, prices, fee); 
            int doSomething; 

            if(holding){
                // sell the stock 
                doSomething = dp(i+1, 0, prices, fee) + prices[i] - fee; 
            }else{
                // Buy the stock 
                doSomething = dp(i + 1, 1, prices, fee) - prices[i]; 
            }

            //Record the best Option in the memoization table 
            return memo[i][holding] = max(doNothing, doSomething); 
        }

};

*/ 

// tabulation code: 
/*
#include <iostream> 
#include <vector> 
using namespace std; 

 class Solution {
    public: 
    int maxProfit(vector<int> & prices, int fee){
        int n = prices.size(); 
        // create two vectors to store the maximum profit up to day i
        vector<int> hold(n, 0); 
        vector<int> notHold(n, 0); 

        //inital conditions : 
        hold[0] = -prices[0]; 
        notHold[0] = 0; 

        // fill the dp tables
        for(int i=1; i<n; ++i){
            hold[i] = max(hold[i-1], notHold[i-1] - prices[i]); 
            notHold[i] = max(notHold[i - 1], hold[i - 1] + prices[i] - fee); 
        }

        return notHold[n - 1]; 
    }
 };
 */ 

// Question 3: Hard 
/*Longest Increasing Path in Matrix : 
- Given an M * N integers matrix, return the length of the longest increasing 
path in the Matrix. 

- From each cell, you can either move in four directions, left, right, up or down. You 
 may not move diagonally or move outside the boundary(i.e., wrap-around is not allowed) */

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    // If the result is already memoized
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Right, Down, Left, Up
    int maxLength = 1; // Minimum length will be 1 (cell itself is a path)

    for (auto dir : directions) {
        int x = i + dir[0];
        int y = j + dir[1];

        // Boundary check and increasing condition
        if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] > matrix[i][j]) {
            int len = 1 + dfs(x, y, matrix, dp); // Path length from the neighbor
            maxLength = max(maxLength, len);  // Update with the longest path found
        }
    }
    
    dp[i][j] = maxLength; // Memoize the result
    return dp[i][j];
}

int longestIncreasingPath(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, -1)); // Memoization array

    int result = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result = max(result, dfs(i, j, matrix, dp)); // Compute longest path for each cell
        }
    }

    return result;  // Return the maximum length
}

int main() {
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    cout << "Longest Increasing Path Length: " << longestIncreasingPath(matrix) << endl;
    return 0;
}
*/ 


/*Question 4: Generate Parenthesis: 
Given n pairs of parenthesis, write a funcion to generate all combinations
of well-formed parentheses.*/
// Tabulation : 
/*
#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std; 

vector<string> generateParenthesis(int n){
    vector<vector<vector<string>>> dp(n+1, vector<vector<string>>(n+1)); 

    dp[0][0].push_back(""); 

    //fill the dp table
    for(int open = 0; open <= n; ++open){
        for(int close = 0; close <= n ; ++close){
            if (open > 0) {
                for(const string &s : dp[open - 1][close]){
                    dp[open][close].push_back("(" + s); 
                }
            }

            if(close > open){
                for(const string & s : dp[open][close - 1]){
                    dp[open][close].push_back(")" + s);
                }
            }
        }
    }
     return dp[n][n]; 
}

int main(){
    int n = 4; 
    vector<string> result = generateParenthesis(n);

  for(const string &str : result){
    cout << str << endl; 
  }

  return 0; 
}*/ 

// Memoization : 
/*
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Function to generate all combinations of well-formed parentheses
vector<string> generate(int open, int close, unordered_map<string, vector<string>>& memo) {
    string key = to_string(open) + "," + to_string(close);

    // If the result is already computed, return it
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    vector<string> result;

    // Base case: if no open and close parentheses left, return empty string
    if (open == 0 && close == 0) {
        result.push_back("");
        return result;
    }

    // If there are open parentheses left, we can add an open parenthesis
    if (open > 0) {
        vector<string> subResults = generate(open - 1, close, memo);
        for (string str : subResults) {
            result.push_back("(" + str);
        }
    }

    // If the number of close parentheses left is more than open, we can add a close parenthesis
    if (close > open) {
        vector<string> subResults = generate(open, close - 1, memo);
        for (string str : subResults) {
            result.push_back(")" + str);
        }
    }

    // Memoize the result for the current state
    memo[key] = result;

    return result;
}

// Function to start the generation process
vector<string> generateParenthesis(int n) {
    unordered_map<string, vector<string>> memo; // Memoization map
    return generate(n, n, memo);
}

int main() {
    int n = 3; // Example input
    vector<string> result = generateParenthesis(n);

    // Print the result
    cout << "All combinations of well-formed parentheses for n = " << n << ":\n";
    for (string str : result) {
        cout << str << endl;
    }

    return 0;
}
*/ 


/*Question : 5: House Robber: 
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security systems connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each 
house, return the maximum amount of money you can rob tonight without 
alerting the police.
*/
// memoization : 
/*
#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std; 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> memo(n, -1); // initialize with -1

        return maxV(nums, n-1, memo);
    }
        private: 

        int maxV(const vector<int> &nums, int i, vector<int> &memo){
            if (i < 0) {
                return 0; 
            }
            if(memo[i] != -1){return memo[i]; }

            int loot = max(nums[i] + maxV(nums, i-2, memo), maxV(nums, i-1, memo));
            memo[i] = loot; 
            return loot; 
        }
};
*/ 

// ---Tabulation---
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 0) {
            return 0; 
        }
        if(n == 0){
            return nums[0]; 
        }

        vector<int> dp(n); 
        dp[0] = nums[0]; 
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; ++i){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]); 
        }

        return dp[n-1]; 
    }
};
*/ 

// Question 6: Longest palindromix Subsequesnces
/*
Given a string s, find the longest palindromic subsequences length in s. 
A subsequences is a sequence that can be derived from another sequence by 
deleting some or no element without changing theo rder of the remaining elements. 

*/ 

// Tabulation : 
/*
#include <iostream> 
#include <string>
#include <vector>
#include<algorithm> // req for max
using namespace std; 
// lps -> Longest Palindrome subsequence 
int lps(const string &s){
    int n = s.length(); 
     vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = 0; i<n; ++i){
        dp[i][i] = 1; 
    }

    //Fill the dp table
    for(int len = 2; len <= n; ++len){
        for(int i = 0; i<=n - len; ++i){
            int j = i+len-1; 
            if(s[i] == s[j]){
                dp[i][j] = 2 + dp[i + 1][j - 1]; 
            }else{
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); 
            }
        }
    }
    return dp[0][n - 1]; 
}
*/ 


/*Question:7: Equal Subset Sum Difference : 
- Given an Integer array nums, return true if you can partition the 
array into two subsets such that the sum of the elements in both subset 
is equal or false otherwise. 
*/
/*
class Solution{
public:
bool canPartition(vector<int>&nums){
    int totalSum = 0; 

    for(int num : nums){
        totalSum += num; 
    }

    // if sum is odd--> 
    if(totalSum % 2 != 0){
        return false; 
    }

    int target = totalSum / 2; 
    int n = nums.size(); 

    // create dp table 
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    //intialize dp table 
    for(int i=0; i<=n; i++){
        dp[i][0] = true; 
    }

    // fill the dp table 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]]; 
            }else{
                dp[i][j] = dp[i - 1][j]; 
            }
        }
    }
    //* for(int i=0; i<= target; i++){
    //*     for(int j=0; j<=target; j++){
    //*         cout << dp[i][j] << " ";
    //*     }
    //*     cout << endl; 
    //* }
    return dp[n][target]; 
}
}; 

*/ 


/*Question 8: 
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return the minimum number of elements to remove 
to make nums​​​ a mountain array.

Example 1:

Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to 
remove any elements. */

/*
#include <iostream> 
#include <vector> 
#include <string>
using namespace std; 

int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 3){
            return 0; 
        }

        vector<int>lis(n, 1); 
        for(int i=1; i<n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    lis[i] = max(lis[i], lis[j] + 1); 
                }
            }
        }

//* 2: compute Lds each index
        vector<int> lds(n, 1); 
        for(int i=n - 2; i>=0; --i){
            for(int j=n-1; j>i; --j){
                if(nums[i] > nums[j]){
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

    //* 3: find max len of valid mountain subArray
    int maxMtnLen = 0; 
    for(int i=1; i<n-1; ++i){
        if(lis[i] > 1 && lds[i] > 1){
        maxMtnLen = max(maxMtnLen, lis[i] + lds[i] -1); 

        }
    }


//*calculate min removals : 
    return n - maxMtnLen; 
}

int main(){
    vector<int> nums = {2, 1, 1, 5, 6, 2, 3, 1};
    cout << "Minimum removals to make mountain array " << minimumMountainRemovals(nums) << endl;
    return 0;
}*/


/*Question 9: Box Stacking : 
Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, 
lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each 
other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and 
heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to 
put it on another cuboid.

Return the maximum height of the stacked cuboids.

Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190
*/ 
/*
#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std; 

class Solution {
public:
    void normalizeCuboids(vector<vector<int>>& cuboids) {
    for (auto& cuboid : cuboids) {
        sort(cuboid.begin(), cuboid.end());
    }
   }
    int maxHeightHel(int index, vector<vector<int>> & cuboids, vector<int> &memo){
        // if already computed
        if(memo[index] != -1) return memo[index]; 

        //bc 
        int maxHeight = cuboids[index][2]; 

        // try to stack this cuboid on top of any previous cuboid
        for(int prev = 0; prev < index; ++prev){
            if(cuboids[prev][0] <= cuboids[index][0] && 
                cuboids[prev][1] <= cuboids[index][1] && 
                cuboids[prev][2] <= cuboids[index][2]){
                maxHeight = max(maxHeight, maxHeightHel(prev, cuboids, memo) + cuboids[index][2]);
            }
        }
        memo[index] = maxHeight; 
        return maxHeight; 
    }

     int maxHeight(vector<vector<int>>& cuboids) {
       normalizeCuboids(cuboids);

       // sort cuboids based on dimensions
       sort(cuboids.begin(), cuboids.end()); 

       // memoization table
       vector<int> memo(cuboids.size(), -1); 

       // cmpt maxHeight
       int result = 0; 
       for(int i=0; i<cuboids.size(); ++i){
        result = max(result, maxHeightHel(i, cuboids, memo)); 
       } 
       return result; 
    }
};

*/ 

