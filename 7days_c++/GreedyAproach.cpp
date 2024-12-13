/*35:NB2:30: GreedyApproach(LaLchi): Make the Greedy choice at all steps 
Choose the local optimum & hope for global optimum 

Greedy Approach : Optimal sub-Structure property 
- A problem is said to have an optimal subStructure 
  if it can be devided into Sub-Problems. Whose Optimal Solution is 
  part of overall optimal Solution : */ 
  
  
/* Q. 1: activity Selection: select the max no. activities that can
be perform by a single person.
(A person can work on one activity at a time) */ 
/*
#include <iostream> 
#include <vector>
using namespace std; 
int maxActivities(vector<int> start, vector<int> end){
	// sort on end time 
	// Ao select
	cout << "Activity Selection A0\n"<< endl; 
	int count = 1; 
	int currEndTime = end[0]; 
	
	for(int i = 1; i<=start.size(); i++){
		if(start[i] >= currEndTime){// non-overLapping
		cout << "Activity  slection a" << i << endl; 
		     count++; 
		     currEndTime = end[i]; 
		}
	}      
	return count;
}

int main (){
	vector<int> start = {1, 3, 0, 5, 8, 5}; 
	vector<int> end = {2, 4, 6, 7, 9, 9}; //4 
	
	cout << maxActivities(start, end)<< endl; 
	return 0; 
}*/ 
//-----------------------------------------------------------
//Q.2Pairs In C++ : STL containers to store two objects 

/*
#include <iostream>
#include <vector>
#include <algorithm>  // for sort function
using namespace std;

// Comparison function to sort by the second value (end time) in ascending order
bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;  // ascending order by end time

    // Uncomment and use one of the below lines to change the sorting criteria

    // return p1.second > p2.second;  // descending order by end time

    // return p1.first < p2.first;  // ascending order by start time
    // return p1.first > p2.first;  // descending order by start time
}

int main() {
    vector<int> start = {0, 1, 2};
    vector<int> end = {9, 2, 4};

    // Initialize the activity vector with pairs of (start, end) times
    vector<pair<int, int>> activity(3);
    activity[0] = make_pair(0, 9);
    activity[1] = make_pair(1, 2);  
     
    
    activity[2] = make_pair(2, 4);

    // Print the original activities
    for (int i = 0; i < activity.size(); i++) {
        cout << "A" << i << " : " << activity[i].first << "," << activity[i].second << endl;
    }

    // Sort activities based on end times using the compare function
    sort(activity.begin(), activity.end(), compare);

    cout << "------------sorted---------------\n" << endl;

    // Print the sorted activities
    for (int i = 0; i < activity.size(); i++) {
        cout << "A" << i << " : " << activity[i].first << "," << activity[i].second << endl;
    }

    return 0;
}
*/ 

/* 	Q. 3 : Fractional Knapsack: 
 - put items in knapsack to get the maximum total value in the knapsack 
 
   value = [60, 100, 120); 
   weight = [10, 20, 30]; 
*//*

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std; 
bool compare(pair<double, int>p1, pair<double, int>p2){
	return p1.first > p2.first; // descending based on ratio: 
}

int frackKnap(vector<int> val, vector<int>wt, int w){ //O(n log n)
	int n = val.size(); 
	vector<pair<double, int>> ratio(n, make_pair(0.0, 0)); // pair( ratio, idx) ---> (double, int)
	
	for(int i=0; i<n; i++){
		
		double r = val[i]/(double)wt[i];
		ratio[i] = make_pair(r, i); 
	}
	
	sort(ratio.begin(), ratio.end(), compare); 
	
	int ans = 0; 
	for(int i=0; i<n; i++){
		int idx = ratio[i].second; // wt, val
		if(wt[idx] <= w){
			ans += val[idx]; 
			w -=wt[idx]; 
		}else{
			ans += ratio[i].first * w; 
			w = 0; 
			break; 
		}
	}
	cout << "max value = " << ans << endl; 
	return ans; 
}

int main(){
	vector<int> val = {60, 100, 120}; 
	vector<int> wt = {10, 20, 30}; 
	int w =	50; 
	
	frackKnap(val, wt, w); 
	
	return 0; 
}
*/ 

