#pragma once
#include "constant.h"

class Material {
	
public:

	//constructors 
	Material() {};

	color3 getdiffuseColor() { return diffuseColor; }

	color3 getambientColor() { return ambientColor; }

	float getq() { return q; }

	float getReflection() { return reflectionFactor; }

	float getRefraction() { return refractionFactor; }

	float getRefractionIndex() { return indexOfrefraction; }

	Material(color3 kd, color3 ks, float qq, float kr, float kt, float indr) {
		diffuseColor = kd;
		ambientColor = ks;
		reflectionFactor = kr;
		refractionFactor = kt;
		indexOfrefraction = indr;
		q = qq;
	}

private:
	// Color properties as described by Phong model
	color3 diffuseColor;
	color3 ambientColor;

	float q = 0;

	// Illumination factors
	float	reflectionFactor = 0;
	float	refractionFactor = 0;
	float	indexOfrefraction = 0;
};


Material* getMaterial(int val);