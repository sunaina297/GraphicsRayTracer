#pragma once

#include "constant.h"

class Ray {

public:

	// initialize ray

	//constructors 
	Ray() {};

	Ray(vec3 o, vec3 ve) { p0 = o; v = ve; };

	// gets 
	vec3 getOrigin() { return p0; }
	vec3 getDirection() { return v; }

	// ray 
	vec3 point_ray(float t) const { return p0 + t * v; }

	// make ray 
	void create_ray(vec3& a, vec3& b) {  p0 = a; v = b; }


private:
	// point (x, y, z)
	vec3 p0 = { 0,0,0 };
	// vector 
	vec3 v = { 0,0,-1 };

};