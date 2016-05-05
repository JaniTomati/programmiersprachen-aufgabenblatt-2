// circle.hpp (Programmiersprachen Aufgabenblatt 2)
// Teilweise uebernommen von den Vorlesungsfolien Nr. 3

#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include <cmath>

class Circle {
public: 
	// Konstruktoren
	Circle();
	Circle(Vec2 const& ctr, float r, Color const& clr);
	// Memberfunktionen
	void draw() const;
	float get_diameter() const;
	float get_area() const; 
	float get_circumference() const;
	void set_radius(float r_); 
	float get_radius() const; 

private:
	// Membervariablen
	Vec2 ctr; // center 
	float r; // radius
	Color clr; // color

};

#endif // CIRCLE_HPP