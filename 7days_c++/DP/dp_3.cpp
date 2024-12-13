// 53:NB2:131: graph_3

/*Question : 1: Coin Change
-  You are given an integer array coins representing coins of different
  denominations and an integer amount representing a total amount of money.

-  Return the number of combinations that make up that amount. If that amount
  of money cannot be made up by any combination of the coins, return 0.

-  You may assume that you have an infinite number of each kind of coin.
-  The answer is guaranteed to fit into a signed 32-bit integer.
Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] <= j)
                { // valid
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                }
                else
                { // invalid
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < amount + 1; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[n][amount];
    }
};

/*
Question 2: --  leetcode : Coin Change :
*/

/*Question 3: Rod cutting :
Cut rpd into pieces to get maxProfit from pieces. Possible pieces are
always of len 1 to n.

price = {1, 5, 8, 9, 10, 17, 17, 20};
length = { 1, 2, 3, 4, 5, 6, 7, 8};
_________________
|i = pricess     |
|j = rodLength : |
|________________|
        |
    MaxProfit
*/
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int rodCutting(vector<int> price, vector<int> length, int rodLength){
    int n = length.size();

    vector<vector<int>>dp(n+1, vector<int>(rodLength+1, 0));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<rodLength+1; j++){
            if(length[i-1] <=j ){
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][rodLength];
}
int main(){
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    int rodLength = 8;

   cout <<  rodCutting( price, length, rodLength) << endl ;

    return 0;
}
*/

// 4: question :leetCode ---> 1547 min cost to cut sticks

/*5: Question:  Longest Common SubSequent :
 Subsequence is created from a string with characters in the same relative
 order.
*/
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcsRec(string str1, string str2 ){
 if(str1.size() == 0 || str2.size() == 0){
     return 0;
 }

 int n = str1.size();
 int m = str2.size();

 if (str1[n-1] == str2[m-1]) {
     return 1 + lcsRec(str1.substr(0, n-1), str2.substr(0, m-1));
 }else{
     int ans1 = lcsRec(str1.substr(0, n-1), str2);
     int ans2 = lcsRec(str1, str2.substr(0, m-1));

     return max(ans1, ans2);
 }
}

int main(){
 string str1 = "abcdge";
 string str2 = "abedg";

 cout << lcsRec(str1, str2);
 return 0;
}

*/
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcsMem(string str1, string str2, vector<vector<int>> dp){
    // bc:
    if (str1.size() == 0 || str2.size() == 0){
        return 0;
    }

    int n = str1.size();
    int m = str2.size();

    if (dp[n][m] != -1){
        return dp[n][m];
    }

    if (str1[n - 1] == str2[m - 1]){
        dp[n][m] = 1 + lcsMem(str1.substr(0, n-1), str2.substr(0, m-1), dp);
    }
    else {
        int ans1 = lcsMem(str1.substr(0, n-1), str2, dp);
        int ans2 = lcsMem(str1, str2.substr(0, m-1), dp);
        dp[n][m] = max(ans1, ans2);
    }

    return dp[n][m];
}

int main(){
    string str1 = "abcd";
    string str2 = "aceb";
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    cout << lcsMem(str1, str2, dp);

    return 0;
}
*/ 


// With Tabulation : 
/*
#include <iostream> 
#include <vector>
#include <string> 
using namespace std; 
int  lcsTab(string str1, string str2){  // O(n * m)
    int n = str1.size(); 
    int m = str2.size(); 

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); 

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1; 
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }
    }
    return dp[n][m]; 
}
int main (){
    string str1 = "abcdge"; 
    string str2 = "abedg"; 

    cout << lcsTab(str1, str2) << endl; 

    return 0; 
}*/ 

