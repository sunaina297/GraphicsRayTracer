#pragma once
#include "primitives.h"
#include "light.h"

Sphere* getSceneSpheres();

int getSceneSphereLen();

void scene1();

void scene2();

void scene3();

void scene4();

color3 getBackground();

color3 getAmbient();

int getLightSourceLen();

Light* getLightSources();

int getScenePlaneLen();

Plane* getScenePlanes();