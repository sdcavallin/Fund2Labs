#include <string>
#include <iostream>
#pragma once

using namespace std;

class Shape {
public:
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;
	virtual ~Shape();
};

class Shape2D : virtual public Shape {
public:
	virtual float Area() const = 0;
	void ShowArea() const;
	virtual string GetName2D() const = 0;
	bool operator>(const Shape2D& rhs) const;
	bool operator<(const Shape2D& rhs) const;
	bool operator==(const Shape2D& rhs) const;
};

class Square : public Shape2D {
	float side;
public:
	Square();
	Square(float s);
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class Triangle : public Shape2D {
	float base, height;
public:
	Triangle();
	Triangle(float b, float h);
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class Circle : public Shape2D {
	float radius;
protected:
	const float PI = 3.14159f;
public:
	Circle();
	Circle(float r);
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class Shape3D : virtual public Shape {
public:
	virtual float Volume() const = 0;
	void ShowVolume() const;
	virtual string GetName3D() const = 0;
	bool operator>(const Shape3D& rhs) const;
	bool operator<(const Shape3D& rhs) const;
	bool operator==(const Shape3D& rhs) const;
};

class TriangularPyramid : public Shape3D, private Triangle {
	float height;
public:
	TriangularPyramid();
	TriangularPyramid(float h, float baseBase, float baseHeight);
	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};

class Cylinder : public Shape3D, private Circle {
	float height;
public:
	Cylinder();
	Cylinder(float h, float r);
	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};

class Sphere : public Shape3D, private Circle {
	float radius;
public:
	Sphere();
	Sphere(float r);
	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};