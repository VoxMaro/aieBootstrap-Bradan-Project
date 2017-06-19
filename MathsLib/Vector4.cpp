#include "Vector4.h"
#include <cmath>

//Vector4 Library
//Bradan Lean

Vector4::Vector4() : x(0), y(0), z(0), w(0)
{
}

Vector4::Vector4(float a_x, float a_y, float a_z, float a_w) : x(a_x), y(a_y), z(a_z), w(a_w)
{
}

Vector4::Vector4(const Vector4 & copy)
{
	x = copy.x;
	y = copy.y;
	z = copy.z;
	w = copy.w;
}

Vector4& Vector4::operator+=(Vector4 & other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

Vector4& Vector4::operator-=(Vector4 & other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

Vector4& Vector4::operator*=(float other)
{
	x *= other;
	y *= other;
	z *= other;
	w *= other;
	return *this;
}

Vector4 Vector4::operator+(Vector4 & other)
{
	return Vector4(*this) += other;
}

Vector4 Vector4::operator-(Vector4 & other)
{
	return Vector4(*this) -= other;
}

Vector4& Vector4::operator=(Vector4 & other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
	return *this;
}

Vector4 Vector4::operator*(float other)
{
	return Vector4(*this) *= other;
}

Vector4 operator*(float other, Vector4 & other2)
{
	return Vector4(other2) *= other;
}

float & Vector4::operator[](unsigned int index)
{
	return v[index];
}

float Vector4::magnitude()
{
	return sqrt(x*x + y*y + z*z + w*w);
}

void Vector4::normalise()
{
	*this *= 1 / magnitude();
}

float Vector4::dot(Vector4 &a_dotTarget)
{
	return x * a_dotTarget.x + y * a_dotTarget.y + z * a_dotTarget.z + w*a_dotTarget.w;
}

Vector4 Vector4::cross(Vector4 &a_crossTarget)
{
	return Vector4(y*a_crossTarget.z - z*a_crossTarget.y, z*a_crossTarget.x - x*a_crossTarget.z, x*a_crossTarget.y - y*a_crossTarget.x, (w*a_crossTarget.w));
}
