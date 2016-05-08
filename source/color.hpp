// color.hpp (Programmiersprachen Aufgabenblatt 2)

#ifndef COLOR_HPP
#define COLOR_HPP

struct Color {

	// Konstruktoren
	Color(): 
	r {0.0f}, g {0.0f}, b {0.0f} {

	}

	Color(float c):
	r {c}, g {c}, b {c} {

	}

	Color(float r_, float g_, float b_): // Werte ueber 1 und unter 0 werden automatisch auf 0 gesetzt
	r {r_}, g {g_}, b {b_} {

		if (r_ > 1 || r_ < 1) {
			r_ = 0.0;
		}

		if (g_ > 1 || g_ < 1) {
			g_ = 0.0;
		}

		if (b_ > 1 || b_ < 1) {
			b_ = 0.0;
		}

	}

	// Membervariablen
	float r, g, b; 

};

#endif // COLOR_HPP