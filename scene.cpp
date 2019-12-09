#include "constant.h"
#include "light.h"
#include "primitives.h"
#include "material.h"
#include "render.h"

static Sphere* scene_spheres;
static int scene_sphere_len;

static Plane* scene_planes;
static int scene_plane_len;

static Light* lightSources;
static int lightSources_len;

static color3 ambient = {1.0, 0.9, 1.0 };
static color3 background = { 0.0, 0.9, 1.0 };


// RETREIVAL 
Sphere* getSceneSpheres() {
	return scene_spheres;
}

int getSceneSphereLen() {
	return scene_sphere_len;
}

Plane* getScenePlanes() {
	return scene_planes;
}

int getScenePlaneLen() {
	return scene_plane_len;
}

color3 getAmbient() {
	return ambient;
}

color3 getBackground() {
	return background;
}

Light* getLightSources() {
	return lightSources;
}
int getLightSourceLen() {
	return lightSources_len;
}


// SCENES
void scene1() {

	printf("Begin Scene\n\n");

	// basic lighting
	ambient = { 1.0, 1.0, 1.0 };
	background = { 0.0, 0.9, 1.0 };

	// material 
	Material* red = getMaterial(0);
	Material* green = getMaterial(1);
	Material* blue = getMaterial(2);
	Material* smooth_blue = getMaterial(3);

	// light 
	lightSources = new Light[2];
	lightSources_len = 2;

	vec3 lightLocation = { -2, 7, 5 };
	vec3 lightlocation2 = { 10, 10, 5 };
	color3 lightIntensity = { 1,1, 1};
	color3 lightIntensity2 = { 2, 2, 2 };

	Light* light1 = new Light(lightLocation, lightIntensity);
	Light* light2 = new Light(lightlocation2, lightIntensity2);

	lightSources[0] = *light1;
	lightSources[1] = *light2;


	// primitives
	vec3 sphere1_center = { -3, 0, -5 };
	vec3 sphere2_center = { 0, -1, -5 };
	vec3 sphere3_center = { 3, 0, -5 };

	// spheres 
	scene_sphere_len = 3;
	if (scene_spheres == NULL) {
		scene_spheres = new Sphere[scene_sphere_len];
	}
	else {
		delete[] scene_spheres;
		scene_spheres = new Sphere[scene_sphere_len];
	}
	//scene_spheres = new Sphere[3];
	Sphere* sphere1 = new Sphere(sphere1_center, 1.3, red);
	Sphere* sphere2 = new Sphere(sphere2_center, 1.3, green);
	Sphere* sphere3 = new Sphere(sphere3_center, 1.3, blue);

	scene_spheres[0] = *sphere1;
	scene_spheres[1] = *sphere2;
	scene_spheres[2] = *sphere3;

	//planes
	scene_plane_len = 1;
	if (scene_planes == NULL) {
		scene_planes = new Plane[scene_plane_len];
	}
	else {
		delete[] scene_planes;
		scene_planes = new Plane[scene_plane_len];
	}
	Plane* plane1 = new Plane(1.0, 1.0, 0, -5.0, smooth_blue);
	scene_planes[0] = *plane1;

	render();
}





