// test.cpp (Programmiersprachen Aufgabenblatt 2)

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

// * --------------- Tests --------------- * //

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

}


// * --------------- Main --------------- * //

int main(int argc, char *argv[]) {

  return Catch::Session().run(argc, argv);

}
// * ----------------------------------- * //