// Mat2.hpp (Programmiersprachen Aufgabenblatt 2)

#ifndef MAT2_HPP
#define MAT2_HPP

// Mat2 class definition 
class Mat2 {
public:
	// Konstruktoren 
	Mat2();
	Mat2(float a, float b, float c, float d);

	// Membervariablen
	float a, b, c, d; 

	// Memberfunktion 
	Mat2& operator *= (Mat2 const& m);
};

Mat2 operator * (Mat2 const& m1, Mat2 const& m2);

#endif // MAT2_HPP