//1:  Backtracking on arrays 
/* O/P : 1 2 3 4 5
   backtraking O/P : -1 0 1 2 3
#include <iostream>
#include <string> 
#include <vector>
using namespace std; 
void printArr(int arr[], int n){
	for(int i = 0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl; 
}
void changeArr(int arr[], int n, int i){
	if(i == n){
		printArr(arr, n); 
		return; 
	}
	
	arr[i] = i+1; 
	changeArr(arr, n, i+1); 
	arr[i] -= 2; // backtrack 
}

int main(){
	int arr[5] = {0}; 
	int n = 5; 
	changeArr(arr, n, 0); 
	printArr(arr, n);
	return 0; 
}
*/ 
/*2: find Subsets : 
find and prints all subsets of a given string  : TC: 2^n 
"abc": "", a, b, c, bc, ab, ba,  abc, 


#include <iostream> 
#include <string> 
#include <vector>
using namespace std; 

void printSubsets(string str, string subset){
	if (str.size()== 0){
		cout << subset << "\n"; 
		return; 
	}
	
	char ch = str[0];
	//yes choice 
	printSubsets(str.substr(1, str.size()-1), subset+ch); 
	
	//NO choice 
	printSubsets(str.substr(1, str.size()-1), subset); 
}

int main(){
	string str = "abc"; 
	string subset = ""; 
	printSubsets(str, subset);
	return 0; 
}*/

/*3:  Find permutations(arrangements) : 
find & print all permutations(arrangements) of given str: 
"abc"  : O/P:   abc
				acb
				bac
				bca
				cab
				cba
- TC : perm => n! O(n!)
- SC : O(n) */ 
/*
#include <iostream> 
#include <string> 
using namespace std; 

void permutations(string str, string ans){
	 int n = str.size(); 
	 if( n == 0) {
	 	cout << ans << "\n";
	 	return; 
	 }
	
	for(int i = 0; i<str.size(); i++){
		char ch = str[i]; 
		string nextStr = str.substr(0, i) + str.substr(i+1, n-i-1); 
		permutations(nextStr, ans + ch); // ith char choice to add in perm
	}
}

int main(){
	string str = "abc"; 
	string ans = ""; 
	
	permutations(str, ans);
	return 0; 
}

 */ 
// 4: N-Queens : Approach 
/* Place N queens on an N*N chessBoard such that no2 queens can attack each other
N = 2: 
*/ /*
#include <iostream>
#include <vector> 
#include <string> 
using namespace std; 
printBoard(vector<vector<char>> board){
	int n = board.size(); 
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << board[i][j] << " " ; 
		}
		cout << endl; 
	}
	cout << "-------------\n"; 
}
void nQueens(vector<vector<char>>board, int row) {
	int n = board.size(); 
	if(row == n){
		printBoard(board);
		return;
	}
	
	for (int j=0; j<n; j++){
		board[row][j] = 'Q'; 
		nQueens(board, row+1); 
		board[row][j] = '.'; 
	}
}
int main (){
	vector<vector<char>> board; 
	int n = 2; 
	for(int i=0; i<n; i++){
		vector<char> newRow; 
		for(int j=0; j<n; j++){
		   newRow.push_back('.'); 	
	}
	board.push_back(newRow); 
 }
  	nQueens(board, 0); 
	
	return 0; 
}*/

