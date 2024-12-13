#include <iostream>
#include <algorithm>
using namespace std;

int reverse(int n){
	int res = 0; 
	while(n>0){
		int lastDig = n%10; 
		res = res*10 + lastDig; 
		n = n/10;
	}
	return res; 
}
bool isPali(int num){
	 int revNum = reverse(num); 
	 return num == revNum; 
} 
int main(){
	int n; 
	cout <<"Enter a Number "<<endl;
	cin>>n;
	if(isPali(n))
	{
		cout<<n<<"is Palindrome: ";
	}
	else {
 		  cout<<n<<"Not palindrome: ";
	} 
	return 0; 
}
