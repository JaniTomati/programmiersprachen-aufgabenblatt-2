// vec2.hpp

#ifndef VEC2_HPP
#define VEC2_HPP

// Vec2 class definition 
class Vec2 {
public: 
	Vec2(float x = 0.0, float y = 0.0); // default Konstruktor 
	Vec2(Vec2 const& x, Vec2 const& y);
	// ... 
	float x; 
	float y;

	Vec2& operator += (Vec2 const& v);
	Vec2& operator -= (Vec2 const& v);
	Vec2& operator *= (float v);
	Vec2& operator / (float v);
};

#endif // VEC2_HPP