//5:  N-Queens : Chess Board 
/* N=4
#include <iostream> 
#include <vector> 
#include <string>
using namespace std; 
bool isSafe(vector<vector<char>> board, int row, int col){
	int n =board.size(); 
	//horizontal 
	for(int j=0; j<n; j++){
		if(board[row][j] == 'Q'){
			return false; 
		}
	}
	
	//vertical 
	for(int i=0; i<row; i++){
		if(board[i][col] == 'Q'){
			return false; 
		}
	}
	
	// left diagonal safety  : Q r,c : r-1, c-1 : r-2, r-2: 
	for(int i=row, j=col; i>=0 && j>=0; i-- , j--){
		if(board[i][j]== 'Q'){
			return false; 
		}
	}
	
	// right diagonal safety : 
	for(int i=row, j=col; i>=0 && j<n; i--, j++){
		if(board[i][j] == 'Q'){
			return false; 
		}
	}
	return true; 
}
printBoard(vector<vector<char>> board){
	int n = board.size(); 
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << board[i][j] << " " ; 
		}
		cout << endl; 
	}
	cout << "-------------\n"; 
}
int nQueens(vector<vector<char>>board, int row){
	int n = board.size(); 
	if(row == n){
		printBoard(board); 
		return 1; 
	}
	
	int count = 0; 
	for(int j=0; j<n; j++){ // colms
		if(isSafe(board,row, j)){
			board[row][j] = 'Q'; 
			count += nQueens(board, row+1); 
			board[row][j] = '.'; 
		}
	}
	return count ; // no of possible solutions at each level 
}
int main(){
	vector<vector<char>> board; 
	int n = 5; 
	for(int i = 0; i<n; i++){
		vector<char> newRow;
		for(int j=0; j<n; j++){
			newRow.push_back('.');
		}
		board.push_back(newRow); 
	}
	int count = nQueens(board, 0); 
	cout << "count: " << count << endl; 
	return 0; 
}
*/ 
/*6: for Knights Total possible Moves are : 9888 
// 10 are from : 
#include <iostream>
#include <vector>
using namespace std;

const int N = 4;
const int MAX_SOLUTIONS = 10; // Maximum number of solutions to print

bool isSafe(vector<vector<char>> &board, int row, int col) {
    int n = board.size();

    // Check all possible moves of a knight
    int rowMove[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int colMove[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int i = 0; i < 8; i++) {
        int newRow = row + rowMove[i];
        int newCol = col + colMove[i];

        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && board[newRow][newCol] == 'K') {
            return false;
        }
    }
    return true;
}

void printBoard(const vector<vector<char>> &board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------\n";
}

bool placeKnights(vector<vector<char>> &board, int knights, int &count) {
    int n = board.size();
    if (knights == 0) {
        printBoard(board);
        count++;
        return count < MAX_SOLUTIONS;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.' && isSafe(board, i, j)) {
                board[i][j] = 'K';
                if (!placeKnights(board, knights - 1, count)) return false;
                board[i][j] = '.';
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(N, vector<char>(N, '.'));
    int count = 0;
    placeKnights(board, N, count);
    if (count == 0) {
        cout << "Solution nahi mila bhai!" << endl;
    }
    return 0;
}
*/ 
/*7:  Find a Number of ways to reach from (0,0 ) to (n -1, m-1) in a n * m Grid
 - *Allowd moves right OR Down 
 Ways : 
R R D D
R D R D
R D D R
D R R D
D R D R
D D R R
gridWays: 6
 
#include <iostream>
#include <string>
using namespace std; 
int gridWays(int r, int c, int n, int m, string ans){
	if(r == n-1 && c == m-1){ 
		 cout << ans << "\n" ; 
		 return 1; 
	}
	if(r >= n || c >= m ){
		return 0; 
	}
	//right
	int val1 = gridWays(r, c+1, n, m, ans+"R "); 
	
	//down
	int val2 = gridWays(r+1, c, n, m, ans+"D ");
	
	 return val1 + val2 ;
}
int main(){
	int n = 3; 
	int m = 3; //3*3
	string ans = "" ;
	
	cout << "gridWays: "  << gridWays(0, 0, n, m, ans); 
	return 0; 
}
*/ 