void scene2() {
	printf("Begin Scene\n\n");

	// basic lighting
	ambient = { 0.2, 0.6, 1.0 };
	background = { 0.0, 0.9, 1.0 };

	// material 
	Material* red = getMaterial(0);
	Material* green = getMaterial(1);
	Material* blue = getMaterial(2);
	Material* reddis = getMaterial(3);


	// light
	lightSources_len = 3;
	lightSources = new Light[lightSources_len];

	vec3 lightLocation = { -2, 7, 5 };
	vec3 lightlocation2 = { 5, 5, 5 };
	vec3 lightlocation3 = { -5, 5, 5 };
	color3 lightIntensity = { 2,2, 2 };
	color3 lightIntensity2 = { 5, 5, 5 };
	color3 lightIntensity3 = { 10, 5, 5 };

	Light* light1 = new Light(lightLocation, lightIntensity);
	Light* light2 = new Light(lightlocation2, lightIntensity2);
	Light* light3 = new Light(lightlocation3, lightIntensity3);

	lightSources[0] = *light1;
	lightSources[1] = *light2;
	lightSources[2] = *light3;


	// primitives
	vec3 sphere1_center = { -3, 0, -5 };
	vec3 sphere2_center = { 0, -1, -5 };
	vec3 sphere3_center = { 3, 0, -3 };
	vec3 sphere4_center = { -1, 2, -4};
	// spheres 
	scene_sphere_len = 4;
	if (scene_spheres == NULL) {
		scene_spheres = new Sphere[scene_sphere_len];
	}
	else {
		delete[] scene_spheres;
		scene_spheres = new Sphere[scene_sphere_len];
	}
	Sphere* sphere1 = new Sphere(sphere1_center, 1.3, red);
	Sphere* sphere2 = new Sphere(sphere2_center, 1.3, green);
	Sphere* sphere3 = new Sphere(sphere3_center, 1.3, red);
	Sphere* sphere4 = new Sphere(sphere4_center, 0.3, red);

	scene_spheres[0] = *sphere1;
	scene_spheres[1] = *sphere2;
	scene_spheres[2] = *sphere3;
	scene_spheres[3] = *sphere4;


	//planes
	scene_plane_len = 1;
	if (scene_planes == NULL) {
		scene_planes = new Plane[scene_plane_len];
	}
	else {
		delete[] scene_planes;
		scene_planes = new Plane[scene_plane_len];
	}
	Plane* plane1 = new Plane(0.0, 1.0, 0, -7.0, green);
	//Plane* plane2 = new Plane(0.0, 1.0, 0, -10.0, reddis);
	scene_planes[0] = *plane1;
	//scene_planes[1] = *plane2;

	render();

}




void scene3() {
	printf("Begin Scene\n\n");

	// basic lighting
	ambient = { 1.0, 1.0, 1.0 };
	background = { 0.0, 0.9, 1.0 };

	// material 
	Material* red = getMaterial(6);
	Material* green = getMaterial(7);


	// light 
	lightSources = new Light[2];
	lightSources_len = 2;

	vec3 lightLocation = { -2, 7, 5 };
	vec3 lightlocation2 = { 10, 10, 5 };
	color3 lightIntensity = { 1,1, 1 };
	color3 lightIntensity2 = { 2, 2, 2 };

	Light* light1 = new Light(lightLocation, lightIntensity);
	Light* light2 = new Light(lightlocation2, lightIntensity2);

	lightSources[0] = *light1;
	lightSources[1] = *light2;


	// primitives
	vec3 sphere1_center = { -3, 0, -5 };
	vec3 sphere2_center = { 0, -1, -5 };
	vec3 sphere3_center = { 3, 0, -5 };

	// spheres 
	scene_sphere_len = 3;
	if (scene_spheres == NULL) {
		scene_spheres = new Sphere[scene_sphere_len];
	}
	else {
		delete[] scene_spheres;
		scene_spheres = new Sphere[scene_sphere_len];
	}
	//scene_spheres = new Sphere[3];
	Sphere* sphere1 = new Sphere(sphere1_center, 1.3, red);
	Sphere* sphere2 = new Sphere(sphere2_center, 1.3, red);
	Sphere* sphere3 = new Sphere(sphere3_center, 1.3, red);

	scene_spheres[0] = *sphere1;
	scene_spheres[1] = *sphere2;
	scene_spheres[2] = *sphere3;

	//planes
	scene_plane_len = 1;
	if (scene_planes == NULL) {
		scene_planes = new Plane[scene_plane_len];
	}
	else {
		delete[] scene_planes;
		scene_planes = new Plane[scene_plane_len];
	}
	Plane* plane1 = new Plane(1.0, 1.0, 0, -5.0, green);
	scene_planes[0] = *plane1;

	render();
}

