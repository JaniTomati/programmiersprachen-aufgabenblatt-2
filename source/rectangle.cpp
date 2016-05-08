// rectangle.cpp (Programmiersprachen Aufgabenblatt 2)

#include <iostream>
#include "rectangle.hpp"

// Default-Konstruktor
Rectangle::Rectangle():
cnr {0.0f, 0.0f}, a {1.0f}, b {1.0f}, clr {0.0f, 0.0f, 0.0f} {

}

// Konstruktor bekommt center, hoehe, breite und color uebergeben 
Rectangle::Rectangle(Vec2 const& cnr_, float a_, float b_, Color const& clr_):
cnr {cnr_}, a {a_}, b {b_}, clr {clr_} {

	if (a_ == 0.0f) {
		std::cerr << "/!\\ Die Seiten muessen laenger als 0 sein!" << std::endl;
		a = 1.0f; // wird auf Defaultlaenge 1 gesetzt
	}

	else if (a_ < 0.0f) { // negative Hoehe wird positiv gemacht
		a = a_ * (-1);
	}

	if (b_ == 0.0f) {
		std::cerr << "/!\\ Die Seiten muessen laenger als 0 sein!" << std::endl;
		b = 1.0f; // wird auf Defaultlaenge 1 gesetzt
	}

	else if (b_ < 0.0f) { // negative Breite wird positiv gemacht
		b = b_ * (-1);
	}
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

	// Setzt die Hoehe auf den eingegebenen Wert
void Rectangle::set_aside(float a_) {
	if (a_ == 0.0f) {
		std::cerr << "/!\\ Die Seiten muessen laenger als 0 sein!" << std::endl;
		a = 1.0f; // wird auf Defaultlaenge 1 gesetzt
	}

	else if (a_ < 0.0f) { // negative Hoehe wird positiv gemacht
		a = a_ * (-1);
	}

	else a = a_;
}

	// Gibt die Hoehe zurueck
float Rectangle::get_aside() const {
	return a;
}

	// Setzt die Breite auf den eingegebenen Wert 
void Rectangle::set_bside(float b_) {
	if (b_ == 0.0f) {
		std::cerr << "/!\\ Die Seiten muessen laenger als 0 sein!" << std::endl;
		b = 1.0f; // wird auf Defaultlaenge 1 gesetzt
	}

	else if (b_ < 0.0f) { // negative Breite wird positiv gemacht
		b = b_ * (-1);
	}

	else b = b_;
}
	
	// Gibt die Breite zurueck
float Rectangle::get_bside() const {
	return b;
}
	
	// Setzt einen neuen Mittelpunkt
void Rectangle::set_corner(Vec2 const& cnr_) {
	cnr = cnr_;
}

	// Gibt den Mittelpunkt zurueck
Vec2 Rectangle::get_corner() const {
	return cnr;
}

	// Setzt eine neue Farbe
void Rectangle::set_color(Color const& clr_) {
	clr = clr_;
}

	// Gibt die Farbe zurueck
Color Rectangle::get_color() const {
	return clr;
}

	// Malt das Rechteck auf dem sie aufgerufen wird in dem Fenster das uebergeben wurde
void Rectangle::draw(Window const& win) const {
    win.draw_line(get_corner().x, get_corner().y, get_corner().x + get_bside(), get_corner().y, get_color().r, get_color().g, get_color().b);
    win.draw_line(get_corner().x, get_corner().y, get_corner().x, get_corner().y + get_aside(), get_color().r, get_color().g, get_color().b);
    win.draw_line(get_corner().x, get_corner().y + get_aside(), get_corner().x + get_bside(), get_corner().y + get_aside(), get_color().r, get_color().g, get_color().b);
    win.draw_line(get_corner().x + get_bside(), get_corner().y, get_corner().x + get_bside(), get_corner().y + get_aside(), get_color().r, get_color().g, get_color().b);
} 

	// Malt das Rechteck auf dem sie aufgerufen wird in dem Fenster das uebergeben wurde und setzt neue eingegebene Farben
void Rectangle::draw(Window const& win, Color const& clr_) const {
	win.draw_line(get_corner().x, get_corner().y, get_corner().x + get_bside(), get_corner().y, clr_.r, clr_.g, clr_.b);
    win.draw_line(get_corner().x, get_corner().y, get_corner().x, get_corner().y + get_aside(), clr_.r, clr_.g, clr_.b);
    win.draw_line(get_corner().x, get_corner().y + get_aside(), get_corner().x + get_bside(), get_corner().y + get_aside(), clr_.r, clr_.g, clr_.b);
    win.draw_line(get_corner().x + get_bside(), get_corner().y, get_corner().x + get_bside(), get_corner().y + get_aside(), clr_.r, clr_.g, clr_.b);

}

	// Prueft, ob ein Punkt im Rechteck liegt, auf dem die Funktion aufgerufen wurde
bool Rectangle::is_inside(Vec2 const& v) const {
	if (v.x >= cnr.x && v.y >= cnr.y && v.x <= cnr.x + b && v.y <= cnr.y + a) {
		return true;
	}

	else return false;
}