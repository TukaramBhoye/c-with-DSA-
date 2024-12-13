
/* OOPs : type of writing code 
- Functional
1:  Classes & Objects : 
	- classes : group of these entities 
	- Objects : entities in the real world 
	properties/ attribute
	-Functions/ member Functions/ Methods(associates with Object)

#include <iostream> 
using namespace std; 
class Student {
	// Prpoperties : 
	string name; 
	float cgpa;
	 
 	 // Methods : 
	void getPercentage(){
		cout << (cgpa * 10) << endl; 
	}
};
class user (){
	int id; 
	string username; 
	string password; 
	string bio; 
	
	void deactivate(){
		cout << "deleting account \n"; 
	}
	
	void editBio(string newBio){
		bio = newBio; 
	}
};


int main (){
	Student s1; // s1 object
	
	student s2; // another place in memory 
	user u; 
	return 0; 
} */

/* Access Modifiers : kewords: public, private, Protected 
#include <iostream> 
using namespace std; 
class Student {
	// Prpoperties :
	public:  
		string name; 
		float cgpa;
		 
	 	 // Methods : 
		void getPercentage(){
			cout << (cgpa * 10)<< "%\n";
		}
};

int main (){
	Student s1; // s1 object
	s1.name = "Tukaram"; 
	s1.cgpa = 6.74; 
	
	cout << s1.name << endl; 
	cout << s1.cgpa << endl; 
	s1.getPercentage();
	return 0;
}*/

/**Geters & seters : use to private properties to get and set
#include <iostream> 
using namespace std; 
class Student {
	  string name;
	  float cgpa; 
	  
    public: 
  		void percentage(float cgpa){
  			cout << cgpa * 10 << endl; 
	   }
	   void setName(string nameVal){
	   		name = nameVal; 
	   }
	   void setCgpa(float cgpaVal){
	   		cgpa = cgpaVal; 
	   }
	   
	   string getName(){
	   		  return name; 
	   }
	   float getCgpa(){
	   		 return cgpa; 
	   }
};

int main (){
	Student s1; // s1 object
	s1.setName("tukaram"); 
	s1.setCgpa(6.74); 
	
	cout << s1.getName() << endl; 
	cout << s1.getCgpa() << endl; 
 	s1.percentage(6.74);
	return 0;
}
*1.encapsulation : is wraping of a data & methods in to single unit 
it also implements data hiding using access modifiers (public, private, protected)

- encapsulation
- inhertance 
- Polymorphism 
- Abstraction 

*2. Constructor: 
	Special method Invoked automatically at time of Object creation. Used for Initialization prperties
	- same as class name 
	- Constructor does'nt have return type
	- Only called once (automatically), at object creation 
	- Memory allocation happens when constructor is called 
Ex; 
*//*
#include <iostream> 
using namespace std; 

class Car{ 
	  string name; 
	  string color; 
	  
    public: 
 	   Car() { // non parameterized constructor
 	   		 cout << "constructor without params\n"; 
		}
//	  Car(String nameValue, string colorValue){ parameterize constructor
      Car(string name, string color){
	  
		cout << "constrictor is called. Object being created.. \n";
	  	this->name = name;
	  	this->color= color; 
			    |		|
//left clr from class: right clr is property
			    
		  
//	    name =	nameValue; // this-> : called object parameter 
//	  	color = colorValue;
	  }

	  void start(){
	  	cout << "car has started n/" ; 
	  	
	  }
	  void stop(){
	  	cout << "car has stop \n "; 
	  }
	  
	  string getName(){ 
	  	return name;
	  }
};
int main (){
	Car c0; 
	Car c1("maruti 800", "white");
	Car c2("fortuner", "white"); 
	cout << c1.getName() << endl; 
	return 0; 
}

*/

