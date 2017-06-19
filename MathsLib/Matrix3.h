#pragma once

#include "Vector3.h"
//reloaded
class Matrix3 {
public:
	Matrix3();
	Matrix3(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9);
	Matrix3(Matrix3 & other);
	//Matrix3(float *a_array);

	//todo:concatenation, subscript operator, cast operator, setrotate

	Matrix3 operator* (Matrix3& other);
	Vector3 operator* (Vector3& other);
	Matrix3& operator= (Matrix3& other);

	static Matrix3 createRotation(float a_rot);

	Vector3& operator[] (unsigned int index);
	explicit operator float*() { return &m1; };

	void setRotateX(float a_rot);
	void setRotateY(float a_rot);
	void setRotateZ(float a_rot);

	void set(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9);

	

	union {
		struct { float m1, m2, m3, m4, m5, m6, m7, m8, m9; };
		struct { float m[9]; };
		struct { float mm[3][3]; };
		struct { Vector3 mv[3]; };
	};

};