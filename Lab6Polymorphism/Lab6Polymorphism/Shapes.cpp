#include "Shapes.h"

Shape::~Shape() {
	
}

void Shape2D::ShowArea() const {
	cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
}
bool Shape2D::operator>(const Shape2D& rhs) const {
	return (Area() > rhs.Area());
}
bool Shape2D::operator<(const Shape2D& rhs) const {
	return (Area() < rhs.Area());
}
bool Shape2D::operator==(const Shape2D& rhs) const {
	return (Area() == rhs.Area());
}

Square::Square() {
	side = 0;
}
Square::Square(float s) {
	side = s;
}
void Square::Scale(float scaleFactor) {
	side *= scaleFactor;
}
void Square::Display() const {
	cout << "The area of the Square is : " << Area() << endl
		<< "Length of a side: " << side << endl;
}
float Square::Area() const {
	return side * side;
}
string Square::GetName2D() const {
	return "Square";
}

Triangle::Triangle() {
	base = 0;
	height = 0;
}
Triangle::Triangle(float b, float h) {
	base = b;
	height = h;
}
void Triangle::Scale(float scaleFactor) {
	base *= scaleFactor;
	height *= scaleFactor;
}
void Triangle::Display() const {
	cout << "The area of the Triangle is : " << Area() << endl
		<< "Base: " << base << endl
		<< "Height: " << height << endl;
}
float Triangle::Area() const {
	return 0.5f * base * height;
}
string Triangle::GetName2D() const {
	return "Triangle";
}

Circle::Circle() {
	radius = 0;
}
Circle::Circle(float r) {
	radius = r;
}
void Circle::Scale(float scaleFactor) {
	radius *= scaleFactor;
}
void Circle::Display() const {
	cout << "The area of the Circle is : " << Area() << endl
		<< "Radius: " << radius << endl;
}
float Circle::Area() const {
	return PI * (radius * radius);
}
string Circle::GetName2D() const {
	return "Circle";
}

void Shape3D::ShowVolume() const {  // multi-caret selection baby
	cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
}
bool Shape3D::operator>(const Shape3D& rhs) const {
	return (Volume() > rhs.Volume());
}
bool Shape3D::operator<(const Shape3D& rhs) const {
	return (Volume() < rhs.Volume());
}
bool Shape3D::operator==(const Shape3D& rhs) const {
	return (Volume() == rhs.Volume());
}

TriangularPyramid::TriangularPyramid() : Triangle(0, 0) {
	height = 0;
}
TriangularPyramid::TriangularPyramid(float h, float baseBase, float baseHeight) : Triangle(baseBase, baseHeight) {
	height = h;
}
void TriangularPyramid::Scale(float scaleFactor) {
	height *= scaleFactor;
	Triangle::Scale(scaleFactor);
}
void TriangularPyramid::Display() const {
	cout << "The volume of the TriangularPyramid is : " << Volume() << endl
		<< "The height is: " << height << endl;
	Triangle::Display();
}
float TriangularPyramid::Volume() const {
	return (1.0f / 3.0f) * Triangle::Area() * height;
}
string TriangularPyramid::GetName3D() const {
	return "TriangularPyramid";
}

Cylinder::Cylinder() : Circle(0) {
	height = 0;
}
Cylinder::Cylinder(float h, float r) : Circle(r) {
	height = h;
}
void Cylinder::Scale(float scaleFactor) {
	height *= scaleFactor;
	Circle::Scale(scaleFactor);
}
void Cylinder::Display() const {
	cout << "The volume of the Cylinder is : " << Volume() << endl
		<< "The height is: " << height << endl;
	Circle::Display();
}
float Cylinder::Volume() const {
	return Circle::Area() * height;
}
string Cylinder::GetName3D() const {
	return "Cylinder";
}

Sphere::Sphere() : Circle(0) {
	radius = 0;
}
Sphere::Sphere(float r) : Circle (r) {
	radius = r;
}
void Sphere::Scale(float scaleFactor) {
	radius *= scaleFactor;
	Circle::Scale(scaleFactor);
}
void Sphere::Display() const {
	cout << "The volume of the Sphere is : " << Volume() << endl;
	Circle::Display();
}
float Sphere::Volume() const {
	return (4.0f / 3.0f) * Circle::PI * (radius * radius * radius);
}
string Sphere::GetName3D() const {
	return "Sphere";
}