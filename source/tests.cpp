// tests.cpp (Programmiersprachen Aufgabenblatt 2)

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

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

// * --------------- MAT2-Tests --------------- * /

TEST_CASE("describe_operator_mat_*=", "[Mat2]") {
	Mat2 mt1 {};
	Mat2 mt2 {2.0f, 3.0f, 4.0f, 5.0f};
	Mat2 mt3 {-3.0f, 5.0f, 0.0f, -1.0f};

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

}

// * --------------- Main --------------- * //

int main(int argc, char *argv[]) {

  return Catch::Session().run(argc, argv);

}

// * ----------------------------------- * //