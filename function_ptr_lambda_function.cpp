#include <iostream>
#include <vector>


void square(int x)
{
	std::cout << "Square Value--->" << x * x << std::endl;;
}

void computeSquare(std::vector<int >& val, void (*fptr)(int))
{
	for (int i : val)
		fptr(i);
}

void computeCube(std::vector<int>& val, void (*fptr)(int))
{
	for (int i : val)
		fptr(i);
}

int main()
{	
	std::vector<int> arr = { 1,2,3,4,5,6,7 };
	computeSquare(arr, square);
	computeCube(arr, [](int x) {std::cout << "Cube Value--->" << x * x * x << std::endl; });

	return 0;
}
