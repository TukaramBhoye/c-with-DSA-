/*#include <iostream>
using namespace std; 
int main (){
	int n; // n  
	// outer loop
	for(int i=1; i<=4; i++)// rows 
	{  //inner loop 
		for(int j = 1; j<=4; j++) // columns 
		{ 
		  //work 
		  cout<<i<<" ";  // "" : use for space 
		}
		cout<<endl; 
	}
	return 0; 
}
**2.: Star Pattern 
#include <iostream>
using namespace std; 
int main (){
//	int n = 4; 
	for (int i = 4; i>=1; i--)
//		(int i = 1; i<=n; i++)   second way of :reverse star pattern 
		// (int j = i; j<=(n-i+1); j++)
	{
		for(int j = 1; j<=i; j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	return 0; 
}
*/ 

#include <iostream>
using namespace std; 
int main (){
	for (int i=1; i<=4; i++)
	{
		for(int j=1; j<=i; j++)
		{
			cout<<j<<"";
		}
		cout<<endl;
	}
		
	return 0; 
}
