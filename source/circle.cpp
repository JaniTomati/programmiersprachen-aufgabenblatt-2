// circle.cpp (Programmiersprachen Aufgabenblatt 2)
#include <iostream>
#include "circle.hpp"

	// Default-Konstruktor
Circle::Circle(): 
ctr {0.0f, 0.0f}, r {1.0f}, clr {0.0f, 0.0f, 0.0f} {

}
	
	// Konstruktor (Uebergabeparameter: center, radius, color)
Circle::Circle(Vec2 const& ctr_, float r_, Color const& clr_): 
ctr {ctr_}, r {r_}, clr {clr_} {
	if (r_ == 0.0f) {
		std::cerr << "Der Radius muss groeßer Null sein!";
	}

	if (r_ < 0.0f) { // negativer Radius wird positiv gemacht
		r_ *= (-1);
	}

}

	// Durchmesser: D = 2 * r
float Circle::get_diameter() const {
	return 2 * r;
}

	// Flaecheninhalt: A = pi * r^2 
float Circle::get_area() const {
	return M_PI * r * r;
}

	// Umfang: U = 2 * pi * r
float Circle::get_circumference() const {
	return 2 * M_PI * r;
}

	// Uebergibt einem Kreis einen neuen Radius
void Circle::set_radius(float r_) {
	r = r_;
}

	// Gibt den Radius des Kreises aus, auf dem die Funktion aufgerufen wird 
float Circle::get_radius() const {
	return r;
}
	
	// Uebergibt einem Kreis einen neuen Mittelpunkt
void Circle::set_center(Vec2 const& ctr_) {
	ctr = ctr_;
}

	// Gibt den Mittelpunkt des Kreises aus, auf dem die Funktion aufgerufen wird 
Vec2 Circle::get_center() const {
	return ctr;
}
	// Uebergibt einem Kreis eine neue Farbe
void Circle::set_color(Color const& clr_) {
	clr = clr_;
}

// Gibt die Farbe eines Kreises aus, auf dem die Funktion aufgerufen wird 
Color Circle::get_color() const {
	return clr;
}

/* void Circle::draw(Window const& win, Circle const& c) const {
	win.draw_point(c.get_center().x, c.get_center().y, 0.0f, 0.1f, 0.2f);
} */