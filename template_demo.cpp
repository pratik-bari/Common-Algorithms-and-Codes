#include <iostream>
#include <string>

using namespace std;

template<typename T, int N>
void printValue(T value)
{
	cout << "Value --->" << value << endl;
	cout << "From template --->" << N << endl;
}

template <typename T, int N>
class Data {
private:
	T data[N];

public:
	void getSize() {cout << "Size -->" << sizeof(data) << endl;}
};

int main()
{
	printValue<string, 5>("Hello World");
	printValue<int, 10>(100);
	printValue<float, 28>(20.5f);

	Data<int, 10>d;
	d.getSize();

	Data<double, 20>dstr;
	dstr.getSize();
	return 0;
}