/*Q. 1; Create a User class with properties: id (private), 
	 username(police) & password(private). Its id should be
  	 intialised in a parameterised in a parameterised constructor. 
  	 It should haave a Getter & setter for Password. 
*/ /*
#include <iostream> 
using namespace std; 
class user {
	private: 
		   int id; 
		   string password; 
    public : 
    	   string username; 
	   user(int id){
	   	this->id = id; 
	   }
	   
	   //Getter 
	   void string getPassword(){
	   	return password; 
	   }
	   
	   // setter
	   void setPassword(string password){
	   		this->password = password;
//	   		this use when object and parameter are same 
	   }
};

int main (){
	user u1(101); 
	u1.username = "tukaram" ; 
	u1.setPassword("abcd");
	
	cout << "username " <<u1.username << endl; 
	cout << "password : "<<u1.getPassword() << endl; // private access through getter
	return 0 ;
} */
/** 3. Copy constructor : Special Constructor(default uset to copy properties of one into another.
#include <iostream> 
using namespace std; 
class Car {
	 public:
	  string name; 
	  string color; 
	
	Car(string name, string color){
		this->name = name; 
		this->color = color; 
	}
	Car(Car &original){  // reference from old object 
		cout << "copying original to new..\n"; 
		name = original.name; 
		color = original.color; 
	}
};
int main (){
	Car c1("maruti 800", "white");
	Car c2(c1);
	cout << c2.name << endl; // maruti 800 
	cout << c2.color << endl; // white
	
	return 0; 
}

**Shallow & Deep Copy : 
		  Shallow copy copies reference to original array. 
		  But array remains same. Deep copy created a brand new copy of the array. 
*/ 
/* shallow Copy : 

#include <iostream> 
using namespace std; 
    class Car{
   	
	   public: 
		string name; 
		string color; 
		int *mileage; 
	
	Car(string name, string color) {
		this->name = name; 
		this->color = color;  
		mileage = new int; // dynamic memory allocation 
		*mileage = 12;	
	}
//	shallow copy: copy  address by reference in same stack
	Car(Car &original){
		cout << "copying orignal to new.. \n";
		name = original.name; 
		color = original.color;
		mileage = original.mileage; // copy address by reference 
	}
};

int main (){
	Car c1("maruti 800", "green");
	
	Car c2(c1);
	cout << c2.name << endl; 
	cout << c2.color << endl; 
	cout << *c2.mileage << endl; 
	*c2.mileage = 10;  // 
	cout << *c1.mileage << endl; 
	return 0;
}
 */ /*

#include <iostream> 
using namespace std; 
    class Car{
   	
	   public: 
		string name; 
		string color; 
		int *mileage; 
	
	Car(string name, string color) {
		this->name = name; // object = property 
		this->color = color;  
		mileage = new int; // dynamic memory allocation 
		*mileage = 12;	
	}
//	shallow copy: copy  address by reference in same stack
	Car(Car &original){
		cout << "copying orignal to new.. \n";
		name = original.name; 
		color = original.color;
		mileage = new int;
		*mileage = *original.mileage;  // deep copy :
	}
	
	
//	Destructor: Dealloaate memory : explitely delete
	~Car(){
		cout << "deletig Object.. \n";
		if(mileage != NULL){
			delete mileage; 
			mileage = NULL; 
		}
	}
};

int main (){
	Car c1("maruti 800", "green");
	
	Car c2(c1);
	cout << c2.name << endl; 
	cout << c2.color << endl; 
	cout << *c2.mileage << endl; 
	*c2.mileage = 10;  // 
	cout << *c1.mileage << endl; 
	return 0;
}
*/ 

