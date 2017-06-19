#pragma once

class Vector3 {
public:

	Vector3();
	Vector3(float a_x, float a_y, float a_z);

	Vector3(const Vector3 &copy);
	//Point addition/subtraction with vector
	//V = V + V (point translated by a vector)
	//V = V – V(point translated by a vector)

	Vector3& operator += (Vector3 &other);
	Vector3& operator -= (Vector3 &other);
	Vector3& Vector3::operator*=(float other);

	Vector3 operator + (Vector3 &other);
	Vector3 operator - (Vector3 &other);
	Vector3& operator = (Vector3 &other);

	Vector3 operator*(float other);

	friend Vector3 Vector3::operator*(float other, Vector3 &other2);

	float& operator[] (unsigned int index);

	explicit operator float*() { return &x; };

	float magnitude();
	void normalise();

	float dot(Vector3 &a_dotTarget);
	Vector3 cross(Vector3 &a_crossTarget);
	union {
		struct { float x, y, z; };
		struct { float v[3]; };
	};
};