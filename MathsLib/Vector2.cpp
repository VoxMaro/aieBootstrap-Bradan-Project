#include "Vector2.h"
#include <cmath>

//Vector2 Library
//Bradan Lean

Vector2::Vector2() : x(0), y(0)
{
}

Vector2::Vector2(float a_x, float a_y) : x(a_x), y(a_y)
{
}

Vector2::Vector2(const Vector2 & copy)
{
	x = copy.x;
	y = copy.y;
}

Vector2& Vector2::operator+=(Vector2 & other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2& Vector2::operator-=(Vector2 & other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2& Vector2::operator*=(float other)
{
	x*=other;
	y*=other;
	return *this;
}

Vector2 Vector2::operator+(Vector2 &other)
{
	return Vector2(*this)+=other;
}

Vector2 Vector2::operator-(Vector2 &other)
{
	return Vector2(*this)-=other;
}

Vector2& Vector2::operator=(Vector2 & other)
{
	x = other.x;
	y = other.y;
	return *this;
}

Vector2 Vector2::operator*(float other)
{
	return Vector2(*this)*=other;
}
Vector2 operator*(float other, Vector2 &other2)
{
	Vector2 temp = other2;
	temp *= other;
	return temp;
}

float& Vector2::operator[](unsigned int index)
{
	return v[index];
}

float Vector2::magnitude()
{
	return sqrt(x*x+y*y);
}

void Vector2::normalise()
{
	 *this *= 1/magnitude();
}

Vector2 Vector2::getNormal()
{
	return Vector2(*this) *= 1 / magnitude();
}

float Vector2::dot(Vector2 &a_dotTarget)
{

	return (x * a_dotTarget.x + y * a_dotTarget.y);
}
