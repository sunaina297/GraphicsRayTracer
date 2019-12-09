
#include "constant.h"
#include "ray.h"
#include "primitives.h"


float Sphere::rayIntersect(Ray r) {

	float t0, t1;
	// geometric solution
	vec3 L =  center - r.getOrigin();
	vec3 normalDir = normalize(r.getDirection());

	float tca = dot(L, normalDir);

	// if (tca < 0) return false;
	// L^2 - tca^2
	float d2 = dot(L,L) - (tca * tca);
	if (d2 > radius) { return -1; };

	float thc = sqrt(radius - d2);
	t0 = tca - thc;
	t1 = tca + thc;

	if (t0 > t1) std::swap(t0, t1);

	if (t0 < 0) {
		t0 = t1; // if t0 is negative, let's use t1 instead 
		if (t0 < 0) return -1; // both t0 and t1 are negative 
	}

	
	return t0;
}


float Plane::rayIntersect(Ray r) {

	vec3 rayOrigin = r.getOrigin();
	vec3 rayDir = r.getDirection();

	float x = rayOrigin[0];
	float y = rayOrigin[1];
	float z = rayOrigin[2];

	float dirx = rayDir[0];
	float diry = rayDir[1];
	float dirz = rayDir[2];

	float t = (A * x + B * y + C * z + D) / (A * dirx + B * diry + C * dirz);

	if (t < 0) { return -1; }

	return t;
}


