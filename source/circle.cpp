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
		std::cerr << "/!\\ Der Radius muss groeßer Null sein!" << std::endl;
		r = 1.0f; // Wird auf Defaultradius gesetzt
	}

	else if (r_ < 0.0f) { // negativer Radius wird positiv gemacht
		r = r_ * (-1);
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
	if (r_ == 0.0f) {
		std::cerr << "/!\\ Der Radius muss groeßer Null sein!" << std::endl;
		r = 1.0f; // Wird auf Defaultradius gesetzt
	}

	else if (r_ < 0.0f) { // negativer Radius wird positiv gemacht
		r = r_ * (-1);
	}

	else r = r_;
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

	// Malt den Kreis auf dem sie aufgerufen wird in dem Fenster das uebergeben wurde
void Circle::draw(Window const& win) const {
	win.draw_point(get_center().x, get_center().y, get_color().r, get_color().g, get_color().b); // Mittelpunkt

    for (int i = 1; i <= 360; ++i) {
        Vec2 start ((make_rotation_mat2(2 * M_PI * i / 360)) * Vec2(get_radius(), 0) + get_center());
        Vec2 end ((make_rotation_mat2(2 * M_PI * (i + 1) / 360)) * Vec2(get_radius(), 0) + get_center());
        win.draw_line(start.x, start.y, end.x, end.y, get_color().r, get_color().g, get_color().b);
    }
}

	// Malt den Kreis auf dem sie aufgerufen wird in dem Fenster das uebergeben wurde und setzt neue eingegebene Farben
void Circle::draw(Window const& win, Color const& clr_) const {
	win.draw_point(get_center().x, get_center().y, get_color().r, get_color().g, get_color().b); // Mittelpunkt

    for (int i = 1; i <= 360; ++i) {
        Vec2 start ((make_rotation_mat2(2 * M_PI * i / 360)) * Vec2(get_radius(), 0) + get_center());
        Vec2 end ((make_rotation_mat2(2 * M_PI * (i + 1) / 360)) * Vec2(get_radius(), 0) + get_center());
        win.draw_line(start.x, start.y, end.x, end.y, clr_.r, clr_.g, clr_.b);
    }

}

void Circle::draw_clock(Window const& win) const {
    for (int i = 1; i <= 60; ++i) {
        Vec2 start ((make_rotation_mat2(2 * M_PI * i / 60)) * Vec2(get_radius(), 0.0f) + get_center());
        Vec2 end ((make_rotation_mat2(2 * M_PI * i / 60)) * Vec2(get_radius() - 0.02f, 0.0f) + get_center());
        win.draw_line(start.x, start.y, end.x, end.y, 0.7f, 0.8f, 0.8f);
    }

    for (int i = 1; i <= 12; ++i) {
        Vec2 start ((make_rotation_mat2(2 * M_PI * i / 12)) * Vec2(get_radius(), 0.0f) + get_center());
        Vec2 end ((make_rotation_mat2(2 * M_PI * i / 12)) * Vec2(get_radius() - 0.1f, 0.0f) + get_center());
        win.draw_line(start.x, start.y, end.x, end.y, get_color().r, get_color().g, get_color().b);
    }
}
	
	// Prueft, ob ein Punkt im Kreis liegt, auf dem die Funktion aufgerufen wurde
bool Circle::is_inside(Vec2 const& v) const {
	if (sqrt((v.x - ctr.x) * (v.x - ctr.x)) + ((v.y - ctr.y) * (v.y - ctr.y)) < r) {
		return true;
	}

	else return false;

}