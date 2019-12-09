#include "material.h"


Material* getMaterial(int val) {
	Material* m;
	color3 kd1 = { 0.4, 0.4, 0.4 };
	color3 ks1 = { 0.0, 0.0, 1.0 };
	m = new Material(kd1, ks1, 10, 0.5, 3.0, 1.5);

	//scene 1
	// reddish ?
	if (val == 0) {
		color3 kd1 = { 0.4, 0.4, 0.4 };
		color3 ks1 = { 0.0, 0.0, 1.0 };
		m = new Material(kd1, ks1, 0, 0.1, 0.8, 1.5);
	}
	//green
	else if (val == 1) {
		color3 kd2 = { 0.3, 0.5, 0.0 };
		color3 ks2 = { 0.2, 0.4, 0.0 };
		m = new Material(kd2, ks2, 50, 0.67, 0, 0);
	}
	//dark blue
	else if (val == 2) {
		color3 kd3 = { 0.2, 0.0, 0.3 };
		color3 ks3 = { 0.0, 1.0, 0.0 };
		m = new Material(kd3, ks3, 100, 0.1, 0, 0);
	}
	//smooth dark blue
	else if (val == 3) {
		color3 kd3 = { 0.2, 0.0, 0.3 };
		color3 ks3 = { 0.0, 1.0, 0.0 };
		m = new Material(kd3, ks3, 30, 0.1, 0, 0);
	}

	//scene 4
	else if (val == 4) {
		color3 kd3 = { 0.8, 1.0, 0.5 };
		color3 ks3 = { 0.3, 0.3, 1.0 };
		m = new Material(kd3, ks3, 30, 0.1, 0, 0);
	}
	// scene 4
	else if (val == 5) {
		color3 kd3 = { 0.59, 0.5, 0.847059 };
		color3 ks3 = { 0.847059, 0.847059, 0.847059 };
		m = new Material(kd3, ks3, 30, 0.1, 0, 0);
	}
	// scene 3
	else if (val == 6) {
		color3 kd1 = { 0.4, 0.4, 0.4 };
		color3 ks1 = { 0.0, 0.0, 1.0 };
		m = new Material(kd1, ks1, 0, 0.1, 0.8, 1.5);
	}
	else if (val == 7) {
		color3 kd2 = { 0.3, 0.5, 0.0 };
		color3 ks2 = { 0.2, 0.4, 0.0 };
		m = new Material(kd2, ks2, 0, 0.65, 0, 0);
	}
	
	return m;
}