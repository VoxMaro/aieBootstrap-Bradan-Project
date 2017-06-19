#pragma once

class Vector4 {
public:

	Vector4();
	Vector4(float a_x, float a_y, float a_z, float a_w);

	Vector4(const Vector4 &copy);
	//Point addition/subtraction with vector
	//V = V + V (point translated by a vector)
	//V = V – V(point translated by a vector)

	Vector4& operator += (Vector4 &other);
	Vector4& operator -= (Vector4 &other);
	Vector4& Vector4::operator*=(float other);

	Vector4 operator + (Vector4 &other);
	Vector4 operator - (Vector4 &other);
	Vector4& operator = (Vector4 &other);

	Vector4 Vector4::operator*(float other);
	

	friend Vector4 Vector4::operator*(float other, Vector4 &other2);
	float& operator[] (unsigned int index);

	explicit operator float*() { return &x; };

	float magnitude();
	void normalise();

	float dot(Vector4 &a_dotTarget);
	Vector4 cross(Vector4 &a_crossTarget);

	union {
		struct { float x, y, z, w; };
		struct { float v[4]; };
	};
};