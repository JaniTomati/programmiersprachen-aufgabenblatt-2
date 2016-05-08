// tests.cpp (Programmiersprachen Aufgabenblatt 2)

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

// * --------------- VEC2-Tests --------------- * //

	// Test_Cases: a = a + b
TEST_CASE("describe_operator_+=", "[Vec2]") {
	Vec2 vc1 {1.0f, 2.0f};
	Vec2 vc2 {5.0f, 3.0f};
	Vec2 vc3 {4.2f, 6.9f};
	Vec2 vc4 {0.0f, 0.0f};
	Vec2 vc5 {-1.0f, -2.0f}; 
 	
	vc1 += vc2; 				// Fuehrt Operator auf vc1 und vc2 aus => ueberschreibt vc1 mit neuen Werten
	REQUIRE(vc1.x == 6.0f);		// ueberprueft neuen X-Wert des Vektors vc1 
	REQUIRE(vc1.y == 5.0f);		// ueberprueft neuen Y-Wert des Vektors vc1

	vc2 += vc3;
	REQUIRE(vc2.x == 9.2f);
	REQUIRE(vc2.y == 9.9f);

	vc3 += vc4;
	REQUIRE(vc3.x == 4.2f);
	REQUIRE(vc3.y == 6.9f);

	vc4 += vc5;
	REQUIRE(vc4.x == -1.0f);
	REQUIRE(vc4.y == -2.0f);

	vc5 += Vec2 {-2.25f, 3.0f};
	REQUIRE(vc5.x == -3.25f);
	REQUIRE(vc5.y == 1.0f);

	Vec2 vc {};
	REQUIRE(vc.x == 0.0f);
	REQUIRE(vc.y == 0.0f);
}

	// Test_Cases: a = a - b
TEST_CASE("describe_operator_-=", "[Vec2]") {
	Vec2 vc1 {1.0f, 2.0f};
	Vec2 vc2 {5.0f, 3.0f};
	Vec2 vc3 {4.2f, 6.9f};
	Vec2 vc4 {0.0f, 0.0f};
	Vec2 vc5 {-1.5f, -2.0f}; 
 	
	vc1 -= vc2; 
	REQUIRE(vc1.x == -4.0f);
	REQUIRE(vc1.y == -1.0f);

	vc2 -= vc3;
	REQUIRE(vc2.x == Approx(0.8f)); // test kept failing without Approx();
	REQUIRE(vc2.y == -3.9f);

	vc3 -= vc4;
	REQUIRE(vc3.x == 4.2f);
	REQUIRE(vc3.y == 6.9f);

	vc4 -= vc5;
	REQUIRE(vc4.x == 1.5f);
	REQUIRE(vc4.y == 2.0f);

	vc5 -= Vec2 {-2.25f, 3.0f}; 
	REQUIRE(vc5.x == 0.75f);
	REQUIRE(vc5.y == -5.0f);
}

	// Test_Cases: a = a * b
TEST_CASE("describe_operator_*=", "[Vec2]") {
	Vec2 vc1 {1.0f, 2.0f};
	Vec2 vc2 {5.0f, 3.0f};
	Vec2 vc3 {4.2f, 6.9f};
	Vec2 vc4 {0.0f, 0.0f};
	Vec2 vc5 {-1.2f, -2.0f}; 

	vc1 *= 2.0f;
	REQUIRE(vc1.x == 2.0f);
	REQUIRE(vc1.y == 4.0f);

	vc2 *= 3.5f;
	REQUIRE(vc2.x == Approx(17.5f));
	REQUIRE(vc2.y == Approx(10.5f));

	vc3 *= -2.25f;
	REQUIRE(vc3.x == Approx(-9.45));
	REQUIRE(vc3.y == Approx(-15.525));

	vc4 *= -1.75;
	REQUIRE(vc4.x == Approx(0.0f));
	REQUIRE(vc4.y == Approx(0.0f));

	vc5 *= 4.325;
	REQUIRE(vc5.x == Approx(-5.19f));
	REQUIRE(vc5.y == Approx(-8.65));

}

	// Test_Cases: a = a / b
TEST_CASE("describe_operator_/=", "[Vec2]") {
	Vec2 vc1 {1.0f, 2.0f};
	Vec2 vc2 {5.0f, 3.0f};
	Vec2 vc3 {4.2f, 6.9f};
	Vec2 vc4 {0.0f, 0.0f};
	Vec2 vc5 {-1.0f, -2.0f}; 

	vc1 /= 2.0f; 
	REQUIRE(vc1.x == Approx(0.5f));
	REQUIRE(vc1.y == Approx(1.0f));

	vc2 /= 3.5f;
	REQUIRE(vc2.x == Approx(1.4286f));
	REQUIRE(vc2.y == Approx(0.85714f));

	vc3 /= -2.25f;
	REQUIRE(vc3.x == Approx(-1.866666f));
	REQUIRE(vc3.y == Approx(-3.066666f));

	vc4 /= -1.75;
	REQUIRE(vc4.x == Approx(0.0f));
	REQUIRE(vc4.y == Approx(0.0f));

	vc5 /= 4.325;
	REQUIRE(vc5.x == Approx(-0.231213872f));
	REQUIRE(vc5.y == Approx(-0.46242775f));

	vc5 /= 0.0f;		// Fehlermeldung
	REQUIRE(vc5.x == Approx(-0.231213872f));
	REQUIRE(vc5.y == Approx(-0.46242775f));	
}

	// Test_Cases: w = u + v 