/*. 4: Min Absolute difference Pairs: 
 - Pair elements of A & B to Minimizes 
 sum of absolute difference between pairs:  
 3 - 8 = -5	== 5 give positive no. 
 & 8 - 3 = 5  */ 
 /*
#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std; 

int main (){
	vector<int> A = {4, 1, 8, 7}; 
	vector<int> B = {2, 3, 6, 5}; 
	
	sort(A.begin(), A.end()); 
	sort(B.begin(), B.end()); 
	
	int absDiff = 0; 
	for(int i=0; i<A.size(); i++){
		absDiff += 	abs( A[i] - B[i]);
	}
	
	cout << "Min abs diff = " << absDiff << endl; 
	return 0; 
}*/ 

/*5:NB2:35: Max Length Chain of Pairs A (c, d) can come after par(a,b) if b < c. 
Find the longest chain which can be formed from a given set of pairs. 

pairs = (5, 24) (39, 60) (5, 28) (27, 40) (50, 90)
*/ /*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

bool compare(pair<int, int>p1, pair<int, int>p2){
	return p1.second < p2.second; 
}

int maxChainLength(vector<pair<int, int>>pairs){
	int n = pairs.size(); 
	
	sort(pairs.begin(), pairs.end(), compare); 
	int ans = 1; 
	int currEnd = pairs[0].second; 
	
	for(int i=1; i<n; i++){
		if(pairs[i].first > currEnd){ //pairs non Overlapping
			ans++; 
			currEnd = pairs[i].second; 
		}
	}
	
	cout << "max chain length = "<< ans << endl; 
	return ans; 
}
int main (){
	int n = 5; 
	vector<pair<int, int>> pairs(n, make_pair(0, 0));
	pairs[0] = make_pair(5, 24); 
	pairs[1] = make_pair(39, 60);
 	pairs[2] = make_pair(5, 28);
 	pairs[3] = make_pair(27, 40); 
 	pairs[4] = make_pair(50, 90); 
 	
 	maxChainLength(pairs);
 	
 	return 0; 
}

*/ 

/* Q.6:NB2:36: Indian Coins: 
   we are given an infinite supply of denominations
   [1, 2, 5, 10, 20, 50, 100, 500, 200] find min no. 
   of coins to make change for a value V. 
   V = 121; 
   ans = 3(coins: 100 + 20 + 1)
   */ 
   /*
  #include <iostream> 
  #include <vector> 
  using namespace std; 
  
  int getMinChange(vector<int> coins, int V){
  	int ans = 0; 
  	int n = coins.size(); 
  	
  	for(int i=n-1; i>=0; i--){
  		if( V>= coins[i]){
  			ans += V/coins[i]; 
  			V = V % coins[i]; 
		  }
	  }
	  
	  cout << "min coins for change = " << ans << endl; 
	  
	  return ans; 
  }
  
  int main(){
	  	vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000}; 
	  	int V = 9; 
	  	
	  	getMinChange(coins,  V);
	  	
 		return 0; 
  } 
   */ 
/*Q:7: Job Sequensing problem: 
  Maximize the total profit if only one job can be scheduled at a time
*/ 
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
bool compare(pair<int, int>p1, pair<int, int>p2){
	return p1.second > p2.second; 
}
int maxProfit(vector<pair<int, int>>jobs){
	sort(jobs.begin(), jobs.end(), compare); 
	
	int profit = jobs[0].second; 
	int safeDeadLine = 2; 
	
	for(int i=1; i<jobs.size(); i++){
		if(jobs[i].first >= safeDeadLine){
			profit += jobs[i].second; 
			safeDeadLine++; 
		}
	}
	cout << "Max profit from jobs: "<< profit << endl; 
	
	return profit; 
}O/P = 60:

int main (){
	int n = 4; 
	vector<pair<int, int>>jobs(n, make_pair(0, 0)); 
	jobs[0] = make_pair(4, 20); 
	jobs[1] = make_pair(1, 10); 
	jobs[2] = make_pair(1, 40); 
	jobs[3] = make_pair(1, 30); 
	
	maxProfit(jobs); 
	return 0; 
} 

