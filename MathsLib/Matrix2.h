#pragma once

#include "Vector2.h"
//reloaded
class Matrix2 {
public:
	Matrix2();
	Matrix2(float a_m1, float a_m2, float a_m3, float a_m4);
	Matrix2(Matrix2 & other);
	Matrix2(float * a_array);
	//Matrix2(float *a_array);

	//todo:concatenation, subscript operator, cast operator, setrotate

	Matrix2 operator* (const Matrix2& other) const;
	Vector2 operator* (Vector2& other);
	Matrix2& operator= (Matrix2& other);
	Matrix2& operator*=(const Matrix2 &a_rhs);
	Matrix2& operator*=(Matrix2 &a_rhs);

	Vector2& operator[] (unsigned int index);
	explicit operator float*() { return &m1; };

	void setRotate(float a_rot);
	void set(float a_m1, float a_m2, float a_m3, float a_m4);
	//float m1, m2, m3, m4; 

	union{
		struct { float m1, m2, m3, m4; };
		struct { float m[4]; };
		struct { float mm[2][2]; };
		struct { Vector2 mv[2]; };
	};
	
};