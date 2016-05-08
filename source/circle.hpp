// circle.hpp (Programmiersprachen Aufgabenblatt 2)
// Teilweise uebernommen von den Vorlesungsfolien Nr. 3

#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <cmath>

class Circle {
public: 
	// Konstruktoren
	Circle();
	Circle(Vec2 const& ctr, float r, Color const& clr);

	// Memberfunktionen
	void draw(Window const& win) const;
	void draw(Window const& win, Color const& clr_) const;
	float get_diameter() const;
	float get_area() const; 
	float get_circumference() const;
	void set_radius(float r_); 
	float get_radius() const; 
	void set_center(Vec2 const& ctr_); 
	Vec2 get_center() const;
	void set_color(Color const& clr_);
	Color get_color() const;
	bool is_inside(Vec2 const& v) const;
	void draw_clock(Window const& win) const;

private:
	// Membervariablen
	Vec2 ctr; // center 
	float r; // radius
	Color clr; // color

};

#endif // CIRCLE_HPP