//4.: Inheritance : When properties & member functions of base class are passed on the  derived class.
/*
#include <iostream> 
#include <string>
using namespace std; 

class Animal {
	public:
		string color;  // property
		void eat(){  //functions / methods
			cout << "eats \n"; 
		}
		void breath(){
			cout << "breath \n"; 
		}
};
//class fish: public Animal{ // can access in class or derived clann 
			  		 		 // cannot access in main 
class fish : public Animal{
	public: 
	int fins;
	 
	void swim(){
		cout << "swim \n "; 
	}
};

int main (){
	fish f1;
	f1.fins = 3; 
	cout << f1.fins << endl; 
	f1.swim();
	f1.eat();
	f1.breath();
}
*/ 
/*Type of Inheritance : i. Single Inheritance: 
    Base-Class 
   		|
    derieved-class 
 
#include <iostream> 
#include <string>
using namespace std; 

class Animal {
	  public: 
      string color; 
  	  
  	  void eat(){
  	  	cout << "eats \n"; 
		}
	void breath(){
        cout << "brethes\n"; 
	}
};

  class fish : public Animal {
	public: 
	int fins; 
	void swim(){
		eat(); 
		cout << "swim \n" ; 
	}
};  

int main (){
	fish f1; 
	f1.swim();
	f1.eat();
	f1.breath(); 
	
	return 0; 
}
*/ 
// ii. Multi-level Inheritance : base-class --> derieved-clas --> Derived-class
/*
#include <iostream> 
#include <string>
using namespace std; 

class Animal{
	public: 
	void eat(){
		 cout << "cats \n";	
	}
	void breathe(){
		cout << "brethes \n" ; 
	}
};

class Mammal : public Animal {
	public: 
	string bloodType;
	Mammel(){
		bloodType = "worm";
	}
};
class Dog : public Mammal{
	public: 
	void tailWag(){
		cout << "a dog wogs its tail\n"; 
	}
};
int main (){
	Dog d; 
	d.eat(); 
	d.breathe();
	d.tailWag();
	cout << d.bloodType << endl; 
	return 0; 
}
*/

// iii. Types of Inheritance : Multiple Inheritance
/*
#include <iostream> 
#include <string>
using namespace std; 

class Teacher { 
    public:
        int salary; 
        string subjects; 
};

class Student {
	public: 
		int rollNo; 
		float cgpa; 
};

class TA : public Teacher, public Student { // we can write multiple 
    public:
	   string name; 	  
};

int main (){
	TA t1; 
	t1.name = "tukaram bhoye";
	t1.cgpa = 7.34;
	t1.rollNo = 23;
	t1.salary = 1000; 
	t1.subjects= "marathi","hindi", "english";
	
	cout << t1.name << endl; 
	cout << t1.cgpa << endl; 
	cout << t1.rollNo << endl; 
	cout << t1.subjects << endl; 
	cout << t1.salary << endl; 
	
}
*/ 

