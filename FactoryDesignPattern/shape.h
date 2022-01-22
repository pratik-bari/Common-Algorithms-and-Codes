#pragma once
#include <iostream>

class Shape 
{
public:
	Shape() { std::cout << "Shape created" << std::endl; }
	virtual ~Shape() { std::cout << "Shape destroyed " << std::endl; }

	virtual float getArea() = 0;
};

class Rectangle : public Shape 
{
	float height;
	float width;

public:
	Rectangle(float ht, float wd) :height(ht), width(wd) { std::cout << "Rectangle created" << std::endl; }
	~Rectangle() { std::cout << "Rectangle destroyed" << std::endl; }

	float getArea() override { return height * width; }
};

class Triangle : public Shape
{
	float height;
	float base;

public:
	Triangle(float ht, float bs) :height(ht), base(bs) { std::cout << "Triangle created" << std::endl; }
	~Triangle() { std::cout << "Triangle destroyed" << std::endl; }

	float getArea() override { return 0.5 * height * base; }
};

class Circle : public Shape
{
	float radius;

public:
	Circle(float rd) : radius(rd) { std::cout << "Circle created" << std::endl; }
	~Circle() { std::cout << "Circle destroyed" << std::endl; }

	float getArea() override { return 3.1428 * radius * radius; }
};