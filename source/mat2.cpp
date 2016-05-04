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

// Operator * (Mat & Mat): Multiplikation zweier Matritzen, bei der eine neue Matritze zurueckgegeben wird 
Mat2 operator * (Mat2 const& m1, Mat2 const& m2) {
	float mat_a = m1.a * m2.a + m1.b * m2.c;
	float mat_b = m1.a * m2.b + m1.b * m2.d; 
	float mat_c = m1.c * m2.a + m1.d * m2.c;
	float mat_d = m1.c * m2.b + m1.d * m2.d;

	return Mat2 {mat_a, mat_b, mat_c, mat_d};
}

// Operator * (Mat & Vec): Multiplikation von Matritze und Vektor, bei der ein neuer Vektor zurueckgegeben wird
Vec2 operator * (Mat2 const& m, Vec2 const& v) {
	return Vec2 {(m.a * v.x + m.b * v.y), (m.c * v.x + m.d * v.y)};
}

/* Zwei Matritzen koennen nur dann multipliziert werden, wenn die Anzahl der Spalten der ersten Matrix
gleich der Anzahl der Zeilen der zweiten Matrix ist */
void operator * (Vec2 const& v, Mat2 const& m){
	std::cout << "Wenn v eine 2 x 1-Matrix ist, so muss B eine 1 x l-Matrix sein! Eine Multiplikation ist nicht möglich." <<std::endl;
	return;
}

Mat2 operator * (float a, Mat2 const& m) {
	return Mat2 {a * m.a, a * m.b, a * m.c, a * m.d};
}

// Memberfunktion: Berechnung der Determinaten einer Matrix, auf der die Funktion aufgerufen wird
float Mat2::det() const {
	return (a * d) - (b * c);
}

// Funktion: Berechnung der Inversen einer uebergebenen Matrix
Mat2 inverse(Mat2 const& m) {
	if (m.det() == 0) {
		std::cout << "Eine Matrix besitzt nur dann ein Inverses, wenn ihre Determinate ungleich 0 ist!" << std::endl;
	}

	else {
		Mat2 inv {m.d, -m.b, -m.c, m.a};
		return (1 / m.det()) * inv;
	}

}
// Funktion: Transponiert die Matrix, die ihr uebergeben wird => Spalten werden zu Zeilen, Zeilen zu Spalten
Mat2 transpose(Mat2 const& m) {
	return Mat2 {m.a, m.c, m.b, m.d};
}

// Funktion: Erstellt Rotationsmatrix für ein uebergebene Gleitkommazahl / einen uebergebenen Winkel
Mat2 make_rotation_mat2(float phi) {
	Mat2 rotate{};
	rotate.a = cos(phi);
	rotate.b = -sin(phi);
	rotate.c = sin(phi);
	rotate.d = cos(phi);
	return rotate;
	// return Mat2 {cos(phi), -sin(phi), sin(phi), cos(phi)};
}