TEST_CASE("describe_operator_addition", "[Vec2]") {
	Vec2 vc1 {1.0f, 2.0f};
	Vec2 vc2 {5.0f, 3.0f};
	Vec2 vc3 {4.2f, 6.9f};
	Vec2 vc4 {0.0f, 0.0f};
	Vec2 vc5 {-1.0f, -2.0f}; 

	Vec2 vc12 = vc1 + vc2; 
	REQUIRE(vc12.x == 6.0f);
	REQUIRE(vc12.y == 5.0f);

	Vec2 vc13 = vc1 + vc3;
	REQUIRE(vc13.x == 5.2f);
	REQUIRE(vc13.y == 8.9f);

	Vec2 vc23 = vc2 + vc3;
	REQUIRE(vc23.x == 9.2f);
	REQUIRE(vc23.y == 9.9f);

	Vec2 vc35 = vc3 + vc5; 
	REQUIRE(vc35.x == Approx(3.2f)); // test kept failing without Approx();
	REQUIRE(vc35.y == 4.9f);

	Vec2 vc45 = vc4 + vc5;
	REQUIRE(vc45.x == -1.0f);
	REQUIRE(vc45.y == -2.0f);
}

	// Test_Cases: w = u - v 
TEST_CASE("describe_operator_subtraktion", "[Vec2]") {
	Vec2 vc1 {1.0f, 2.0f};
	Vec2 vc2 {5.0f, 3.0f};
	Vec2 vc3 {4.2f, 6.9f};
	Vec2 vc4 {0.0f, 0.0f};
	Vec2 vc5 {-1.0f, -2.0f}; 

	Vec2 vc12 = vc1 - vc2; 
	REQUIRE(vc12.x == -4.0f);
	REQUIRE(vc12.y == -1.0f);

	Vec2 vc13 = vc1 - vc3; 
	REQUIRE(vc13.x == Approx(-3.2f));
	REQUIRE(vc13.y == -4.9f);

	Vec2 vc23 = vc2 - vc3; 
	REQUIRE(vc23.x == Approx(0.8f)); // test kept failing without Approx();
	REQUIRE(vc23.y == -3.9f);

	Vec2 vc35 = vc3 - vc5;
	REQUIRE(vc35.x == 5.2f);
	REQUIRE(vc35.y == 8.9f);

	Vec2 vc45 = vc4 - vc5;
	REQUIRE(vc45.x == 1.0f);
	REQUIRE(vc45.y == 2.0f);
}

	// Test_Cases: u = v * s 
TEST_CASE("describe_operator_multiplikation1", "[Vec2]") {
	Vec2 vc1 {1.0f, 2.0f};
	Vec2 vc2 {5.0f, 3.0f};
	Vec2 vc3 {4.2f, 6.9f};
	Vec2 vc4 {0.0f, 0.0f};
	Vec2 vc5 {-1.0f, -2.0f}; 

	Vec2 vcm1 = vc1 * 2.0f; 
	REQUIRE(vcm1.x == 2.0f);
	REQUIRE(vcm1.y == 4.0f);

	Vec2 vcm2 = vc2 * 4.2f; 
	REQUIRE(vcm2.x == 21.0f);
	REQUIRE(vcm2.y == Approx(12.6f)); // test kept failing without Approx();

	Vec2 vcm3 = vc3 * 6.9f;
	REQUIRE(vcm3.x == 28.98f);
	REQUIRE(vcm3.y == 47.61f);

	Vec2 vcm4 = vc4 * 5.5f; 
	REQUIRE(vcm4.x == 0.0f);
	REQUIRE(vcm4.y == 0.0f);

	Vec2 vcm5 = vc5 * -3.75;
	REQUIRE(vcm5.x == 3.75f);
	REQUIRE(vcm5.y == 7.5f);

}

	// Test_Cases: u = s * v 
TEST_CASE("describe_operator_multiplikation2", "[Vec2]") {
	Vec2 vc1 {1.0f, 2.0f};
	Vec2 vc2 {5.0f, 3.0f};
	Vec2 vc3 {4.2f, 6.9f};
	Vec2 vc4 {0.0f, 0.0f};
	Vec2 vc5 {-1.0f, -2.0f}; 

	Vec2 vcm1 = 2.0f * vc1; 
	REQUIRE(vcm1.x == 2.0f);
	REQUIRE(vcm1.y == 4.0f);

	Vec2 vcm2 = 4.2f * vc2; 
	REQUIRE(vcm2.x == 21.0f);
	REQUIRE(vcm2.y == Approx(12.6f)); // test kept failing without Approx();

	Vec2 vcm3 = 6.9f * vc3;
	REQUIRE(vcm3.x == 28.98f);
	REQUIRE(vcm3.y == 47.61f);

	Vec2 vcm4 = 5.5f * vc4; 
	REQUIRE(vcm4.x == 0.0f);
	REQUIRE(vcm4.y == 0.0f);

	Vec2 vcm5 = -3.75 * vc5;
	REQUIRE(vcm5.x == 3.75f);
	REQUIRE(vcm5.y == 7.5f);

}

	// Test_Cases: u = v / s