/*Types of Inheritance: Hierarchical inheritance 
************************************************************************/
/* OOPs part 2:
Polymorphism: ability to take diffrent forms & behaves in diffrent ways. 

i. function overloading : compile time polyMorphism 
#include <iostream> 
#include <string> 
using namespace std;
class Print {
    public: 
    void show(int x){
    	cout << "int: " << x << endl; 
	}
	
    void show (string str){
	cout << "string: " << str << endl; 
	}
};
int main (){
	Print obj1; 
	obj1.show(25);
	obj1.show("tukaram");
	return 0; 	
}
*//*
ii. Operator OVerloading : 
syntax : returnType operator opSymbol..+,-,* (){....}
*/ /*
#include <iostream>
#include <string>
using namespace std; 
class Complex{
	  int real;
	  int img; 
    
	public: 	
      Complex(int r, int i){
      	real = r;
      	img = i; 
	  }
	  
	  void showNum(){
	  	cout << real <<"-"<< img << "i\n"; 
	  }
	  
//	   operation overloading : means add meaning  
	  Complex operator - (Complex &c2){
	  	int resReal = this->real - c2.real;
//	  				  curr-obj
  		int resImg = this->img - c2.img;
  		Complex c3(resReal, resImg);
  		cout << "res = ";
  		c3.showNum();
  		return c3; 
	  }
};  
int main(){
	Complex c1(1, 2); 
	Complex c2(3, 4); 
	
	c1.showNum();
	c2.showNum();
	
	Complex c3 = c1 - c2; 
	 
	return 0;  
}*/
// overridden : overridden mean same functions name  priority goes child
// iii: runTime Polymorphism : inheritance-same function name in both class  : 
/*#include <iostream>
#include <string>
using namespace std; 
class Parent{
	public: 
	void show(){
		cout << "this parent class" << endl;
	}
};
class Child : public Parent{
	public : 
 	void show() {
 		cout << "Child class show : "<<endl; 
	 }
};
int main (){
	Child c1;
	Parent c2; 
	
	c2.show();
	c1.show(); 
	return 0; 
}
*/ 
/* iv : Run runTime Polymorphism: 
#include <iostream>
#include <string>
using namespace std; 
class Parent {
	public :
		void show(){
			cout<< "Parent class \n";
		}
		
		virtual void Hello (){
			cout << "parent hello \n"; 
		}
};
class Child : public Parent{
	public: 
	void show(){
		cout << "child class show \n"; 
	}
//	redefine without virtual keyword : 
	void Hello (){
			cout << "Child hello \n"; 
		}
};
int main (){
	Child ch1; 
	Parent *ptr; 
	
	ptr = &ch1; // Run time binding possible bcz of inheritance
	ptr->Hello(); 
	return 0; 
} */
/*
#include <iostream>
#include <string>
using namespace std; 
class  Shape{
	public :
		virtual void draw() = 0; ; // abstract fun, pure virtual function 
//					
};
class Circle: public Shape {
	public: 
	void draw(){
        cout << "draw a circle" << endl ; 
	}
};
class Square : public Shape {
	 public: 
 	void draw(){
        cout << "draw a Square " << endl ; 
	}	
};


int main (){
	Circle c1; 
	c1.draw();
	
	Square s1; 
	s1.draw();
	
//	Shape s1. // error 
//	s1.draw();  bcz abstract class 
   return 0; 
}
*/
/**ii.:Static Keword: variable declare as static in function are 
			  created and intialized once. for the lifetime of the program 
			  - They are share by all the object o class. 
  a) Static Variables b) static Object
 
#include <iostream> 
#include <string>
using namespace std; 

class Example {
public: 
    static int x; // Declaration of static member variable
//    static const int x = 0; // Declaration and initialization of const static member variable

};

// Initialization of static member variable outside the class
int Example::x = 0;

int main() {
    Example ex1;
    Example ex2; 
    Example ex3; 
    
    cout << ex1.x++ << endl;  // O/P: 0  
    cout << ex2.x++ << endl; // O/P: 1
    cout << ex3.x++ << endl; // O/P: 2 
    
//	cout << ex1.x++ << endl; //int x = 0; O/P: 0  
//	cout << ex2.x++ << endl; // O/P: 0  
//	cout << ex3.x++ << endl; // O/P: 0 
    
    return 0;
} */
/* b) Static Object : deleting the static var from stack 

#include <iostream>
#include <string> 
using namespace std; 
class Example {
	public: 
	Example(){
		 cout << "constructor.." << endl; 
	}
	~Example(){
       cout << "destructor.."<< endl; 
	}
};

int main (){
	int a = 0; 
	if(a == 0){ */
/*		Example eg1; //OP : constructor..
							destructor..
							code ending.. 
       static Example eg1;  jab tak code hai tab tak rahega aur end me distruct ke sath delete mry.stack se delete hoga 
  	  	 	  		  	   O/P : constructor..
							     code ending...
							     destructor..

	}
	
	cout << "code ending...\n"; 
	return 0;	
}
*/ 
/* Friend Class & Function : 

#include <iostream>
#include <string> 
using namespace std; 

class A {
	  string secret = "secret data"; 
	  friend class B;
	  friend void revealedSecret(A &obj);
};

class B { //becomes a freind class of A 
	public: 
	    void showSecret(A &obj){
	    	cout << obj.secret << endl; 
		}
};
void revealedSecret (A &obj){
	cout << obj.secret << endl; 
}

int main (){
	A a; 
	B b; 
    revealedSecret(a);
    b.showSecret(a);
	
	return 0; 
}
*/ /*Q. Predict the Output: 
#include <iostream>
#include <string> 
using namespace std; 

class Parent {
	  public: 
	  Parent(){
	  		cout << "constructor of Parent \n"; 
	  }
	  ~Parent(){
	       cout << "Parent Destructor \n"; 
	  }
};
class Child : public Parent {
	public: 
	Child(){
		cout << "constructor of Child \n ";
	}
	~Child(){
		cout << "Destructor of Child \n";	
	}
};
int main (){
	Child p;


	return 0; 
}
*/
#include <iostream>
#include <string>
using namespace std; 
class Base{
	public: virtual void print(){
		cout << "Base \n "; 
	}
};
class Derived: public Base {
	void print(){
		cout << "Derived \n"; 
	}
};
int main (){
	Base *b = new Derived(); 
	b->print(); 
	delete b; 
	return 0; 
}

