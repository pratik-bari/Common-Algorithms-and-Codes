#include <iostream>
#include <mutex>

std::mutex mtx;

class Singleton
{
	Singleton() { std::cout << "Singleton Object created !!!!" << std::endl; }
	~Singleton() { std::cout << "Singleton Object destroyed !!!!" << std::endl; }

	static int count;
	static Singleton * instance;

	int height;
	int width;

public:

	void setHeightWidth(int ht, int wd) { height = ht; width = wd; }
	void displayHeightWidth() { std::cout << "Height-->" << height << "\tWidth-->" << width << std::endl; }

	static void addRefCount() { count++; }
	static void subRefCount() { count--; }

	static Singleton * getInstance()
	{
		if (instance == nullptr)
		{
			mtx.lock();
			if (instance == nullptr)
				instance = new Singleton();

			mtx.unlock();
		}

		addRefCount();
		return instance;
	}

	static void deleteInstance()
	{
		subRefCount();
		if (instance != nullptr && count == 0)
		{
			delete instance;
			instance = nullptr;
		}
	}
};

Singleton * Singleton::instance = nullptr;
int Singleton::count = 0;

void someFunction()
{
	Singleton * ptr1 = Singleton::getInstance();
	ptr1->displayHeightWidth();

	ptr1->setHeightWidth(1, 1);
	Singleton::deleteInstance();
}

int main()
{
	Singleton * ptr = Singleton::getInstance();
	ptr->setHeightWidth(100, 200);

	ptr->displayHeightWidth();

	ptr->setHeightWidth(70, 250);
	ptr->displayHeightWidth();

	someFunction();
	ptr->displayHeightWidth();

	Singleton::deleteInstance();

	Singleton * ptr3 = Singleton::getInstance();
	ptr3->setHeightWidth(5, 5);
	ptr3->displayHeightWidth();
	Singleton::deleteInstance();

	return 0;
}