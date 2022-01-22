#pragma once
#include "shape.h"

class ShapeFactory 
{
public:
	static Shape * getShapeInstance(int num) 
	{
		Shape * instance = nullptr;
		switch (num) 
		{
		case 1:
			instance = new Rectangle(100, 100);
			break;
		
		case 2:
			instance = new Triangle(100, 100);
			break;

		case 3:
			instance = new Circle(100);
			break;

		default:
			break;
		
		}

		return instance;
	}

	static Shape * deleteShapeInstance(Shape * instance)
	{
		if (instance != nullptr)
			delete instance;

		return nullptr;
	}
};
