// rectangle.hpp (Programmiersprachen Aufgabenblatt 2)

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include <cmath>

class Rectangle {
public:
	// Konstruktoren
	Rectangle();
	Rectangle(Vec2 const& ctr_, float a_, float b_, Color const& clr_);
	// Memberfunktionen 
	float get_area() const; 
	float get_perimeter() const;
	float get_diagonal() const;
	float get_aside() const;
	float get_bside() const;
	void set_aside(float a_);
	void set_bside(float b_);

private:
	// Membervariablen
	Vec2 ctr;
	float a; // höhe
	float b; // breite
	Color clr;

};

#endif // RECTANGLE_HPP