TEST_CASE("describe_operator_division", "[Vec2]") {
	Vec2 vc1 {1.0f, 2.0f};
	Vec2 vc2 {5.0f, 3.0f};
	Vec2 vc3 {4.2f, 6.9f};
	Vec2 vc4 {0.0f, 0.0f};
	Vec2 vc5 {-1.0f, -2.0f}; 

	Vec2 vcd1 = vc1 / 2.0f; 
	REQUIRE(vcd1.x == 0.5f);
	REQUIRE(vcd1.y == 1.0f);

	Vec2 vcd2 = vc2 / 4.2f; 
	REQUIRE(vcd2.x == Approx(1.190476));
	REQUIRE(vcd2.y == Approx(0.714285));

	Vec2 vcd3 = vc3 / 6.9f; 
	REQUIRE(vcd3.x == Approx(0.608695f));
	REQUIRE(vcd3.y == Approx(1.0f));

	Vec2 vcd4 = vc4 / 0.0f;
	REQUIRE(vcd4.x == Approx(0.0f));
	REQUIRE(vcd4.y == Approx(0.0f));

	Vec2 vcd5 = vc5 / -3.75;
	REQUIRE(vcd5.x == Approx(0.266666f));
	REQUIRE(vcd5.y == Approx(0.533333f));
}

// * --------------- MAT2-Tests --------------- * //

	// Test_Case: mat_a = mat_a * mat_b
TEST_CASE("describe_operator_mat_*=", "[Mat2]") {
	Mat2 mt1 {};
	Mat2 mt2 {2.0f, 3.0f, 4.0f, 5.0f};
	Mat2 mt3 {-3.0f, 5.0f, 0.0f, -1.0f};
	Mat2 mt4 {-4.2, 6.9f, 1.2f, -2.8f};

	mt1 *= mt2; 
	REQUIRE(mt1.a == 2.0f);
	REQUIRE(mt1.b == 3.0f);
	REQUIRE(mt1.c == 4.0f);
	REQUIRE(mt1.d == 5.0f);

	mt2 *= mt2; 
	REQUIRE(mt2.a == 16.0f);
	REQUIRE(mt2.b == 21.0f);
	REQUIRE(mt2.c == 28.0f);
	REQUIRE(mt2.d == 37.0f);

	mt3 *= mt1;
	REQUIRE(mt3.a == 14.0f);
	REQUIRE(mt3.b == 16.0f);
	REQUIRE(mt3.c == -4.0f);
	REQUIRE(mt3.d == -5.0f);

	mt4 *= mt1;
	REQUIRE(mt4.a == 19.2f);
	REQUIRE(mt4.b == Approx(21.9f)); // test kept failing without Approx();
	REQUIRE(mt4.c == Approx(-8.8f)); // test kept failing without Approx();
	REQUIRE(mt4.d == -10.4f);


}

	// Test_Case: mat_c = mat_a * mat_b
TEST_CASE("describe_operator_mat_*", "[Mat2]") {
	Mat2 mt1 {};
	Mat2 mt2 {2.0f, 3.0f, 4.0f, 5.0f};
	Mat2 mt3 {-3.0f, 5.0f, 0.0f, -1.0f};
	Mat2 mt4 {-4.2, 6.9f, 1.2f, -2.8f};

	Mat2 mt12 = mt1 * mt2;
	REQUIRE(mt12.a == 2.0f);
	REQUIRE(mt12.b == 3.0f);
	REQUIRE(mt12.c == 4.0f);
	REQUIRE(mt12.d == 5.0f);

	Mat2 mt22 = mt2 * mt2;
	REQUIRE(mt22.a == 16.0f);
	REQUIRE(mt22.b == 21.0f);
	REQUIRE(mt22.c == 28.0f);
	REQUIRE(mt22.d == 37.0f);

	Mat2 mt32 = mt3 * mt2;
	REQUIRE(mt32.a == 14.0f);
	REQUIRE(mt32.b == 16.0f);
	REQUIRE(mt32.c == -4.0f);
	REQUIRE(mt32.d == -5.0f); 

	Mat2 mt42 = mt4 * mt2;
	REQUIRE(mt42.a == 19.2f);
	REQUIRE(mt42.b == Approx(21.9f)); // test kept failing without Approx();
	REQUIRE(mt42.c == Approx(-8.8f)); // test kept failing without Approx();
	REQUIRE(mt42.d == -10.4f);

}

