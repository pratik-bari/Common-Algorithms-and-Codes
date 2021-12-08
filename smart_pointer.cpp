#include <iostream>
#include <string.h>

using namespace std;

class SmartPtr 
{
public:
	int* ptr;

	SmartPtr(int *p = NULL) 
	{ 
		ptr = p;
		cout << "Constructor called !!!" << endl;
	}

	~SmartPtr() 
	{ 
		cout << "Destructor called !!!" << endl;
		delete ptr; 
	}

	void displayVal() { cout << "Pointer Value--->" << *ptr << endl; }

	int& operator*() { return *ptr; }
};

int main()
{
	SmartPtr sptr(new int());
	*sptr = 200000;

	sptr.displayVal();

	return 0;
}
