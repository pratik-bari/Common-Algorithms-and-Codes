#include <iostream>
#include "shapeFactory.h"


int main() 
{
	while (1)
	{
		int shapeNum;
		std::cout << "Enter value of the shape to be entered : ";
		std::cin >> shapeNum;

		Shape * instance = ShapeFactory::getShapeInstance(shapeNum);
		
		if (instance == nullptr)
			break;
	
		std::cout << "Area--->" << instance->getArea() << std::endl;

		instance = ShapeFactory::deleteShapeInstance(instance);
	}

	return 0;
}