TEST_CASE("describe_operator_matvec_*", "[Mat2]") {
	Mat2 mt1 {};
	Mat2 mt2 {2.0f, 3.0f, 4.0f, 5.0f};
	Mat2 mt3 {-3.0f, 5.0f, 0.0f, -1.0f};
	Mat2 mt4 {-4.2, 6.9f, 1.2f, -2.8f};
	Vec2 vc1 {};
	Vec2 vc2 {5.0f, 3.0f};
	Vec2 vc3 {4.2f, 6.9f};
	Vec2 vc4 {1.0f, 2.0f};

	Vec2 vm22 = mt2 * vc2;
	REQUIRE(vm22.x == 19);
	REQUIRE(vm22.y == 35);

}

TEST_CASE("describe_operator_vecmat_*", "[Mat2]") {
	Mat2 mt1 {};
	Mat2 mt2 {2.0f, 3.0f, 4.0f, 5.0f};
	Vec2 vc1 {};
	Vec2 vc2 {5.0f, 3.0f};

	vc2 * mt2; // Multiplikation von Vektor + 2x2 Matrix ist nicht moeglich 
}

TEST_CASE("describe_function_determinate", "[Mat2]") {
	Mat2 mt1 {};
	REQUIRE(mt1.det() == 1.0f);

	Mat2 mt2 {2.0f, 3.0f, 0.0f, 5.0f};
	REQUIRE(mt2.det() == 10.0f);

	Mat2 mt3 {-4.2, 6.9f, 1.2f, -2.8f};
	REQUIRE(mt3.det() == Approx(3.48f));

	Mat2 mt4 {-0.4f, 3.23f, 9.75f, 2.13};
	REQUIRE(mt4.det() == Approx(-32.3445));
}

TEST_CASE("describe_function_inverse", "[Mat2]") {
	Mat2 mt1 {2.0f, 3.0f, 4.0f, 5.0f};
	Mat2 mt1_i = inverse(mt1);
	REQUIRE(mt1_i.a == Approx(-2.5f));
	REQUIRE(mt1_i.b == Approx(1.5f));
	REQUIRE(mt1_i.c == Approx(2.0f));
	REQUIRE(mt1_i.d == Approx(-1.0f));

	Mat2 mt2_i = inverse(Mat2{0.0f, 0.0f, 0.0f, 0.0f}); // Fehlermeldung 

	Mat2 mt3 {-4.2, 6.9f, 1.2f, -2.8f};
	Mat2 mt3_i = inverse(mt3);
	REQUIRE(mt3_i.a == Approx(-0.8046f));
	REQUIRE(mt3_i.b == Approx(-1.9827586f));
	REQUIRE(mt3_i.c == Approx(-0.34482759f));
	REQUIRE(mt3_i.d == Approx(-1.20689655f));

}

TEST_CASE("describe_function_transpose", "[Mat2]"){
	Mat2 m1 {2.0f, 3.0f, 4.0f, 5.0f};
	Mat2 m1_t = transpose(m1);
	REQUIRE(m1_t.a == 2.0f);
	REQUIRE(m1_t.b == 4.0f);
	REQUIRE(m1_t.c == 3.0f);
	REQUIRE(m1_t.d == 5.0f);

	Mat2 m2 {-4.2, 6.9f, 1.2f, -2.8f};
	Mat2 m2_t = transpose(m2);
	REQUIRE(m2_t.a == -4.2f);
	REQUIRE(m2_t.b == 1.2f);
	REQUIRE(m2_t.c == 6.9f);
	REQUIRE(m2_t.d == -2.8f);

	Mat2 m3 {-3.0f, 5.0f, 0.0f, -1.0f};
	Mat2 m3_t = transpose(m3);
	REQUIRE(m3_t.a == -3.0f);
	REQUIRE(m3_t.b == 0.0f);
	REQUIRE(m3_t.c == 5.0f);
	REQUIRE(m3_t.d == -1.0f);

}

TEST_CASE("describe_function_rotate", "[Mat2]") {
	Mat2 m1 = make_rotation_mat2(4.0f);
	REQUIRE(m1.a == Approx(-0.65364f));
	REQUIRE(m1.b == Approx(0.7568f));
	REQUIRE(m1.c == Approx(-0.7568f));
	REQUIRE(m1.d == Approx(-0.65364f));

	Mat2 m2 = make_rotation_mat2(1.0f);
	REQUIRE(m2.a == Approx(0.54030f));
	REQUIRE(m2.b == Approx(-0.841470f));
	REQUIRE(m2.c == Approx(0.841470f));
	REQUIRE(m2.d == Approx(0.54030f));

	Mat2 m3 = make_rotation_mat2(2.34f);
	REQUIRE(m3.a == Approx(-0.695563f));
	REQUIRE(m3.b == Approx(-0.7184648f));
	REQUIRE(m3.c == Approx(0.7184648f));
	REQUIRE(m3.d == Approx(-0.695563f));

}

// * ------------- Circle-Tests ------------- * //

