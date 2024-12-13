/*nclude <iostream>
using namespace std; 
int main (){
	int a = 5; 
	for(int i = 1; i<=a; i++)
	{  
	   cout<<"*";
		for(int j =1; j<=a-1; j++)
		{
		 	if ( i == 1 || i==a)
		 	{
		 		cout<<"*";
	 		}
			 else
			 {
			 	cout<<"$";
			 }
		}
		cout<<"*"<<endl;
	}
	return 0; 
}
*/
#include <iostream>
using namespace std; 
int main (){
	int n = 4;
	for(int i = 1; i<=n; i++)
	{  // spaces
	   for(int j=1 ; j<=n-i; j++)
	   	{
	   		cout<<" "; 
		}
		// stars 
		for(int j=1; j<=i; j++)
		{
			cout<<"*";
		}
		cout<<endl;	
	}
	 return 0; 
}
	

