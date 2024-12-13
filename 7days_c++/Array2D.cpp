/*
#include <iostream>
using namespace std; 
int spiralMatrix(int mat[][4], int n, int m){
	int srow = 0, erow = n-1;
	int scol = 0, ecol = m-1; 
	
	while (srow <= erow && scol <= ecol ){// scol < ecol : like this middle element will not print 
	// Top : 
	for(int j = scol; j<=ecol; j++){
		cout << mat[srow][j] << " "; 
	}
	
	//right : 
	for(int i = srow+1; i<=erow; i++)
	{
		cout << mat[i][ecol] << " ";  
	}
	
	/*bottom: 
	for(int j = ecol-1; j>=scol; j--){
		cout << mat[erow][j] << " ";
	}
	//left 
	
	for(int i = erow-1; i>=srow+1; i--){
		cout << mat[i][scol] << " ";
	}
	To Avoid duplicasy of odd matrix(3*5) values: use further code
	*/ 
/*	for(int j = ecol-1; j>=scol; j--){
		if(srow == erow){
			break; 
		}
		cout << mat[erow][j] << " ";
	}
	//left 
	
	for(int i = erow-1; i>=srow+1; i--){
		if(scol == ecol){
			break; 
		}
		cout << mat[i][scol] << " ";
	}
	srow++ ; scol++;
	erow--; ecol--;  
	}
	
}
int main (){
	int matrix [4][4] = {{1, 2, 3, 4}
 			   		  	 {5, 6, 7, 8},
 						 {9, 10, 11, 12}, 
					 	 {13, 14, 15, 16}};
	spiralMatrix(matrix, 4, 4);	
	return 0; 
}

*//*
#include <iostream> 
using namespace std;
int diagonalSum(int mat[][4], int n){ // TC = O(n^2)
	int sum = 0; 
	for(int i = 0; i<n; i++ ){
		for(int j = 0; j<n; j++ ){
			if(i == j){
				sum += mat[i][j]; // primary diagonal
			}
			else if(j == n-i-1){
				sum += mat[i][j];
			}
		}
	}
	cout << "sum = " << sum << endl; 
	return sum; 
}
int diagonalSum2(int mat[][4], int n){
	int sum = 0; 
	for(int i = 0; i < n; i++){
	     sum += mat[i][i];//pd
		 if(i!= n-i-1){
			sum += mat[i][n-i-1]; // secondary diagonal 
		}
	}
	cout << "Sum: "<< sum << endl; 
	return sum; 
}
bool search(int mat[][4], int n, int m, int key ){
	int i = 0, j= m - 1; 
	while (i < n && j >= 0){
		if (mat [i][j] == key){
			cout << "Key is : " << i << " " << j << endl; 
			return true;
		}else if (mat[i][j] > key){
			j--;
		}
		else{
			i++; 
		}
	}
	return false; 
}
	

int main (){
 	int matrix [4][4] = {{1, 2, 3, 4},
 			   		  	 {5, 6, 7, 8},
 						 {9, 10, 11, 12}, 
					 	 {13, 14, 15, 16}};
//	 diagonalSum(matrix, 4);
//	 diagonalSum2(matrix, 4);
	 search(matrix, 4, 4, 13);
	 return 0; 
}

**matrix Pointers : 
*/ /*
#include <iostream> 
using namespace std; 
void func(int mat[][4], int n, int m){
	cout << "oth row ptr: " << mat << endl;
	cout << "1 row ptr: " << mat+1 <<endl; 
	cout << "2 row ptr: " << mat+2<< endl; 
	
//	dereference:value means it value in the row will be predict 
	cout << "oth row value " << *mat << endl; 
	cout << "1th row value " << *(mat+1) << endl; 
	cout << "2th row value " << *(mat+2) << endl; 
	
}
void deref(int mat[][4], int n, int m) {
	cout << *(*(mat + 2) + 2) << endl; 
//	mat + row = 2 , column = 2
}
int main (){
	int matrix [4][4] = {{1, 2, 3, 4},
 			   		  	 {5, 6, 7, 8},
 						 {9, 10, 11, 12}, 
					 	 {13, 14, 15, 16}};
//	func(matrix, 4, 4) ;
	deref(matrix, 4, 4) ;
	return 0; 
} 
Matrix Pointers : i , j
ptr[i][j] = *(ptr + i) + j) // *(ptr + i) : using pointer find value 
		    firstrow access + j 
mat ith row vaue *(*(mat + i) + j) // j+:to find the column value from selected row
*/
//find the number  
/*#include <iostream>
using namespace std; 
int arrNum (int mat[][3], int n, int m){
//	n = 2, m = 3; 
	int key = 0 ;
	 for(int i=0; i<n; i++){
	 	for(int j = 0; j<m; j++){
	 		if(mat[i][j]== 7){
	             key++; 
			 }
		 }
	 }	
	 cout<< key  << " " << endl; 
}
int sumSecondArr(int mat[2][3],int n, int m ){
	int sum = 0; 
	for(int j = 0; j<m; j++)
	sum = sum + mat[1][j];
	cout << sum << endl; 
}

int transposeMat(int mat[][3], int n, int m){
	int transpose[3][3], i, j; 
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			cout << mat[i][j]<< " " ; 
		}
		cout <<  endl; 
	}
	for(i=0; i<n; i++){
		for(j = 0; j<m; j++){
 	        transpose[j][i] = mat[i][j]; 
		}
		cout  << endl ;
	} 
	// print the transpose 
	for (i=0; i<n; i++){
		for(j=0; j<m ; j++){
			 cout << transpose[i][j]<< " "; 
		}
		cout << endl; 
	}
}

int main (){
	int arr[][3] = {{4,7,8}, {8,8,7},{2,4,5}};
	
//	arrNum(arr, 3,3);
//	sumSecondArr(arr, 3, 3);
	transposeMat(arr,3, 3 );
	return 0; 
}
*/