TEST_CASE("describe_function_getDiameter", "[Circle]") {
	Circle c1 {};
	REQUIRE((c1.get_diameter()) == Approx(2.0f));

	Circle c2 {{1.0, 2.5}, -3.2, {0.0, 0.0, 0.0}};
	REQUIRE((c2.get_diameter()) == Approx(6.4f));

	Circle c3 {{2.3, 10.2}, 4.2, {0.0, 0.0, 0.0}};
	REQUIRE((c3.get_diameter()) == Approx(8.4f));

	Circle c4  {{6.9, 4.6}, 6.9, {0.3, 1.0, 0.5}};
	REQUIRE((c4.get_diameter()) == Approx(13.8f));

	Circle c5  {{6.9, 4.6}, 0.0, {0.3, 1.0, 0.5}}; // Fehlermeldung
	REQUIRE((c5.get_radius()) == Approx(1.0f));

}

TEST_CASE("describe_function_getAreaCircle", "[Circle]") {
	Circle c1 {};
	REQUIRE((c1.get_area()) == Approx(3.14159f));

	Circle c2 {{1.0, 2.5}, 3.2, {0.0, 0.0, 0.0}};
	REQUIRE((c2.get_area()) == Approx(32.169901f));

	Circle c3 {{2.3, 10.2}, 4.2, {0.0, 0.0, 0.0}};
	REQUIRE((c3.get_area()) == Approx(55.41769441f));

	Circle c4  {{6.9, 4.6}, 6.9, {0.3, 1.0, 0.5}};
	REQUIRE((c4.get_area()) == Approx(149.5712262f));

}

TEST_CASE("describe_function_getcircumference", "[Circle]") {
	Circle c1 {};
	REQUIRE((c1.get_circumference()) == Approx(6.2831f));

	Circle c2 {{1.0, 2.5}, 3.2, {0.0, 0.0, 0.0}};
	REQUIRE((c2.get_circumference()) == Approx(20.106193f));

	Circle c3 {{2.3, 10.2}, 4.2, {0.0, 0.0, 0.0}};
	REQUIRE((c3.get_circumference()) == Approx(26.389378f));

	Circle c4  {{6.9, 4.6}, 6.9, {0.3, 1.0, 0.5}};
	REQUIRE((c4.get_circumference()) == Approx(43.3539786f));

}

TEST_CASE("describe_function_getRadius", "[Circle]") {
	Circle c1 {};
	REQUIRE((c1.get_radius()) == Approx(1.0f));

	Circle c2 {{1.0, 2.5}, 3.2, {0.0, 0.0, 0.0}};
	REQUIRE((c2.get_radius()) == Approx(3.2f));

	Circle c3 {{2.3, 10.2}, 4.2, {0.0, 0.0, 0.0}};
	REQUIRE((c3.get_radius()) == Approx(4.2f));

	Circle c4 {{6.9, 4.6}, 6.9, {0.3, 1.0, 0.5}};
	REQUIRE((c4.get_radius()) == Approx(6.9f));

}

TEST_CASE("describe_function_setRadius", "[Circle]") {
	Circle c1 {};
	c1.set_radius(-3.2f);
	REQUIRE((c1.get_radius()) == Approx(3.2f));

	Circle c2 {{1.0, 2.5}, 3.2, {0.0, 0.0, 0.0}};
	c2.set_radius(-4.3f);
	REQUIRE((c2.get_radius()) == Approx(4.3f));

	Circle c3 {{2.3, 10.2}, 4.2, {0.0, 0.0, 0.0}};
	c3.set_radius(6.9f);
	REQUIRE((c3.get_radius()) == Approx(6.9f));

	Circle c4 {{6.9, 4.6}, 6.9, {0.3, 1.0, 0.5}};
	c4.set_radius(0.0f);
	REQUIRE((c4.get_radius()) == Approx(1.0f));

}


TEST_CASE("describe_function_getCenterCircle", "[Circle]") {
	Circle c1 {};
	REQUIRE((c1.get_center().x) == Approx(0.0f));
	REQUIRE((c1.get_center().y) == Approx(0.0f));

	Circle c2 {{1.0, 2.5}, 3.2, {0.0, 0.0, 0.0}};
	REQUIRE((c2.get_center().x) == Approx(1.0f));
	REQUIRE((c2.get_center().y) == Approx(2.5f));

	Circle c3 {{2.3, 10.2}, 4.2, {0.0, 0.0, 0.0}};
	REQUIRE((c3.get_center().x) == Approx(2.3f));
	REQUIRE((c3.get_center().y) == Approx(10.2f));

	Circle c4 {{6.9, 4.6}, 6.9, {0.3, 1.0, 0.5}};
	REQUIRE((c4.get_center().x) == Approx(6.9f));
	REQUIRE((c4.get_center().y) == Approx(4.6f));

}

