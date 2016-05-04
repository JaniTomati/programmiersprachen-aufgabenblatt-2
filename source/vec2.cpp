// vec2.cpp

#include "vec2.hpp"
#include <iostream>

Vec2::Vec2(): // Standardkonstruktor Initialisiert die Paramater x und y mit 0 
x{0}, y{0} {

}

Vec2::Vec2(float x_, float y_): // Konstruktor bekommt x und y Variable des Punktes uebergeben 
x{x_}, y{y_} {

} 

// Operator += : Addiert zwei Vektoren und überschreibt den Vektor links vom Operator mit den neuen Werten
Vec2& Vec2::operator += (Vec2 const& v) { 
	x += v.x;
	y += v.y;
	return *this;
}

// Operator -= : Subtrahiert zwei Vektoren und überschreibt den Vektor links vom Operator mit den neuen Werten
Vec2& Vec2::operator -= (Vec2 const& v) {
	x -= v.x;
	y -= v.y;
	return *this;
}

// Operator *= : Multipliziert einen Vektor mit einer Gleitkommazahl und überschreibt den Vektor mit den neuen Werten
Vec2& Vec2::operator *= (float v) {
	x *= v;
	y *= v; 
	return *this;
}

// Operator *= : Dividiert eine Gleitkommazahl von einem Vektor und überschreibt den Vektor mit den neuen Werten
Vec2& Vec2::operator /= (float v) {
	if (v == 0.0f) {
		std::cout << "/!\\ Die Teilung durch 0 ist nicht erlaubt!" << std::endl;
	}

	else {
		x /= v;
		y /= v;
		return *this;
	}

}
