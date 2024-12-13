// charArrayString 19: 
/*
#include <iostream>
#include <cstring>
using namespace std; 
int main (){
     char word[30];
    //  cin >> word ; cin ignore whitespaces 
     	 		   // use cin.getline
     cin.getline(word, 30, '*');// star ( * ) : use as delimeter : stops after values  
     cout << "yout word is " << word << endl; 
     cout << "length: " << strlen(word)<< endl; 
	
	return 0; 
}
*//*
#include <iostream>
#include <cstring>
using namespace std; 
void toUpper(char word[], int n){
	
	for(int i = 0; i<n; i++ ) {
		char ch = word[i]; 
		if (ch>='A' && ch<='Z'){
			word[i]  = ch - 'A' + 'a' ;  // lowercase
		} 
	}		//			ch - "a" : length of charcter 
 			//			A value swap in a
}
int main (){
    char word[30] = "ApPle"; 
    toUpper(word, strlen(word));
    cout << word << endl; 
	return 0; 
}
*//*
#include <iostream>
#include <cstring>
using namespace std; 
void reverse(char word[], int n){
	int st = 0, end = n-1; 
	while(st<end){
		swap(word[st], word[end]); 
		st++; 
		end--; 
	}
		
}
bool isPalindrome(char word[], int n)
{
	int st = 0, end = n-1; 
	while (st<end){
		if(word[st++]!=word[end--]){
			cout << "not valid Palindrome\n "; 
			return false; 
		}
	}
	cout << "valid Palindrome \n"; 
	return true; 
}
int main (){
//    reverse(word, strlen(word));
//    cout << "reverse : " << word << endl; 
    
    char word[30] = "racecar";
    isPalindrome(word, strlen(word));
	return 0; 
}
*/ 
/*<cstring> Fundtions : 
1: strcpy (dest, src) : to copy string fromm src to dest
   example : char str1[100]; 
   		   	 char str2[100] =  "hello world" ; 
   		   	 strcpy(str1, str2);
   		   	 cout << str1 << endl;  // o/p : hello world
2: strcat(str1, str2) : to concate string from str1 to str2) 
   				 char str1[100];  "hello" ; 
	   		   	 char str2[100] =  " world" ; 
	   		   	 strcpy(str1, str2);
	   		   	 cout << str1 << endl;  // o/p : hello world 	  
3: strcmp(str1, str)   : compares 2 Strings based on values (-negetive, O, +positive ) 
   					    char str1[100]; "hello" ; 
	   		   	 char str2[100] =  " world" ; 
	   		   	 strcpy(str1, str2);
	   		   	 cout << str1 << endl;  // o/p : h index is first randomNegVal: -23 OR world and hello so o/p :rendome PositiveVal 
	   		   	 ***********************************************
	   		   	 
	   		   	 
*//* 

#include <iostream>
#include <string> 
using namespace std; 
int main (){
	string str = "hello";
	cout << str << endl; 
	str = "yellow"; // not valid in char same varaible 
	getline(cin, str);
	cout << str << endl; 
	return 0; 
	
}
**For each loop :  
*/ /*
#include <iostream>
#include <string> 
using namespace std; 
int main (){
	string str = "hello Bhaijan";
//	cout << str.length() << endl ; 
	for(int i=0; i<str.length(); i++){// (.) dot operator in oopes use when called member function
		cout<< str[i] << "/" ; 			// use : object . function(); 
}
	cout << "\n"; 
	//	second way called string : for each loop 
	for ( char ch: str){
		cout << ch << " ";
	}
	cout << endl; 
	cout << str[0] << " "; 
	cout << str[1] << endl; 
	cout << str.at(3) << endl; 
	return 0; 
	
}*/ 
#include <iostream>
#include <string> 
using namespace std; 
bool isAnagram(string str1, string str2){
	if(str1.length() != str2.length()){
		cout << "not valid anagrams \n"; 
		return false; 
	}
	int count[26] = {0}; 
	for(int i = 0; i<str1.length(); i++ ){
		int idx = str1[i]-'a'; 
		count[idx]++; 
	}
	for(int i = 0; i<str2.length(); i++){
		int idx = str1[i]-'a'; 
		count[idx]++;
	}
	for(int i=0; i<str2.length(); i++){
			int idx = str2[i] - 'a'; 
			if(count[idx]==0){
				cout << "not valid anagrams \n " ; 
				return false; 
			}
			count[idx]--; 
	}
	cout << "valid anagrams \n"; 
	return true; 
}
int main (){
	string str1 = "anagram"; 
	string str2 = "nagaram"; 
	
	isAnagram(str1, str2);
	return 0; 	
}

