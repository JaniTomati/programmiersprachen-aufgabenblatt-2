// circle.cpp (Programmiersprachen Aufgabenblatt 2)
#include <iostream>
#include "circle.hpp"

	// Default-Konstruktor
Circle::Circle(): 
ctr {0.0, 0.0}, r {1.0}, clr {0.0, 0.0, 0.0} {

}
	
	// Konstruktor (Uebergabeparameter: center, radius, color)
Circle::Circle(Vec2 const& ctr_, float r_, Color const& clr_): 
ctr {ctr_}, r {r_}, clr {clr_} {

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