/*8: Sudoku Solver: [9][9] 
#include <iostream> 
using namespace std; 
void printSudoku(int sudoku[][9]) {
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
  		 	cout << sudoku[i][j] << " "; 
	}
	cout << endl; 
	}
}
bool isSafe(int sudoku[9][9], int row, int col,int digit){
	
	//  Vertical 
	for(int i=0; i<=8; i++){
		if(sudoku[i][col] == digit){
			return false; 
		}
	}
	//horizontal 
	for(int j=0; j<=8; j++){
		if(sudoku[row][j] == digit){
			return false; 
		}
	}
	//  check in grid 3*3
	int startRow = (row/3) * 3; 
	int startCol = (col/3) * 3; 
	
	for(int i=startRow; i<=startRow+2; i++){
		for(int j =startCol; j<=startCol+2; j++){
			if( sudoku[i][j] == digit){
				return false; 
			}
		}
	}
	return true;
}

bool sudokuSolver(int sudoku[9][9], int row, int col){
     if(row == 9){
     	// sudoku solve
     	printSudoku(sudoku); 
     	return true; 
	 }
	 
    int nextRow = row; 
    int nextCol = col + 1; 
    if(col+1 == 9){ 
        nextRow = row + 1; 
        nextCol = 0; 
	}
	
	if(sudoku[row][col] != 0) { // is there even one number present then next call 
	 	return	sudokuSolver(sudoku, nextRow, nextCol); 
	}
	
	for(int digit = 1; digit <=9; digit++){
		if(isSafe(sudoku, row, col, digit)){
			sudoku[row][col] = digit; 
			if(sudokuSolver(sudoku, nextRow, nextCol)){
				return true; 
			}
			sudoku[row][col] = 0; 
		}
	}
	return false; 
}
int main(){
	int sudoku[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
	
	sudokuSolver(sudoku, 0, 0); 
	return 0; 
}
*/ 
/* Assignments : 
Q.1 : Arey bhidu, ek chuha bhatak gaya hai maze me, aur uska starting 
 point hai (0, 0). Maze ko sochle ek 2D plane jaisa, jo ek N*N ka 
 square matrix hai. Jisme cells ka value 0 hai to wo blocked location 
 hai aur value 1 hai to open path hai jahan se chuha nikal sakta hai 
 apni manzil tak. Chuha ka destination hai (N-1, N-1). Tera kaam hai 
 saare possible raste dhoondhna jahan se chuha apne source se destination 
 tak pohonch sakta hai. Chuha ko move karne ke liye chaar direction 
 milte hai: 'U' (up) matlab (x, y-1), 'D' (down) matlab (x, y+1), 
 'L' (left) matlab (x-1, y), aur 'R' (right) matlab (x+1, y).
*/ /* 
#include <iostream>
#include <string>
#include <vector>
using namespace std; 

void solveMazeUtil(int maze[][4], int x, int y, string sol, int N, vector<vector<bool>>& vis){
    // Agar chuha manzil pe pahunch gaya
    if(x == N - 1 && y == N-1 && maze[x][y] == 1){
        cout << sol << "\n"; 
        return; 
    }
    
    // Check karo agar move valid hai
    if (x < 0 || y < 0 || x >= N || y >= N || maze[x][y] == 0 || vis[x][y]) {
        return;
    }
    
    // Mark karo current cell ko visited
    vis[x][y] = true;
    
    // Move 'D' (down)
    if(x + 1 < N && maze[x + 1][y] == 1 && !vis[x + 1][y]){
        solveMazeUtil(maze, x + 1, y, sol + "D", N, vis);
    }
    
    // Move 'U' (up)
    if(x - 1 >= 0 && maze[x - 1][y] == 1 && !vis[x - 1][y]){
        solveMazeUtil(maze, x - 1, y, sol + "U", N, vis);
    }
    
    // Move 'R' (right)
    if(y + 1 < N && maze[x][y + 1] == 1 && !vis[x][y + 1]){
        solveMazeUtil(maze, x, y + 1, sol + "R", N, vis);
    }
    
    // Move 'L' (left)
    if(y - 1 >= 0 && maze[x][y - 1] == 1 && !vis[x][y - 1]){
        solveMazeUtil(maze, x, y - 1, sol + "L", N, vis);
    }
    
    // Unmark karo current cell ko visited for backtracking
    vis[x][y] = false;
}

void solveMaze(int maze[][4], int N){
    string sol = ""; 
    vector<vector<bool>> vis(N, vector<bool>(N, false)); 
    
    if(maze[0][0] == 1) { // only move if the initial position allows 
        solveMazeUtil(maze, 0, 0, sol, N, vis); 
    }
}

int main(){
    int n = 4; 
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0}, 
        {0, 1, 1, 1}
    };
    
    solveMaze(maze, n); 
    return 0;
}
*/ 
/* Q 2: Given a string containing digits from 2-9 inclusive, print 
        all possible letter combinatios that the number could represent 
		You can Print the answer in any Order. 
*HINDI Explaination: 
Bhai, scene ye hai ki, humein ek string di gayi hai jisme 2 se lekar 9 tak 
ke digits hain. Humein us string ke har digit ko uske corresponding 
letters se jodkar possible combinations nikalne hain, jaise ki humare 
phone ke keypad pe hota hai.
Jaise ki agar hum 2 press karte hain, toh uska possible letter hai 'abc'. Agar 3 press karte hain, toh uska letters hain 'def', aur aise har digit ke liye alag-alag letters hain.

Toh humein karna kya hai? Humein us string ke har digit ke liye saare 
possible combinations print karni hain. Order mein koi dikkat nahi hai, 
bas saare combinations nikalke print karna hai.
*/
 /*
#include <iostream> 
#include <string>
#include <vector> 
using namespace std; 
void bfs(int pos, int len, string ans, string Dig, vector<vector<char>>& L){
	if (pos == len){
		cout << ans << endl; 
	}else{
		vector<char>letters = L[Dig[pos]-'0']; 
		for (int i = 0; i<letters.size(); i++){
			bfs(pos+1, len, ans + letters[i], Dig, L);
		}
	}
}
void letterCombination(string Dig, vector<vector<char>>& L){
	int len = Dig.size(); 
	if(len == 0){
		cout << ""; 
		return; 
	}
	
	string ans = ""; 
	bfs(0, len, ans, Dig, L); 
}
int main(){
	vector<vector<char>> L =  {{}, {}, {'a','b','c'}, 
						 {'d','e','f'}, 
						 {'g','h','i'}, 
						 {'j','k','l'}, 
       					 {'m','n','o'}, 
						 {'p','q','r','s'}, 
						 {'t','u','v'}, 
						 {'w','x','y','z'}};
    
	string digits; 
	cout << "enter numbers : ";
	cin >> digits;
	
    letterCombination(digits, L); 
    return 0; 
} 
- Space Complexity: O(n) : 
  		Extra space letter combinations store karne ke liye bhi use 
		hota hai, lekin maximum ek recursive call ke liye ek combination 
		hi store hoti hai, isliye overall space complexity O(len) hi rahegi.

- Overall Time Complexity:
	Is approach ka overall time complexity O(3^N * 4^M) hai, jahan N digits 
	hain jo 3 letters ke hote hain aur M digits hain jo 4 letters ke hote hain.
*/ 

