// Mat2.hpp (Programmiersprachen Aufgabenblatt 2)

#ifndef MAT2_HPP
#define MAT2_HPP
#include "vec2.hpp"

// Mat2 class definition 
class Mat2 {
public:
	// Konstruktoren 
	Mat2();
	Mat2(float a, float b, float c, float d);

	// Membervariablen
	float a, b, c, d; 

	// Memberfunktion 
	float det() const;
	Mat2& operator *= (Mat2 const& m);
};

Vec2 operator * (Mat2 const& m, Vec2 const& v);
void operator * (Vec2 const& v, Mat2 const& m);
Mat2 operator * (Mat2 const& m1, Mat2 const& m2);
Mat2 operator * (float a, Mat2 const& m);
Mat2 inverse(Mat2 const& m);
Mat2 transpose(Mat2 const& m);
Mat2 make_rotation_mat2(float phi);

#endif // MAT2_HPP