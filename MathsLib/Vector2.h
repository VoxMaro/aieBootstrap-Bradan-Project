#pragma once

class Vector2 {
public:

	Vector2();
	Vector2(float a_x, float a_y);

	Vector2(const Vector2 &copy);
	//Point addition/subtraction with vector
	//V = V + V (point translated by a vector)
	//V = V – V(point translated by a vector)

	Vector2& operator += (Vector2 &other);
	Vector2& operator -= (Vector2 &other);
	Vector2& Vector2::operator*=(float other);

	Vector2 operator + (Vector2 &other);
	Vector2 operator - (Vector2 &other);
	Vector2& operator = (Vector2 &other);

	Vector2 operator*(float other);
	
	friend Vector2 Vector2::operator*(float other, Vector2 &other2);

	float& operator[] (unsigned int index);

	explicit operator float*() { return &x; };

	float magnitude();
	void normalise();
	Vector2 getNormal();


	float dot(Vector2 &a_dotTarget);
	union {
		struct{ float x, y; };
		struct{ float v[2]; };
	};
	

};