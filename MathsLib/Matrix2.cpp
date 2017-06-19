#include "Matrix2.h"
#include "Vector2.h"
#include <cmath>
//#include <cmemory>

//Matrix2 Library
//Bradan Lean

Matrix2::Matrix2()
{
	//m1 = m2 = m3 = m4 = 0;
	m2 = m3 = 0;
	m1 = m4 = 1;
}

Matrix2::Matrix2(float a_m1, float a_m2, float a_m3, float a_m4) : m1(a_m1), m2(a_m2), m3(a_m3), m4(a_m4)
{
	
}

Matrix2::Matrix2(Matrix2 &other) {
	for (int i = 0; i < 2; ++i)
		(*this)[i] = other[i];
}



Matrix2::Matrix2(float * a_array)
{
	for (int i = 0; i < 4; ++i)
		(*this).m[i] = a_array[i];
	//std::memcpy(this,a_array,sizeof(a_array));
}

//Matrix2 Matrix2::operator*(Matrix2 & other)
//{
//	return Matrix2(Vector2(m1, m2).dot(Vector2(other.m1,other.m3)),
//		Vector2(m1, m2).dot(Vector2(other.m2, other.m4)),
//		Vector2(m3, m4).dot(Vector2(other.m1, other.m3)),
//		Vector2(m3, m4).dot(Vector2(other.m2, other.m4)));
//}

	/*float v1 = (*this)[0].dot(Vector2(other.m1, other.m3));
	float v2 = (*this)[0].dot(Vector2(other.m2, other.m4));
	float v3 = (*this)[1].dot(Vector2(other.m1, other.m3));
	float v4 = (*this)[1].dot(Vector2(other.m2, other.m4));


	Matrix2 mult = Matrix2(v1,v2,v3,v4);
	
	return mult;*/

Matrix2  Matrix2::operator * (const Matrix2 &a_rhs) const
{
	return Matrix2(
		a_rhs.m1*m1 + a_rhs.m2*m3, a_rhs.m1*m2 + a_rhs.m2*m4,
		a_rhs.m3*m1 + a_rhs.m4*m3, a_rhs.m3*m2 + a_rhs.m4*m4);
}


Vector2 Matrix2::operator*(Vector2 & other)
{

	//Vector2 v1 = Vector2(m1,m2);
	//Vector2 v2 = Vector2(m3,m4);
	//float v_x = v1.dot(other);
	//float v_y = v2.dot(other);
	//return Vector2(v_x,v_y);
	return Vector2(m1*other.x+m3*other.y, m2*other.x + m4*other.y);

}

Matrix2& Matrix2::operator*= (const Matrix2 &a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}
//Matrix2& Matrix2::operator*= (Matrix2 &a_rhs)
//{
//	*this = *this * a_rhs;
//	return *this;
//}


Matrix2& Matrix2::operator=(Matrix2 & other)
{
	m1 = other.m1;
	m2 = other.m2;
	m3 = other.m3;
	m4 = other.m4;
	//for (int i = 0; i < 4; ++i)
	//		(*this)[i] = other[i];
	return *this;
	//return Matrix2(other.m1,other.m2,other.m3,other.m4);
}


Vector2& Matrix2::operator[](unsigned int index)
{
	//return Vector2(m[index * 2 + 1], m[index * 2 + 2]);
	/*Vector2 vop1 = Vector2(m1,m3);
	if (index == 0) return vop1;
	if (index == 1) return Vector2(m2, m4);*/
	//return mv[index];
	return mv[index];	
}

//Matrix2::operator float*() const
//{
//	float temp[4];
//	for (int i = 0; i < 4; ++i)
//		temp[i] = (*this).m[i];
//	return temp;
//}

void Matrix2::setRotate(float a_rot)
{
	//*this = Matrix2(cosf(a_rot), -sinf(a_rot), sinf(a_rot), cosf(a_rot));
	//*this = Matrix2(20.0f, 20.0f, 20.0f, 20.0f);
	/*m1 = cosf(a_rot);
	m2 = -sinf(a_rot);
	m3 = sinf(a_rot);
	m4	= cosf(a_rot);*/
	//set(cosf(a_rot), -sinf(a_rot), sinf(a_rot), cosf(a_rot)); row major fuckery
	set(cosf(a_rot), sinf(a_rot), -sinf(a_rot), cosf(a_rot));
}

void Matrix2::set(float a_m1, float a_m2, float a_m3, float a_m4)
{
	//m = { a_m1,a_m2,a_m3,a_m4 };
	m1 = a_m1;
	m2 = a_m2;
	m3 = a_m3;
	m4 = a_m4;
}
