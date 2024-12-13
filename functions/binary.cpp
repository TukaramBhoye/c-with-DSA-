#include <iostream>
using namespace std; 
void binToDec(int binNum){
	int n = binNum;
	int decNum =0; 
	int pow = 1; // upgrade power 2^0, 2^1, 2^3...........

//use to found last digit while(n>0) lastDig =  n%10 : n = n/10

    while(n>0){
	int lastdig = n%10; //last digit
	decNum += lastdig*pow; //multiply with lastdi
	pow *= 2; update power for next
	n = n/10; 	// last number 
	}
	cout<<decNum << endl; 
}
void decToBin(int decNum)
{
	int  n = decNum; 
	int pow = 1; // power : 10^0, 10^1, 10^2, .....
	int biNum = 0; 
	
	while(n>0){
		int rem = n%2; 
		biNum += rem * pow;
		n = n/2; 
		pow = pow * 10; 
	}
	cout << "Binary of " << decNum << " = " biNum << endl; 
}
int main(){
	binToDec(1011);
	return 0;
}
/*
i. rem/2
ii. rem * 10 --->add --in --result
iii. pow = pow*10 update power
iv. n/2  */