TEST_CASE("describe_function_setCenterCircle", "[Circle]") {
	Circle c1 {};
	c1.set_center({3.2f, 0.4f});
	REQUIRE((c1.get_center().x) == Approx(3.2f));
	REQUIRE((c1.get_center().y) == Approx(0.4f));

	Circle c2 {{1.0, 2.5}, 3.2, {0.0, 0.0, 0.0}};
	c2.set_center({-4.3f, -2.5});
	REQUIRE((c2.get_center().x) == Approx(-4.3f));
	REQUIRE((c2.get_center().y) == Approx(-2.5f));

	Circle c3 {{2.3, 10.2}, 4.2, {0.0, 0.0, 0.0}};
	c3.set_center({6.9f, 4.2f});
	REQUIRE((c3.get_center().x) == Approx(6.9f));
	REQUIRE((c3.get_center().y) == Approx(4.2f));

	Circle c4 {{6.9, 4.6}, 6.9, {0.3, 1.0, 0.5}};
	c4.set_center({0.0f, 0.0f});
	REQUIRE((c4.get_center().x) == Approx(0.0f));
	REQUIRE((c4.get_center().y) == Approx(0.0f));

}

TEST_CASE("describe_function_getColorCircle", "[Circle]") {
	Circle c1 {};
	REQUIRE((c1.get_color().r) == Approx(0.0f));
	REQUIRE((c1.get_color().g) == Approx(0.0f));
	REQUIRE((c1.get_color().b) == Approx(0.0f));

	Circle c2 {{1.0, 2.5}, 3.2, {0.0, 0.94, 0.3}};
	REQUIRE((c2.get_color().r) == Approx(0.0f));
	REQUIRE((c2.get_color().g) == Approx(0.94f));
	REQUIRE((c2.get_color().b) == Approx(0.3f));

	Circle c3 {{2.3, 10.2}, 4.2, {0.1, 0.24, 0.8}};
	REQUIRE((c3.get_color().r) == Approx(0.1f));
	REQUIRE((c3.get_color().g) == Approx(0.24f));
	REQUIRE((c3.get_color().b) == Approx(0.8f));

	Circle c4 {{6.9, 4.6}, 6.9, {0.3, 1.0, 0.5}};
	REQUIRE((c4.get_color().r) == Approx(0.3f));
	REQUIRE((c4.get_color().g) == Approx(1.0f));
	REQUIRE((c4.get_color().b) == Approx(0.5f));

}

TEST_CASE("describe_function_setColorCircle", "[Circle]") {
	Circle c1 {};
	c1.set_color({0.2f, 0.3f, 0.4f});
	REQUIRE((c1.get_color().r) == Approx(0.2f));
	REQUIRE((c1.get_color().g) == Approx(0.3f));
	REQUIRE((c1.get_color().b) == Approx(0.4f));

	Circle c2 {{1.0, 2.5}, 3.2, {0.0, 0.94, 0.3}};
	c2.set_color({0.0f, 0.0f, 0.0f});
	REQUIRE((c2.get_color().r) == Approx(0.0f));
	REQUIRE((c2.get_color().g) == Approx(0.0f));
	REQUIRE((c2.get_color().b) == Approx(0.0f));

	Circle c3 {{2.3, 10.2}, 4.2, {0.1, 0.24, 0.8}};
	c3.set_color({0.34f, 0.25f, 0.12f});
	REQUIRE((c3.get_color().r) == Approx(0.34f));
	REQUIRE((c3.get_color().g) == Approx(0.25f));
	REQUIRE((c3.get_color().b) == Approx(0.12f));

	Circle c4 {{6.9, 4.6}, 6.9, {0.3, 1.0, 0.5}};
	c4.set_color({0.3f, 1.0f, 0.5f});
	REQUIRE((c4.get_color().r) == Approx(0.3f));
	REQUIRE((c4.get_color().g) == Approx(1.0f));
	REQUIRE((c4.get_color().b) == Approx(0.5f));

}

// * ------------ Rectangle-Tests ------------ * //

TEST_CASE("describe_function_getAreaRectangle", "[Rectangle]") {
	Rectangle r1 {};
	REQUIRE((r1.get_area()) == Approx(1.0f));

	Rectangle r2 {{2.3, 10.2}, -4.2, 6.9, {0.0, 0.0, 0.0}};
	REQUIRE((r2.get_area()) == Approx(28.98f));

	Rectangle r3 {{6.9, 4.6}, 10.37, -5.29, {0.3, 1.0, 0.5}};
	REQUIRE((r3.get_area()) == Approx(54.8573f));

	Rectangle r4 {{1.0, 2.5}, 3.2, 1.05, {0.0, 0.0, 0.0}};
	REQUIRE((r4.get_area()) == Approx(3.36f));

}

TEST_CASE("describe_function_getPerimeter", "[Rectangle]") {
	Rectangle r1 {};
	REQUIRE((r1.get_perimeter()) == Approx(4.0f));

	Rectangle r2 {{2.3, 10.2}, 4.2, 6.9, {0.0, 0.0, 0.0}};
	REQUIRE((r2.get_perimeter()) == Approx(22.2f));

	Rectangle r3 {{6.9, 4.6}, 10.37, 5.29, {0.3, 1.0, 0.5}};
	REQUIRE((r3.get_perimeter()) == Approx(31.32f));

	Rectangle r4 {{1.0, 2.5}, 3.2, 1.05, {0.0, 0.0, 0.0}};
	REQUIRE((r4.get_perimeter()) == Approx(8.5f));

}

