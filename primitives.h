#pragma once

#include "material.h"
#include "ray.h"

class Material; 




class Sphere {
public:

	//constructors
	Sphere() {};

	Sphere(vec3 c, double r, Material* m)  {
		center = c;
		radius = r;
		material = m;
	}

	vec3 getCenter() { return center; }

	Material* getMaterial() { return material; }

	float rayIntersect(Ray r);

private:
	vec3 center;
	double radius;
	Material* material;
};




class Plane {

public:

	//constructors 
	Plane() {}

	Plane(double a, double b, double c, double d, Material* m) {
		A = a;
		B = b;
		C = c;
		D = d;
		material = m;
	}

	Material* getMaterial() { return material; }

	double getA() { return A; }
	double getB() { return B; }
	double getC() { return C; }
	double getD() { return D; }

	float rayIntersect(Ray r);

private:
	double A = 0;
	double B = 0;
	double C = 0;
	double D = 1;
	Material* material;
};

// for return 
class Primitive {
	
public:
	Material* m;
	float collision;
	int type = -1;  // 0 = sphere, 1 = plane 
	Sphere s;
	Plane p;

	Primitive() {};
};