#include "Vector3.h"
#include <cmath>

//Vector3 Library
//Bradan Lean

Vector3::Vector3() : x(0), y(0), z(0)
{
}

Vector3::Vector3(float a_x, float a_y, float a_z) : x(a_x), y(a_y), z(a_z)
{
}

Vector3::Vector3(const Vector3 & copy)
{
	x = copy.x;
	y = copy.y;
	z = copy.z;
}

Vector3& Vector3::operator+=(Vector3 & other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3& Vector3::operator-=(Vector3 & other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3& Vector3::operator*=(float other)
{
	x *= other;
	y *= other;
	z *= other;
	return *this;
}

Vector3 Vector3::operator+(Vector3 & other)
{
	return Vector3(*this) += other;
}

Vector3 Vector3::operator-(Vector3 & other)
{
	return (Vector3(*this) -= other);
}

Vector3& Vector3::operator=(Vector3 & other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vector3 Vector3::operator*(float other)
{
	return Vector3(*this) *= other;
}

Vector3 operator*(float other, Vector3 & other2)
{
	return Vector3(other2)*=other;
}

float & Vector3::operator[](unsigned int index)
{
	return v[index];
}

float Vector3::magnitude()
{
	return sqrt(x*x + y*y + z*z);
}

void Vector3::normalise()
{
	*this *= 1 / magnitude();
}

float Vector3::dot(Vector3 &a_dotTarget)
{
	return x * a_dotTarget.x + y * a_dotTarget.y + z * a_dotTarget.z;
}

Vector3 Vector3::cross(Vector3 &a_crossTarget)
{
	return Vector3(y*a_crossTarget.z - z*a_crossTarget.y, z*a_crossTarget.x - x*a_crossTarget.z, x*a_crossTarget.y - y*a_crossTarget.x);
}
