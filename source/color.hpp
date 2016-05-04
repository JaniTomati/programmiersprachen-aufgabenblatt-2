// color.hpp (Programmiersprachen Aufgabenblatt 2)

#ifndef COLOR_HPP
#define COLOR_HPP

struct Color {

	// Konstruktoren
	color(): 
	r {0.0}, g {0.0}, b {0.0} {

	}

	color(double c):
	r {c}, g {c}, b {c} {

	}

	color(double r_, double g_, double b_): 
	r {r_}, g {g_}, b {b_} {

	}

	// Membervariablen
	double r, g, b; // Wertebereich zwischen 0 und 1 einschraenken! 

};

#endif // COLOR_HPP