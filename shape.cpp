#include <iostream>
#include <string>
class Shape
{
public:
	virtual void Scale(float scaleFactor) = 0;
	virtual void ShowInfo() = 0;
	virtual std::string GetName() = 0;
};

class Shape2D : public Shape
{
protected:
	float area;
public:
	virtual float GetArea() = 0;
	virtual bool operator>(Shape2D& other) = 0;
	virtual bool operator<(Shape2D& other) = 0;
	virtual bool operator==(Shape2D& other) = 0;
	virtual void CalculateArea() = 0;
};

class Shape3D : public Shape
{
protected:
	float volume;
public:
	virtual float GetVolume() = 0;
	virtual bool operator>(Shape3D& other) = 0;
	virtual bool operator<(Shape3D& other) = 0;
	virtual bool operator==(Shape3D& other) = 0;
	virtual void CalculateVolume() = 0;
};

class Square :public Shape2D
{
private:
	float side;
public:
	Square(float s) :side(s) {} //Constructor

	float GetArea() override
	{
		return area;
	}
	void Scale(float scaleFactor) override
	{
		area = area * scaleFactor;
	}
	void ShowInfo() override
	{
		std::cout << GetName() << std::endl;
		std::cout << "side: " << side << std::endl;
		std::cout << "area: " << GetArea() << std::endl << std::endl;
	}
	std::string GetName() override {
		return "Square";
	}
	bool operator>(Shape2D& other) override { return area > other.GetArea(); }
	bool operator<(Shape2D& other) override { return area < other.GetArea(); }
	bool operator==(Shape2D& other) override { return area == other.GetArea(); }
	void CalculateArea() override
	{
		area = side * side;
	}
};

class Triangle : public Shape2D
{
private:
	float base;
	float height;
public:
	Triangle(float b, float h) : base(b), height(h) {} // Constructor
	void CalculateArea() override
	{
		area = 0.5 * base * height;
	}
	float GetArea() override
	{
		return area;
	}
	void Scale(float scaleFactor) override { area = area * scaleFactor; }
	void ShowInfo() override
	{
		std::cout << GetName() << std::endl;
		std::cout << "Triangle with base: " << base << " and height: " << height << " and area " << this->GetArea() << std::endl << std::endl;
	}
	std::string GetName() override
	{
		return "Triangle";
	}
	bool operator>(Shape2D& other) override { return area > other.GetArea(); }
	bool operator<(Shape2D& other) override { return area < other.GetArea(); }
	bool operator==(Shape2D& other) override { return area == other.GetArea(); }
};

class Circle : public Shape2D
{
private:
	float radius;
public:
	Circle(float r) : radius(r) {} // Constructor

	void CalculateArea() override
	{
		area = 3.141592 * radius * radius;
	}
	float GetArea() override
	{
		return area;
	}
	void Scale(float scaleFactor) override
	{
		area = area * scaleFactor;
	}
	void ShowInfo() override
	{
		std::cout << GetName() << std::endl;
		std::cout << "Circle with radius: " << radius << " and area " << this->GetArea() << std::endl << std::endl;
	}
	std::string GetName() override
	{
		return "Circle";
	}
	bool operator>(Shape2D& other) override
	{
		return area > other.GetArea();
	}
	bool operator<(Shape2D& other) override
	{
		return area < other.GetArea();
	}
	bool operator==(Shape2D& other) override
	{
		return area == other.GetArea();
	}
};

class TriangularPyramid : public Shape3D {
private:
	float triangleHeight;
	Triangle baseTriangle;
public:
	TriangularPyramid(float triangleHeight, float base, float height) : triangleHeight(triangleHeight), baseTriangle(base, height) {} // Constructor
	void CalculateVolume() override
	{
		baseTriangle.CalculateArea();
		volume = (1.0 / 3.0) * baseTriangle.GetArea() * triangleHeight;
	}
	float GetVolume() override
	{
		return volume;
	}
	void Scale(float scaleFactor) override
	{
		volume = volume * scaleFactor;
	}
	void ShowInfo() override
	{
		CalculateVolume();
		std::cout << GetName() << std::endl;
		std::cout << "TriangularPyramid with height: " << triangleHeight << " and volume: " << this->GetVolume() << std::endl << std::endl;
	}
	std::string GetName() override
	{
		return "TriangularPyramid";
	}