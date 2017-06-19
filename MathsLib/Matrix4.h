#pragma once
#include "Vector4.h"

//revolutions
class Matrix4 {
public:
	Matrix4();
	Matrix4(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9,float a_m10, float a_m11, float a_m12, float a_m13, float a_m14, float a_m15, float a_m16);
	Matrix4(Matrix4& other);
	//Matrix4(float *a_array);

	//todo:concatenation, subscript operator, cast operator, setrotate

	Matrix4 operator* (Matrix4& other);
	Vector4 operator* (Vector4& other);
	Matrix4& operator= (Matrix4& other);

	Vector4& operator[] (unsigned int index);
	explicit operator float*() { return &m1; };

	void setRotateX(float a_rot);
	void setRotateY(float a_rot);
	void setRotateZ(float a_rot);

	void set(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9, float a_m10, float a_m11, float a_m12, float a_m13, float a_m14, float a_m15, float a_m16);

	union {
		struct { float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16; };
		struct { float m[16]; };
		struct { float mm[4][4]; };
		struct { Vector4 mv[4]; };
	};

};