// rectangle.cpp (Programmiersprachen Aufgabenblatt 2)

#include <iostream>
#include "rectangle.hpp"

// Default-Konstruktor
Rectangle::Rectangle():
ctr {0.0f, 0.0f}, a {1.0f}, b {1.0f}, clr {0.0f, 0.0f, 0.0f} {

}

// Konstruktor bekommt center, hoehe, breite und color uebergeben 
Rectangle::Rectangle(Vec2 const& ctr_, float a_, float b_, Color const& clr_):
ctr {ctr_}, a {a_}, b {b_}, clr {clr_} {

}

	// Flacheninhalt: A = a * b
float Rectangle::get_area() const {
	return a * b;
}

	// Umfang: 2 * a + 2 * b = 2 (a + b)
float Rectangle::get_perimeter() const {
	return 2 * a + 2 * b;
}

	// Diagonalenlänge: d = sqrt(a^2 + b^2)
float Rectangle::get_diagonal() const {
	return sqrt(a * a + b * b);
}

	// Gibt die Hoehe zurueck
float Rectangle::get_aside() const {
	return a;
}
	
	// Gibt die Breite zurueck
float Rectangle::get_bside() const {
	return b;
}
	
	// Setzt die Hoehe auf den eingegebenen Wert
void Rectangle::set_aside(float a_) {
	a = a_;
}

	// Setzt die Breite auf den eingegebenen Wert 
void Rectangle::set_bside(float b_) {
	b = b_;
}