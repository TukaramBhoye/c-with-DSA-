/* assignments : Questions 
#include  <iostream> 
using namespace std; 
int main (){
	int n = 5; 
	bool ab = true;
	for (int i=1; i<=n; i++ )
	{
		for(int j=1; j<=i; j++)
		{
	 	if((i+j)%2==0)
	 	// 
			{
				cout<<1;
			}
			else
			{
				cout<<0;	
			}
		}
		cout<<endl;
	}
	return 0; 
}
 
#include  <iostream> 
using namespace std; 
int main (){
	int n = 5; 
	
	for (int i=1; i<=n; i++ )
	{
		for(int j = 1; j<=n-i; j++)
		{
			cout<<" ";
		}
		for(int j = 1; j<=i; j++)
		{
			cout<<"*";
		}
		for(int j = n-i; j>=1; j--)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	return 0; 
}

3. palindromic Pattern with nubers 
for n = 5*/ 
#include  <iostream> 
using namespace std; 
int main (){
	int n = 5; 
	for(int i=1; i<=n; i++)
	{	//spaces
		for(int j=1; j<=n-i; j++)
		{
			cout<<" ";
		}
		//
		for(int j=i; j>=1; j--)
		{
			cout<<j; 
		}
		for(int j=2; j<=i; j++)
				cout<<j; 
		cout<<endl;
	}
	
	return 0; 
}
