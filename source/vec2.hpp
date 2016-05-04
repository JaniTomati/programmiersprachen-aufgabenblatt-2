// vec2.hpp

#ifndef VEC2_HPP
#define VEC2_HPP

// Vec2 class definition 
class Vec2 {
public: 
	Vec2(); // default Konstruktor 
	Vec2(float x, float y);
	// ... 
	float x; 
	float y;

	Vec2& operator += (Vec2 const& v);
	Vec2& operator -= (Vec2 const& v);
	Vec2& operator *= (float v);
	Vec2& operator /= (float v);
};

Vec2 operator + (Vec2 const& u, Vec2 const& v);
Vec2 operator - (Vec2 const& u, Vec2 const& v);
Vec2 operator * (Vec2 const& v, float s);
Vec2 operator / (Vec2 const& v, float s);
Vec2 operator * (float s, Vec2 const& v);  

#endif // VEC2_HPP