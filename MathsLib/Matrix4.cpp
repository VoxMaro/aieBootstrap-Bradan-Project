#include "Matrix4.h"
#include <cmath>

//Matrix4 Library
//Bradan Lean

Matrix4::Matrix4() : m1(1), m2(0), m3(0), m4(0), m5(0), m6(1), m7(0), m8(0), m9(0), m10(0),m11(1),m12(0),m13(0),m14(0),m15(0),m16(1)
{
}

Matrix4::Matrix4(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9, float a_m10, float a_m11, float a_m12, float a_m13, float a_m14, float a_m15, float a_m16) : m1(a_m1), m2(a_m2), m3(a_m3), m4(a_m4), m5(a_m5), m6(a_m6), m7(a_m7), m8(a_m8), m9(a_m9), m10(a_m10), m11(a_m11), m12(a_m12), m13(a_m13), m14(a_m14), m15(a_m15), m16(a_m16)
{
}


Matrix4::Matrix4(Matrix4& other){
	for (int i = 0; i < 16; ++i)
		(*this)[i] = other[i];
}


Matrix4 Matrix4::operator*(Matrix4 & other)
{
	//Matrix4 mult = Matrix4(
	//	(*this)[0].dot(Vector4(other.m1, other.m5, other.m9,  other.m13)),
	//	(*this)[0].dot(Vector4(other.m2, other.m6, other.m10, other.m14)),
	//	(*this)[0].dot(Vector4(other.m3, other.m7, other.m11, other.m15)),
	//	(*this)[0].dot(Vector4(other.m4, other.m8, other.m12, other.m16)),
	//	(*this)[1].dot(Vector4(other.m1, other.m5, other.m9,  other.m13)),
	//	(*this)[1].dot(Vector4(other.m2, other.m6, other.m10, other.m14)),
	//	(*this)[1].dot(Vector4(other.m3, other.m7, other.m11, other.m15)),
	//	(*this)[1].dot(Vector4(other.m4, other.m8, other.m12, other.m16)),
	//	(*this)[2].dot(Vector4(other.m1, other.m5, other.m9,  other.m13)),
	//	(*this)[2].dot(Vector4(other.m2, other.m6, other.m10, other.m14)),
	//	(*this)[2].dot(Vector4(other.m3, other.m7, other.m11, other.m15)),
	//	(*this)[2].dot(Vector4(other.m4, other.m8, other.m12, other.m16)),
	//	(*this)[3].dot(Vector4(other.m1, other.m5, other.m9,  other.m13)),
	//	(*this)[3].dot(Vector4(other.m2, other.m6, other.m10, other.m14)),
	//	(*this)[3].dot(Vector4(other.m3, other.m7, other.m11, other.m15)),
	//	(*this)[3].dot(Vector4(other.m4, other.m8, other.m12, other.m16))
	//);

	Matrix4 mult = Matrix4(
		other[0].dot(Vector4(m1, m5, m9, m13)),
		other[0].dot(Vector4(m2, m6, m10, m14)),
		other[0].dot(Vector4(m3, m7, m11, m15)),
		other[0].dot(Vector4(m4, m8, m12, m16)),

		other[1].dot(Vector4(m1, m5, m9, m13)),
		other[1].dot(Vector4(m2, m6, m10, m14)),
		other[1].dot(Vector4(m3, m7, m11, m15)),
		other[1].dot(Vector4(m4, m8, m12, m16)),

		other[2].dot(Vector4(m1, m5, m9, m13)),
		other[2].dot(Vector4(m2, m6, m10, m14)),
		other[2].dot(Vector4(m3, m7, m11, m15)),
		other[2].dot(Vector4(m4, m8, m12, m16)),

		other[3].dot(Vector4(m1, m5, m9, m13)),
		other[3].dot(Vector4(m2, m6, m10, m14)),
		other[3].dot(Vector4(m3, m7, m11, m15)),
		other[3].dot(Vector4(m4, m8, m12, m16))

	);

	return mult;
}

Vector4 Matrix4::operator*(Vector4& other)
{
	//return Vector4((*this)[0].dot(other), (*this)[1].dot(other), (*this)[2].dot(other), (*this)[3].dot(other));
	return Vector4(m1*other.x + m5*other.y + m9*other.z + m13*other.w, 
					m2*other.x + m6*other.y + m10*other.z + m14*other.w, 
					m3*other.x + m7*other.y + m11*other.z+ m15*other.w,
					m4*other.x + m8*other.y + m12*other.z + m16*other.w);
}

Matrix4& Matrix4::operator=(Matrix4 & other)
{
	for (int i = 0; i < 4; ++i)
		(*this)[i] = other[i];
	return *this;
}

Vector4 & Matrix4::operator[](unsigned int index)
{
	// TODO: insert return statement here
	return mv[index];
}

void Matrix4::setRotateX(float a_rot)
{
	set(1, 0, 0, 0,
		0, cosf(a_rot), sinf(a_rot), 0,
		0, -sinf(a_rot), cosf(a_rot), 0,
		0,0,0,1);
	/*m6 = cosf(a_rot);
	m7 = -sinf(a_rot);
	m9 = sinf(a_rot);
	m10 = cosf(a_rot);*/
}

void Matrix4::setRotateY(float a_rot)
{
	set(cosf(a_rot), 0, -sinf(a_rot), 0,
		0, 1, 0, 0,
		sinf(a_rot), 0, cosf(a_rot), 0,
		0,0,0,1);
}

void Matrix4::setRotateZ(float a_rot)
{
	set(cosf(a_rot), sinf(a_rot), 0, 0,
		-sinf(a_rot), cosf(a_rot), 0, 0,
		0, 0, 1, 0,
		0,0,0,1);
}

void Matrix4::set(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9, float a_m10, float a_m11, float a_m12, float a_m13, float a_m14, float a_m15, float a_m16) {
	m1 = a_m1;
	m2 = a_m2;
	m3 = a_m3;
	m4 = a_m4,
	m5 = a_m5;
	m6 = a_m6;
	m7 = a_m7;
	m8 = a_m8;
	m9 = a_m9;
	m10 = a_m10;
	m11 = a_m11;
	m12 = a_m12;
	m13 = a_m13;
	m14 = a_m14;
	m15 = a_m15;
	m16 = a_m16;
}