// Mat2.cpp (Programmiersprachen Aufgabenblatt 2)

#include "mat2.hpp"
#include "vec2.hpp"
#include <iostream>
#include <math.h>

// Default-Konstruktor: wird mit Einheitsmatrix initialisiert 
Mat2::Mat2(): 
a{1}, b{0}, c{0}, d{1} {

}

// Konstruktor: Wird mit vier float Parametern initialisiert 
Mat2::Mat2(float a_, float b_, float c_, float d_):
a{a_}, b{b_}, c{c_}, d{d_} {

}

// Operator *= : Multiplikation zweier Matritzen. bei der die auf der linke Seite des Operators stehende Matrize ueberschrieben wird
Mat2& Mat2::operator *= (Mat2 const& m) {
	float mat_a = a * m.a + b * m.c; 
	float mat_b = a * m.b + b * m.d;
	float mat_c = c * m.a + d * m.c; 
	float mat_d = c * m.b + d * m.d;

	a = mat_a, b = mat_b, c = mat_c, d = mat_d;

	return *this;
}

// Operator * : Multiplikation zweier Matritzen, bei der eine neue Matritze zurueckgegeben wird 
Mat2 operator * (Mat2 const& m1, Mat2 const& m2) {
	float mat_a = m1.a * m2.a + m1.b * m2.c;
	float mat_b = m1.a * m2.b + m1.b * m2.d; 
	float mat_c = m1.c * m2.a + m1.d * m2.c;
	float mat_d = m1.c * m2.b + m1.d * m2.d;

	return Mat2 {mat_a, mat_b, mat_c, mat_d};
}