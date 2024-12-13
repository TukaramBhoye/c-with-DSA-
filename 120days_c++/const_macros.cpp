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
- 
*/
