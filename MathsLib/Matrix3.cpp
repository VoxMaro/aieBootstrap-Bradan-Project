#include "Matrix3.h"
#include "Vector3.h"
#include <cmath>

//Matrix3 Library
//Bradan Lean

Matrix3::Matrix3(): m1(1), m2(0),m3(0),m4(0),m5(1),m6(0), m7(0), m8(0), m9(0)
{

}

Matrix3::Matrix3(float a_m1, float a_m2, float a_m3, float a_m4,float a_m5, float a_m6, float a_m7, float a_m8, float a_m9) : m1(a_m1), m2(a_m2), m3(a_m3), m4(a_m4), m5(a_m5), m6(a_m6), m7(a_m7), m8(a_m8), m9(a_m9)
{

}

Matrix3::Matrix3(Matrix3 &other) {
	for (int i = 0; i < 9; ++i)
		(*this)[i] = other[i];
}



//Matrix3::Matrix3(float * a_array)
//{
//}

//Matrix3 Matrix3::operator*(Matrix3 & other)
//{
//	return Matrix3(Vector3(m1, m2).dot(Vector3(other.m1,other.m3)),
//		Vector3(m1, m2).dot(Vector3(other.m2, other.m4)),
//		Vector3(m3, m4).dot(Vector3(other.m1, other.m3)),
//		Vector3(m3, m4).dot(Vector3(other.m2, other.m4)));
//}

Matrix3 Matrix3::operator*(Matrix3 & other)
{

	//Matrix3 mult = Matrix3(
	//	(*this)[0].dot(Vector3(other.m1, other.m4, other.m7)),

	//	-(*this)[1].dot(Vector3(other.m1, other.m4, other.m7)),//?

	//	(*this)[2].dot(Vector3(other.m1, other.m4, other.m7)),


	//	-(*this)[0].dot(Vector3(other.m2, other.m5, other.m8)),

	//	(*this)[1].dot(Vector3(other.m2, other.m5, other.m8)),//?

	//	-(*this)[2].dot(Vector3(other.m2, other.m5, other.m8)),


	//	(*this)[0].dot(Vector3(other.m3, other.m6, other.m9)),

	//	-(*this)[1].dot(Vector3(other.m3, other.m6, other.m9)),//?

	//	(*this)[2].dot(Vector3(other.m3, other.m6, other.m9))
	//);

	//Matrix3 mult = Matrix3(
	//	(*this)[0].dot(Vector3(other.m1, other.m4, other.m7)),

	//	(*this)[1].dot(Vector3(other.m1, other.m4, other.m7)),//?

	//	(*this)[2].dot(Vector3(other.m1, other.m4, other.m7)),


	//	(*this)[0].dot(Vector3(other.m2, other.m5, other.m8)),

	//	(*this)[1].dot(Vector3(other.m2, other.m5, other.m8)),//?

	//	(*this)[2].dot(Vector3(other.m2, other.m5, other.m8)),


	//	(*this)[0].dot(Vector3(other.m3, other.m6, other.m9)),

	//	(*this)[1].dot(Vector3(other.m3, other.m6, other.m9)),//?

	//	(*this)[2].dot(Vector3(other.m3, other.m6, other.m9))
	//);

	Matrix3 mult = Matrix3(
		other[0].dot(Vector3(m1, m4, m7)),
		other[0].dot(Vector3(m2, m5, m8)),
		other[0].dot(Vector3(m3, m6, m9)),

		other[1].dot(Vector3(m1, m4, m7)),
		other[1].dot(Vector3(m2, m5, m8)),
		other[1].dot(Vector3(m3, m6, m9)),

		other[2].dot(Vector3(m1, m4, m7)),
		other[2].dot(Vector3(m2, m5, m8)),
		other[2].dot(Vector3(m3, m6, m9))
	);


	/*Matrix3 mult;
	for (auto r = 0;r<3;r++) {
		for (auto c = 0; c<3; c++) {
			for (int inner = 0; inner < 3; inner++) {

				mult[r][c] += (*this)[r][inner] * other[inner][c];

			}
		}
	}*/

	//return Matrix3();
	/*Matrix3 mult;

	mult.m1 = other.m1*m1 + other.m4*m2 + other.m7*m3;
	mult.m2 = other.m2*m1 + other.m5*m2 + other.m8*m3;
	mult.m3 = other.m3*m1 + other.m6*m2 + other.m9*m3;

	mult.m4 = other.m1*m4 + other.m4*m5 + other.m7*m6;
	mult.m5 = other.m2*m4 + other.m5*m5 + other.m8*m6;
	mult.m6 = other.m3*m4 + other.m6*m5 + other.m9*m6;

	mult.m7 = other.m1*m7 + other.m4*m8 + other.m7*m9;
	mult.m8 = other.m2*m7 + other.m5*m8 + other.m8*m9;
	mult.m9 = other.m3*m7 + other.m6*m8 + other.m9*m9;*/
	
	

	return mult;
}

Vector3 Matrix3::operator*(Vector3 & other)
{
	//return Vector3((*this)[0].dot(other), (*this)[1].dot(other), (*this)[2].dot(other));
	return Vector3(m1*other.x + m4*other.y +m7*other.z, m2*other.x + m5*other.y + m8*other.z, m3*other.x + m6*other.y + m9*other.z);
}

Matrix3& Matrix3::operator=(Matrix3 & other)
{
	for (int i = 0; i < 3; ++i)
		(*this)[i] = other[i];
	return *this;
}

Matrix3 Matrix3::createRotation(float a_rot)
{
	return Matrix3(cosf(a_rot), sinf(a_rot), 0, -sinf(a_rot), cosf(a_rot), 0, 0, 0, 1);

}

Vector3& Matrix3::operator[](unsigned int index)
{
	return mv[index];
}

//Matrix3::operator float*() const
//{
//	float temp[2][2];
//	temp[0][0] = m1;
//	temp[0][1] = m2;
//	temp[1][0] = m3;
//	temp[1][1] = m4;
//	return temp;
//}

void Matrix3::setRotateX(float a_rot)
{
	Matrix3 mat3 =  Matrix3(1, 0, 0, 0, cosf(a_rot),sinf(a_rot),0,-sinf(a_rot),cosf(a_rot));
	m1 = mat3.m1;
	m2 = mat3.m2;
	m3 = mat3.m3;
	m4 = mat3.m4;
	m5 = mat3.m5;
	m6 = mat3.m6;
	m7 = mat3.m7;
	m8 = mat3.m8;
	m9 = mat3.m9;
}

void Matrix3::setRotateY(float a_rot)
{
	Matrix3 mat3 = Matrix3(cosf(a_rot), 0, -sinf(a_rot),0, 1, 0, sinf(a_rot),0, cosf(a_rot));
	m1 = mat3.m1;
	m2 = mat3.m2;
	m3 = mat3.m3;
	m4 = mat3.m4;
	m5 = mat3.m5;
	m6 = mat3.m6;
	m7 = mat3.m7;
	m8 = mat3.m8;
	m9 = mat3.m9;
}

void Matrix3::setRotateZ(float a_rot)
{
	set(cosf(a_rot),sinf(a_rot),0,-sinf(a_rot),cosf(a_rot),0,0,0,1);
}

void Matrix3::set(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9) {
	m1 = a_m1;
	m2 = a_m2;
	m3 = a_m3;
	m4 = a_m4,
	m5 = a_m5;
	m6 = a_m6;
	m7 = a_m7;
	m8 = a_m8;
	m9 = a_m9;
}