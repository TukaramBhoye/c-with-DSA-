/*Pointers: use to store the address of the another variable 
			- it just a special variable that stores addres of the variable 
Ex int a = 100; 
   	   *ptr = &a; 
   
*pointers to pointer: holds the adress of the pointer of another pointer 
		int  a = 100; 
   	   	float  *ptr = &a;
		char  **pptr = &ptr;
		 
*Dereference Variable: Gets the value of the variable pointed by any pointer.
 - use(*): *operator lets us directly access & modify the value of variable. 
 

 #include <iostream>
 using namespace std; 
 int main (){
 	int a = 10; 
 	int *ptr = &a;
 	
 	*ptr = 20;cout<< *ptr <<" \n";// *ptr is dereference it print the value of variable 
	 cout<< a <<"\n";
	 cout<< ptr << endl; 
 	
 	*ptr = 20; // change the value of variable using pointer
 	cout<<  a << endl; 
	 
	 return 0; 
 }
  
 **2: Null Pointer: we assign NULL value to  a pointer to show that it does'nt point to any location.
 	  int *ptr = NULL;  
 	  
 -- Dereferencing null ptr is not possible as it'll result in error.
 
  
  #include <iostream>
 using namespace std; 
 int main (){
 	int *ptr; //output: garbade value. if we called without any value
 	int *ptr = NULL; // output: 0x0. we writ.e NULL until there is not value
 	int << ptr << "\n"; 
 	
	cout<< *ptr << "\n";// called - segmentation fault. bcz of called null ptr
	// dereferencing does't possible 
 	cout<< "bye"; //bcz of null already so return don't write
	 
	 return 0; 
 }
 
 **3: Passing Arguments: 
 - pass by value: when parameter is a copy of actual argument variable in memory.
 - value pass by reference: When we pass the reference of argument to the function. 

 
    #include <iostream>
 using namespace std; 
 void changeA(int *ptr){
 	*ptr = 20; // dereference
 }
 int main (){
 	 int a = 10; //poinetr address this 
 	 changeA(&a);// passed address 
 	 cout<< a << endl; 
	 return 0; 
 }
 - reference variable: reference variable is an alternate name(alias) of already existing variable. 

 
    #include <iostream>
 using namespace std; 
 void changeA(int &param){
 	param = 20; // dereference
 	cout<< param << endl; 
 }
 int main (){
 	 int a = 10; //poinetr address this 
 	 changeA(a);// passed address 
 	 cout<< a << endl; 
	 return 0; 
 }
 
 
   #include <iostream>
 using namespace std; 
 
 int main (){
 	int x; 
 	int *ptr; 
 	x = 7; 
 	ptr = &x;
 	cout << *ptr;
    return 0; 
 }
 
  #include <iostream>
 using namespace std; 
 void multiplyBy2(int &a, int &b, int &c){
 	a*=2;
 	b*=2;
 	c*=2;
 }
 int main (){
 	 int x = 1, y = 2, z = 3; 
 	 multiplyBy2(x, y, z);
 	 cout<< x <<endl<< y<<endl<< z<<"\n";
    return 0; 
 }
*/ 
  #include <iostream>
 using namespace std; 
 
 int main (){
 	int a = 32; 
 	int *ptr = &a;
 	
 	char ch = 'A';
 	char &cho = ch;
	
	cho += a; //97
	*ptr += ch; 
	cout << a <<", "<< ch << endl;
    return 0; 
 } 
 
