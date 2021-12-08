#include <iostream>
#include <string.h>

using namespace std;

class A 
{
	public:
		A() { cout << "A constructor called !!!" << endl; }
		~A() { cout << "A Destructor called !!!" << endl; }
		void demoFunct() { cout << "Demo Fucntion called" << endl; }
};

class B : virtual public A
{
public:
	B() { cout << "B constructor called !!!" << endl; }
	~B() { cout << "B Destructor called !!!" << endl; }
};

class C : virtual public A
{
public:
	C() { cout << "C constructor called !!!" << endl; }
	~C() { cout << "C Destructor called !!!" << endl; }
};

class D : public B, public C
{
public:
	D() { cout << "D constructor called !!!" << endl; }
	~D() { cout << "D Destructor called !!!" << endl; }
};

int main()
{
	D d;
	d.demoFunct();

	return 0;
}
