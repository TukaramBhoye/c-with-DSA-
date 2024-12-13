/* boiler plate : 
#include<iostream>
using namespace std;
int main(){
    // logic
    return 0; //last point --------------
}

Q.2: how code run exactly 
 source cod----->Compiler------>executable----> hello world
    |                                 |
    |_________________________________|
                       |				   
				    compile

*/
/*
#include <iostream>  - header file or preProcess directive
using namespace std;  - All preprocessor direcitve start with #
int main ()
{
	cout<<"hello world";
	return 0;
}
- Header files Include pre-written code that's required to execute our program.
  Eg - iostream, vector etc.

- macros : symbolic constants : use like  #define PI 3.14
ex: 

#include <iostream>
#define PI 3.14
using namespace std;
int main (){
	cout<<PI;
	return 0;
}

- Main function : a black box which return value return 0(is int); 
  means successfully work main function 
- Namespace : using namespace std; standard c++ 

if we not use
 the write print type: 
- using namespace std; use to declaration functions : 
 example here cout function or many more : it say functions exist or not-*-
 int main(){
 std::cout<<"hello world";
 return 0;
}
- iostream library : cout, cin comes from.

- cout<<"Hello world";
    | 
   - cout : is pre-existing, prereturn object in c++ : 

#include <iostream>
using namespace std;
int main()
{
	cout<<"****\n***\n**\n*";
	return 0; 
}

*1. - Variables in c++ 

 
Perimeter formula : 2 * (a+b) : 
- here 2 is litral( literal means suppose 2 means 2)
- a + b is variables 

- identifiers(identify things): variable, functions, objects, classess  
- put meaningful names of variables.
- names :               a        b
- plot(memory)   :  [][10][][][][5][]
ex: int a = 10;
    int b = 5; 
    
#include <iostream>
using namespace std;

int main (){
	int a = 10;
    int b = 5; 
    cout<< "a = "<<a<<endl;
    cout<< "b = "<<b<<endl;
    return 0;
}

*2.- Naming conventions : 

- the name should start with an underscore(_) or a letter.
- The name can only contain uppercase & lowercase letters, digits 
  from 0 to 9 underscore
- It must not be a keyword (reserved words). Keywords have a 
  special meaning for the compiler
  
*3.- Data Types 
	 -Primitive : int(4byte), char(1byte), bool(1byte), 
	 			  float(4 byte), double(8byte)
	 			  
	 		  
 
#include <iostream>
#include<iomanip> // here add to set precision 
using namespace std;
int main (){
	int age = 24;
	int marks = -200;
	char tu = 'aa';
	float PI = 3.14159265359;
	bool isadult = true;
	double PI2 = 3.14159265359;
	
	cout<<"size of int = "<<sizeof(int);// use to check size of present datatype
	cout<<"size of char = "<<sizeof(char);
	cout<<"size of bool = "<<sizeof(bool);
	cout<<setprecision(12)<<"PI1 = "<<PI<<endl;
	cout<<setprecision(12)<<"PI2 = "<<PI2<<endl; //setprecision(12) use here to add extra floating values 
	return 0;
}

*4. Input in c++: 

#include <iostream>
#include<iomanip> // here add to set precision 
using namespace std;
int main (){
	int age ;
	cout<<"Enter your age ";
	cin>>age;
	
	cout<<"yout age is "<<age<<endl;
	return 0;
}
*/ 

/* #include <iostream>
using namespace std;
int main ()
{
	int math;
	int sci, eng;
	cout<<"enter math marks";
	cin>>math;
	
	cout<<"enter sci marks";
	cin>>sci;
	
	cout<<"enter marks";
	cin>>eng;
	
	float avg = (math + sci + eng)/3;
	cout<<avg;
	
}


#include <iostream>
using namespace std;
int main (){
	int n;
	int area; 
  	cout<<"enter the area of square"; 
  	cin>>n; 
 	
 	area = n*n;
 	cout<<area<<endl;	
}



#include <iostream>
using namespace std;
int main ()
{
 	float  a = 25, b = 35, c = 40;
 	cout<<"enter the products"<<endl;

 	float total =  a + b + c ;
 	float gst = total * 0.18;
 	cout<<gst + totsl<<endl;
 	cout<<"product total cost is "<<gst<<endl;
	
}

#include <iostream>
using namespace std;
int main ()
{
	float P,R, T;
	cin>>P; 
	cin>>R;
	cin>>T;
	float SI = (P*R*T) / 100;
	cout << "SI =" << SI << endl;
	SI += 0.99;
	cout << SI << endl;
	return 0;
}


#include <iostream>
#define PI 3.14 // this type called macro - where we we defin constant values
using namespace std;
int main ()
{
	float rad;
	cin>> rad;
	cout<< "area = " << ( PI * rad * rad)<< endl;
	return 0;
}
*/