TEST_CASE("describe_function_getDiagonal", "[Rectangle]") {
	Rectangle r1 {};
	REQUIRE((r1.get_diagonal()) == Approx(1.414213562f));

	Rectangle r2 {{2.3, 10.2}, 4.2, 6.9, {0.0, 0.0, 0.0}};
	REQUIRE((r2.get_diagonal()) == Approx(8.077747211f));

	Rectangle r3 {{6.9, 4.6}, 10.37, 5.29, {0.3, 1.0, 0.5}};
	REQUIRE((r3.get_diagonal()) == Approx(11.64134872f));

	Rectangle r4 {{1.0, 2.5}, 3.2, 1.05, {0.0, 0.0, 0.0}};
	REQUIRE((r4.get_diagonal()) == Approx(3.367862824f));

}

TEST_CASE("describe_function_setAside", "[Rectangle]") {
	Rectangle r1 {};
	r1.set_aside(3.33f);
	REQUIRE((r1.get_aside()) == Approx(3.33f));

	Rectangle r2 {{2.3, 10.2}, 4.2, 6.9, {0.0, 0.0, 0.0}};
	r2.set_aside(10.94f);
	REQUIRE((r2.get_aside()) == Approx(10.94f));

	Rectangle r3 {{6.9, 4.6}, 10.37, 5.29, {0.3, 1.0, 0.5}};
	r3.set_aside(2.75f);
	REQUIRE((r3.get_aside()) == Approx(2.75f));

	Rectangle r4 {{1.0, 2.5}, 3.2, 1.05, {0.0, 0.0, 0.0}};
	r4.set_aside(12.9f);
	REQUIRE((r4.get_aside()) == Approx(12.9f));

	Rectangle r5 {{1.0, 2.5}, 3.2, 1.05, {0.0, 0.0, 0.0}};
	r5.set_aside(0.0f);
	REQUIRE((r5.get_aside()) == Approx(1.0f));

}

TEST_CASE("describe_function_getAside", "[Rectangle]") {
	Rectangle r1 {};
	REQUIRE((r1.get_aside()) == Approx(1.0f));

	Rectangle r2 {{2.3, 10.2}, 4.2, 6.9, {0.0, 0.0, 0.0}};
	REQUIRE((r2.get_aside()) == Approx(4.2f));

	Rectangle r3 {{6.9, 4.6}, 10.37, 5.29, {0.3, 1.0, 0.5}};
	REQUIRE((r3.get_aside()) == Approx(10.37f));

	Rectangle r4 {{1.0, 2.5}, 3.2, 1.05, {0.0, 0.0, 0.0}};
	REQUIRE((r4.get_aside()) == Approx(3.2f));

}

TEST_CASE("describe_function_setBside", "[Rectangle]") {
	Rectangle r1 {};
	r1.set_bside(3.33f);
	REQUIRE((r1.get_bside()) == Approx(3.33f));

	Rectangle r2 {{2.3, 10.2}, 4.2, 6.9, {0.0, 0.0, 0.0}};
	r2.set_bside(-10.94f);
	REQUIRE((r2.get_bside()) == Approx(10.94f));

	Rectangle r3 {{6.9, 4.6}, 10.37, 5.29, {0.3, 1.0, 0.5}};
	r3.set_bside(2.75f);
	REQUIRE((r3.get_bside()) == Approx(2.75f));

	Rectangle r4 {{1.0, 2.5}, 3.2, 1.05, {0.0, 0.0, 0.0}};
	r4.set_bside(12.9f);
	REQUIRE((r4.get_bside()) == Approx(12.9f));

}

TEST_CASE("describe_function_getBside", "[Rectangle]") {
	Rectangle r1 {};
	REQUIRE((r1.get_bside()) == Approx(1.0f));

	Rectangle r2 {{2.3, 10.2}, 4.2, 6.9, {0.0, 0.0, 0.0}};
	REQUIRE((r2.get_bside()) == Approx(6.9f));

	Rectangle r3 {{6.9, 4.6}, 10.37, 5.29, {0.3, 1.0, 0.5}};
	REQUIRE((r3.get_bside()) == Approx(5.29f));

	Rectangle r4 {{1.0, 2.5}, 3.2, 1.05, {0.0, 0.0, 0.0}};
	REQUIRE((r4.get_bside()) == Approx(1.05f));

}