// with index of jobs with profits :
*/ /*
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Multiple values can be stored in a class
class Job {
    public:
        int idx;
        int deadline;
        int profit;

        Job(int idx, int deadline, int profit) {
            this->idx = idx;
            this->deadline = deadline;
            this->profit = profit;
        }
};

int maxProfit(vector<pair<int, int>> pairs) {
    int n = pairs.size();
    vector<Job> jobs;

    for (int i = 0; i < n; i++) {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }
    // emplace_back is used when we create a vector of objects and want to pass values directly

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) {
        // Lambda function used for single use, no name or return type
        return a.profit > b.profit;
    }); // Sorting in decreasing order based on profit

    cout << "Selecting Jobs\n"<< jobs[0].idx << endl;
    int profit = jobs[0].profit;
    int safeDeadline = 2;

    for (int i=1; i<n; i++) {
        if (jobs[i].deadline >= safeDeadline) {
            cout << "Selecting Job " << jobs[i].idx << endl;
            profit += jobs[i].profit;
            safeDeadline++;
        }
    }
    cout << "Max Profit = " << profit << endl;
    return profit;
}

int main() {
    int n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0, 0));
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    maxProfit(jobs);
    return 0;
}

*/ 

// Assignment of Greedy alogrithm : 
/*Q. 1 Split a String in balanced String: 
  Balanced strings are those that have an equal quantitity of "L"
  And "R" characters. Given a balanced string s, split it into
  some number of substrings such that: Each 
  substring is balanced. 
  Return the maximum number of balanced strings you can obtain. */
/*
#include <iostream>
#include <string>
using namespace std; 

int balancedStringSplit(string s){
	// 
	int ans = 0; 
	
	int countR = 0; 
	
	int countL = 0; 
	
	for(size_t i = 0; i<s.length(); i++){
		
		if(s[i]== 'R'){
			countR++; 	
		}else if(s[i] == 'L'){
			  countL++; 	
		}
		
		if(countR == countL){
			ans++; 
			countR = 0; 
			countL = 0; 
		}
	}
	
	return ans; 
}
int main (){
	string s = "RLRRLLRLRL";
	

		cout << balancedStringSplit(s) << endl; 
	
	
	return 0; 
}*/ 

/* Q.2 Largest Odd Number in String :
   - You are given a string num, representing a large integer. Return
   	 the largest-valued odd integer(as a string) that is a non-empty
   	 substring of num, or an empty string "" if no odd integer 
		exists. 
    - A substring is a contigous sequence of characters within a string.*/
 /* 
#include <iostream> 
#include <string>
using namespace std; 

string largestOddNumber(string num){
	for(int i=num.length()-1; i>=0; i--){
		int digit = num[i]-'0';
				  -	'5' - '0' karte hain toh:
				  -	'5' ka ASCII value hai 53.
				  -	'0' ka ASCII value hai 48.
				  - Iska matlab, 53 - 48 karte hain toh result aata hai 5.
		
		if(digit & 1){
			return num.substr(0, i+1); 
		}// 0 index se shuru karte hue, string num(i+1)ka portion lena hai.
	}
	return ""; // if not availbale return empty string
}

int main(){
	string n = "52"; 
	
	cout << largestOddNumber(n) << endl; 
	return 0;
}*/ 

/* Q.3: Smallest String With A Given Numeric Value: 
   	  -	The numeric value of a lowercase character is define
   		as its position(1-indexed)in the alphabet, so the numeric value
   		of a is q, the numeric value of b is 2, the numberic 
   		value of c is 3, and so on. 
   		
      - "abe" is  1 + 2 + 5 = 8;
        	  	  a   b   e
    */ 
