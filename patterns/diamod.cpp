/*#include <iostream>
using namespace std; 
int main ()
{
	int n = 10;
	for(int i = 1; i<=n; i++)
	{	//apaces
		for(int j=1; j<=n-i; j++)
		{
			cout<<" ";
		}
		for(int j=1; j<=2*i-1; j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	for(int i =n; i>=1; i--)
	{
		for(int j=1; j<=n-i; j++)
		{
			cout<<" ";
		}
		for(int j=1; j<=2*i-1; j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	
	return 0; 
}
**Butterfly Patterns 

#include <iostream>
using namespace std; 
int main ()
{
	int n = 30; 
	for(int i = 1; i<=n; i++)
	{				
		for(int j=1; j<=i; j++)
		{
			cout<<"*";	
		}
		
		for(int j=1; j<=2*(n-i); j++ )
		{
			cout<<" ";
		}
		for(int j=1; j<=i; j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
		for(int i=n; i>=1; i--)
	{				
		for(int j=1; j<=i; j++)
		{
			cout<<"*";	
		}
		
		for(int j=1; j<=2*(n-i); j++ )
		{
			cout<<" ";
		}
		for(int j=1; j<=i; j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}

	return 0;
}
 

#include <iostream>
using namespace std; 
int main ()
{
	

	return 0;
}
*/ 

//#include <iostream>
//using namespace std; 
//int main ()
//{
//	for(int i=1; i<=4; i++){
//		for(int j=1; j<=4; j++){
//			cout<<i<<" "<<j<<" ";
//		}
//		cout<<endl; 
//	}
//	return 0;
//}

#include <iostream>
using namespace std; 
int main ()
{
 	char a[100];
 	file *fp;
 	fp ("aditya.txt", "r");
 	gets(a, 40, fp);
	fclose(fp); 
	return 0;
}
