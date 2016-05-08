// color.hpp (Programmiersprachen Aufgabenblatt 2)

#ifndef COLOR_HPP
#define COLOR_HPP
#include <iostream>

struct Color {

	// Konstruktoren
	Color(): 
	r {0.0f}, g {0.0f}, b {0.0f} {

	}

	Color(float c):
	r {c}, g {c}, b {c} {
		if (c < 0 || c > 1) {
			std::cerr << "Farbwerte muessen zwischen 0 und 1 liegen!" << std::endl;
			r = 0.0;
			g = 0.0;
			b = 0.0;
		}

	}

		// Werte werden auf 0 gesetzt, sobald sie den gueltigen Wertebereich zwischen 0 und 1 verlassen haben
	Color(float r_, float g_, float b_): 
	r {r_}, g {g_}, b {b_} {

		if (r_ < 0 || r_ > 1) {
			std::cerr << "Farbwerte muessen zwischen 0 und 1 liegen!" << std::endl;
			r = 0.0;
		}

		if (g_ < 0 || g_ > 1) {
			std::cerr << "Farbwerte muessen zwischen 0 und 1 liegen!" << std::endl;
			g = 0.0;
		}

		if (b_ < 0 || b_ > 1) {
			std::cerr << "Farbwerte muessen zwischen 0 und 1 liegen!" << std::endl;
			b = 0.0;
		}
	}

	// Membervariablen
	float r, g, b; 

};

#endif // COLOR_HPP