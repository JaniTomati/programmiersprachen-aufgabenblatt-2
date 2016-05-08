// rectangle.hpp (Programmiersprachen Aufgabenblatt 2)

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <cmath>

class Rectangle {
public:
	// Konstruktoren
	Rectangle();
	Rectangle(Vec2 const& cnr_, float a_, float b_, Color const& clr_);
	// Memberfunktionen 
	void draw(Window const& win) const;
	void draw(Window const& win, Color const& clr_) const;
	float get_area() const; 
	float get_perimeter() const;
	float get_diagonal() const;
	void set_aside(float a_);
	float get_aside() const;
	void set_bside(float b_);
	float get_bside() const;
	void set_corner(Vec2 const& cnr_); 
	Vec2 get_corner() const;
	void set_color(Color const& cnr_);
	Color get_color() const;
	bool is_inside(Vec2 const& v) const;

private:
	// Membervariablen
	Vec2 cnr;
	float a; // Hoehe
	float b; // Breite
	Color clr;

};

#endif // RECTANGLE_HPP