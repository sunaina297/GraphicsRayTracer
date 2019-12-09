#include "ray.h"
#include "primitives.h"
#include "material.h"
#include "scene.h"


static color3 colors[W_Width * W_Height] = { 0 };
static vec3 points[W_Width * W_Height] = { 0 };
static int ind = 0;



// compute ray intersections with primitives 
Primitive* Intersect(Ray r, Sphere* s, int lenS, Plane* p, int lenP) {

	float t;
	//float min_t = INFINITY;
	//Material* point_material = new Material();
	int type;
	Primitive* prim = new Primitive();
	prim->collision = INFINITY;
	// find spheres intersects
	for (int i = 0; i < lenS; i++) {

		t = s[i].rayIntersect(r);

		if ((t < prim->collision) && (t > 0)) {
			prim->collision = t;
			//point_material = s[i].getMaterial();
			//s_center = s[i].getCenter();
			prim->type = 0;
			prim->m = s[i].getMaterial();
			prim->s = s[i];
			//sphere_min = true;
		}
	}

	// find plane intersects
	for (int i = 0; i < lenP; i++) {

		t = p[i].rayIntersect(r);

		if ((t < prim->collision) && (t > 0)) {
			prim->collision = t;
			//point_material = p[i].getMaterial();
			prim->type = 1;
			prim->m = p[i].getMaterial();
			prim->p = p[i];
			//sphere_min = false;
			//A = p[i].getA();
			//B = p[i].getB();
			//C = p[i].getC();
			//D = p[i].getD();
		}
	}

	return prim;
}

// check if pixel is under shadow 
bool Shadow(Light L, vec3 poi, Sphere* s, int lenS, Plane* p, int lenP) {
	bool isShadow = true;

	Ray shadow;
	vec3 shadowDir = L.getLightLocation() - poi;
	shadow.create_ray(poi, shadowDir);

	Primitive* prim = Intersect(shadow, s, lenS, p, lenP);

	if (prim->collision == INFINITY) {
		isShadow = false;
	}

	return isShadow;
}


// power function for vectors 
vec3 powV(int q, vec3 v) {
	vec3 powerOfV = v;
	for (int i = 0; i < q; i++) {
		powerOfV *= v;
	}

	return powerOfV;
}



// trace rays to find intersections
// inplement phong lightning as needed as return color at pixel 
color3 trace(int depth, Ray r) {
	depth -= 1;
	if (depth == 0) {
		// background color return
		return getBackground();
	}

	Sphere* s = getSceneSpheres();
	int lenS = getSceneSphereLen();

	Plane p_point;
	Plane* p = getScenePlanes();
	int lenP = getScenePlaneLen();

	Primitive* prim = Intersect(r, s, lenS, p, lenP);

	// if no intersection
	if (prim->collision == INFINITY) {
		return getBackground();
	}

	//else -- we hit object
	double bias = 0.01;
	vec3 point = r.point_ray(prim->collision)+bias;

	color3 ks = prim->m->getambientColor();
	color3 kd = prim->m->getdiffuseColor();

	vec3 N;
	if (prim->type == 0) {
		vec3 s_center = prim->s.getCenter();
		N = normalize(point - s_center);
		//printv(N);
	}
	else {
		vec3 plane_normal = { (float)prim->p.getA(),(float)prim->p.getB(),(float)prim->p.getC() };
		N = normalize(plane_normal);
	}
	vec3 V = normalize(r.getOrigin() - point);
	vec3 R = normalize(2 * (V * N) * N - V);
	float q = prim->m->getq();
	color3 I = getAmbient() * kd;

	float kr = prim->m->getReflection();
	float kt = prim->m->getRefraction();

	// for reflected rays
	color3 Ir;
	if (kr > 0.0) {
		Ray reflectedRay;
		reflectedRay.create_ray(point, R);
		color3 Ir = trace(depth, reflectedRay);
			// color3 reflectionColor = trace(depth, reflectedRay);
		I += (Ir * kr);
	}
	color3 It;
	// for refracted rays 
	if (kt > 0.0) {
		float refractedInx = prim->m->getRefractionIndex();
		refractedInx = 1 / refractedInx;
		Ray refractedRay;

		float cosI = -1.0 * dot(r.getDirection(), prim->collision);
		if (cosI > 0) {

		}
		float sinT2 = refractedInx * refractedInx * (1 - cosI * cosI);
		if (sinT2 >= 1) { sinT2= 1.0; }

		vec3 refracteddir = normalize(r.getDirection() * refractedInx + prim->collision * (refractedInx * cosI - sqrt(1 - sinT2)));

		refractedRay.create_ray(point, refracteddir);
		color3 It = trace(depth, refractedRay);
		//I += (It * kt);
	}


	// for each light 
	Light* II = getLightSources();
	int m = getLightSourceLen();


	// Phong lighting calculation
	for (int i = 0; i < m; i++) {
		if(!Shadow(II[i], point, s, lenS, p, lenP)) {
		color3 Lin = II[i].getLightIntensity();
		vec3 Lposition = -(II[i].getLightLocation());

		vec3 L = normalize(point - Lposition);

		I += Lin * (kd * L * N) + (ks * powV(q, V * R));
		}
	}

	//I += (kt);

	//printf("ambient\n");
	// only returns ambient 
	return I;
}








void render() {
	//vertexes();
	// loop generates inital rays for each pixel 
	// rays start at origin and have vector v = ( vx, vy, -1)
	float imageAspect = W_Width / W_Height;
	vec3 origin = { 0,0,0 };
	printf("Begin render\n\n");
	for (int x = 0; x < W_Width; x++) {
		for (int y = 0; y < W_Height; y++) {

			//ray point
			float px = (2 * ((x + 0.5) / W_Width) - 1) * tan(fovy / 2 * M_PI / 180) * imageAspect;
			float py = (1 - 2 * ((y + 0.5)) / W_Height) * tan(fovy / 2 * M_PI / 180);
			vec3 point = { px, py , -1 };

			vec3 dir = normalize(point - origin);;
			dir = normalize(dir);

			Ray initial_ray;
			initial_ray.create_ray(origin, dir);

			color3 point_color = trace(4, initial_ray);
			if (point_color[0] > 1.0) { point_color[0] = 1.0; }
			if (point_color[1] > 1.0) { point_color[1] = 1.0; }
			if (point_color[2] > 1.0) { point_color[2] = 1.0; }


			points[ind] = point;
			colors[ind] = point_color;

			//printv(colors[ind]);
			ind++;
			//printf("%d,\n",ind);
		}
	}


	glClear(GL_COLOR_BUFFER_BIT);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glColorPointer(3, GL_FLOAT, 0, colors);
	glVertexPointer(3, GL_FLOAT, 0, points);

	glPolygonMode(GL_FRONT, GL_LINE);
	glDrawArrays(GL_POINTS, 0, W_Width * W_Height);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glFlush();

	glutSwapBuffers();
	ind = 0;
	printf("finish render");
}
