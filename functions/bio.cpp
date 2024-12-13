/*#include <iostream>
using namespace std;
void sayHello(); //function Declaration 

**Forward delaration : D
**Declaration: the function's name, return type, and parameters(if any) 
Definition : the body of the function : 

void assis(){ //this type is function definition 
	sayHello();
}
int main(){
  assis(); // function call 
  return 0;   
} 


void sayHello(){ //function definition 
    cout<<"Hello : \n";
}


#include <iostream>
using namespace std;
int diff(int a, int b=2);
int sum(int a, int b);
int main(){
	int a = sum(2,6);
	int b = diff(2,6);
//2, 6 are arguments :when fun 
//	called with values is called is arguments 
// arguments are fixed value where function done calulation  
 	cout<<"sum is: "<< a << endl;
	cout<<"diff is: "<<b<<endl;  
  	return 0;   
} 


int sum(int a, int b){ //here are name of variable passed is called parameters 
    int s = a+b;
    return s;
}

// b with default value(DV)  but also be give him argument like any num
// for a if we declare DV then he ask for b he have or not DV if exist one value
//Ex: (int a=1, or int b) 

int diff(int a, int b)
{
	int diff = a - b; 
	return diff; 
}
Q. odd or even 

#include <iostream>
using namespace std;
bool isEven(int n){
	if(n%2==0){
	
	return true; 
	}
	else{
	return false;
	}
}
int main ()
{
	int n;
	cout<<"enter the number:";
	cin>>n;
	cout<<isEven(n);
	return 0; 
}
Q2 WAP to print the factorial of a number, n.

#include <iostream>
using namespace std;
int factorial(int n){

	int fact = 1; 
	for(int i=1; i<=n; i++ )
	{
		fact = fact * i;
	}
	cout<< "factoral : ("<<n<<")= "<< fact << endl;
	return fact; 
}
int main (){
	factorial(2); 
	factorial(3);
	factorial(4);
	
	return 0;
}

What happens in memory? 
*/ 

/*scope : local vs Global scope of variables 
local scope : area where store var 

#include <iostream>
using namespace std;
bool isPrime(int n){
	if(n==1)// 1 is already prime no.
	//if n divide with 1 then return false
	{
		return false;
	}
//	for(int i=2; i<=n-1; i++)
//		if(n%2==0) - have two [rocedures : 
	for (int i = 2; i*i<=n; i++)
	{
		if(n%i==0)
		{
		return false;
		}
	}
	 
	return true;
	
}
int main (){
	cout<<isPrime(30)<<endl;
	return 0; 
}
**Q:WAF TO FIND THE BIONOMIAL COEFICIENT FOR GIVEN N & R. 
**BIONOMIAL COEFICIENT:means combination of 3 val

	  	 n!
nCr = ---------- 
       r!(n-r)!
- supposed 4(n) are elective subject. we have to pick 2(r)of them 
  - so how much choices are possible from 4 sub with choices:
  - s1, s2,: s1,s3,: s1,s4, :s2, s3: s2 s4: s3, s4;

**WAF TO FIND THE BIONOMIAL COEFICIENT FOR GIVEN N & R.
 
#include <iostream>
using namespace std;
int facto(int n, int fact=1)
{
	for(int i=1; i<=n; i++){
		fact*=i;	
	}
	return fact;
}
int biocoef(int r, int n)
{
	int val1 = facto(n);
	int val2 = facto(r);
	int val3 = facto(n-r);
	int result = val1/(val2*val3);
	return result;	
}
int main (){
	cout<<biocoef(2,4)<<endl; 
	return 0; 
}
-- Function overloading :Multiple functions same name but diferent parameter 
--1 function name use multiple time 
 
________
 Q.1: The number is palindrome or not :

#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 
isPalin(const string&  str)
{
 	string reversed  = str; 
	reverse(reversed.begin(), reversed.end());
	
	return str == reversed;
}
int main (){
	string n; 
	cout<<"enter the number: ";
	cin>>n;
	if(isPalin(n))
	{
		cout<<"the number is palindrome: "<<endl;
	}
	else
	{
		cout<<"the number is not palindrome: "<<endl; 
	}
	return 0; 
}
Q. 2: sum of Two digit ; 
*/ 

#include <iostream >
using namespace std; 
int fun(int a, int b)
{
	return (a*a)+(b*b)+(2*a*b);
}
int sum(int a, int b){
	int s = a+b;
	return s; 
}
int max(){
	int a, b, c; 
	
	if(a>=b && a>=c)
	{
		return a; 
	}
	else if(b>= a && b>= c)
	{
	 	 return b; 
	}
	else{
		 return c;
	}
	
}
int main (){
	cout<<"the sum is: "<<sum(34, 6)<<endl;
	cout<<"the fun is: "<<fun(34, 6)<<endl;
	cout<<"enter the values here: ";
	
	return 0; 
}


