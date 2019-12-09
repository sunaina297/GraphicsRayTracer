#pragma once
#include "constant.h"

class Light {
public:
	
	// constructors 

	Light() {}

	Light(vec3 l, color3 i) {
		location = l;
		intensity = i;
	}

	color3 getLightIntensity() { return intensity; }

	vec3 getLightLocation() { return location; }


private:
	vec3 location;
	color3 intensity;


};