/*
**CH.2.:Operators:**************
//macros: symbolic constants : cant specified any type : ex 1); define x 2) define ll long long  
constant: occupied pace in memory :
*Q.1: Constants: variable that can not be change over all code 

#include <iostream>
// symbolic constants
#define ll long long
using namespace std;
int main ()
{
	ll x; 
	ll y = 25; 
	return 0;
}

**********************************************************
*/
/*
1.macro constants: 
#include <iostream>
// symbolic constants
#define ll long long
using namespace std;
int main ()
{
	ll x; 
	ll y = 25; 
	return 0;
}

2.constants : 
 

#include <iostream>
// symbolic constants
using namespace std;
int main ()
{
	const int num = 25;
 	int num2 = 25;
 	num2 = 35;
	num = 25; // bcz is already define as constant
 	return 0;
}

**Q.2: Typecasting : explicit forced by programmer(self declaration) 
	- use convert data type of a value 	
#include <iostream>
using namespace std;
int main()
{
	float PI = 3.14;
	cout<<(int)(PI)<<endl;
	cout<<((float)10/3)<<endl; //3.333
	cout<<(char)('A' + 3)<<endl;// A ascii value is 65 A+3 means output:B output is 
 	return 0;
} 

**Q.3 practice question :
1. predict output of cout << (bool)3+2;  ouutput : 1+2=3
   if we write (bool)10 then output: 1     (bool)5 output:1 if we added any value here 1 claculate with 1

#include <iostream>
using namespace std;
int main()
{
	cout <<((bool)3+2)<< endl;
	return 0;
}
**Q.3 practice question :
- predict the output of 

 #include <iostream>
using namespace std;
int main()
{
	cout<<(23.5+2+'A')<< endl; // 23.5+2.0+ 65= 90.5 all values convert into double data type
	return 0;
}

**Q.4.: Operators/Operands :
 	- symbols the tells compiler to execute some operations
binary: -, * , + , % , /; use with 2 values 
unary: -- , ++ ; decrement, increment;

- AC: Code readable hona chahiye : 


#include <iostream>
using namespace std;
int main()
{ //arithmatic operators
	cout <<((bool)3+2)<< endl;
	int a = 5; 
	int b = 3;
	a++;// postorder
	++a;//preorder 
	--b; 
	a--;
	cout <<"-"<<(a-b)<<endl;
	cout <<"+"<<(a+b)<<endl;
	cout <<"*"<<(a*b)<<endl;
	cout <<"/"<<(a/b)<<endl;
	cout <<"%"<<(a%b)<<endl; //remainder 
	return 0;
}

**5: Assignment operator: 
 +=, -=, /=, *= , %= ;

#include <iostream>
using namespace std;
int main()
{
	int a =10;
	a += 5;  //15
	cout<< a << endl;
	a -= 5;  //15 - 5
	cout<< a << endl;
	a *= 5;  // 10 * 5;
	cout<< a << endl; 
	a /= 5;  // 50/5
	cout<< a << endl;
	return 0;
}
**6: Relational operator: 
	 - <=, >=, !=, ==;
	 - && AND . || OR , ! NOT

#include <iostream>
using namespace std;
int main()
{
	int a =3, b=5;
//	cout << (a >= b)<< endl; //false out: 0
//	cout << (a <= b) <<endl; // true : 1
	cout << (! (3 == 5)) << endl;
	
	return 0;
}
*********
Day3: Explanation : 
************************************************
#include <iostream>
using namespace std;
int main ()
{
	int marks; 
	int attendance;
	cout << "enter marks : ";
	cin >> marks ; 
	if((marks >= 33) && (attendance >= 50))
	{
		cout << "pass "<< endl;
	}
	else 
	{
		cout << "fail"<< endl;
	}
	return 0; 
}
/* 
- macros  take place of a value of given variable : replacement 
  BUT: const store variable name and its value so it get pace in memory
- Main : is predefine identifier it is not keyword
- typecasting: 	
    I.implicit type conversion : different data type mix and match
 	II.explicit : big value convert into the small values 
  
  		   ex: 
  		   #include <iostream>
			using namespace std;
			int main ()
			{
			 	cout << (char)('a' + 1)<<endl;
			 		 	EXPLICIT OR OUTPUT: b
 		 	    cout <<('a' + 1)<<endl;
	    	 		IMPLICIT output: 98
	 		}
- round off:	 		
- system design : 
- operation bodmass: in c++ use Operator Precedence(mahtva)- mathematical operators : logical, relational, arithmatic
*/
// #include <iostream>
// using namespace std; 
/*int main (){
	int x=2,y=5;
	int exp1 =(x*y/x); // 5
	int exp2 =(x*(y/x)); //2*2 = 4
	cout<<exp1<<",";cout<<exp2<<"\n";
	return 0; 
}
int main()
{
 	int x=10,y=5;
	int exp1=(y*(x/y+x/y)); 
	int exp2=(y*x/y+y*x/y); //5*10/5= 10 + 10
	cout<<exp1<<"\n";
	cout<<exp2<<"\n";
}
****Conditional statements: ************
Q.voting:
#include <iostream> //bioler plate 
using namespace std; 
int main(){
	int age = 24;
	cin>>age;
	if(age>=18) cout<<"can vote"<<endl;
 	
	else cout<<"can-not vote"<<endl;
	
	if(age >= 45) cout<<"contest for election"<<endl;
	
	return 0;
}
#include <iostream>
using namespace std; 
int main (){
	float marks;
	cout << "enter your marks: ";
	cin >> marks;
	if(marks >= 33)
	{
		cout << "pass" << endl;
	}
	else
	{
		cout << "fail" << endl;
	}
	return 0;
}

Q.1: practice question: 
	- print the largest no. 
	

#include <iostream>
using namespace std; 
int main (){
	int a;
	int b;
	cout<<"enter a number : " << endl;
	cin>>a;
	cout<<"enter b number : " << endl;
	cin>>b;
	
	if(a >= b)
	{
		cout<<"is largest number "<<endl;
	}
	else {
		cout<< " is small number "<< endl;
	}
	return 0; 
}

#include <iostream>
using namespace std; 
int main (){
	int a;
	cin>>a;
	if(a%2==0)
	{
		cout<<"is even number"<<endl;
	}
	else 
	{
		cout<<"is odd number"<<endl;
	}
	return 0;
}
- create an income tax calculator: 

#include <iostream>
using namespace std; 
int main (){
	int income;
	float tax;
	cout << "enter income (in Lakhs):";
	cin >> income;
	if(income < 5){
		tax = 0;
	}
	else if(income <= 10){
		  tax = 0.2 *income;
	}
	else {
		  tax = 0.3 * income;
    }
    cout << "tax = "<< (tax * 100000)<< endl;
    return 0;
}
#include <iostream>
using namespace std; 
int main ()
{
	int a, b, c;
	cout<< "enter the value:  "<<endl;
	cin>>a>>b>>c;
	if(a>=b && a>=c)
	{ 
	  cout<<" the a is greater value: \n ";
	}
	else if(b >= a && b>=c)
	{
		cout<<"the b is greater value: ";
	}
	else{
		cout<<"the c is greater value";
	}
	return 0;
}

**3.: Ternary Operator : 

#include <iostream>
using namespace std; 
int main (){
	bool isAdult;
	int age ;
	cin>>age; 

	isAdult = age>=18? true: false;
	cout<<isAdult<<endl ;
	
	return 0; 
}

#include <iostream>
using namespace std; 
int main (){
	int day; 
	cout<< "enter day: ";
	cin>>day; 
	
	switch(day){
		case 1 : cout<<"Monday";
	 		   	 break;
	 	case 2 : cout << "tuesday" << endl;
		 	   	 break;	
		case 3 : cout << "wedensday" << endl;
		 	   	 break;		 
		case 4 : cout << "thirsday" << endl;
		 
		 	   	 break;	
		case 5 : cout << "friday" << endl;
		 	   	 break;		 
		case 6 : cout << "friday" << endl;
		 	   	 break;		 
		case 7 : cout << "saturday" << endl;
		 	   	 break;		 			 
					 
		default : cout<< "invalid day "<<endl;			 	 

	}
	
	return 0; 
}

Q.4: Build a basic calculator using switch for 4 basic arithmatic operation(+,-,*,/)

#include <iostream>
using namespace std; 
int main (){
	int a, b;
	char op; 
	cout<< "enter day: ";
	cin>>a>>b>>op; 
	//calculator
	if(op == '+'){
		cout<<"a+b = "<< (a+b) << endl;
	}
	else if(op == '-')
	{
		cout<<"a-b = "<< (a-b) << endl;
	}
	else if(op == '*')
	{
		cout<<"a*b = "<< (a*b)<< endl;
	}
	else if(op == '/')
	{
		cout<<"a/b = "<< (a/b) << endl;
	}
	else
	{
		cout<< "Invalid operator ";
	}
	return 0;		
}

#include <iostream>
using namespace std; 
int main (){
	int a, b;
	char op; 
	cout<< "enter value: ";
	cin>>a>>b>>op; 
	//calculator
	switch(op)
	{
		case '+': cout<<"a+b= " << (a+b)<<endl;
			 break;
	    case '*': cout<<"a*b= "<< (a*b)<<endl;
	    	 break;
   	    case '/': cout<<"a/b= "<< (a/b)<<endl;
   	    	 break;
	    case '-': cout<< "a-b= "<< (a-b)<<endl;
	    	 break;
   	    default:cout<<"invalid operator"<<endl;
	}
	return 0;		
}
*26/04/2024***********************************************
*/
/*LOOPS : FOR LOOP, WHILE LOOP, DO WHILE LOOP
#include <iostream>
using namespace std; 
int main (){
	
	for(int num=1; num<=5; num++)
	{
		cout<< num << " ";
	}
	cout<<endl;
	return 0;
}
 
- infinite loop : num = 1; num>=0; 
  		   num++   num value is 1 then it increase 
		   within num++ one by one there is no end.
- single run means - iteration 
- iterate - run karne 
- iterator means : variable  counter var: i (here is num) 
-
**Dry run technique: 
**1. for loop :
Q. print apna college 5 times 

#include <iostream>
using namespace std; 
int main (){
	
	for(int num=1; num<=5; num++)
	{
		cout<<"Apna college "<<endl;
	}
	return 0;
}
Q. : extra ;- 
 
#include <iostream>
using namespace std; 
int main (){
	int n; 
	cout<<"enter a number here: "<<endl;
	cin>>n;
	for(int i = 0; i<n; i++)
	{
		cout<< i <<" ";
	}
	cout<<endl;
	return 0;
}
Q.2 : print sum of n natural numbers: 
 
#include <iostream>
using namespace std; 
int main (){
	
	int n; 
	cout<<"enter numbe: ";
	cin >> n; 
	int sum = 0;
	for(int i=1; i<=n; i++)
	{
		sum = sum + i;
	}
	cout<<sum<<endl;
	return 0;
}
**2: while loop: 

#include <iostream>
using namespace std; 
int main (){
	int n  = 1;
	while (n<13)
	{
		cout<<n<<endl;
		// n is not updated (like n++. so one never reach out 13 and it will run infinite)
		// so value run until the not become thirteen 
		n++;
		// now will reach out 13 bcz update here till the 13 one by one
	}
	cout<<endl;
	return 0;
}
**3: print the square patteren using for loop: 
 
#include <iostream>
using namespace std; 
int main (){
	for (int i= 0; i<4; i++)
	{
		cout<<"****"<<endl;
	}
	cout<<endl;

	return 0;
}

#include <iostream>
using namespace std; 
int main (){
	int n ;
	cout<<"enter the number: "<<endl;
	cin>>n;
	for(int i = n; i>=1; i--)
	{
		cout<<i<<endl;	
	}
	cout<<endl;
	return 0;
}

Q.4: Print the sum of a number using while loop: 
n = 10829 : to take the last digit  10%  
10829/10 = reminder 9 or quotient = 1082
1082/10 = 2 , 108/10 = 8, 10 = 1 : 
kisi bhi number ka last digit chahiye : n%10
if remove last digit from : n/10  


#include <iostream>
using namespace std; 
int main (){
	int n  = 10829;
	int sumdig = 0;
	while (n>0)
	{
		int lastdig = n%10;
		if(lastdig % 2!=0){
            sumdig += lastdig;
            n = n/10;
  		}
		cout<<"last dig : "<<lastdig<<endl<<sumdig<<endl;
		n = n/10;
	}
	cout<<endl;
	return 0; 
}
Q. Print the sum of odd digits of a number 
 
#include <iostream>
using namespace std; 
int main (){
	int n  = 10829;
	int sumdig = 0;
	while (n>0)
	{
		int lastdig = n%10;
		if(lastdig % 2!=0){
            sumdig += lastdig;
            n = n/10;
  		}
		cout<<"last dig : "<<lastdig<<endl<<sumdig<<endl;
		n = n/10;
	}
	cout<<endl;
	return 0; 
}

#include <iostream>
using namespace std; 
int main (){
	int n = 10829;
	while(n>0)
	{
		int lastdig= n%10;
		cout<<lastdig<<" " ;
		n = n/10;
	}
	cout <<endl;
**6.: reverse the number from the given number 
res =  res * 10 + lastDig: use for the return reverse order of numbers 
--> 0*10+9 = 9,   9*10+ 2 =92, 92*10+8= 128 , 928*10+1 = 92801
	res: 9 res:92 res: 128 res: 92801
	
}

#include <iostream>
using namespace std; 
int main (){
	int n = 10289;
	int res = 0; 
	while(n > 0)
	{
		int lastdig = n % 10;
		res = res * 10 + lastdig;
		n = n/10;
	}
	cout<<"reverse= "<<res<<endl;
	return 0;
}
**do while loop : work gets done atleast once irrespective of condition 

#include <iostream>
using namespace std; 
int main (){
	int n = 1;
	do{ 
		cout << n<< endl;
		n++;
	}
	while (n<=5); //terminate end of the while loop 
	
	return 0;
}
** break: break the current teration
#include <iostream>
using namespace std; 
int main (){
	int i = 1;
	while(i<10)
 	{
 		if (i==3){
 			break; 
		 }
 		cout<< i << endl;
		i++; 
    }
    cout<<"exit from the scope: "<<endl;
	return 0;
}
Q.: wap where user can keep entering numbers till they enter a multiple of 10. 

#include <iostream>
using namespace std; 
int main (){
	int n; 
	do{
		cout<<"enter the number: "<<endl;
		cin>>n; 
		if(n%10==0)
		{
			break; // use of break statement;
			continue; //continue will run infinite time: there is no 
		}
	}while(true);
	cout<<"the number of multiple of 10: "<<n<<endl;
	
	return 0;
}
continue: use to skip the value : 

#include <iostream>
using namespace std; 
int main (){
	int i = 1;
	for(i =0; i<=10; i++)
	{
		if(i==3){
	        continue;
	    }
        cout<<i<<endl; //op: is 1 to 10 
  	}
    cout<<i<<endl; //output: 11
	return 0;
}
**Q. check the given number is prime number or not 

#include <iostream>
#include<cmath>
using namespace std;
int main ()
{
	int n;
	cout<<"enter the no: "<<endl;
	cin>>n;
	bool isPrime = true; //assume 
	//for(int i=2; i<=n-1; i++)
	for(int i = 2; i<=sqrt(n); i++)// both are valid.sqrt(n) (under root) library:<cmath>
	{
		if(n%i == 0)// i is factor of n; i completely divides n; n is non-prime
		{
			isPrime = false; 
			break; 
		}
	}
	if(isPrime) //mean:isPrime = true 
	{
		cout<< "the number is prime:  "<<endl;
	}
	else{
		cout<<"number is not prime"<< endl;
	}
	return 0;	
}
*/
