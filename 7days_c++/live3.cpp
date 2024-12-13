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
- I.implicit type conversion : different data type mix and match
- II.explicit : big value convert into the small values 
  
  		
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
- 
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
*/