/* Q.3: Knight's Tour : 
	 Given a N*N board with the knight placed on the first block of an 
	 board Moving according to the rules of chess, knights must visit each 
	 square exactly once print the order of each cell in which they are 
	 visted.
	 
HINDI: exp : scene yeh hai ki humein ek N*N chess board hai, jisme ek 
		knight hai. Knight ko har ek square ko exactly ek baar visit karna hai, 
		chess ke rules ke mutabik. Ab humein batana hai ki knight ne kis order 
		mein har square ko visit kiya hai.
*/ 

#include <iostream>
#include<string>
#include<vector>
using namespace std; 
bool isSafe(int x, int y, int sol[][8], int N){
	return(x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1); 
}

void printSolution(int sol[][8], int N){
	for(int x = 0; x<N; x++){
		for (int y = 0; y < N; y++)
		cout << sol[x][y] << " ";
		cout << endl; 
	}
}
bool solveKTUtil(int x, int y, int movei, int sol[][8], int xMove[], int yMove[], int N){
	int k, next_x, next_y; 
	if(movei == N*N)
		return true; 
	
	for(k = 0; k<8; k++){
		next_x = x + xMove[k]; 
		next_y = y + yMove[k]; 
		
		if(isSafe(next_x, next_y, sol, N)){
			sol[next_x][next_y] = movei; 
			if(solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove, N)){
				return true; 
			}else{
			
				sol[next_x][next_y] = -1 ;// backtracking	
			}
		}
   }
   return false; 
}

bool solveKT(int N){
	int sol[8][8]; 
	for(int x = 0; x < N; x++){
		for(int y = 0; y<N; y++){
			sol[x][y] = -1; 
		}
	}
	int xMove[] = {2, 1, -1, -2, -1, 1, 2};
	int yMove[] = {1, 2, 2, 1, -1, -2, -2, -1}; 
	
	//As the Knights starts from cell(0,0)
	sol[0][0] = 0; 
	if(!solveKTUtil(0, 0, 1, sol, xMove, yMove, N)){
		cout << "Solution does not exist\n"; 
		return false; 
	}
	else{	
		printSolution(sol, N); 
	}
	return true; 
}
int main (){
	int N = 8; 
	solveKT(N); 
	return 0; 
}
Time Complexity Calculation:
- Har node par 8 options (moves) hote hain, aur recursion tree ka depth 
  N^2 hota hai.
- Isse humara total number of nodes approximately 8^N^2 hota hai.
- Hence, Knight's Tour problem ka time complexity O(8^N^2) hota hai.
Tour problem ka time complexity exponential hai, jo board ki size 
N ke sath bahut tezi se badhta hai. Iska matlab hai ki jab bhi 
board ka size bada hota hai, solution find karna exponential time require karta hai.