void scene4() {

	printf("Begin Scene\n\n");

	// basic lighting
	ambient = { 0.5, 0.2, 0.2 };
	background = { 0.0, 0.9, 1.0 };

	// material 
	Material* red = getMaterial(0);
	Material* green = getMaterial(1);
	Material* blue = getMaterial(2);
	Material* reddis = getMaterial(5);


	// light
	lightSources_len = 3;
	lightSources = new Light[lightSources_len];

	vec3 lightLocation = { -2, 7, 5 };
	vec3 lightlocation2 = { 5, 5, 5 };
	vec3 lightlocation3 = { -5, 5, 5 };
	color3 lightIntensity = { 2,2, 2 };
	color3 lightIntensity2 = { 5, 5, 5 };
	color3 lightIntensity3 = { 10, 5, 5 };

	Light* light1 = new Light(lightLocation, lightIntensity);
	Light* light2 = new Light(lightlocation2, lightIntensity2);
	Light* light3 = new Light(lightlocation3, lightIntensity3);

	lightSources[0] = *light1;
	lightSources[1] = *light2;
	lightSources[2] = *light3;


	// primitives
	vec3 sphere1_center = { -3, 0, -5 };
	vec3 sphere2_center = { -3.2, 1, -5 };
	vec3 sphere3_center = { 3, 0, -5 };
	vec3 sphere4_center = { 4, -2, -4 };
	vec3 sphere5_center = { 2, 2.5, -4 };
	vec3 sphere6_center = { -1, 2, -4 };
	vec3 sphere7_center = { -1.2, -2, -3 };
	vec3 sphere8_center = { 0, -2.76, -3 };
	vec3 sphere9_center = { 3, 4, -3 };
	vec3 sphere10_center = { -2, 0.5, -2 };
	vec3 sphere11_center = { -1, 1.8, -1 };

	// spheres 
	scene_sphere_len = 11;
	if (scene_spheres == NULL) {
		scene_spheres = new Sphere[scene_sphere_len];
	}
	else {
		delete[] scene_spheres;
		scene_spheres = new Sphere[scene_sphere_len];
	}
	Sphere* sphere1 = new Sphere(sphere1_center, 0.3, blue);
	Sphere* sphere2 = new Sphere(sphere2_center, 0.3, blue);
	Sphere* sphere3 = new Sphere(sphere3_center, 0.3, blue);
	Sphere* sphere4 = new Sphere(sphere4_center, 0.3, blue);
	Sphere* sphere5 = new Sphere(sphere5_center, 0.3, blue);
	Sphere* sphere6 = new Sphere(sphere6_center, 0.3, blue);
	Sphere* sphere7 = new Sphere(sphere7_center, 0.3, blue);
	Sphere* sphere8 = new Sphere(sphere8_center, 0.3, blue);
	Sphere* sphere9 = new Sphere(sphere9_center, 0.3, blue);
	Sphere* sphere10 = new Sphere(sphere10_center, 0.3, blue);
	Sphere* sphere11 = new Sphere(sphere11_center, 0.3, blue);

	scene_spheres[0] = *sphere1;
	scene_spheres[1] = *sphere2;
	scene_spheres[2] = *sphere3;
	scene_spheres[3] = *sphere4;
	scene_spheres[4] = *sphere5;
	scene_spheres[5] = *sphere6;
	scene_spheres[6] = *sphere7;
	scene_spheres[7] = *sphere8;
	scene_spheres[8] = *sphere9;
	scene_spheres[9] = *sphere10;
	scene_spheres[10] = *sphere11;



	
	//planes
	scene_plane_len = 2;
	if (scene_planes == NULL) {
		scene_planes = new Plane[scene_plane_len];
	}
	else {
		delete[] scene_planes;
		scene_planes = new Plane[scene_plane_len];
	}
	Plane* plane1 = new Plane(0.0, 1, 1, -10.0, blue);
	Plane* plane2 = new Plane(1.0, 1.0, 0, -10.0, reddis);
	scene_planes[0] = *plane1;
	scene_planes[1] = *plane2;

	render();
}