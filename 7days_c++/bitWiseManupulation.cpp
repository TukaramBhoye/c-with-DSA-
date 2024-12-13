/*Bitwise Manipulation : 
#include <iostream>
#include <vector> 
using namespace std; 
int main () {
// 	Bitwiae Operator both have true 3 = 00011 
//					 	  	   		5 = 00101 
//										00001
									         
	cout << (3 & 5) << endl; 
	return 0; 
}
 *//* One's Complement  tilde(~): 
  - Binary NOT Operator tilde(~) :  
  ~ 0 = 1;  
  ~ 1 = 0;  
  
  1 1 0 = 6  Suppose we have 8 bit memory store like: 0 0 0 0 0 1 1 0 
  0 0 1 = 1								 	 		  0 0 0 0 0 0 0 1
  ----- = -7 	                    	  
	tilde Operation  6 no :   0 0 0 0 0 1 1 0 
		  		operation :   1 1 1 1 1 0 0 1   
        1 1 1 1 1 0 0 1 called 1's Complement Form    
 - first bit is (MSB)most significant bit called (sign Bit)
  
  example : *//*
 #include <iostream>
#include <vector> 
using namespace std; 
int main () {
	cout << (~6) << endl; // O/P : -7 
	cout << (~0) << endl; // O/P : -1
	    // in c++ ALL NUMBER MADE 32 bit but small val 6 so use 8 bit
		 		 			 // 32 bit -1 bit = become 31 bit that 1 bit called MSB
 	tilde Operation  6 no :   0 0 0 0 0 1 1 0       |
          remove (-VE)MSB :     1 1 1 1 0 0 1       |  Called 2's Complement
	    1) 1'S Complement :     0 0 0 0 1 1 0       |
    	   	   			  	  	  	  	  + 1 (-ve)
			             -------------------					  
  	  	   	   			magnitude:  	1 1 1 	(-7) 
	return 0; 
}

** Binary shift Operators : 
*/ 	/*
#include <iostream> 
using namespace std; 
int main (){
	cout << (7 >> 2) << endl; //O/P : 1   righte shift =  00000001 = 1
	cout << (7 << 2) << endl; //O/P : 28  7 left shift with 2 =  00000111 = 00011100 = 28
	return 0; 
}
Q. 1: Predict the out put of ~4 
Q. 2: predict the output of 8 << 1 = a << b = a * 2^b = 16

*/ /*
#include <iostream> 
using namespace std; 
int main (){
	cout << (~4) << endl; //  O/p : -5 
	cout << (8 << 1) << endl; // O/p : 16 
	cout <<( 8 >> 1 )<< endl; // O/P : 4
	return 0; 
}*/ 
/* Odd Even NO using bitwise Operator 
#include <iostream> 
using namespace std; 
void oddOrEven(int num) {
	if(!(num & 1)){ // 1 called bitmask which is = 00000001
		cout << "even\n"; 
	}else { 
		  cout << "odd\n";
	}
}
int main (){
	oddOrEven(5); 
	oddOrEven(8);
	return 0; 
}*/ 
//**Q.3: get Ith bit : 
/*
#include <iostream> 
using namespace std; 
int getiBit(int num, int i){
	int bitMask = 1 << i; 
	
	if (!(num & bitMask)){ // ((num & bitMask) == 0) : also write like this 
		return 0; 
	}
	else{
		return 1; 
	}	
}	
int main (){
	cout << getiBit(6, 2);
	return 0; 
} // O/P : 1 


Q. 4 : set ith bit : 
*//*
#include <iostream> 
using namespace std; 
int setiBit(int num, int i){
	int bitMask = 1 << i; 
	return (num | bitMask); 	
}	
int main (){
	cout << setiBit(6, 3
	);
	return 0; 
} // O/P : 
*/
/* Q. 5 : Check for Power of Two  
#include <iostream>
using namespace std; 
int clearIthBit(int num, int i){
	int bitMask = ~(1 << i);
	return (num & bitMask);  
}
bool isPowerOf2(int num) {
	if(!(num & (num-1))){
		return true; 
	}
	else{
		return false; 
	}
}
int main (){ 
	cout << isPowerOf2(4) << endl; 
	cout << isPowerOf2(16) << endl; 
	cout << isPowerOf2(13) << endl; 
	cout << isPowerOf2(7) << endl; 
	return 0; 
}*/ //OP: 1 1 0 0: 
/* Q. WAF  to update the ith bit in a number according to given value (0 or 1). 
#include <iostream> 
using namespace std; 
void updateIthbit(int num, int i, int val){
	num = num & ~(1 << i); // clear ith bit ~(1 << i) = 1000 = 0111.
//		  0111 & ~(1 << 3)  = 0111 & 0111 = 0111 : 
	num = num | (val << i); //take bitMask of num 
//		 0111 | 1 << 3	= 0111 | 1000 = 1111 : 15
	cout << num << endl; // num = 1111  = 15
} 								//8 4 2 1 = 15
int main (){
/	 
	updateIthbit(7, 3, 1);
	updateIthbit(7, 3, 0);
	 
	return 0; 
}
*/ 
// WAP TO CLEAR THE LAST I BITS OF A NUMBER

#include <iostream> 
using namespace std; 
void clearIBits(int num, int i){
	int bitMask = (~0) << i; //(~0)111111 right shift << 2  (~1)000000
                  11111100 << 2 ; 
	num = num & bitMask; 
//		  15= 1111  
//		 &11111100
//     ans: 00001100  
//		 
	cout << num << endl; 
         		  	     
}

/* Q. count the set of bits 
int countSetBits(int num){
	int count = 0;
	while(num > 0){
		int lastDig  = num & 1;   
  					   1111 & 0001 = 0001
		count += lastDig; 
	             0 + 1 = 1 
	             1 + 1 = 2 :  1 + 1 + 1 = 3  1 + 1 + 1 + 1 = 4
		num = num >> 1;
		1111 = 1111 >> 1 = 0111 : 0011 : 0001 : 0000 cycle will repeat until end 0
	} 
	cout << count << endl; 
	return 0; 

}
int main (){
//	clearIBits(15, 2); 
	countSetBits(15); //  OP : sum = 4
	return 0; 
}
*/ 

#include <iostream> 
using namespace std; 
void fastExpo(int x, int n){
	int ans = 1; 
	
	while ( n > 0 ){
		int lastBit = n & 1 ; 
		if(lastBit){ 
		ans = ans * x; 
		}
		x = x * x; 
		n = n >> 1; 
	}
	cout << ans << endl; 
}
int main (){ 
	fastExpo(3, 5);
	return 0; 
}