/*
#include <iostream> 
#include <string>
using namespace std; 

string getSmallestString(int n, int k){
	string ans; 
	while(n != 0){
		int ch = k-(n-1)*26; 
		if(ch<=0){
			ans.push_back('a'); 
			k--; 
			n--; 
		}else{
			ans.push_back(ch+'a'-1);
			n--; 
			k -=(ch); 
		}	
	}
	return ans; 
}
int sumOfPositions(string s) {
	int sum = 0;
	for(char c : s) {
		sum += c - 'a' + 1; // Character ki position ka sum calculate karte jao
	}  //           // increase by 1 of a pos
	return sum;
}


int main(){
	int n = 3; int k = 27; 
	
	string smallestString = getSmallestString(n, k);
	
	cout << smallestString << endl; // "aay" ko print karte hain
	
	int positionSum = sumOfPositions(smallestString);
	cout << "Sum of positions: " << positionSum << endl;
	
	return 0;  
}
*/ 
/* Q.4: Best Time to Buy and sell stock 
   You are given ans array prices where prices[i] is the 
   price of a given stock on the Ith day. You want to maximize 
   your profit by choosing single day to buy one stock and
   choosing a different day in the future to sell that stock
*/ 
/*
#include <iostream>
#include <vector>
#include <algorithm> // for std::max
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    
    vector<int> maxPrice(n);
    maxPrice[n - 1] = prices[n - 1];
    
    for (int i = n - 2; i >= 0; i--) {
        maxPrice[i] = max(prices[i], maxPrice[i + 1]);
    }
    
    int profit = 0;
    for (int i = 0; i < n; i++) {
        int currProfit = maxPrice[i] - prices[i];
        profit = max(currProfit, profit);
    }
    
    return profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int profit = maxProfit(prices);
    cout << "Maximum profit: " <<  profit << endl ;
    return 0; 
}
*//*
**Explanation: 
Let's use the example prices = {7, 1, 5, 3, 6, 4}:

Step 1: Calculate maxPrice backward:

Start from the last day:
maxPrice[5] = 4 (since it's the last day, the maximum price from here onwards is the price on the last day).
Move backward:
maxPrice[4] = max(6, 4) = 6
maxPrice[3] = max(3, 6) = 6
maxPrice[2] = max(5, 6) = 6
maxPrice[1] = max(1, 6) = 6
maxPrice[0] = max(7, 6) = 7
Step 2: Calculate profit:

Initialize profit = 0.
Iterate through the prices array:
For i = 0: currProfit = maxPrice[0] - prices[0] = 7 - 7 = 0
For i = 1: currProfit = maxPrice[1] - prices[1] = 6 - 1 = 5
For i = 2: currProfit = maxPrice[2] - prices[2] = 6 - 5 = 1
For i = 3: currProfit = maxPrice[3] - prices[3] = 6 - 3 = 3
For i = 4: currProfit = maxPrice[4] - prices[4] = 6 - 6 = 0
For i = 5: currProfit = maxPrice[5] - prices[5] = 4 - 4 = 0
Update profit accordingly: profit becomes 5 after the iteration.
Result: The maximum profit that can be achieved by buying and selling stocks based on the given prices is 5.
*/ 
//---------------------------------------------------
/*Q.5: Given an integer array nums and an integer k, split nums into k
	   non-empty subArrays such that the larges sum of any subArray is minimized. 
	   Return the minimized largest sum of the split.(A subArray is a 
	   contigous part of the array.
  
  O/p : 18***/
   
#include <iostream> 
#include <vector>
using namespace std; 
int largestSum_subArray(vector<int>&nums, int k){
	long long int mn = INT_MIN; 
	long long int mid, ans, mx = 0, sum; 
	
	int tmp; 
	for(auto &i: nums){
		mx += i; 
		mn = max(mn, i*1LL); 
	}
	
	while(mn<=mx){
		mid = (mx-mn)/2+mn; 
		tmp = 1, sum=0; 
		
		for(auto &i: nums){
			sum +=i; 
			if(sum>mid){
				tmp++; 
				sum = i; 
			}
		}
		if(tmp==k){
			ans = mid; 
			mx = mid-1; 
		}else if(tmp>k){
			mn = mid+1;
		}else{
			ans = mid; 
		    mx = mid-1; 
		}
	}
	cout << ans << endl; 
	return ans; 
}
int main (){
vector<int>nums ={7, 2, 5, 10, 8};
	int k = 2; 
	largestSum_subArray(nums, k);
	return 0; 
} 