TEST_CASE("describe_function_getCenterRectangle", "[Rectangle]") {
	Rectangle r1 {};
	REQUIRE((r1.get_corner().x) == Approx(0.0f));
	REQUIRE((r1.get_corner().y) == Approx(0.0f));

	Rectangle r2 {{2.3, 10.2}, 4.2, 6.9, {0.0, 0.0, 0.0}};
	REQUIRE((r2.get_corner().x) == Approx(2.3f));
	REQUIRE((r2.get_corner().y) == Approx(10.2f));

	Rectangle r3 {{-6.9, 4.6}, 10.37, 5.29, {0.3, 1.0, 0.5}};
	REQUIRE((r3.get_corner().x) == Approx(-6.9f));
	REQUIRE((r3.get_corner().y) == Approx(4.6f));

	Rectangle r4 {{1.0, 2.5}, 3.2, 1.05, {0.0, 0.0, 0.0}};
	REQUIRE((r4.get_corner().x) == Approx(1.0f));
	REQUIRE((r4.get_corner().y) == Approx(2.5f));

}

TEST_CASE("describe_function_setCenterRectangle", "[Rectangle]") {
	Rectangle r1 {};
	r1.set_corner({3.2f, 0.4f});
	REQUIRE((r1.get_corner().x) == Approx(3.2f));
	REQUIRE((r1.get_corner().y) == Approx(0.4f));

	Rectangle r2 {{1.0, 2.5}, 3.2, 4.3, {0.0, 0.0, 0.0}};
	r2.set_corner({-4.3f, -2.5});
	REQUIRE((r2.get_corner().x) == Approx(-4.3f));
	REQUIRE((r2.get_corner().y) == Approx(-2.5f));

	Rectangle r3 {{2.3, 10.2}, 4.2, 10.12, {0.0, 0.0, 0.0}};
	r3.set_corner({6.9f, 4.2f});
	REQUIRE((r3.get_corner().x) == Approx(6.9f));
	REQUIRE((r3.get_corner().y) == Approx(4.2f));

	Rectangle r4 {{6.9, 4.6}, 6.9, 9.21, {0.3, 1.0, 0.5}};
	r4.set_corner({0.0f, 0.0f});
	REQUIRE((r4.get_corner().x) == Approx(0.0f));
	REQUIRE((r4.get_corner().y) == Approx(0.0f));

}

TEST_CASE("describe_function_getColorRectangle", "[Rectangle]") {
	Rectangle r1 {};
	REQUIRE((r1.get_color().r) == Approx(0.0f));
	REQUIRE((r1.get_color().g) == Approx(0.0f));
	REQUIRE((r1.get_color().b) == Approx(0.0f));

	Rectangle r2 {{1.0, 2.5}, 3.2, 4.3, {0.0f, 0.94f, 0.3f}};
	REQUIRE((r2.get_color().r) == Approx(0.0f));
	REQUIRE((r2.get_color().g) == Approx(0.94f));
	REQUIRE((r2.get_color().b) == Approx(0.3f));

	Rectangle r3 {{2.3, 10.2}, 4.2, 10.12, {0.9f, 0.3f, 0.7f}};
	REQUIRE((r3.get_color().r) == Approx(0.9f));
	REQUIRE((r3.get_color().g) == Approx(0.3f));
	REQUIRE((r3.get_color().b) == Approx(0.7f));

	Rectangle r4 {{6.9, 4.6}, 6.9, 3.2, {0.3f, 1.0f, 0.5f}};
	REQUIRE((r4.get_color().r) == Approx(0.3f));
	REQUIRE((r4.get_color().g) == Approx(1.0f));
	REQUIRE((r4.get_color().b) == Approx(0.5f));

}

TEST_CASE("describe_function_setColorRectangle", "[Rectangle]") {
	Rectangle r1 {};
	r1.set_color({1.0f, 0.4f, 0.9f});
	REQUIRE((r1.get_color().r) == Approx(1.0f));
	REQUIRE((r1.get_color().g) == Approx(0.4f));
	REQUIRE((r1.get_color().b) == Approx(0.9f));

	Rectangle r2 {{1.0, 2.5}, 3.2, 4.3, {0.0f, 0.94f, 0.3f}};
	r2.set_color({0.0f, 0.0f, 0.0f});
	REQUIRE((r2.get_color().r) == Approx(0.0f));
	REQUIRE((r2.get_color().g) == Approx(0.0f));
	REQUIRE((r2.get_color().b) == Approx(0.0f));

	Rectangle r3 {{2.3, 10.2}, 4.2, 10.12, {0.9f, 0.3f, 0.7f}};
	r3.set_color({0.2f, 0.42f, 0.69f});
	REQUIRE((r3.get_color().r) == Approx(0.2f));
	REQUIRE((r3.get_color().g) == Approx(0.42f));
	REQUIRE((r3.get_color().b) == Approx(0.69f));

	Rectangle r4 {{6.9, 4.6}, 6.9, 3.2, {0.3f, 1.0f, 0.5f}};
	r4.set_color({1.0f, 1.0f, 1.0f});
	REQUIRE((r4.get_color().r) == Approx(1.0f));
	REQUIRE((r4.get_color().g) == Approx(1.0f));
	REQUIRE((r4.get_color().b) == Approx(1.0f));

}


// * --------------- Main --------------- * //

int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}

// * ----------------------------------- * //