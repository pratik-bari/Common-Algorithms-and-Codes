#include<iostream>
#include<cstring>

class MString {
public:
	char data[100];

	MString(char * arg)
	{
		strcpy(data, arg);
	}

	MString operator+(MString obj)
	{
		MString temp("");
		strcpy(temp.data, data);
		strcat(temp.data, obj.data);
		return temp;
	}
};

int main()
{	
	MString obj1("Hello");
	MString obj2("World");

	MString obj3 = obj1 + obj2;

	std::cout << "Added String --->" << obj3.data << std::endl;

	return 0;
}
